#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct board
{
    int tileNum;
};

int main()
{
    int i, ii, index=0;

    int P1 = 50, P2 = 52;
    char P1art = '+', P2art = '=';

    board ChutesAndLadders[] = {     {100}, {99}, {98}, {97}, {96}, {95}, {94}, {93}, {92}, {91},
                                     {81},  {82}, {83}, {84}, {85}, {86}, {87}, {88}, {89}, {90},
                                     {80},  {79}, {78}, {77}, {76}, {75}, {74}, {73}, {72}, {71},
                                     {61},  {62}, {63}, {64}, {65}, {66}, {67}, {68}, {69}, {70},
                                     {60},  {59}, {58}, {57}, {56}, {55}, {54}, {53}, {52}, {51},
                                     {41},  {42}, {43}, {44}, {45}, {46}, {47}, {48}, {49}, {50},
                                     {40},  {39}, {38}, {37}, {36}, {35}, {34}, {33}, {32}, {31},
                                     {21},  {22}, {23}, {24}, {25}, {26}, {27}, {28}, {29}, {30},
                                     {20},  {19}, {18}, {17}, {16}, {15}, {14}, {13}, {12}, {11},
                                      {1},   {2},  {3},  {4},  {5},  {6},  {7},  {8},  {9}, {10} };

    cout<<"\n\n"<<endl;

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

    cout<<"\n\n"<<endl;

    return 0;
}
