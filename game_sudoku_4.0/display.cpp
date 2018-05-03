#include"display.h"
#include"console.h"
display::display()
{
    ;
}
void display::frame()
 {
    clrscr(); gotoXY(19,6);
    cout<<char(201);
    for(int i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(203);
    for(int i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(203);
    for(int i=0;i<2;i++)
    cout<<char(205)<<(char)205<<char(209);
    cout<<char(205)<<char(205)<<char(187);
    gotoXY(19,7);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    for(int i=0;i<2;i++)
    cout<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,8);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoXY(19,9);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
    <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
   gotoXY(19,10);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
  gotoXY(19,11);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
     <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,12);
    cout<<char(204)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
    <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
    <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(185);
    gotoXY(19,13);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
    <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,14);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
    <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
   gotoXY(19,15);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,16);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
       <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
       <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
    gotoXY(19,17);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,18);
    cout<<char(204)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
        <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(206)
        <<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(216)<<char(205)<<char(205)<<char(185);
    gotoXY(19,19);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,20);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
   gotoXY(19,21);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,22);
    cout<<char(199)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(215)
        <<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(197)<<char(196)<<char(196)<<char(182);
   gotoXY(19,23);
    cout<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)
        <<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186)<<"  "<<char(179)<<"  "<<char(179)<<"  "<<char(186);
    gotoXY(19,24);
    cout<<char(200)<<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(202)
        <<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(202)
        <<char(205)<<char(205)<<char(207)
        <<char(205)<<char(205)<<char(207)<<char(205)<<char(205)<<char(188);
    TextColor(3);gotoXY(50,23);
    cout<<"Press 'enter' to check";
    TextColor(3);gotoXY(50,24);
    cout<<"Press ' ' to exit!";
}
void display::openGame()
{
    for(int f=0;f<6;f++)
  {
  switch(f)
   {
   case 0:
  TextColor(7);clrscr();  gotoXY(35,12);
   cout<<"S";Sleep(750);break;
   case 1:
   TextColor(4);clrscr();    gotoXY(35,12);
   cout<<"SU";Sleep(750);break;
   case 2:
   TextColor(3);clrscr();   gotoXY(35,12);
   cout<<"SUD";Sleep(750);break;
   case 3:
   TextColor(2);clrscr();  gotoXY(35,12);
   cout<<"SUDO";Sleep(750);break;
   case 4:
   TextColor(8);clrscr();  gotoXY(35,12);
   cout<<"SUDOK";Sleep(750);break;
   case 5:
   TextColor(9);clrscr(); gotoXY(35,12);
   cout<<"SUDOKU";Sleep(850);break;
   }
  }
}
void display::closeGame()
{
  clrscr();
    for(int f=0;f<7;f++)
  {
  switch(f)
   {
   case 0:
   TextColor(7);clrscr(); gotoXY(35,12);
   cout<<"G";Sleep(550);break;
   case 1:
   TextColor(4);clrscr();    gotoXY(35,12);
   cout<<"GO";Sleep(550);break;
   case 2:
   TextColor(3);clrscr(); gotoXY(35,12);
   cout<<"GOO";Sleep(550);break;
   case 3:
   TextColor(2);clrscr();  gotoXY(35,12);
   cout<<"GOOD";Sleep(550);break;
   case 4:
  TextColor(8);clrscr(); gotoXY(35,12);
   cout<<"GOODB";Sleep(550);break;
   case 5:
  TextColor(9);clrscr();gotoXY(35,12);
   cout<<"GOODBY";Sleep(550);break;
   case 6:
  TextColor(10);clrscr();gotoXY(35,12);
   cout<<"GOODBYE";Sleep(650);break;
   }
  }
  return ;
}
