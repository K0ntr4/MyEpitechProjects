#!/bin/bash
if [[ -z $1 ]]
   then cut -d ";" -f 3 | grep -v 0 | wc -l
else
    cut -d ";" -f 3 | grep --ignore-case $1 | wc -l
fi
