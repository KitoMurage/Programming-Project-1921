#!/bin/bash

# Test Case 1: Test loading valid maze file
./maze valid_maze.txt
# Expected: Maze should load without errors

# Test Case 2: Test loading invalid maze file (file does not exist)
./maze non_existent_maze.txt
# Expected: Error message indicating that the file does not exist

# Test Case 3: Test loading invalid maze file (maze dimensions out of range)
./maze invalid_dimensions_maze.txt
# Expected: Error message indicating that maze dimensions are out of range

# Test Case 4: Test navigating through maze successfully
./maze valid_maze.txt <<< "w"
# Expected: Player should be able to move up without errors

# Test Case 5: Test hitting a wall
./maze valid_maze.txt <<< "a"
# Expected: Error message indicating that the player cannot move left due to a wall

# Test Case 6: Test moving off the edge of the map
./maze valid_maze.txt <<< "w" <<< "w" <<< "w" <<< "w" <<< "w" <<< "w" <<< "w"
# Expected: Error message indicating that the player cannot move further up as they are at the top edge of the map

# Test Case 7: Test viewing map
./maze valid_maze.txt <<< "M"
# Expected: Map should be displayed with the player's current location marked by 'X'

# Test Case 8: Test winning the game
./maze valid_maze.txt <<< "wwww"
# Expected: Message indicating that the player has won should be displayed
