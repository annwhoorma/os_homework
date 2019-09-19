i=100000
touch out.txt
trap "rm -f out.txt.lock" EXIT

while [ $i -gt 0 ]
do
	if ln out.txt out.txt.lock 2> /dev/null; then
		last=$(tail -n 1 out.txt)
		last=$((last + 1))
		echo "$last" >> out.txt
		rm -f out.txt.lock
	fi
	i=$((i - 1))
done
