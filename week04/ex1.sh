#!/bin/bash
[ -e ex1_output.txt ] && unlink ex1_output.txt
for i in 1 2 3 4 5 6 7 8 9 10
do
	gcc ex1.c -o ex1
	./ex1 >> ex1_output.txt
done
