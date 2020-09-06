#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

void gotoxy(int x, int y);

void drawDisplay(short, short, short [][3]);

char validateChar(short);

int main(int argc, char *argv[])
{
  /*
	abc
	000 - 0=0|1|2|
	000 - 1=0|1|2|
	000 - 2=0|1|2|
	000 - 3=0|1|2|
	000 - 4=0|1|2|
	*/

	// short rowDisp[15] = {0,0,0,0,0,0,0,0,0,0,0,0};
	short display[5][3], i,j;
	for(i=0; i<5; i++)
	{
    for(j=0; j<3; j++) display[i][j] = 1;
	}
	short x=3, y=4, in;
	bool running=true;


	/*
	0 -> [0]{1,1,1} [1]{1,0,1} [2]=[1] [3]=[1] [4]{1,1,1}
	*/

	while(running)
	{
		gotoxy(0,1);
		cout << "input: "; cin >> in;
		switch(in)
		{
			// display[i][j] = 1;
			case 0:
				display[1][1] = 0; display[2][1] = 0; display[3][1] = 0;
				break;
			case 1:
	      display[0][0] = 0;
	      for(i=1; i<5; i++) { display[i][0] = 0; display[i][1] = 0; }
				break;
			case 2:
					display[1][0] = 0; display[1][1] = 0;
					display[3][1] = 0; display[3][2] = 0;
					break;
		 	case 3:
        display[1][0] = 0; display[1][1] = 0;
	      display[3][0] = 0; display[3][1] = 0;
				break;
			case 4:
				display[0][1] = 0; display[1][1] = 0;
				display[3][0] = 0; display[3][1] = 0;
				display[4][0] = 0; display[4][1] = 0;
				break;
			case 5:
	      display[1][1] = 0; display[1][2] = 0;
				display[3][0] = 0; display[3][1] = 0;
				break;
			case 6:
	      display[1][1] = 0; display[1][2] = 0; display[3][1] = 0;
	      break;
	    case 7:
	      for(i=1; i<5; i++) { display[i][0] = 0; display[i][1] = 0; }
				break;
			case 8:
	      display[1][1] = 0; display[3][1] = 0;
	      break;
			case 9:
	      display[1][1] = 0;
	      display[3][0] = 0; display[3][1] = 0;
				display[4][0] = 0; display[4][1] = 0;
				break;
			case -1:
				running = false;
				break;
			default:
				break;
		}

		drawDisplay(x,y,display); x += (3*2) + 1;
		for(i=0; i<5; i++)
		{
	    for(j=0; j<3; j++) display[i][j] = 1;
		}

 	}
	return 0;
}

void drawDisplay(short x, short y, short display[][3])
{
	// Dibuja el display, suerte leyendo el codigo.
	short i,j=0;
	for(i=0; i<5; i++)
	{
    gotoxy(x,y);
		cout << validateChar(display[i][j]);
		cout << validateChar(display[i][j+1]);
    cout << validateChar(display[i][j+2]); y++;
	}
}

char validateChar(short elem)
{
	// Valida que caracter del codigo ASCII Extended debe retornar en base
	// al valor binario enviado por parametro.
	if(elem>0) return 219;
	return 255;
}

void gotoxy(int x, int y)
{
	/*
	Setea la posicion del cursor en la consola.
	TODO: incluir libreria windows.h: #include <window.h>
	*/
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}
