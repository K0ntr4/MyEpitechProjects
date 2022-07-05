validate_table () {
    if [ ! $(cat $file_path | grep -oe "data_${1}\"") ]; then
        table_not_found_error $1;
    fi
}

validate_create_table () {
    if [ $(cat $file_path | grep -oe "desc_${1}\"") ]; then
        table_already_exists_error $3
    fi
}

validate_file () {
    if ! (test -f $file_path ); then
        file_not_found_error $file_path;
    fi
}

validate_field () {
    declare -a fields

    field_validate=$1
    get_fields fields $table
    is_valid=0;

    for field_local in ${fields[@]}; do
        if [[ "$field_local" == $field_validate ]]; then
            is_valid=1;
        fi
    done

    if [[ $is_valid == 0 ]]; then
        field_not_found_error $field_validate;
    fi
}