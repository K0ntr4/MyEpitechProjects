print () {
    local widths=()

    for key in "${fields[@]}"; do
        widths+=(${#key})
    done

    for ((i=0; i < "${#fields[@]}"; i++)); do
        for ((j=0; j < $iterator; j++)); do
            local value_width=${#data[${j}_${fields[$i]}]}
            if [[ $(($value_width > ${widths[$i]})) == 1 ]]; then
                widths[$i]=$value_width
            fi
        done
    done

    if [[ $json_format == 0 ]]; then
        header_print
    fi

    if [[ $json_format == 1 ]]; then
        echo "["
    fi

    if [[ $orderby == "" ]]; then
        normal_print;
    else
        sorted_print
    fi

    if [[ $json_format == 1 ]]; then
        echo -e "\n]"
    fi
}


gen_diff () {
    len=$((${widths[$1]} - ${#2} + 2))
    local i=0

    if [[ ${#2} == 0 ]] && [[ $j > 0 ]]; then
        ((len+=1));
    fi

    for ((;i < len; i++)); do
        echo -n ' '
    done
}

header_print () {
    local total_width=0
    local j=0

    for key in "${fields[@]}"; do
        echo -n "$key"
        ((total_width+=$((${widths[$j]} + 3))))
        if [[ $(( j )) < $((${#fields[@]} - 1)) ]]; then
            gen_diff j "$key"
            echo -n "| "
        fi
        first=1
        ((j+=1))
    done
    echo

    for ((i=0; i < total_width; i++)); do
        echo -n '-'
    done
    echo
}

normal_print () {  
    local i=0

    for ((i=0; i < iterator; i++)); do 
        if [[ $json_format == 1 ]]; then
            json_print $i $((i + 1))
        else
            row_print $i;
        fi
    done

 
}

sorted_print () {
    local ordered=$(for key in "${!data_sorter[@]}"; do
        echo $key ' - ' "${data_sorter["$key"]}"
    done | sort -i -k3 | grep -Po "^\d*" | tr '\n' ' ')

    local buff=""
    local i=0

    for ((n=0; n < ${#ordered}; n++)); do
        local curr_char=${ordered:n:1};
        if [ $(expr match "$curr_char" '[0-9]') == 1 ]; then
            buff+=$curr_char
        else 
            if [[ $json_format == 1 ]]; then
                json_print $buff $n
            else
                row_print $buff
            fi
            buff=""
        fi
    done
}

row_print () {
    local j=0

    for ((k=0; k < "${#fields[@]}"; k++)); do
        local key="${fields[$k]}"


        echo -n "${data[${1}_$key]}"

        if [[ $(( j )) < $((${#fields[@]} - 1)) ]]; then
            gen_diff j "${data[${1}_$key]}"
            echo -n "|"

            if [[ ${#data[${1}_${fields[$((k + 1))]}]} > 0 ]]; then
                echo -n " "
            fi
        fi

        first=1
        ((j+=1))
    done
    echo
}

json_print () {
    local j=0
    local first=0
    local i=$2

    if [[ $i > 1 ]]; then
        echo ","
    fi

    echo "$(trail 4 " "){"
    for key in "${fields[@]}"; do
        if [[ $first == 1 ]]; then
            echo ','
        fi
        first=1
        echo -n "$(trail 8 " ")\"$key\": \"${data[${1}_$key]}\""
    done
    echo -en "\n$(trail 4 " ")}"
}

trail () {
    local max=$1;
    local char="$2"
    local i=0;

    for ((i=0; i < max; i++)) {
        echo -n "$char"
    }
}