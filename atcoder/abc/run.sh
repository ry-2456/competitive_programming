#!/bin/bash
while (( $# > 0 ))
do
  case $1 in
    -n | --number)
      echo "option"
      echo $1
      exit 0
      ;;
  esac
  shift
done
