#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/* 키보드 키 */
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4
#define KEY_ENTER 5

int Menu(); //첫 화면
int keyControl(); //메뉴에서 입력한 키보드키 반환

void lrn_1(); //1. 화면에 출력하는 방법
void lrn_2(); //2. 변수(상자)에 값 넣는 방법
void lrn_3(); //3. 코드를 여러번 쉽게 실행시키는 방법


//글자위치 조정 함수
gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//글자색 설정 함수
textcolor(int color_num) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

int main() {
	int menu_select;

	while (1) {
		menu_select = Menu();
		system("cls");

		switch (menu_select) {
		case 1:
			lrn_1();
			break;
		case 2:
			lrn_2();
			break;
		case 3:
			lrn_3();
			break;
		}

	}
}

int Menu() {
	int x = 30, y = 5;
	int keynum; //키보드 키 값 저장
	int menu = 1; //메뉴 선택 여부

	system("mode con cols=100 lines=30");
	system("title C Basic Practice");

	gotoxy(42, 1); textcolor(11); printf("Hello, World!");
	gotoxy(x - 2, y); textcolor(15); printf("> 1. 화면에 출력하는 방법");
	gotoxy(x, y + 2); textcolor(15); printf("2. 변수(상자)에 값 넣는 방법");
	gotoxy(x, y + 4); textcolor(15); printf("3. 코드를 여러번 쉽게 실행시키는 방법");

	while (1) {
		keynum = keyControl();

		switch (keynum) {
		case KEY_UP:
			if (y > 6) {
				gotoxy(x - 2, y); printf(" ");
				y = y - 2;
				gotoxy(x - 2, y); printf(">");
				menu--;
			}
			break;
		case KEY_DOWN:
			if (y < 10) {
				gotoxy(x - 2, y); printf(" ");
				y = y + 2;
				gotoxy(x - 2, y); printf(">");
				menu++;
			}
			break;
		case KEY_ENTER:
			return menu;
		}
	}
}

int keyControl() {
	char keytemp;

	keytemp = _getch();
	if (keytemp == 13)
		return KEY_ENTER;
	switch (keytemp) {
	case 72:
		return KEY_UP;
	case 80:
		return KEY_DOWN;
	case 75:
		return KEY_LEFT;
	case 77:
		return KEY_RIGHT;
	default:
		return -1; //다른 키보드값 입력
	}
}

void lrn_1() {
	int x = 10, y = 6;

	gotoxy(2,1); textcolor(10); printf("[ 화면에 출력하기 ]");
	gotoxy(2,2); textcolor(15); printf("= printf는 화면에 무언가를 출력시켜주는 역할을 한다");

	gotoxy(x - 8, y); textcolor(10); printf("printf 사용법 : "); textcolor(15);
	gotoxy(x, y+1); printf("printf(\"안녕\"); -> \"안녕\"이 출력된다");
	gotoxy(x, y+2); printf("printf(\"Hello\"); -> \"Hello\"가 출력된다");

	gotoxy(x - 8, y+5); textcolor(10); printf("써야하는 곳 : "); textcolor(15);
	gotoxy(x, y+7); printf("#include <stdio.h>");
	gotoxy(x, y+8); printf("int main()");
	gotoxy(x, y+9); printf("{");
	gotoxy(x, y+10); printf("	(이 줄에 작성!)");
	gotoxy(x, y+11); printf("	return 0;");
	gotoxy(x, y+12); printf("}");

	gotoxy(0, y+20); system("pause");

	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ 화면에 출력하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= printf는 화면에 무언가를 출력시켜주는 역할을 한다");

	gotoxy(x - 8, y); textcolor(10); printf("printf 사용법 2 : "); textcolor(15);
	gotoxy(x, y + 1); printf("printf(\"안녕\\n여러분\"); -> 안녕");
	gotoxy(x + 27, y + 2); printf("여러분  이 출력된다");
	gotoxy(x, y + 4); printf("printf(\"Hello\\nWorld\"); -> Hello");
	gotoxy(x + 27, y + 5); printf("World  가 출력된다");

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_2() {

}

void lrn_3() {

}