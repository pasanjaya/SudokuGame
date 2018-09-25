#include <stdio.h>
#include "sudokuGrid.h"

#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUE (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUE * NUM_VALUE)
#define MAX_CELL (GRID_SIZE - 1)
#define TRUE 1
#define FALSE 0

typedef int cell;
typedef char value;
typedef value sudokuGrid[GRID_SIZE];

int hasSolution(sudokuGrid game);

int main(int argc, char const *argv[]) {
  sudokuGrid sample;
  readGame(sample); // read from the command line
  // showGame(sample);

  if(hasSolution(sample)){
    printf("%s\n","Final Solution is: ");
    showGame(sample); // printout the solution grid
  }

  return 0;
}

int hasSolution(sudokuGrid game){
  showGame(game);
   int solved;
   cell candidateCell;
   value trailValue;

   if(isFull(game)){
     solved = TRUE;
   } else {
     candidateCell = getFreeCell(game);
     trailValue = MIN_VALUE;
     solved = FALSE;

     while (!solved && (trailValue <= MAX_VALUE)) {
       if(isLegal(game, candidateCell, trailValue)){
         setCell(game, candidateCell, trailValue);

         if(hasSolution(game)){
           solved = TRUE;
         } else {
           clearCell(game, candidateCell);
         }
       }
       trailValue++;
     }
   }
   return solved;
}
