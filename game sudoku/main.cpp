#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include"console.h"
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
void change(int sudokuBoard[][9]);
void display(int sudokuBoard[][9]);
void opengame();
void closegame();
void getOption(int sudokuBoard[][9]);
void editSquare(int sudokuBoard[][9]);
void instructions();
void testgame(int sudokuBoard[][9]);
void frame();
int chonman();
void createBoard(int sudokuBoard[][9]);
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}
void textcolor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void gotoxy (int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
enum trangthai{lef,righ,up,douwn,enter};
struct sudoku
{
    int arrchange[9][9];
    int sudokuBoard[9][9];
}ar;
struct dichuyen
{
    int x,y;
    trangthai tt1,tt2,tt3;
}t;
int main()
{
    opengame();
   getOption(ar.sudokuBoard);
   closegame();
   return 0;
}
void change(int sudokuBoard[][9])
{
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
    {
        if(sudokuBoard[i][j]==0)
            ar.arrchange[i][j]=0;
         else
         ar.arrchange[i][j]=1;
    }
}
void frame()
 {         int x,i;
    clrscr(); gotoxy(19,6);
    cout<<char(201);
    for(int i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(203);
    for(i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(203);
    for(i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(187);
    gotoxy(19,7);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    for(i=0;i<2;i++)
    cout<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,8);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,9);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
    <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,10);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,11);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
     <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,12);
    cout<<char(204)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
    <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
    <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(185);
    gotoxy(19,13);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
    <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,14);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,15);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,16);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
       <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
       <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,17);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,18);
    cout<<char(204)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
        <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
        <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(185);
    gotoxy(19,19);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,20);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,21);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,22);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoxy(19,23);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoxy(19,24);
    cout<<char(200)<<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(202)
        <<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(202)
        <<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(188);
    textcolor(3);gotoxy(50,23);
    cout<<"Press 'enter' to check";
    textcolor(3);gotoxy(50,24);
    cout<<"Press ' ' to exit!";
}
void display(int sudokuBoard[][9])
{
    change(ar.sudokuBoard);
    int a=21;
    int b=7;
   textcolor(5);
   frame();
   for(int i=0;i<9;i++)
   {
       for(int j=0;j<9;j++)
       {
           gotoxy(a,b);
           textcolor(1);
           cout<<sudokuBoard[i][j];
           a+=3;
       }
       a=21;
       b+=2;

   }
    editSquare(ar.sudokuBoard);
}

void opengame()
{
    for(int f=0;f<6;f++)
  {
  switch(f)
   {
   case 0:
   textcolor(7);clrscr();  gotoxy(35,12);
   cout<<"S";Sleep(750);break;
   case 1:
   textcolor(4);clrscr();    gotoxy(35,12);
   cout<<"SU";Sleep(750);break;
   case 2:
   textcolor(3);clrscr();   gotoxy(35,12);
   cout<<"SUD";Sleep(750);break;
   case 3:
   textcolor(2);clrscr();  gotoxy(35,12);
   cout<<"SUDO";Sleep(750);break;
   case 4:
   textcolor(8);clrscr();  gotoxy(35,12);
   cout<<"SUDOK";Sleep(750);break;
   case 5:
   textcolor(9);clrscr(); gotoxy(35,12);
   cout<<"SUDOKU";Sleep(850);break;
   }
  }
}
void closegame()
{
  clrscr();
    for(int f=0;f<7;f++)
  {
  switch(f)
   {
   case 0:
   textcolor(7);clrscr();  gotoxy(35,12);
   cout<<"G";Sleep(550);break;
   case 1:
   textcolor(4);clrscr();    gotoxy(35,12);
   cout<<"GO";Sleep(550);break;
   case 2:
   textcolor(3);clrscr();   gotoxy(35,12);
   cout<<"GOO";Sleep(550);break;
   case 3:
   textcolor(2);clrscr();  gotoxy(35,12);
   cout<<"GOOD";Sleep(550);break;
   case 4:
   textcolor(8);clrscr();  gotoxy(35,12);
   cout<<"GOODB";Sleep(550);break;
   case 5:
   textcolor(9);clrscr(); gotoxy(35,12);
   cout<<"GOODBY";Sleep(550);break;
   case 6:
   textcolor(10);clrscr();gotoxy(35,12);
   cout<<"GOODBYE";Sleep(650);break;
   }
  }
  return ;
}
  void getOption(int sudokuBoard[][9])
  {
   clrscr();
    string a[3]={"Instructions","New game","Exit"};
    int maunen=176,mau[5];
    int mauchu=7,st=0;

    while(1)
    {
        clrscr();
        for(int i=0;i<3;i++)
        {
            textcolor(mau[i]);
            gotoxy(30,i+10);
            cout<<a[i]<<endl;
        }
        if(_kbhit)
        {
            int z=_getch();
            if(z==224)
            {
                char c=_getch();
                if(c==72)
                    t.tt1=up;
                if(c==80)
                    t.tt1=douwn;
                if(t.tt1==up)
                    {
                        if(st==0)
                            st=2;
                        else
                          st--;
                    }
                else if(t.tt1==douwn)
                    {
                        if(st==2)
                            st=0;
                        else
                            st++;
                    }
            }
                else if(z==13)
                    {
                        if(st==0)
                        {
                            instructions();
                            return;
                        }
                        if(st==1)
                        {
                            createBoard(ar.sudokuBoard);
                            return;
                        }
                        if(st==2)
                        {
                            closegame();
                            return;
                        }
                    }
            }
        for(int i=0;i<3;i++)
            mau[i]=mauchu;
        mau[st]=maunen;
    }
   return;
}
void createBoard(int sudoBoard[][9])
{
    ifstream file;
   file.open("board.txt",ios::in);
   int board[100][100],st,h=0;
   st=chonman();
   for(int i=0;i<81;i++)
    for(int j=0;j<9;j++)
    file>>board[i][j];
   for(int i=st*9;i<9+st*9;i++)
   {
       for(int j=0;j<9;j++)
        {
            ar.sudokuBoard[h][j]=board[i][j];
        }
        h++;
   }
   file.close();
   change(ar.sudokuBoard);
   display(ar.sudokuBoard);
}
int chonman()
{
     clrscr();
    string a[9]={"version 1","version 2","version 3","version 4","version 5","version 6","version 7","version 8","version 9"};
    int maunen=176,mau[10];
    int mauchu=7,st=0;
    for(int i=0;i>9;i++)
        mau[i]=mauchu;
    mau[0]=maunen;
    for(int i=0;i<9;i++)
        {

            gotoxy(30,i+10);
            cout<<a[i]<<endl;
        }
    gotoxy(30,10);

    while(1)
    {
        clrscr();
        for(int i=0;i<9;i++)
        {
            textcolor(mau[i]);
            gotoxy(30,i+10);
            cout<<a[i]<<endl;
        }
        if(_kbhit)
        {
            int z=_getch();
            if(z==224)
            {
                char c=_getch();
                if(c==72)
                    t.tt1=up;
                if(c==80)
                    t.tt1=douwn;
                if(t.tt1==up)
                    {
                        if(st==0)
                            st=8;
                        else
                          st--;
                    }
                else if(t.tt1==douwn)
                    {
                        if(st==8)
                            st=0;
                        else
                            st++;
                    }
            }
                else if(z==13)
                    return st;
            }
        for(int i=0;i<9;i++)
            mau[i]=mauchu;
        mau[st]=maunen;
    }


}
void instructions()
{
    cout<<endl;
    cout<<"Ban phai dien so tu 1->9 vao moi hang, moi o va moi o vuong 3x3."<<endl
        <<"Su dung cac phim 'W','S','A','D',lan luot de di chuyen len xuong sang trai sang phai"<<endl
        <<"1 so duoc xem nhu la dien dung vi tri khi"<<endl

        <<" -Trong hang ngang 9 o cua so do, khong co so nao lap lai so nay."<<endl

        <<" -Trong hang doc 9 o cua so do, khong co so nao lap lai so nay."<<endl
        <<" -Trong o vuong 3x3 cua so do, khong co so nao lap lai so nay.";


    while(1)
    {
        if(_kbhit())
        {
            char key=_getch();
            if(key==13)
            {
            clrscr();
            getOption(ar.sudokuBoard);
            return;
            }
        }
    }
    return;
}

