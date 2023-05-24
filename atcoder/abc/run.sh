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
