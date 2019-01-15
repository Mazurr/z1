#include "playTicTacToe.h"
int play(int siz)
{   //Create new board ##########################################
    int i,a;
    int x,y,d,z,check,button;
    char save[32];
    FILE *fp;
    const const char *txt = ".txt";
    siz += 4;
    char board[siz][siz];
     for(i = 0; i <= siz-1; i++)
    {
      for(a = 0; a <= siz-1; a++)
      {
          board[i][a] = '-';
      }
    }
    //Game Loop #################################################
    while(1)
    {
    //CPU move ##################################################
    int seed = time(0);
    srand(seed);
    do
    {
        d = rand()%(siz-4)+2;
        z = rand()%(siz-4)+2;

    }while(board[d][z] != '-' && d >=2 && d<siz-2 && z >=2 && z<siz-2);
    board[d][z]= 'O';
    //Show board ####################################################
    for(i = 1;i<siz-2;i++)
    {
        if(i>1){
        printf("%d",(i-2));
        }else{
        printf(" ");
        }
      for(a = 2; a < siz-2; a++)
      {
        if(i<2){
        printf(" %d ",(a-2));
        }else{
        printf("[%c]",board[i][a]);
        }
      }
      printf("\n");
    }
     //Check board for CPU ########################################
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d][z-2+i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z-2+i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z+2-i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    //Board is full? #######################################
    for(i = 2; i <= siz-2; i++)
    {
      for(a = 2; a <= siz-2; a++)
      {
          if(board[i][a]=='-'){continue;}
          else{check++;}
          if(check == (siz-4)*(siz-4)){
            printf("Draw!\n");
            return 9;
          }
      }
    }
    //Player move ####################################################
    printf("Set coordinations(If you want to save in X type -1)\n");
    do
    {
        int result;
        do{
            printf("X: ");
            result = scanf("%d",&x);
            if(result)
                break;
            else{
                printf("Only numbers!\n");
                result = scanf("%*s");
                }
        }while(1);
    //Save game #######################################################
        if(x == -1){
            printf("Name the save: ");
            scanf("%s", &save);
            strcat(save, txt);
            fp = fopen(save, "w");
            fprintf(fp, "%d",siz);
            for(i = 0; i <= siz-1; i++)
            {
                for(a = 0; a <= siz-1; a++)
                {
                    fprintf(fp,"%c",board[i][a]);
                }
            }
            fclose(fp);
            return 9;

        }
        do{
            printf("Y: ");
            result = scanf("%d",&y);
            if(result)
                break;
            else{
                printf("Only numbers!");
                result = scanf("%*s");
                }
        }while(1);

        x +=2;
        y +=2;
        if(x >= siz-2 || y >= siz-2)
        {
            printf("Wrong coordinates\n");
        }

        if(board[x][y] != '-')
            {
                printf("This coordinates are non-empty\n");
            }

    }while(x < 0 || y < 0 || x >= siz-2 || y >= siz-2 || board[x][y] != '-' );
        board[x][y] = 'X';
    //Check board for player ###########################################
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x][y-2+i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y-2+i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y+2-i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    }
}














int continuePlay(){
    int i,a;
    int x,y,d,z,check,button,siz;
    char save[32];
    const char *txt = ".txt";
    FILE *fp;
    printf("Write save name:");
    scanf("%s", &save);
    strcat(save, txt);
    if((fp = fopen(save, "rb"))==NULL)
    {
        printf("File doesn't exist!");
        return 9;
    }
    //Fill board ################################################
    fscanf(fp,"%d",&siz);
    char board[siz][siz];
    for(i = 0; i <= siz-1; i++)
    {
      for(a = 0; a <= siz-1; a++)
      {
          fscanf(fp,"%c",&board[i][a]);
      }
    }
    fclose(fp);
    //Show board ####################################################
    for(i = 1;i<siz-2;i++)
    {
        if(i>1){
        printf("%d",(i-2));
        }else{
        printf(" ");
        }
      for(a = 2; a < siz-2; a++)
      {
        if(i<2){
        printf(" %d ",(a-2));
        }else{
        printf("[%c]",board[i][a]);
        }
      }
      printf("\n");
    }
    //Game Loop #################################################
    while(1)
    {
    //Player move ####################################################
    printf("Set coordinations(If you want to save in X type -1)\n");
    do
    {
        int result;
        do{
            printf("X: ");
            result = scanf("%d",&x);
            if(result)
                break;
            else{
                printf("Only numbers!\n");
                result = scanf("%*s");
                }
        }while(1);
    //Save game #######################################################
        if(x == -1){
            printf("Name the save: ");
            scanf("%s", &save);
            strcat(save, txt);
            fp = fopen(save, "w");
            fprintf(fp, "%d",siz);
            for(i = 0; i <= siz-1; i++)
            {
                for(a = 0; a <= siz-1; a++)
                {
                    fprintf(fp,"%c",board[i][a]);
                }
            }
            fclose(fp);
            return 9;

        }
        do{
            printf("Y: ");
            result = scanf("%d",&y);
            if(result)
                break;
            else{
                printf("Only numbers!");
                result = scanf("%*s");
                }
        }while(1);

        x +=2;
        y +=2;
        if(x >= siz-2 || y >= siz-2)
        {
            printf("Wrong coordinates\n");
        }

        if(board[x][y] != '-')
            {
                printf("This coordinates are non-empty\n");
            }

    }while(x < 0 || y < 0 || x >= siz-2 || y >= siz-2 || board[x][y] != '-' );
        board[x][y] = 'X';
    //Check board for player ###########################################
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x][y-2+i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y-2+i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[x-2+i][y+2-i]=='X'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("You win!\n");
            return 9;
        }
    }
    //CPU move ##################################################
    int seed = time(0);
    srand(seed);
    do
    {
        d = rand()%(siz-4)+2;
        z = rand()%(siz-4)+2;

    }while(board[d][z] != '-' && d >=2 && d<siz-2 && z >=2 && z<siz-2);
    board[d][z]= 'O';

     //Check board for CPU ########################################
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d][z-2+i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z-2+i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    for(i=0;i<=5;i++)
    {
        if(board[d-2+i][z+2-i]=='O'){
            check++;
            }
        else{
            check=0;
            }
        if(check==3)
        {
            printf("CPU win!\n");
            return 9;
        }
    }
    //Board is full? #######################################
    for(i = 2; i <= siz-2; i++)
    {
      for(a = 2; a <= siz-2; a++)
      {
          if(board[i][a]=='-'){continue;}
          else{check++;}
          if(check == (siz-4)*(siz-4)){
            printf("Draw!\n");
            return 9;
          }
      }
    }
    //Show board ####################################################
    for(i = 1;i<siz-2;i++)
    {
        if(i>1){
        printf("%d",(i-2));
        }else{
        printf(" ");
        }
      for(a = 2; a < siz-2; a++)
      {
        if(i<2){
        printf(" %d ",(a-2));
        }else{
        printf("[%c]",board[i][a]);
        }
      }
      printf("\n");
    }

    }
}

