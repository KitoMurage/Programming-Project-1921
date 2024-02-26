#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Include string.h for strlen and strncpy

#define MAX_SIZE 100

// Function to display the maze
void displayMaze(char maze[][MAX_SIZE], int height, int width, int playerRow, int playerCol) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == playerRow && j == playerCol)
                printf("X "); // Show player position with 'X'
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <maze_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int height = 0, width = 0;
    char maze[MAX_SIZE][MAX_SIZE];

    // Read maze from file
    char line[MAX_SIZE];
    while (fgets(line, sizeof(line), file)) {
        int len = strlen(line); // Use strlen to get the length of the line
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0'; // Remove newline character

        if (width == 0)
            width = len;

        if (height < MAX_SIZE) {
            strncpy(maze[height], line, width); // Use strncpy to copy the line to the maze array
            height++;
        } else {
            printf("Maximum maze height exceeded.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Find the starting position of the player
    int playerRow = -1, playerCol = -1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 'S') {
                playerRow = i;
                playerCol = j;
                break;
            }
        }
        if (playerRow != -1)
            break;
    }

    if (playerRow == -1 || playerCol == -1) {
        printf("Starting point 'S' not found in maze.\n");
        return 1;
    }

    // Display initial maze
    displayMaze(maze, height, width, playerRow, playerCol);

    char move;
    while (1) {
        printf("Enter movement (WASD, M to see the map): ");
        scanf(" %c", &move);

        if (move == 'M' || move == 'm') {
            // Show the entire maze
            printf("\n");
            displayMaze(maze, height, width, playerRow, playerCol);
            printf("\n");
            continue; // Skip the movement update
        }

        int newRow = playerRow, newCol = playerCol;

        // Calculate new position based on the movement input
        switch (move) {
            case 'W':
            case 'w':
                newRow--;
                break;
            case 'A':
            case 'a':
                newCol--;
                break;
            case 'S':
            case 's':
                newRow++;
                break;
            case 'D':
            case 'd':
                newCol++;
                break;
            default:
                printf("Invalid input. Please use WASD or M.\n");
                continue; // Skip the movement update
        }

        // Check if the new position is valid (not a wall or out of bounds)
        if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width && maze[newRow][newCol] != '#') {
            playerRow = newRow;
            playerCol = newCol;
        } else {
            printf("Invalid move. Please try again.\n");
            continue; // Skip the movement update
        }

        // Clear screen and display updated maze
        system("clear"); // Change to "cls" for Windows
        displayMaze(maze, height, width, playerRow, playerCol);

        // Check if the player has reached the exit
        if (maze[playerRow][playerCol] == 'E') {
            printf("Congratulations! You have reached the exit.\n");
            break; // End the game loop
        }
    }

    return 0;
}
