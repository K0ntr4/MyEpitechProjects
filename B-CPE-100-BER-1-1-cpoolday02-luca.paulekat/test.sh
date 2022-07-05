#!/bin/bash
echo $MY_LINE1
echo $MY_LINE2
cat Day02/passwd | cut -d : -f 1 | sed -n 'n;p' | rev | sort -r | head -24 | tail -n +42 | tr '\n' '-' | sed 's/-/, /g' | head -c -2 | sed 's/$/-/' | sed 's/-/. -/g' | tr '-' '\n'