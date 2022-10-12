#include <stdio.h>

typedef unsigned short uint16;
typedef unsigned char uint8;
typedef unsigned long uint32;

uint8 position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9' }; //the numbers in board for player choice
uint8 checkwinner();
void board();
uint8 player_1(uint8 choice);
uint8 player_2(uint8 choice);
void main()
{


    uint8 p1=0,p2=0,c=0, choice=0;
    board();
      for(uint8 count=1;count<=5;count++) // loop count 5 times for all mave for 2 player
        {
            do{
                printf("Player 1 (X) , enter a number:  ");
                scanf(" %s", &choice);
                c = player_1(choice);
              }while (c==1);

            p1 = checkwinner();

            if (p1 == 1){         //mean the player 1 is winner
                break;
                    }
            else if(count==5){      // if count = 5 mean no one is winner the game close
                break;
                    }

            c=0;

           do{
                printf("Player 2 (O), enter a number:  ");
                scanf(" %s", &choice);
                c=player_2(choice);
             }while(c==1);

        p2 = checkwinner();
          if (p2 == 1){        //mean the player 2 is winner
            break;}
      }

    board();

    if (p1 == 1)
        printf("    ** Player 1 win **");
    else if(p2==1)
        printf("    ** Player 2 win **");
    else
        printf("     ** no result **");



}

uint8 player_1(uint8 choice)
{//function to take the user move and replace it by X for player1


    uint8 flag=0;
    uint8 mark=0;
    while(1){    //loop Exit if user choice = empty square on board or used square
        flag=0;

        mark = 'X';

        for(uint8 num=49;num<=57;num++){ // for loop to count numbers from 1-9 from decimal from asci code

            if(choice ==position[num-49])  // if user choice = number in asci on board
            {
                position[num-49] = mark;  //  the number on board the user choice = X

                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("Invalid move\n");  // mean the use not enter any number from the board

            return 1; // to repeat the same operation and user enter another number from board

        }else{
            board();
            break;
        }
}
}

uint8 player_2(uint8 choice)
{   //function to take the user move and replace it by O for player2


    uint8 flag=0;
    uint8 mark=0;
while(1){        //loop Exit if user choice = empty square on board or used square
        flag=0;


        mark = 'O';

        for(uint8 num=49;num<=57;num++){    // for loop to count numbers from 1-9 from decimal from asci code

            if(choice == position[num-49]) // if user choice = number in asci on board
            {
                position[num-49] = mark;   //  the number on board the user choice = O

                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("Invalid move\n");  // mean the use not enter any number from the board
            return 1;    // to repeat the same operation and user enter another number from board

        }else{
            board();
            break;
        }
}
}

uint8 checkwinner()
{ // to check the rules of win in the game

    if (position[0] == position[1] && position[1] == position[2]) // check 1st raw
        return 1;

    else if (position[3] == position[4] && position[4] == position[5]) // check 2nd raw
        return 1;

    else if (position[6] == position[7] && position[7] == position[8])  // check 3rd raw
        return 1;

    else if (position[0] == position[3] && position[3] == position[6])   // check 1st colum 
        return 1;

    else if (position[1] == position[4] && position[4] == position[7])   // check 2nd colum
        return 1;

    else if (position[2] == position[5] && position[5] == position[8])   // check 3rd colum
        return 1;

    else if (position[0] ==position[4] && position[4] ==position[8])   // check right slope
        return 1;

    else if (position[2] ==position[4] && position[4] ==position[6])    // check left slope
        return 1;
}





void board()
{

    system("cls");  // for clear powershell every once

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

// Draw the table raws and colums and put X or O on board
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", position[0], position[1], position[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", position[3], position[4], position[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", position[6], position[7], position[8]);

    printf("     |     |     \n\n");
}


