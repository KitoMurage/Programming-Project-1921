#include "maze.h"

struct maze{
    int height;
    int width;
    int posX;
    int posY;
    char maze[MAX_HEIGHT][MAX_WIDTH];
};

int display_maze(int height, int width, int posX, int posY){
    /**this function will display the map of the maze and the current possition of the player
    X will be printed out in the location of the player in the matrix**/

}
int read_maze(int height, int width, int posX, int posY){
    // this function will load the maze from the file and print it into the terminal
}
int starting(int posX, int posY){
    //function to find the starting position of the player returns an error message if S is not found
}
int end(){
    //function to find the finishing position of the player returns an error message if E is not found
}
int dimensions(int height, int width){
    //this function will find the height and width of the walls
}
void movementright(int width){
    //this function will move the player to the right by moving X into a different row
}
void movementleft(int width){
    //this function will move the player to the left by moving X into a different row
}
void movementup(int height){
    //this function will move the player down
}
void movementdown(int height){
    //this function will move the player to right 
}


int main(int argc, char *argv[]) {

    //error message to check whether an argument was provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
     //error message to check whether the file exists
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    /**read in the maze
    code to Ensure that the maze is valid
    find the starting position 'S' 
       **/
    

    /** implement a switch statement that will take a user input 
    and move accordingly depending on the input.
    Determine whether the input is valid **/
    //print a success statement


}

