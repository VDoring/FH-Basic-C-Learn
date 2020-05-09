#include <stdio.h>
#include <Windows.h>
#include <conio.h>

/* Ű���� Ű */
#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 3
#define KEY_RIGHT 4
#define KEY_ENTER 5

int Menu(); //ù ȭ��
int keyControl(); //�޴����� �Է��� Ű����Ű ��ȯ

void lrn_1(); //1. ȭ�鿡 ����ϴ� ���
void lrn_2(); //2. ����(����)�� �� �ִ� ���
void lrn_3(); //3. �ڵ带 ������ ���� �����Ű�� ���


//������ġ ���� �Լ�
gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//���ڻ� ���� �Լ�
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
	int keynum; //Ű���� Ű �� ����
	int menu = 1; //�޴� ���� ����

	system("mode con cols=100 lines=30");
	system("title C Basic Practice");

	gotoxy(42, 1); textcolor(11); printf("Hello, World!");
	gotoxy(x - 2, y); textcolor(15); printf("> 1. ȭ�鿡 ����ϴ� ���");
	gotoxy(x, y + 2); textcolor(15); printf("2. ����(����)�� �� �ִ� ���");
	gotoxy(x, y + 4); textcolor(15); printf("3. �ڵ带 ������ ���� �����Ű�� ���");

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
		return -1; //�ٸ� Ű���尪 �Է�
	}
}

void lrn_1() {
	int x = 10, y = 6;

	gotoxy(2,1); textcolor(10); printf("[ ȭ�鿡 ����ϱ� ]");
	gotoxy(2,2); textcolor(15); printf("= printf�� ȭ�鿡 ���𰡸� ��½����ִ� ������ �Ѵ�");

	gotoxy(x - 8, y); textcolor(10); printf("printf ���� : "); textcolor(15);
	gotoxy(x, y+1); printf("printf(\"�ȳ�\"); -> \"�ȳ�\"�� ��µȴ�");
	gotoxy(x, y+2); printf("printf(\"Hello\"); -> \"Hello\"�� ��µȴ�");

	gotoxy(x - 8, y+5); textcolor(10); printf("����ϴ� �� : "); textcolor(15);
	gotoxy(x, y+7); printf("#include <stdio.h>");
	gotoxy(x, y+8); printf("int main()");
	gotoxy(x, y+9); printf("{");
	gotoxy(x, y+10); printf("	(�� �ٿ� �ۼ�!)");
	gotoxy(x, y+11); printf("	return 0;");
	gotoxy(x, y+12); printf("}");

	gotoxy(0, y+20); system("pause");

	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ ȭ�鿡 ����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= printf�� ȭ�鿡 ���𰡸� ��½����ִ� ������ �Ѵ�");

	gotoxy(x - 8, y); textcolor(10); printf("printf ���� 2 : "); textcolor(15);
	gotoxy(x, y + 1); printf("printf(\"�ȳ�\\n������\"); -> �ȳ�");
	gotoxy(x + 27, y + 2); printf("������  �� ��µȴ�");
	gotoxy(x, y + 4); printf("printf(\"Hello\\nWorld\"); -> Hello");
	gotoxy(x + 27, y + 5); printf("World  �� ��µȴ�");

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_2() {

}

void lrn_3() {

}