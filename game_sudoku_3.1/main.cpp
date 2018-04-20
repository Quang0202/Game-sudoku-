#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include"console.h"
#include<windows.h>
#include<conio.h>
#include"display.h"
#include<fstream>
using namespace std;
enum trangthai{LEFT,RIGHT,UP,DOUWN,enter};
struct sudoku
{
    int x,y;
    int sudokuArray[9][9];
    trangthai tt1,tt2,tt3;
};
void change(int sudokuBoard[][9]);//create array to change
void displayBoard(int sudokuBoard[][9]);//display game frame
void getOption();//create menu
void editSquare(int sudokuBoard[][9]);//Move and change the numbers in the square
void instructions();
void testgame(int sudokuBoard[][9]);
int ChooseVersion();//Select the version
void createBoard(sudoku &s);//create sudoku array
int changeArray[9][9];//create array to change
int main()
{
    display ds;
    ds.openGame();
    getOption();
    ds.closeGame();
    return 0;
}

void getOption()
  {
   clrscr();
   display ds;
   sudoku s;
    string a[3]={"Instructions","New game","Exit"};
    int backgroundColor=176,color[5];
    int textColor=7,step=0,st;
    for(int i=0;i<3;i++)
            color[i]=textColor;
        color[0]=backgroundColor;
    for(int i=0;i<3;i++)
        {
            TextColor(color[i]);
            gotoXY(30,i+10);
            cout<<a[i]<<endl;
        }
    while(1)
    {
        clrscr();
        for(int i=0;i<3;i++)
        {
            TextColor(color[i]);
            gotoXY(30,i+10);
            cout<<a[i]<<endl;
        }
        if(_kbhit)
        {
            int z=_getch();
            if(z==224)
            {
                int c=_getch();
                if(c==72)
                    s.tt1=UP;
                if(c==80)
                    s.tt1=DOUWN;
                if(s.tt1==UP)
                    {
                        if(step==0)
                            step=0;
                        else
                          step--;
                    }
                else if(s.tt1==DOUWN)
                    {
                        if(step==2)
                            step=2;
                        else
                            step++;
                    }
            }
                else if(z==13)
                    {
                        if(step==0)
                        {
                            instructions();
                            return;
                        }
                        if(step==1)
                        {
                            createBoard(s);
                            return;
                        }
                        if(step==2)
                        {
                        ds.closeGame();
                            return;
                        }
                    }
            }
        for(int i=0;i<3;i++)
            color[i]=textColor;
        color[step]=backgroundColor;
    }
   return;
}
void instructions()
{
    cout<<endl;
    cout<<"     Ban phai dien so tu 1->9 vao moi hang, moi o va moi o vuong 3x3."<<endl
        <<"     Su dung cac phim 'W','S','A','D',lan luot de di chuyen len xuong sang trai sang phai"<<endl
        <<"     1 so duoc xem nhu la dien dung vi tri khi"<<endl

        <<"       -Trong hang ngang 9 o cua so do, khong co so nao lap lai so nay."<<endl

        <<"       -Trong hang doc 9 o cua so do, khong co so nao lap lai so nay."<<endl
        <<"       -Trong o vuong 3x3 cua so do, khong co so nao lap lai so nay.";


    while(1)
    {
        if(_kbhit())
        {
            char key=_getch();
            if(key==13)
            {
            clrscr();
            getOption();
            return;
            }
        }
    }
    return;
}
void createBoard(sudoku &s)
{
    ifstream file;
   file.open("board.txt",ios::in);
   int board[100][100],st,h=0;
   st=ChooseVersion();
   for(int i=0;i<81;i++)
    for(int j=0;j<9;j++)
    file>>board[i][j];
   for(int i=st*9;i<9+st*9;i++)
   {
       for(int j=0;j<9;j++)
        {
            s.sudokuArray[h][j]=board[i][j];
        }
        h++;
   }
   file.close();
   change(s.sudokuArray);

   displayBoard(s.sudokuArray);
}
int ChooseVersion()
{
     clrscr();
     sudoku s;
    string a[9]={"VERSION 1","VERSION 2","VERSION 3","VERSION 4","VERSION 5","VERSION 6","VERSION 7","VERSION 8","VERSION 9"};
    int backgroundColor=176,color[10];
    int textColor=7,step=0;
     for(int i=0;i<9;i++)
           color[i]=textColor;
        color[0]=backgroundColor;
     for(int i=0;i<9;i++)
        {
            TextColor(color[i]);
           gotoXY(30,i+10);
            cout<<a[i]<<endl;
        }
    while(1)
    {
        clrscr();
        for(int i=0;i<9;i++)
        {
            TextColor(color[i]);
           gotoXY(30,i+10);
            cout<<a[i]<<endl;
        }
        if(_kbhit)
        {
            int z=_getch();
            if(z==224)
            {
                char c=_getch();
                if(c==72)
                    s.tt1=UP;
                if(c==80)
                    s.tt1=DOUWN;
                if(s.tt1==UP)
                    {
                        if(step==0)
                            step=8;
                        else
                          step--;
                    }
                else if(s.tt1==DOUWN)
                    {
                        if(step==8)
                            step=0;
                        else
                            step++;
                    }
            }
                else if(z==13)
                    return step;
            }
        for(int i=0;i<9;i++)
           color[i]=textColor;
        color[step]=backgroundColor;
    }


}
void change(int sudokuBoard[][9])
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        if(sudokuBoard[i][j]==0)
             changeArray[i][j]=0;

         else
         changeArray[i][j]=1;
    }
}
void displayBoard(int sudokuBoard[][9])
{
    display ds;
    int a=21;
    int b=7;
   TextColor(5);
   ds.frame();
   for(int i=0;i<9;i++)
   {
       for(int j=0;j<9;j++)
       {
           gotoXY(a,b);
           TextColor(3);
           cout<<sudokuBoard[i][j];
           a+=3;
       }
       a=21;
       b+=2;
   }
    editSquare(sudokuBoard);
}
void editSquare(int sudokuBoard[][9])
{
    sudoku s;
    s.x=21;
    s.y=7;
    int a=0,c;
    int b=0;
    int number;
   while(1)
    {
       gotoXY(s.x,s.y);
        if(_kbhit())
         {
             char key=_getch();
             if(key=='w'||key=='W')
                s.tt2=UP;
            else if(key=='s'||key=='S')
                s.tt2=DOUWN;
            else if(key=='d'||key=='D')
                s.tt2=RIGHT;
            else if(key=='a'||key=='A')
                s.tt2=LEFT;
            else if(key==13)
            {
                testgame(sudokuBoard);
                return;
            }
            else if(key==32)
            {
                getOption();
                return;
            }
            else if(key>48&&key<58)
            {
                if(changeArray[b][a]==0)
               {
                   c=key-48;
                   TextColor(7);
                    cout<<c;
                    sudokuBoard[b][a]=c;
               }
            }
         if (s.tt2 == DOUWN)
			{
			    s.y+=2;
			    b++;
			}
		else if (s.tt2 == UP)
			{s.y-=2;
               b--;
			}
		else if (s.tt2 == LEFT)
			{s.x-=3;
			a--;
			}
		else if (s.tt2 == RIGHT)
			{s.x+=3;
			a++;
			}
        if(s.x>=46)
            {
                s.x=21;
                a=0;
            }
        else
            if(s.y>=24)
            {
                s.y=7;
                b=0;
            }
         else
            if(s.y<=6)
                {
                    s.y=23;
                    b=8;
                }

         else
            if(s.x<=20)
            {
                s.x=45;
                a=8;
            }
    }
}
    return;
}
void testgame(int sudokuBoard[][9])
{
    int stepcl=0,stepro=0,steparr=0,sumro=0,sumcl=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
        sumro+=sudokuBoard[i][j];
        sumcl+=sudokuBoard[j][i];
        }
        if(sumro!=45||sumcl!=45)
            {
                gotoXY(26,30);
                cout<<"Game over!!"<<endl;
            break;
            }
        else
            {
                sumro=0;sumcl=0;
                steparr++;
            }
    }
    if(steparr!=9)
        {
            gotoXY(26,30);
            cout<<"Game over!!"<<endl;
        }
    else
   {
       gotoXY(26,30);
      cout<<"You win!!!"<<endl;
    }
    while(1)
    {

    if(_kbhit())
    {
        char key=_getch();

         if(key==32)
        {
            clrscr();
            getOption();
            return;
        }
    }
    }
    return;

}
