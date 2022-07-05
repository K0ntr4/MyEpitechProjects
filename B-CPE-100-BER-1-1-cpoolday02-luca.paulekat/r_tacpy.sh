#!/bin/bash
cat Day02/passwd | cut -d : -f 1 | sed -n 'n;p' | rev | sort -r | sed -n '24,42p' | tr '\n' '-' | sed 's/-/, /g' | head -c -2 | sed 's/$/-/' | sed 's/-/. -/g' | tr '-' '\n'