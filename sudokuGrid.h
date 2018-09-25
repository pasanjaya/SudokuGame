#define MIN_VALUE '1'
#define MAX_VALUE '9'
#define EMPTY_VALUE '.'
#define NUM_VALUE (MAX_VALUE - MIN_VALUE + 1)
#define GRID_SIZE (NUM_VALUE * NUM_VALUE)
#define MAX_CELL (GRID_SIZE - 1)
#define NUMBER_OF_BOXES (GRID_SIZE/9)

typedef int cell;
typedef char value;
typedef value sudokuGrid[GRID_SIZE];


void readGame(sudokuGrid game){
  for (int i = 0; i < GRID_SIZE; i++) {
    game[i] = getchar();
  }
  printf("\n");
}

void showGame(sudokuGrid game){
  for(int k = 0; k < 9; k+=3){
    for (int i = 0; i < 3; i++) {
      for(cell j = 0; j<3; j++){
        printf("%c ", game[k+ i*9 + j]);
      }
    }
    printf("\n");
  }
  for(int k = 27; k < 36; k+=3){
    for (int i = 0; i < 3; i++) {
      for(cell j = 0; j<3; j++){
        printf("%c ", game[k+ i*9 + j]);
      }
    }
    printf("\n");
  }
  for(int k = 54; k < 63; k+=3){
    for (int i = 0; i < 3; i++) {
      for(cell j = 0; j<3; j++){
        printf("%c ", game[k+ i*9 + j]);
      }
    }
    printf("\n");
  }

  //   if(i%3 == 0){
  //     printf("\n");
  //   }
  //   printf("%c ", game[i]);
  // }
  // printf("\n");
}

void setCell(sudokuGrid game, cell location, value digit){
  game[location] = digit;
}

value getCell(sudokuGrid game, cell location){
  return game[location];
}

void clearCell(sudokuGrid game, cell location){
  game[location] = EMPTY_VALUE;
}

int isFull(sudokuGrid game){
  for (cell i = 0; i < GRID_SIZE; i++) {
    if(game[i] == EMPTY_VALUE){
      return 0;
    }
  }
  printf("%s\n","full");
  return 1;
}

cell getFreeCell(sudokuGrid game){
  for (cell i = 0; i < GRID_SIZE; i++) {
    if(game[i] == EMPTY_VALUE){
      return i;
    }
  }
  return -999;
}

int isLegal(sudokuGrid game, cell location, value candidateDigit){

  int currentBox = location/NUM_VALUE; // get the current box
  // to check the presence of number in 3X3 box
  int cellStart = currentBox*NUM_VALUE;
  for (cell i = 0; i < NUM_VALUE; i++) {
    if(game[cellStart + i] == candidateDigit){
      return 0;
    }
  }


  // to check the presence of number in row
  int checkingRow = (location%NUM_VALUE)/3;
  for(int i = 0; i <= currentBox; i++){
    int cellStart = 3*checkingRow + NUM_VALUE*i;
    for(cell j = 0; j < 3; j++){
      if(game[cellStart + j] == candidateDigit){
        return 0;
      }
    }
  }

  // to check the presence of number in column
  int checkingColumn = (location-(currentBox*NUM_VALUE))%3; // get the checkin column in current box
  for(int i = currentBox; i < NUMBER_OF_BOXES; i+=3){
    int cellStart = checkingColumn + i*NUM_VALUE;
    for (cell j = 0; j<3; j++){
      if(game[cellStart + j*3] == candidateDigit){
        return 0;
      }
    }
  }

  return 1;
}
