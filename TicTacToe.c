#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playTicTacToe.h"



int main(int argc, char** argv){
  int select = 9;
  int size = 5;
  int result;
  while(select!=0){
    switch(select){
      case 9:
      { // Menu
        printf("Tic-Tac-Toe\nWhat you want to do:\n1.New Game\n2.Load Game\n0.Exit\n");
        do{
            printf("Your choice: ");
            result = scanf("%d",&select);
            if(result)
                break;
            else{
                printf("I accept only numbers!\n");
                result = scanf("%*s");
                }
        }while(1);
        if(select != 1 && select != 2 && select != 0)
        {
            printf("Choose correct number!\n");
            select = 9;
        }
        break;
      }
     case 1:
      {
        //Game
        printf("Choose the board size(from 3 to infinity):");
        scanf("%d", &size);
        select = play(size);
        break;
        }
     case 2:
     {

        select = continuePlay();
       break;
     }
  }
}
return 0;
}
