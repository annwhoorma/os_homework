#!/bin/bash

for i in 1 .. 10
do
	gcc ex1.c -o ex1 && ./ex1 >> ex1_output.txt
done
