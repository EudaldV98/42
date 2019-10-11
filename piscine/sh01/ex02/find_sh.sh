#!/usr/bin/env bash

find . -type f -name "*.sh" -print | rev | cut -d . -f 2 | cut -d / -f 1 | rev
