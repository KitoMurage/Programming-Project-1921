#!/bin/bash

echo -n "Testing no arguments - "
./maze > tmp
if grep -q "Usage: ./maze <maze_file>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing bad filename - "
./maze fake.txt > tmp
if grep -q "Error opening file." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing irregular height - "
timeout 0.2s ./maze data/ireg_height_5x5.txt > tmp
if grep -q "Error: Maze does not have expected format" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

rm -f tmp
