#!/usr/bin/env bash

cat /etc/passwd | grep -v '^#' | awk 'NR%2==0' | cut -f 1 -d ':' | rev | sort -r | awk -v ln1=$FT_LINE1  -v ln2=$FT_LINE2 'NR >=ln1 && NR <= ln2'  | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | xargs echo -n
