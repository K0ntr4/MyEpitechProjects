#!/bin/sh
source functions/help.sh
source functions/parse_args.sh
source functions/validate.sh
source functions/to_ass.sh

update_values () {
    entry=$(sed "$nr1,$nr2!d" $file_path)

    for key in "${!values_dict[@]}"; do
        if [[ $(echo -e "$entry" | grep -P "\""$search_field"\":.*\""$search_field_value"\"") != "" ]]; then
            comma=$(echo -e "$entry" | grep -Po "$key.*?\K,$")
            sed -i "$nr1,$nr2 s/$key\".*/$key\": \"${values_dict[$key]}\"$comma/g" $file_path
        fi
    done
}

update () {
    table=${new_args[1]}

    validate_file
    validate_table $table

    command=$(echo ${new_args[@]:2:$(expr length "new_args[@]")} | grep -E '.+?=.+?where\s.+?=.+?$')


    search_field=$(echo "$command" | grep -Po "where\s\K.*?(?==)")
    search_field_value=$(echo "$command" | grep -Po "where\s.*?=\K.*")
    new_values=$(echo "$command" | grep -Po "^.*(?= where)")

    validate_field $search_field

    if [[ ! $command ]]; then
        echo shut the fuck up
        exit
    fi

    end_index=$(to_end_of_table)
    start_index=$(cat $file_path | grep -no "data_${table}" | grep -oe '[0-9]*');
    curly_brackets=$(cat $file_path | grep -n '' | head -n $end_index  | tail -n $((start_index - end_index)) | grep -E '({|})' | grep -Eo '[0-9]*')
    curly_brackets=$(echo  $curly_brackets)

    len=$(expr length "$curly_brackets")
    
    declare -A values_dict
    string_to_ass_array values_dict "$new_values"

    nr1=""
    nr2=""
    mode=0 

    for ((i = 0; i < len; i++)); do
        curr_char=${curly_brackets:i:1}

        if [ $(expr match "$curr_char" '[0-9]') == 1 ]; then
            if [ $mode == 0 ]; then
                nr1+=$curr_char
            elif [ $mode == 1 ]; then
                nr2+=$curr_char
            fi
        fi

        if [ $(expr match "$curr_char" ' ') == 1 ] || [ $i == $((len - 1)) ]; then
            if [ $mode == 0 ]; then
                mode=1;
            elif [ $mode == 1 ]; then
                update_values
                nr1=""
                nr2=""
                mode=0;
            fi
        fi
    done
}