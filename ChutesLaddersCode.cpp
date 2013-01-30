/*************************************************************/
/* Programmer: Noel Alexander                                */
/* MacBook Pro, 2.4ghz Intel Core 2 Duo                      */
/* CodeBlocks 10.05 on MacOSX                                */
/*                 Chutes and Ladders                        */
/* Due: 02/01/13                                             */
/* Last Revision Date: 01/24/13                              */
/*************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

struct board
{
    int tileNum;
    string tileArt;
};

int move(int, int, int);//accepts position of a player,  a die roll, and the 'name' of the player, returns new position
void printBoard(struct board[], int, int, char, char);

int main()
{
    int P1 = 0, P2 = 0;
    char P1art = '+', P2art = '=';
    int P1count = 0, P2count = 0;
    int dieRoll;
    bool noWinner = true;
    char junk;

    board ChutesAndLadders[] = { {100, "100!"}, {99, " 99 "}, {98, "78->"}, {97, " 97 "}, {96, " 96 "}, {95, "75->"}, {94, " 94 "}, {93, "73->"}, {92, " 92 "}, {91, " 91 "},
                                 {81, " 81 "},  {82, " 82 "}, {83, " 83 "}, {84, " 84 "}, {85, " 85 "}, {86, " 86 "}, {87, "<-24"}, {88, " 88 "}, {89, " 89 "}, {90, " 90 "},
                                 {80, "<100"},  {79, " 79 "}, {78, " 78 "}, {77, " 77 "}, {76, " 76 "}, {75, " 75 "}, {74, " 74 "}, {73, " 73 "}, {72, " 72 "}, {71, "<-90"},
                                 {61, " 61 "},  {62, "<-19"}, {63, " 63 "}, {64, "<-60"}, {65, " 65 "}, {66, " 66 "}, {67, " 67 "}, {68, " 68 "}, {69, " 69 "}, {70, " 70 "},
                                 {60, " 60 "},  {59, " 59 "}, {58, " 58 "}, {57, " 57 "}, {56, "53->"}, {55, " 55 "}, {54, " 54 "}, {53, " 53 "}, {52, " 52 "}, {51, "<-67"},
                                 {41, " 41 "},  {42, " 42 "}, {43, " 43 "}, {44, " 44 "}, {45, " 45 "}, {46, " 46 "}, {47, "<-26"}, {48, " 48 "}, {49, "<-11"}, {50, " 50 "},
                                 {40, " 40 "},  {39, " 39 "}, {38, " 38 "}, {37, " 37 "}, {36, "<-44"}, {35, " 35 "}, {34, " 34 "}, {33, " 33 "}, {32, " 32 "}, {31, " 31 "},
                                 {21, "42->"},  {22, " 22 "}, {23, " 23 "}, {24, " 24 "}, {25, " 25 "}, {26, " 26 "}, {27, " 27 "}, {28, "84->"}, {29, " 29 "}, {30, " 30 "},
                                 {20, " 20 "},  {19, " 19 "}, {18, " 18 "}, {17, " 17 "}, {16, "6 ->"}, {15, " 15 "}, {14, " 14 "}, {13, " 13 "}, {12, " 12 "}, {11, " 11 "},
                                 {1, "38->"},   {2, " 02 "},  {3, " 03 "},  {4, "14->"},  {5, " 05 "},  {6, " 06 "},  {7, " 07 "},  {8, " 08 "},  {9, "31->"},  {10, " 10 "} };


    srand(time(0));//setting random seed for later usage

    cout<<string(50, '\n');//"clear" screen

    cout<<"Welcome to Chutes and Ladders!\nThe first player to reach (or pass) tile 100 wins.\n"<<endl;

    while(noWinner)
    {//play the game within loop

        cout<<"Press enter to start Player 1's turn.";
        cin.get(junk);

        cout<<string(50, '\n');//"clear" screen

        dieRoll = rand()%5;
        dieRoll++;

        cout<<"Player 1 is on tile number "<<P1<<", rolls the die and receives a "<<dieRoll<<"."<<endl;
        cout<<"Player 1 advances to tile number "<<P1 + dieRoll<<"."<<endl;
        P1 = move(P1, dieRoll, 1);

        cout<<endl;
        printBoard(ChutesAndLadders, P1, P2, P1art, P2art);
        cout<<endl;

        P1count++;

        //check for win
        if(P1 >= 100)
        {
            cout<<"Player 1 wins!"<<endl;
            noWinner = false;
        }

        cout<<"\n"<<endl;

        if(noWinner)
        {
            cout<<"Press enter to start Player 2's turn.";
            cin.get(junk);

            cout<<string(50, '\n');//"clear" screen

            dieRoll = rand()%6;
            dieRoll++;

            cout<<"Player 2 is on tile number "<<P2<<", rolls the die and receives a "<<dieRoll<<"."<<endl;
            cout<<"Player 2 advances to tile number "<<P2 + dieRoll<<"."<<endl;
            P2 = move(P2, dieRoll, 2);

            cout<<endl;
            printBoard(ChutesAndLadders, P1, P2, P1art, P2art);
            cout<<endl;

            P2count++;

            cout<<endl;

            //check for win
            if(P2 >= 100)
            {
                cout<<"Player 2 wins!"<<endl;
                noWinner = false;
            }

        }

    }//end loop to play game

    cout<<"The game took "<<P1count<<" turns for Player 1 and "<<P2count<<" turns for Player 2."<<endl;

    return 0;
}

int move(int currentPosition, int dieRoll, int PlayerNum)
{
    int newPosition, tempPosition;

    tempPosition = currentPosition + dieRoll;

    switch(tempPosition)
    {
        case 1: {newPosition = 38;
                 cout<<"The garden planted on tile 1 sends Player "<<PlayerNum<<" to tile 38 with a beautiful bouquet."<<endl;
                 break;}
        case 4: {newPosition = 14;
                 cout<<"Baking a cake on tile 4 sends Player "<<PlayerNum<<" to tile number 14. mmmm...cake!"<<endl;
                 break;}
        case 9: {newPosition = 31;
                 cout<<"The money earned cutting grass on tile number 9 sends Player "<<PlayerNum<<" to the circus on tile 31!"<<endl;
                 break;}
        case 16: {newPosition = 6;
                  cout<<"Reading comic books during class on tile 16 sends Player "<<PlayerNum<<" to time out on tile 6."<<endl;
                  break;}
        case 21: {newPosition = 42;
                  cout<<"Caring for the stray cat on tile 21 sends Player "<<PlayerNum<<" to tile 42 with kitty love."<<endl;
                  break;}
        case 28: {newPosition = 84;
                  cout<<"Rescuing the cat stuck in a tree on tile 28 sends Player "<<PlayerNum<<" to tile 84 with even more kitty love!."<<endl;
                  break;}
        case 36: {newPosition = 44;
                  cout<<"Eating the healthy food on tile 36 sends Player "<<PlayerNum<<" to tile 44 feeling strong and tall."<<endl;
                  break;}
        case 47: {newPosition = 26;
                  cout<<"Skating on thin ice on tile 47 sends Player "<<PlayerNum<<" to tile 26. Brrrr!."<<endl;
                  break;}
        case 49: {newPosition = 11;
                  cout<<"Eating all the chocolate on tile 49 sends Player "<<PlayerNum<<" to tile 11 feeling sick, sick, sick!"<<endl;
                  break;}
        case 51: {newPosition = 67;
                  cout<<"Doing chores on tile 51 sends Player "<<PlayerNum<<" to tile 67 with tuppence for the bank."<<endl;
                  break;}
        case 56: {newPosition = 53;
                  cout<<"Playing in the rain on tile 56 sends Player "<<PlayerNum<<" to tile 53 with an awful cold."<<endl;
                  break;}
        case 62: {newPosition = 19;
                  cout<<"Carrying too many plates on tile 62 sends Player "<<PlayerNum<<" to tile 19. What a mess!"<<endl;
                  break;}
        case 64: {newPosition = 60;
                  cout<<"Riding a bike with no hands on tile 64 sends Player "<<PlayerNum<<" to tile 60 with a broken arm."<<endl;
                  break;}
        case 71: {newPosition = 91;
                  cout<<"Returning the lost purse on tile 71 sends Player "<<PlayerNum<<" to tile 91 with a big reward."<<endl;
                  break;}
        case 80: {newPosition = 100;
                  cout<<"Winning the dog show on tile 80 sends Player "<<PlayerNum<<" to tile 100 with a blue ribbon!"<<endl;
                  break;}
        case 87: {newPosition = 24;
                  cout<<"Climbing on the counter on tile 87 sends Player "<<PlayerNum<<" to tile 24 with a bump on the head."<<endl;
                  break;}
        case 93: {newPosition = 73;
                  cout<<"Coloring on the walls on tile 93 sends Player "<<PlayerNum<<" to tile 73 with a bucket of soapy water."<<endl;
                  break;}
        case 95: {newPosition = 75;
                  cout<<"Hitting a baseball through the window on tile 95 sends Player "<<PlayerNum<<" to tile 75 with empty pockets."<<endl;
                  break;}
        case 98: {newPosition = 78;
                  cout<<"Pulling the cat's tail on tile 98 sends Player "<<PlayerNum<<" to tile 78 covered in scratches."<<endl;
                  break;}
        default: {newPosition = tempPosition; break;}
    }

    return newPosition;
}

void printBoard(struct board ChutesAndLadders[], int P1, int P2, char P1art, char P2art)
{
    int i, ii, index=0;

    cout<<"P1 is represented by "<<P1art<<"\nP2 is represented by "<<P2art<<endl;

    for(i=0;i<10;i++)
    {
        for(ii=0;ii<10;ii++)
        {
            //if ChutesAndLadders[index].tileNum == a player, print player character
            if (P1==ChutesAndLadders[index].tileNum  && P2==ChutesAndLadders[index].tileNum)
            {
                cout<<"["<<P1art<<"  "<<P2art<<"]";
            }

            else if(P1==ChutesAndLadders[index].tileNum)
            {
                cout<<"[ "<<P1art<<"  ]";
            }

            else if(P2==ChutesAndLadders[index].tileNum)
            {
                cout<<"[ "<<P2art<<"  ]";
            }

            else
            {
                cout<<"["<<setw(3)<<ChutesAndLadders[index].tileArt<<"]";
            }

            index++;
        }
        cout<<endl;
    }

}
