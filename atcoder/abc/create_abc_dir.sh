#!/bin/bash


if [ $# != 1 ]; then
  echo "Pass one artugment"
  exit 1
fi

if [ ${#1} != 3 ]; then
  echo "Error - The argument length must be 3 : $1"
  exit 1
fi

if expr $1 : "[0-9]$" >&/dev/null; then
  echo "Error - The argument must contain only digits : $1" 
  exit 1
fi

dir_name=abc$1
if [ -d $dir_name ]; then
  echo "Error - $dir_name already exists."
  exit 1
fi

mkdir -p $dir_name
mkdir -p $dir_name/data/{a,b,c,d,e,f,g,h}
touch $dir_name/{a,b,c,d,e,f,g,h}.cpp

# write 
for cpp_file in $(ls $dir_name | grep -E "*.cpp")
do
  file_dir=$dir_name/$cpp_file
  echo "#include <bits/stdc++.h>" >> $file_dir
  echo "" >> $file_dir
  echo "int main() {" >> $file_dir
  echo "" >> $file_dir
  echo "}" >> $file_dir
done

echo created $dir_name
