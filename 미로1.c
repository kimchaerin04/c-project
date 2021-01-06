#include <stdio.h>
#include <windows.h>

#define UP 72
#define DOWN 80 
#define LEFT 75     
#define RIGHT 77 

void textcolor(int color_number)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

gotoxy(int x, int y) //gotoxy함수를 호출
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int keeper(int(*map)[36], int X, int Y) { //2차원 배열과 좌표(공의 좌표)

	int checker;

	if (*(*(map + Y) + X) == 0) { 
		checker = 1;
	} //좌표부분의 맵값이 0이면 1을 반환
	else if (*(*(map + Y) + X) == 2) {
		checker = 1;
	}
	else { checker = 0; } //0이 아니면 지나가면 안됨 

	return checker;
}
int main() {

	int X = 4, Y = 3; //좌표값.
	int test, checker, helper, helper2;
	int map[20][36] = {
		{0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9},
		{1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9},
		{1,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,1,9},
		{1,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,2,9,1,9},
		{1,9,0,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,1,9},
		{1,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9},
		{1,9,0,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9},
		{1,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9},
		{1,9,1,9,0,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,1,9},
		{1,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9},
		{1,9,0,9,1,9,1,9,1,9,0,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9},
		{1,9,1,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9},
		{1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9},
		{1,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9},
		{1,9,0,9,1,9,1,9,1,9,0,9,0,9,0,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9},
		{1,9,0,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9},
		{1,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9},
		{1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9},
		{1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9} };
	

	system("mode con cols=37 lines=24");

	gotoxy(4, 1); textcolor(15); printf("     ♣♣  미 로 찾 기   ♣♣");
	gotoxy(0, 2); //원하는 좌표로 가서
	for (helper = 0; helper < 20; helper++) { 
		for (helper2 = 0; helper2 < 36; helper2++) {
			if (map[helper][helper2] == 1) {
				textcolor(8);
				printf("□");
			}
			else if (map[helper][helper2] == 2) {
				textcolor(10);
				printf("§");
			}
			else if (map[helper][helper2] == 0) {
				printf("  ");
			} //0인 경우 빈칸을 출력

		}
		printf("\n");
	}
	textcolor(11);
	gotoxy(X, Y + 2);
	printf("●");

	while (1) {

		test = getch(); 
		textcolor(11);
		switch (test) { 

		case UP: gotoxy(X, Y + 2);;
			printf(" ");
			Y -= 1;//좌표를 이동

			checker = keeper(map, X, Y);
			//map배열 주소와 좌표를 넘김
			if (checker == 1) {
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}
			else if (checker == 0)
			{
				Y += 1;//막힌길이니깐 좌표를 되돌린다
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}
		case DOWN: gotoxy(X, Y + 2);
			printf(" ");
			Y += 1;
			checker = keeper(map, X, Y);
			if (checker == 1) {
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}
			else if (checker == 0)
			{
				Y -= 1;
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}

		case LEFT: gotoxy(X, Y + 2);
			printf(" ");
			X -= 2;

			checker = keeper(map, X, Y);
			if (checker == 1) {

				gotoxy(X, Y + 2);
				printf("●");

				break;
			}
			else if (checker == 0)
			{
				X += 2;
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}

		case RIGHT:   gotoxy(X, Y + 2);
			printf(" ");
			X += 2;

			checker = keeper(map, X, Y);
			if (checker == 1) {

				gotoxy(X, Y + 2);
				printf("●");

				break;
			}
			else if (checker == 0)
			{
				X -= 2;
				gotoxy(X, Y + 2);
				printf("●");
				break;
			}

		} 
//gotoxy(0,0);
//printf("%2d %2d",X,Y);

		if (X == 32 & Y == 3 || X == 33 & Y == 3) { break; }
		else { continue; } //
		   
	} 
	system("cls"); 
	
	for (helper = 0; helper <= 15; helper++) {
		gotoxy(10, 11); textcolor(helper); 
		printf("★탈출했습니다!★\n");
		printf("             *^ ******^*  \n");
		printf("           *  ●    ●  * \n");
		printf("          * @    ^     @ *\n");
		printf("            ************  \n");
		Sleep(100);
	}

	system("pause>nul");
	fflush(stdin);

	system("cls");
	gotoxy(0, 11); textcolor(15);

}