#ifndef CREATEARRAY.H
#define CREATEARRAT.H
#include<iostream>
using namespace std;
class createArray
{
public:
    createArray();
    void createBoard(int sudokuArray[][9],int step);
    void change(int sudokuArray[][9]);//create array to change
};
#endif // CREATEARRAY
