#!/bin/bash

for X in {0000..0007} ; do
  if [ ! -e CZE/${X}_in.txt ] ; then
    echo "All ok"
    exit 0;
  fi
  echo "Testing: CZE/${X}_in.txt"
  ./main2.out < CZE/${X}_in.txt > /tmp/out.txt
  if ! diff CZE/${X}_out.txt /tmp/out.txt ; then
    echo "Mismatch CZE/${X}_in.txt"
    exit 1
  fi


done
