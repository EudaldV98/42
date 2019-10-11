#!/usr/bin/env bash

NBR2=$(echo $FT_NBR2 | tr "mrdoc" "01234") ; NBR=$(echo $FT_NBR1 | tr "\'" "0" | tr "\\" "1" | tr "\"" "2" | tr "\?" "3" | tr "\!" "4") ; echo "obase=13; ibase=5; $NBR + $NBR2" | bc | tr "0123456789ABC" "gtaio luSnemf"
