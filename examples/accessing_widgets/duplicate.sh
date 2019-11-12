#!/usr/bin/env bash

# Example:
#   ./duplicate.sh 02 03

# Force execution to halt if there are any errors in this script:
set -e
set -o pipefail

if [ "$#" -ne 2 ]; then
    echo "Illegal number of parameters"
fi

old=$1
new=$2

files="
  accessing_widgets_lib/samplewidgetsXXX.cpp
  accessing_widgets_lib/samplewidgetsXXX.h
  accessing_widgets_tests/samplewidgetsXXX_tests.cpp"

for file in $files; do
  cat "${file//XXX/$old}" | sed -e "s|$old|$new|g" > "${file//XXX/$new}"
done
