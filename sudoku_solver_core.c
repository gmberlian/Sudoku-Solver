#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void print(int arr[][9]);
void scan(int arr[][9]);
bool isSolved(int arr[][9]);
bool isPossible(int arr[][9], int k,int x,int y);

int main(void) {
   char again;
   printf("Welcome to Sudoku Solver v1.0.1 by BEAR!\n\n");
   do{
      int arr[9][9] = {0};
      scan(arr);
      isSolved(arr);
      print(arr);

      printf("\nWould you like me to solve another sudoku puzzle? (y/n): ");
      scanf("%c", &again);
      getchar();
      printf("\n");
   } while (again == 'y');

   return 0;
}

void scan(int arr[][9]){
   char ch;
   int i = 0, j = 0;

   printf("Please input the sudoku 9x9 puzzle. For blank value, input \"space\". To input value in the new row, press \"Enter\":\n");
   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         if(!isspace(ch = getchar())){
            arr[i][j] = ch - '0';
         }
      }
      getchar();
   }
   return;
}

void print(int arr[][9]){
   int i = 0, j = 0, k = 0;
   printf("\n\nSolved!\n\n");
   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         printf(" %d ", arr[i][j]);
         if((j+1) % 3 == 0 && j < 8){
            printf("|");
         }
      }
      printf("\n");
      if((i+1) % 3 == 0 && i < 8){
         for(k = 0; k < 3; k++){
            for(j = 0; j < 9; j++){
               printf("-");
            }
            if(k < 2){
               printf("+");
            }
         }
         printf("\n");
      }
   }
   return;
}

bool isSolved(int arr[][9]){
   int i, j, k;
   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         if(arr[i][j] == 0){
            for(k = 1; k <= 9; k++){
               if(isPossible(arr, k, j, i)){
                  arr[i][j] = k;
                  if(isSolved(arr)){
                     return true;
                  }
               }
            }
            arr[i][j] = 0;
            return false;
         }
      }
   }
   return true;
}


bool isPossible(int arr[][9],int k,int x,int y){
   int i = 0, j = 0;
   for(j = 0; j < 9; j++){
      if(arr[y][j] == k){
         return false;
      }
   }

   for(i = 0; i < 9; i++){
      if(arr[i][x] == k){
         return false;
      }
   }

   for(i = 3 * (y / 3); i < 3 * (y / 3 + 1); i++){
      for(j = 3 * (x / 3); j < 3 * (x / 3 + 1); j++){
         if(arr[i][j] == k){
            return false;
         }
      }
   }
   return true;
}
