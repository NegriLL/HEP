#!/bin/bash

for i in {1..10}
do

    ./hello.exe $i > output_${i} &
done

wait
echo "Jobs complete!"
