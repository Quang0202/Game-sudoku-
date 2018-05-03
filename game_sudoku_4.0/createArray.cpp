#include<iostream>
#include"createArray.h"
#include<conio.h>
#include<fstream>
using namespace std;
extern int changeArray[9][9];
createArray::createArray()
{
    ;
}
void createArray::createBoard(int sudokuArray[][9],int step)
{
    ifstream file;
   file.open("board.txt",ios::in);
   int board[100][100],h=0;
   for(int i=0;i<81;i++)
    for(int j=0;j<9;j++)
    file>>board[i][j];
   for(int i=step*9;i<9+step*9;i++)
   {
       for(int j=0;j<9;j++)
        {
            sudokuArray[h][j]=board[i][j];
        }
        h++;
   }
   file.close();
}
void createArray::change(int sudokuArray[][9])
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        if(sudokuArray[i][j]==0)
             changeArray[i][j]=0;

         else
         changeArray[i][j]=1;
    }
}