void editSquare(int sudokuBoard[][9])
{
    t.x=21;
    t.y=7;
    int a=0,c;
    int b=0;
    int number;
   while(1)
    {
         gotoxy(t.x,t.y);
        if(_kbhit())
         {
             char key=_getch();
             if(key=='w'||key=='W')
                t.tt2=up;
             if(key=='s'||key=='S')
                t.tt2=douwn;
             if(key=='d'||key=='D')
                t.tt2=righ;
             if(key=='a'||key=='A')
                t.tt2=lef;
            if(key==13)
            {
                testgame(ar.sudokuBoard);
                return;
            }
            if(key==32)
            {
                getOption(ar.sudokuBoard);
                return;
            }
            if(key>48&&key<58)
            {
                if(ar.arrchange[b][a]==0)
               {
                   c=key-48;
                   textcolor(7);
                    cout<<c;
                    ar.sudokuBoard[b][a]=c;
               }
            }
         if (t.tt2 == douwn)
			{
			    t.y+=2;
			    b++;
			}
		else if (t.tt2 == up)
			{t.y-=2;
               b--;
			}
		else if (t.tt2 == lef)
			{t.x-=3;
			a--;
			}
		else if (t.tt2 == righ)
			{t.x+=3;
			a++;
			}
        if(t.x>=46)
            {
                t.x=21;
                a=0;
            }
        else
            if(t.y>=24)
            {
                t.y=7;
                b=0;
            }
         else
            if(t.y<=6)
                {
                    t.y=23;
                    b=8;
                }

         else
            if(t.x<=20)
            {
                t.x=45;
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
        sumro+=ar.sudokuBoard[i][j];
        sumcl+=ar.sudokuBoard[j][i];
        }
        if(sumro!=45||sumcl!=45)
            {
                gotoxy(26,30);
                cout<<"Game over!!"<<endl;
                cout<<"Press 'enter' to redo"<<endl;
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
            gotoxy(26,30);
            cout<<"Game over!!"<<endl
                <<"Press 'enter' to redo"<<endl
                <<"Press ' ' to exit"<<endl;
        }
    else
    { gotoxy(26,30);
      cout<<"You win!!!"<<endl;
      cout<<"Press ' ' to exit"<<endl;
    }
    while(1)
    {

    if(_kbhit())
    {
        char key=_getch();
        if(key==13)
        {
            clrscr();
            display(ar.sudokuBoard);
            return;
        }
        else if(key==32)
        {
            clrscr();
            getOption(ar.sudokuBoard);
            return;
        }
    }
    }
    return;

}
