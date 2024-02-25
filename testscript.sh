#!/bin/bash
# Check if no filename is provided
if [ $# -eq 0 ]; then
    echo "Fail: No filename provided"
    echo "Usage: $0 <filename>"
    exit 1
fi

filename="$1"


# Check if the file exists
if [ ! -e "$filename" ]; then
    echo "Fail: File not found"
    echo "File not found: $filename"
    exit 1
fi

# Check if the maze executable exists
if [ ! -x "./maze" ]; then
    echo "Fail: Maze executable not found"
    echo "Maze executable not found in the current directory"
    exit 1
fi

# If all checks pass,
echo "Pass"
