source functions/parse_args.sh

create() {
    OPERATION=$2
    STRING=$4
    DELIM=","
    s=$STRING$DELIM
    ARGUMENTS=();
    while [[ $s ]]; do
        ARGUMENTS+=( "${s%%"$DELIM"*}" );
        s=${s#*"$DELIM"};
    done;
    DESC=""
    arr_length=${#ARGUMENTS[@]}

    if [[ "$OPERATION" == "database" ]]; then
        if  !(test -f "$file_path"); then
            touch $file_path
            echo "{" > $file_path
            echo "}" >> $file_path
        else
            file_already_exists_error $file_path
        fi
    fi
    if [[ "$OPERATION" == "table" ]]; then
        validate_file
        validate_create_table $3
        DESC+="\ \ \ \ \"desc_${3}\": ["
        DATA+="\ \ \ \ \"data_${3}\": ["
        for ((i = 0 ; i < $arr_length ; i++)); do
            if [[ i != $arr_length ]] && (( i > 0 )); then
                DESC+=","
            fi
            DESC+="\n       \"${ARGUMENTS[i]}\""
        done
        DESC+="\n    ]"
        DATA+="\n    ]"
        TEST=$(cat ${file_path} | grep "-c" "\[")
        if (( $TEST > 0 )); then
            DATA+=","
        fi
        sed -i "2 i ${DESC},\n${DATA}" $file_path
    fi
}