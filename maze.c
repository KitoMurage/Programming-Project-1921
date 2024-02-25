#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 100
#define MIN_HEIGHT 5
#define MAX_WIDTH 100
#define MIN_WIDTH 5

struct maze{
    int height;
    int width;
    int playerX;
    int playerY;
    char maze[MAX_HEIGHT][MAX_WIDTH];
}

int display_maze(){
    /**this function will display the map of the maze and the current possition of the player
    X will be printed out in the location of the player in the matrix**/

}
int read_maze(){
    // this function will load the maze from the file and print it into the terminal
}
int starting(){
    //function to find the starting position of the player returns an error message if S is not found
}
int end(){
    //function to find the finishing position of the player returns an error message if E is not found
}
int dimensions(){
    //this function will find the height and width of the walls
}
void movementright(){
    //this function will move the player to the right by moving X into a different row
}
void movementleft(){
    //this function will move the player to the left by moving X into a different row
}
void movementup(){
    //this function will move the player down
}
void movementdown(){
    //this function will move the player to right 
}


int main(int argc, char *argv[]) {

    
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    /** implement a switch statement that will take a user input 
    and move accordingly depending on the input **/
}