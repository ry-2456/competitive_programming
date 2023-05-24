#!/bin/bash
while (( $# > 0 ))
do
  case $1 in
    -n | --number | --number=*)
      if [[ "$1" =~ ^--number= ]]; then
        NUMBER=$(echo $1 | sed -e 's/^--number=//')
      elif [[ -z "$2" ]] || [[ "$2" =~ ^-+ ]]; then
        echo "'number' requires an arguments." 1>&2
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
      else
        LEVEL="$2"
        shift
      fi
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

