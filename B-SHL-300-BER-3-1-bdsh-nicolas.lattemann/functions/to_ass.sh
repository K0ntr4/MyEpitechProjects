string_to_ass_array () {
    local data=$2
    local key=""
    local value=""
    local keymode=1
    ic=0

    declare -n dict="$1"
    len=$(expr length "$data");
    for ((i = 0; i <= len; i++)); do
        if [ "${data:i:1}" == '=' ]; then
            keymode=0;
            continue;
        fi

        if [ "${data:i:1}" == ',' ] || [ $i == $((len)) ]; then
            key="$(echo $key | tr -d '[:blank:]')"
            dict[$key]="$value"
            key=""
            value=""
            keymode=1;
            ic=$((ic+1));
            continue;
        fi

        if [ $keymode == 1 ]; then
            key+=${data:i:1}
        elif [ $keymode == 0 ]; then
            value+=${data:i:1}
        fi
    done
}