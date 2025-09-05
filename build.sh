#!/bin/bash
gcc src/$1.c -o target/$1.out
echo "Built: $1.out"
