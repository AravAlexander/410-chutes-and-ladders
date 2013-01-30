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
using namespace std;

struct board
{
    int tileNum;
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
    int seed;

    board ChutesAndLadders[] = { {100}, {99}, {98}, {97}, {96}, {95}, {94}, {93}, {92}, {91},
                                 {81},  {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90},
                                 {80},  {79}, {78}, {77}, {76}, {75}, {74}, {73}, {72}, {71},
                                 {61},  {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70},
                                 {60},  {59}, {58}, {57}, {56}, {55}, {54}, {53}, {52}, {51},
                                 {41},  {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50},
                                 {40},  {39}, {38}, {37}, {36}, {35}, {34}, {33}, {32}, {31},
                                 {21},  {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30},
                                 {20},  {19}, {18}, {17}, {16}, {15}, {14}, {13}, {12}, {11},
                                 {1},   {2},  {3},  {4},  {5},  {6},  {7},  {8},  {9},  {10} };

    cout<<"\n\nBefore we begin, please enter a random number seed: ";
    cin>>seed;
    cout<<endl;

    srand(seed);//setting random seed for later usage

    cout<<string(50, '\n');//"clear" screen

    cout<<"Welcome to Chutes and Ladders!\nThe first player to reach (or pass) tile 100 wins.\nPlease press enter to begin the game.\n"<<endl;
    cin.get(junk);

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
                cout<<"["<<P1art<<" "<<P2art<<"]";
            }

            else if(P1==ChutesAndLadders[index].tileNum)
            {
                cout<<"[ "<<P1art<<" ]";
            }

            else if(P2==ChutesAndLadders[index].tileNum)
            {
                cout<<"[ "<<P2art<<" ]";
            }

            else
            {
                cout<<"["<<setw(3)<<ChutesAndLadders[index].tileNum<<"]";
            }

            index++;
        }
        cout<<endl;
    }

}
