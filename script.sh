#!/bin/bash



echo -n "Testing no arguments - "
timeout 0.2s ./maze > tmp
if grep -q "Usage: ./maze <filename>" tmp; then
    echo "PASS"
else
    echo "FAIL"
fi



echo -n "Testing bad filename - "
timeout 0.2s ./maze non_existent.txt > tmp
if grep -q "Error opening file." tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi



echo -n "Testing irregular height - "
timeout 0.2s ./maze data/ireg_height_5x5.txt > tmp
if grep -q "Error: Maze does not fall within accepted height" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi



echo -n "Testing irregular width - "
timeout 0.2s ./maze data/ireg_width_5x5.txt > tmp
if grep -q "Error: Maze does not fall within accepted width" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi



echo -n "Testing column and row length- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Maze does not have expected format" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing invalid user input- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Invalid option selected" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing hit wall or empty space- "
timeout 0.2s ./maze > tmp
if grep -q "Error: You can not move into a wall or empty space" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing invalid option selected- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Invalid option selected" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing invalid move- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Invalid movement direction" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing invalid user switch input- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Invalid option selected" tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi


echo -n "Testing maze start point- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Starting point 'S' not found in maze." tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing maze end point- "
timeout 0.2s ./maze > tmp
if grep -q "Error: Ending point 'E' not found in maze." tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing successful completion message- "
timeout 0.2s ./maze > tmp
if grep -q "Congratulations, you have cleared the maze." tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



echo -n "Testing valid maze loaded- "
timeout 0.2s ./maze data/reg_5x5.txt > tmp
if grep -q "Valid maze has been loaded." tmp;
then
    echo "PASS"
else 
    echo "FAIL"
fi



rm -f tmp

