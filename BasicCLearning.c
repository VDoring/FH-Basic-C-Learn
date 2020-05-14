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
void lrn_4(); //4. 기호들 소개/사용 방법


//글자위치 조정 함수
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//글자색 설정 함수
void textcolor(int color_num) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

//커서 켜기/끄기
void CursorView(char show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

int main() {
	int menu_select;

	CursorView(0);
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
		case 4:
			lrn_4();
			break;
		}

	}
}

int Menu() {
	int x = 30, y = 5;
	int keynum; //키보드 키 값 저장
	int menu = 1; //메뉴 선택 여부

	system("mode con cols=100 lines=30");
	system("title C Basic Practice v0.2");

	gotoxy(42, 1); textcolor(11); printf("Hello, World!");
	gotoxy(x - 3, y); textcolor(15); printf("▶ 1. 화면에 출력하는 방법");
	gotoxy(x, y + 2); textcolor(15); printf("2. 변수(상자)에 값 넣는 방법");
	gotoxy(x, y + 4); textcolor(15); printf("3. 코드를 여러번 쉽게 실행시키는 방법");
	gotoxy(x, y + 6); textcolor(15); printf("4. 기호들 소개 및 사용 방법");

	while (1) {
		keynum = keyControl();

		switch (keynum) {
		case KEY_UP:
			if (y > 6) {
				gotoxy(x - 3, y); printf(" ");
				y = y - 2;
				gotoxy(x - 3, y); printf("▶");
				menu--;
			}
			break;
		case KEY_DOWN:
			if (y < 10) {
				gotoxy(x - 3, y); printf(" ");
				y = y + 2;
				gotoxy(x - 3, y); printf("▶");
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
	gotoxy(x, y+1); printf("printf(\"안녕\");  -> 안녕 이 출력된다");
	gotoxy(x, y+2); printf("printf(\"Hello\"); -> Hello 가 출력된다");

	gotoxy(x - 8, y+5); textcolor(10); printf("예제 : "); textcolor(15);
	gotoxy(x, y+7); printf("#include <stdio.h>");
	gotoxy(x, y+8); printf("int main()");
	gotoxy(x, y+9); printf("{");
	gotoxy(x, y+10); printf("	printf(\"Hello\"); //Hello 출력");
	gotoxy(x, y+12); printf("	return 0;");
	gotoxy(x, y+13); printf("}");

	gotoxy(0, y+20); system("pause");
	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ 화면에 출력하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= printf는 화면에 무언가를 출력해주는 역할을 한다");

	gotoxy(x - 8, y); textcolor(10); printf("printf 사용법 2 : "); textcolor(15);
	gotoxy(x, y + 1); printf("printf에 \\n을 사용하면 한줄을 띄워준다. (개행)");
	gotoxy(x, y + 2); printf("\\ 은 Enter키 바로 위에 있다");
	gotoxy(x, y + 6); printf("printf(\"안녕\\n여러분\"); -> 안녕");
	gotoxy(x + 27, y + 7); printf("여러분  이 출력된다");
	gotoxy(x, y + 9); printf("printf(\"Hello\\nWorld\"); -> Hello");
	gotoxy(x + 27, y + 10); printf("World   가 출력된다");

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_2() {
	int x = 10, y = 6;

	gotoxy(2, 1); textcolor(10); printf("[ 변수에 값 저장하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= 변수는 값을 담을 수 있는 상자이다");

	gotoxy(x - 8, y); textcolor(10); printf("변수 만들기 : "); textcolor(15);
	gotoxy(x, y + 1); printf("int box; -> box라는 변수(상자)를 만든다.");
	gotoxy(x, y + 2); printf("box = 1; -> box에 1을 저장한다.");
	
	gotoxy(x - 8, y + 5); textcolor(10); printf("예제 : "); textcolor(15);
	gotoxy(x, y + 7); printf("#include <stdio.h>");
	gotoxy(x, y + 8); printf("int main()");
	gotoxy(x, y + 9); printf("{");
	gotoxy(x, y + 10); printf("	int box;");
	gotoxy(x, y + 11); printf("	box = 1;");
	gotoxy(x, y + 13); printf("	return 0;");
	gotoxy(x, y + 14); printf("}");

	gotoxy(0, y + 20); system("pause");
	system("cls");
	char line1[] = "int로 시작된 변수를 출력할때는 %d를 사용한다.";
	char line12[] = "printf(\"%d\", box);";

	gotoxy(2, 1); textcolor(10); printf("[ 변수에 값 저장하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= 변수는 값을 담을 수 있는 상자이다");

	gotoxy(x - 8, y); textcolor(10); printf("변수에 저장된 값 출력하기 : "); textcolor(15);
	gotoxy(x, y + 1); printf("%s", line1);
	
	gotoxy(x - 8, y + 4); textcolor(10); printf("예제 : "); textcolor(15);
	gotoxy(x, y + 6); printf("#include <stdio.h>");
	gotoxy(x, y + 7); printf("int main()");
	gotoxy(x, y + 8); printf("{");
	gotoxy(x, y + 9); printf("	int box;");
	gotoxy(x, y + 10); printf("	box = 1;");
	gotoxy(x, y + 11); printf("	%s //이때 쌍따옴표(\"\")부분과 아닌 부분을 구별해야한다", line12); 
	gotoxy(x, y + 13); printf("	return 0;");
	gotoxy(x, y + 14); printf("}");

	gotoxy(x, y + 16); printf("= 1 출력.");

	gotoxy(0, y + 20); system("pause");
	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ 변수에 값 저장하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= 변수는 값을 담을 수 있는 상자이다");

	gotoxy(x - 8, y); textcolor(10); printf("다른 타입의 상자들 살펴보기 : "); textcolor(15);
	char line1_[] = "char로 시작된 변수는 %c(단일문자) 또는 %s를 사용한다.";
	char line4[] = "float로 시작된 변수는 %f를 사용한다.";
	gotoxy(x, y + 1); printf("char 은 문자를 저장한다. %s", line1_);
	gotoxy(x, y + 2); printf("ex) A, b, Hello, weather 등");
	gotoxy(x, y + 4); printf("float 은 소수를 저장한다. %s", line4);
	gotoxy(x, y + 5); printf("ex) 3.14, 2.1, 5.5543 등");

	gotoxy(x - 8, y + 8); textcolor(10); printf("예제 : "); textcolor(15);
	char line10[] = "printf(\"%c\", text);";
	char line14[] = "printf(\"%s\", longtext);";
	char line17[] = "printf(\"%f\", pi);";
	gotoxy(x, y + 10); printf("char text = 'a';");
	gotoxy(x, y + 11); printf("%s //a 출력", line10);
	gotoxy(x, y + 13); printf("char longtext[] = \"arrow\";");
	gotoxy(x, y + 14); printf("%s //arrow 출력", line14);
	gotoxy(x, y + 16); printf("float pi = 3.14;");
	gotoxy(x, y + 17); printf("%s //3.14 출력", line17);

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_3() {
	int x = 10, y = 6;

	system("mode con cols=100 lines=37");

	gotoxy(2, 1); textcolor(10); printf("[ 간편하게 코드 여러번 실행시키기 ]");
	gotoxy(2, 2); textcolor(15); printf("= 반복문은 무언가를 반복시킨다");

	gotoxy(x - 8, y); textcolor(10); printf("for 반복문 기본 구성 : "); textcolor(15);
	gotoxy(x, y + 1); printf("for(int i = 0;  i < 3;  i++)");
	gotoxy(x, y + 2); printf("       초기식   조건식  변화식");
	gotoxy(x, y + 4); printf("초기식: 반복문 시작시 사용.");
	gotoxy(x, y + 5); printf("조건식: 반복될 조건. 거짓이 될시 반복문을 종료.");
	gotoxy(x, y + 6); printf("변화식: 반복문이 한번 실행될 때마다 수행할 식");

	gotoxy(x - 8, y + 9); textcolor(10); printf("예제 : "); textcolor(15);
	gotoxy(x, y + 10); printf("#include <stdio.h>");
	gotoxy(x, y + 11); printf("int main()");
	gotoxy(x, y + 12); printf("{");
	gotoxy(x, y + 13); printf("	for(int i = 0; i < 3; i++) //3번 반복");
	gotoxy(x, y + 14); printf("	{");
	gotoxy(x, y + 15); printf("	    printf(\"Hello\\n\");");
	gotoxy(x, y + 16); printf("	}");
	gotoxy(x, y + 18); printf("	return 0;");
	gotoxy(x, y + 19); printf("}");

	gotoxy(x, y + 21); printf("= Hello");
	gotoxy(x, y + 22); printf("  Hello");
	gotoxy(x, y + 23); printf("  Hello");
	gotoxy(x, y + 24); printf("출력.");

	gotoxy(0, y + 28); system("pause");
	return;
}

void lrn_4() {
	int x = 10, y = 6;

	gotoxy(2, 1); textcolor(10); printf("[ 기호를 사용하기 ]");
	gotoxy(2, 2); textcolor(15); printf("= 연산자는 무언가를 연산한다");

	gotoxy(x - 8, y); textcolor(10); printf("연산자 소개 : "); textcolor(15);
	gotoxy(x, y + 2); printf("https://studyc.tistory.com/5");

	gotoxy(0, y + 20); system("pause");
	return;
}