#include<iostream>
#include <cstdio>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include<stdio.h>
#include"Console.h"
using namespace std;
int Game[4][4] = {0};
int Score=0;
//hàm xóa màn hình

void modau ()
{
    textColor(14);
    cout<<"               -------------------XIN CHAO GAMER------------------      "<<endl;Sleep(100);
    textColor(10);
	cout<< endl<<endl<<endl;Sleep(50);
	cout <<"   222222222222222         000000000            444444444       888888888     "<<endl;Sleep(100);
	cout <<"  2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   "<<endl;Sleep(100);
	cout <<"  2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 "<<endl;Sleep(100);
	cout <<"  2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8"<<endl;Sleep(100);
	cout <<"              2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8"<<endl;Sleep(100);
	cout <<"              2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8"<<endl;Sleep(100);
	textColor(12);
	cout <<"           2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 "<<endl;Sleep(100);
	cout <<"      22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  "<<endl;Sleep(100);
	cout <<"    22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 "<<endl;Sleep(100);
	textColor(9);
	cout <<"   2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8"<<endl;Sleep(100);
	cout <<"  2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8"<<endl;Sleep(100);
	cout <<"  2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8"<<endl;Sleep(100);
	cout <<"  2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8"<<endl;Sleep(100);
	cout <<"  2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 "<<endl;Sleep(100);
	cout <<"  2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   "<<endl;Sleep(100);
	cout <<"  22222222222222222222     000000000             4444444444     888888888     "<<endl;Sleep(100);
	cout << endl;Sleep(50);
	cout <<endl;Sleep(50);
    Sleep(100);
    textColor(13);
	cout <<"Press any key to start game... ";
	cout <<endl<<endl<<endl;
    Sleep(100);
    getch();
}

void draw_background(){
	int a = 0, b = 0;
	for(int i = 0; i <= 16; i++){
		for(int j = 0; j <= 16; j++){

			if(i == 0 || i == 4 || i ==  8 || i == 12 || i == 16){
				textColor(136);
				cout << 33;
			}
			else if(j == 0 || j == 4 || j ==  8 || j == 12 || j == 16){
				textColor(136);
				cout << 33;
			}
			else {

				textColor(0);
				cout << 33;

			}

		}
		textColor(0);
		cout << endl;

	}


}

int color_of_data(int x){

	switch(x){
		case 2: return 160;
		case 4: return 48;
		case 8: return 208;
		case 16: return 176;
		case 32: return 64;
		case 64: return 80;
		case 128: return 96;
		case 256: return 225;
		case 512: return 161;
		case 1024: return 192;
		case 2048: return 208;
	}

}
int color_of_block(int x){

	switch(x){
		case 0: return 119;
		case 2: return 170;
		case 4: return 51;
		case 8: return 221;
		case 16: return 187;
		case 32: return 68;
		case 64: return 85;
		case 128: return 102;
		case 256: return 238;
		case 512: return 187;
		case 1024: return 204;
		case 2048: return 221;
	}

}

void draw_game()
{
	int y = 3;
	for(int i = 0; i < 4; i++){
		int x = 4;
		for(int j = 0; j < 4; j++){

			textColor(color_of_block(Game[i][j]));
			gotoXY(x-2, y-2);
			cout << "      ";
			gotoXY(x-2, y-1);
			cout << "      ";
			gotoXY(x-2, y);
			cout << "      ";
			textColor(color_of_data(Game[i][j]));

			if(Game[i][j] != 0){
				gotoXY(x+1, y-1);
				cout << Game[i][j];
			}

			x = x + 8;
		}
		y = y + 4;
	}
	gotoXY(40, 5);
	textColor(15);
	cout << "DIEM CUA BAN : " << Score<<endl;
}
// hướng dẫn cách choi
void huongdan()
{
    //clrscr();
    gotoXY(40, 7);
	textColor(15);
	cout<<"LUAT CHOI: "<<endl;
	gotoXY(40, 8);
	textColor(10);
	cout<<"_A: SANG TRAI"<<endl;
	gotoXY(40, 9);
	textColor(9);
	cout<<"_S: XUONG"<<endl;
	gotoXY(40, 10);
	textColor(14);
	cout<<"_D: SANG PHAI"<<endl;
	gotoXY(40, 11);
	textColor(13);
	cout<<"_W: LEN"<<endl;
}
void Up() {

    int i,j;
	for (j = 0; j < 4; j++) {
		int t = 0;
		for (i = 0; i < 4; i++) {
			if (Game[i][j] != 0) {
				Game[t][j] = Game[i][j];
				t++;
			}
		}
		for ( i = t; i < 4; i++) Game[i][j] = 0;
	}
	for (j = 0; j < 4; j++) {
		int t = 0;
		for ( i = 0; i < 4; i++) {
			if (Game != 0) {
				if (Game[i][j] == Game[i + 1][j]) {
					Game[t][j] = 2 * Game[i][j];
					Score += Game[t][j];
					t++;
					i++;
				}
				else {
					Game[t][j] = Game[i][j];
					t++;
				}
			}
		}
		for ( i = t; i < 4; i++) Game[i][j] = 0;
	}

}

