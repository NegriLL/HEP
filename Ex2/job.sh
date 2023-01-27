#!/bin/bash

hello(){
	echo var=$(./Ex2/hello.exe)
	echo "$var" > ./Ex2/file$i.txt
}

for i in {1..2}
do
	hello
done

wait
echo "Jobs complete!"
