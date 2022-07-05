source functions/help.sh

export file_path=0
export json_format=0
export mode=0
export new_args=()

set_mode () {
    if [ $mode == 0 ]; then
        mode=$1;
    fi
}

parse_flags () {
    for ((i = 1; i < $(expr length "$arg"); i++)); do
        flag=${arg:i:1}

        case $flag in
            "f") next_is_file=1;;
            "h") show_help;;
            "j") json_format=1;;
            *) invalid_flag_error $flag;; # ERROR
        esac
    done
}

parse_flags_as_words () {
    flag=$arg

    case $flag in
        "--file") next_is_file=1;;
        "--help") show_help;;
        *) invalid_flag_error $flag;; # ERROR
    esac
}

detect_mode () {
    next_is_file=0

    for arg in $@
    do
        if [[ $next_is_file == 1 ]]; then
            file_path=$arg;
            next_is_file=0;
            continue;
        fi

        if [[ "${arg:0:2}" == '--' ]]; then
            parse_flags_as_words;
            continue;
        fi

        if [[ $(expr "${arg:0:1}" = "-") == 1 ]]; then
            parse_flags;
            continue;
        fi

        new_args+=($arg);
        set_mode $arg;
    done

    if [ $file_path == 0 ] && [ $BDSH_File ]; then
        file_path=$BDSH_File;
    fi

    if [ $file_path == 0 ] && [ -f .bdshrc ]; then
        file_path=$(cat .bdshrc);
    fi

    if [ $file_path == 0 ] && [ mode != "create" ]; then
        file_path_not_found_error;
    fi
}