void Down()
{
    int i,j;
	for (j = 0; j < 4; j++) {
		int t = 3;
		for ( i = 3; i >= 0; i--) {
			if (Game[i][j] != 0) {
				Game[t][j] = Game[i][j];
				t--;
			}
		}
		for ( i = t; i >= 0; i--) Game[i][j] = 0;
	}
	for ( j = 0; j < 4; j++) {
		int t = 3;
		for ( i = 3; i >= 0; i--) {
			if (Game != 0) {
				if (Game[i][j] == Game[i - 1][j]) {
					Game[t][j] = 2 * Game[i][j];
					Score += Game[t][j];
					t--;
					i--;
				}
				else {
					Game[t][j] = Game[i][j];
					t--;
				}
			}
		}
		for ( i = t; i >= 0; i--) Game[i][j] = 0;
	}

}

void Left()
{
    int i, j;
	for ( i = 0; i < 4; i++) {
		int t = 0;
		for ( j = 0; j < 4; j++) {
			if (Game[i][j] != 0) {
				Game[i][t] = Game[i][j];
				t++;
			}
		}
		for ( j = t; j < 4; j++) Game[i][j] = 0;
	}
    for( i = 0; i<4; i++)
    {
        int t=0;
		for ( j = 0; j < 4; j++) {
			if (Game[i][j] != 0) {
				if (Game[i][j] == Game[i][j + 1]) {
					Game[i][t] = 2 * Game[i][j];
					Score += Game[i][t];
					j++;
					t++;
				}
				else {
					Game[i][t] = Game[i][j];
					t++;
				}
			}
		}
		for (int j = t; j < 4; j++) Game[i][j] = 0;
    }

}

void Right()
{
    int i,j;
	for ( i = 0; i < 4; i++) {
		int t = 3;
		for ( j = 3; j >= 0; j--) {
			if (Game[i][j] != 0) {
				Game[i][t] = Game[i][j];
				t--;
			}
		}
		for ( j = t; j >= 0; j--) Game[i][j] = 0;
	}
     for (i = 0; i < 4; i++) {
		int t = 3;
		for ( j = 3; j >= 0; j--) {
			if (Game[i][j] != 0) {
				if (Game[i][j] == Game[i][j - 1]) {
					Game[i][t] = 2 * Game[i][j];
					Score += Game[i][t];
					j--;
					t--;
				}
				else {
					Game[i][t] = Game[i][j];
					t--;
            }
			}
		}
		for ( j = t; j >= 0; j--) Game[i][j] = 0;
	}
}

bool check_arr_empty(){
	int check;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(Game[i][j] == 0) return true;
		}
	}
	return false;
}
void make_game(){
	int i, j;
	if(check_arr_empty()==false) return;
	//tao so ngau nhien
	srand(time(NULL));
		do{
			i = rand()%4;
			j = rand()%4;
		}while (Game[i][j]);
		int s=rand()%100;
		if(s>89)Game[i][j]=4;
		else
		Game[i][j] = 2;
}
void game_end(){
	//Thang
	int i, j;
	for( i = 0; i < 4; i++){
		for( j = 0; j < 4; j++){
			if(Game[i][j] == 2048) {
				gotoXY(60, 8);
				textColor(14);
				cout << "YOU WIN!!!";
				gotoXY(1, 20);
				system("pause");
				exit(1);
			}
		}
	}

	//thua
	bool check = false;
	for( i = 0; i < 3; i++){
		for( j = 0; j < 3; j++){
			if(Game[i][j] == Game[i][j+1] || Game[i][j] == Game[i+1][j])
				check = true;
		}
	}

	if(check == false && check_arr_empty() == 0){
		gotoXY(60, 8);
		textColor(14);
		cout << "YOU LOSE!!";
		gotoXY(1, 20);
		system("pause");
		exit(1);
	}
}


int main()

{
    ShowCur(false);
   modau();
   clrscr();
   srand (time(NULL));
   int x = rand() % 4,
       y = rand() % 4;
   Game [x][y]=2;
   gotoXY(0,0);
   draw_background();
   huongdan();
    while(1)
    {
    draw_game();
    game_end();
    char key = _getch();
    if (key == 'w' || key == 'W') {
			Up();
		}
		else if (key == 's' || key == 'S') {
			Down();
		}
		else if (key == 'a' || key == 'A') {
			Left();
		}
		else if (key == 'd' || key == 'D') {
			Right();
		}
		else continue;
        make_game();
    }

}

