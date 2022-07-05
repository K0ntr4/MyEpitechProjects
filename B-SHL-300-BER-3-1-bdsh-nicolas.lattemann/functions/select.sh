source functions/print.sh
source functions/validate.sh

split () {
    declare -n dest_array=$1
    string="$2"
    char="$3"

    buff=""
    len=$(expr length "$string")
    for ((i = 0; i < $len + 1; i++)); do
        curr_char=${string:i:1};

        if [ $(expr match "$curr_char" "$char") == 1 ] || [ $i == $len ]; then
            dest_array+=($buff);
            buff=""
        else
            buff+=$curr_char;
        fi
    done
}


shove_data_into_arrays () {
    declare -n data_local="data"
    declare -n data_sorter_local="data_sorter"
    declare -A values

    local fields="$(echo "$1" | grep -Po "\"\K.*(?=\":)")"
    local i=1
    local pairs=$(echo "$fields" | grep -c "")

    for ((; i <= pairs; i++)); do
        local key="$(echo "$fields" | sed "$i,$i!d")"

        values[$key]="$(echo "$1" | grep -Po "$key\":.*\"\K.+?(?=\")")"
    done

    for key in ${!values[@]}; do
        data_local["${iterator}_$key"]="${values[$key]}"

        if [[ $orderby == $key ]]; then
            data_sorter_local["${iterator}_$key"]="${values[$key]}"
        fi
    done

    ((iterator+=1))
}

get () {
    local nr1=""
    local nr2=""
    local mode=0
    local has_where=0 

    if [[ $search_field != "" ]]; then
        has_where=1;
    fi

    local len=$(expr length "$curly_brackets")
    for ((i = 0; i <= len; i++)); do
        local curr_char="${curly_brackets:i:1}"

        if [ $(expr match "$curr_char" '[0-9]') == 1 ]; then
            if [ $mode == 0 ]; then
                nr1+=$curr_char
            elif [ $mode == 1 ]; then
                nr2+=$curr_char
            fi
        fi

        if [ $(expr match "$curr_char" "\s") == 1 ] || [ $i == $((len)) ]; then
            if [ $mode == 0 ]; then
                mode=1;
            elif [ $mode == 1 ]; then
                local data_line=$(echo "$table_data" | sed "$nr1,$nr2!d" | grep -Po  "\"$search_field\":.*\"$search_field_value\"")

                if [[ $data_line != "" ]] && [[ $has_where == 1 ]] || [[ $has_where == 0 ]]; then
                    shove_data_into_arrays "$(echo -e "$table_data" | sed "$nr1,$nr2!d")"
                fi

                nr1=""
                nr2=""
                mode=0;
            fi
        fi
    done
}

select_ () { 
    validate_file

    declare -a tables
    declare -a fields
    declare -A data
    declare -A data_sorter
    local iterator=0

    split tables "${new_args[1]}" ","
    split fields "${new_args[2]}" ","


    if [[ $fields == "" ]] || [[ $fields == "orderby" ]]; then
        fields=()
        get_fields fields ${tables[0]}
    fi

    for field in ${fields[@]}; do
        validate_field $field;
    done

    for table in ${tables[@]}; do
        validate_table $table;
    done

    search_field=$(echo "${new_args[@]}" | grep -Po "where\s\K.*?(?==)")
    search_field_value=$(echo "${new_args[@]}" | grep -Po "where\s.*?=\K(.*?(?= orderby)|.*)")
    orderby=$(echo "${new_args[@]}" | grep -Po "(where\s.*?\s+)?orderby\s+\K[^\s]*")

    for table in "${tables[@]}"; do
        table_data="$(cat $file_path | grep -Poz "data_$table.*\K(.|\n)*?(?=])" | tr -d '\0')"
        curly_brackets="$(echo "$table_data" | grep -n '' | grep -E '({|})' | grep -Po '^[0-9]*')"

        get
    done

    print
}


