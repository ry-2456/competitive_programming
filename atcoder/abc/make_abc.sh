#/bin/sh


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
echo created $dir_name
