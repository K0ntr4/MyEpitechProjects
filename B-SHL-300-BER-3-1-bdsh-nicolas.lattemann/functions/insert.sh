#!/bin/sh
source functions/help.sh
source functions/parse_args.sh
source functions/validate.sh

to_end_of_table () {
    index=$(cat $file_path | grep -no "data_${table}" | grep -oe '[0-9]*');
    closing_brackets=$(cat $file_path | grep -no ']' | grep -oe '[0-9]*');
    num=""

    for ((i = 0; i < (($(expr length "$closing_brackets") + 1)); i++)); do
        curr_char=${closing_brackets:i:1}

        if [ $(expr match "$curr_char" '[0-9]') == 1 ]; then
            num+=$curr_char
        else
            if [ $(($num > $index)) == 1 ]; then
                index=$num
                break;
            fi
            num=""
            continue;
        fi
    done

    echo "$index"
}

append_comma () {
    if [[ $(sed "$((index - 1))!d" $file_path | grep -P "(}|\])$") ]]; then
        sed -i "$((index - 1)) s/$/,/" $file_path
    fi
}

insert () {
    arr_len=${#new_args[@]}
    table=${new_args[1]}

    validate_file
    validate_table $table

    data=""

    for ((i = 2; i < $arr_len; i++)); do
        data+=" ${new_args[i]}"
    done

    declare -A values_dict


    declare -a fields 

    get_fields fields $table

    for key in "${fields[@]}"; do
       values_dict[$key]=""
    done

    ic=0
    string_to_ass_array values_dict "$data"

    index=$(to_end_of_table)

    append_comma

    sed -i "$index i $(indent 2){" $file_path

    i=0
    for key in "${!values_dict[@]}"; do
        i=$((i + 1))
        data=$(indent 3)'~'$key'~: ~'${values_dict[$key]}'~'
        if [ $i != ${#fields[@]} ]; then
            data=$data,
        fi
        sed -i "$index a $data" $file_path
        index=$((index + 1))
    done

    sed -i "$index a $(indent 2)}" $file_path
    sed -i -- "s/~/\"/g" $file_path
    sed -i -- "s/#/ /g" $file_path
}

indent () {
    indentation=4*$1

    indent=""
    for ((i = 0; i < $indentation; i++)); do
        indent+="#"
    done

    echo -e "$indent";
}