#!/bin/bash
while (( $# > 0 ))
do
  case $1 in
    -n | --number | --number=*)
      if [[ "$1" =~ ^--number= ]]; then
        NUMBER=$(echo $1 | sed -e 's/^--number=//')
      elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
        echo "'number' requires an arguments." 1>&2
        exit 1
      else
        NUMBER="$2"
        shift
      fi
      ;;
    -l | --level | --level=*)
      if [[ "$1" =~ ^--level= ]]; then
        LEVEL=$(echo $1 | sed -e 's/^--level=//')
      elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
        echo "'level' requires an arguments." 1>&2
        exit 1
      else
        LEVEL="$2"
        shift
      fi
      ;;
    -i | --input | --input=*)
      if [[ "$1" =~ ^--input= ]]; then
        INPUT=$(echo $1 | sed -e 's/^--input=//')
      elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
        echo "'input' requires an arguments." 1>&2
        exit 1
      else
        INPUT="$2"
        shift
      fi
      ;;
    -h | --help)
      cat .run_help
      exit 0
      ;;
  esac
  shift
done

if [[ -z $NUMBER ]]; then
  echo "'number' must be specified. " 1>&2
  exit 1
fi
if [[ -z $LEVEL ]]; then
  echo "'level' must be specified. " 1>&2
  exit 1
fi

DIR="abc${NUMBER}"
CPP_FILE="${DIR}/${LEVEL}.cpp"
DATA_DIR="${DIR}/data/${LEVEL}"

if [[ ! -d $DIR ]]; then
  echo "'${DIR}' dir does not exists." 1>&2
  exit 1
fi
if [[ ! -e $CPP_FILE ]]; then
  echo "'${CPP_FILE}' file does not exists." 1>&2
  exit 1
fi
if [[ ! -d $DATA_DIR ]]; then
  echo "'${DATA_DIR}' dir does not exists." 1>&2
  exit 1
fi

# compile cpp file
g++ -Wall $CPP_FILE -o hoge

# run and input data
for data_file in $(ls $DATA_DIR)
do
  # skip except input data specified by -i option
  FILE_NUM=$(echo $data_file | sed -E "s/[^0-9]//g")
  if [ -n $INPUT ] && [ "$INPUT" != "$FILE_NUM" ]; then
    continue
  fi

  # run and input
  echo "=============================="
  echo "input($data_file)"
  echo "------------------------------"
  cat "$DATA_DIR/$data_file"

  echo "------------------------------"
  echo "output"
  echo "------------------------------"

  ./hoge < "$DATA_DIR/$data_file"

  echo
done

rm hoge
