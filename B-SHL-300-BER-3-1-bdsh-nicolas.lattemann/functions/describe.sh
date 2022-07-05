describe () {
    table=${new_args[1]};

    declare -a fields

    get_fields fields $table
    print_fields
}


print_fields () {
    local j=0
    local total_width=0
    for key in "${fields[@]}"; do
        echo -n "$key"
        ((total_width+=${#key}))
        if [[ $(( j )) < $((${#fields[@]} - 1)) ]]; then
            gen_diff j "$key"
            echo -n "  | "
            ((total_width+=4))
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

get_fields () {
    table_desc="$(cat $file_path | grep -Poz "desc_$2.*\K(.|\n)*?(?=])" | tr -d '",\0')"

    declare -n fields_local="$1"

    local buff=""
    local len=${#table_desc}

    for ((i=0; i < len; i++)); do
        local curr_char=${table_desc:i:1};

        if [[ $curr_char == " " ]] || [[ $i == $len ]]; then
            fields_local+=( $buff )
            buff=""
        else
            buff+="$curr_char"
        fi
    done
}