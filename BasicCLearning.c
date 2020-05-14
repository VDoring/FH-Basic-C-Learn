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
void lrn_4(); //4. ��ȣ�� �Ұ�/��� ���


//������ġ ���� �Լ�
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//���ڻ� ���� �Լ�
void textcolor(int color_num) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

//Ŀ�� �ѱ�/����
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
	int keynum; //Ű���� Ű �� ����
	int menu = 1; //�޴� ���� ����

	system("mode con cols=100 lines=30");
	system("title C Basic Practice v0.2");

	gotoxy(42, 1); textcolor(11); printf("Hello, World!");
	gotoxy(x - 3, y); textcolor(15); printf("�� 1. ȭ�鿡 ����ϴ� ���");
	gotoxy(x, y + 2); textcolor(15); printf("2. ����(����)�� �� �ִ� ���");
	gotoxy(x, y + 4); textcolor(15); printf("3. �ڵ带 ������ ���� �����Ű�� ���");
	gotoxy(x, y + 6); textcolor(15); printf("4. ��ȣ�� �Ұ� �� ��� ���");

	while (1) {
		keynum = keyControl();

		switch (keynum) {
		case KEY_UP:
			if (y > 6) {
				gotoxy(x - 3, y); printf(" ");
				y = y - 2;
				gotoxy(x - 3, y); printf("��");
				menu--;
			}
			break;
		case KEY_DOWN:
			if (y < 10) {
				gotoxy(x - 3, y); printf(" ");
				y = y + 2;
				gotoxy(x - 3, y); printf("��");
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
	gotoxy(x, y+1); printf("printf(\"�ȳ�\");  -> �ȳ� �� ��µȴ�");
	gotoxy(x, y+2); printf("printf(\"Hello\"); -> Hello �� ��µȴ�");

	gotoxy(x - 8, y+5); textcolor(10); printf("���� : "); textcolor(15);
	gotoxy(x, y+7); printf("#include <stdio.h>");
	gotoxy(x, y+8); printf("int main()");
	gotoxy(x, y+9); printf("{");
	gotoxy(x, y+10); printf("	printf(\"Hello\"); //Hello ���");
	gotoxy(x, y+12); printf("	return 0;");
	gotoxy(x, y+13); printf("}");

	gotoxy(0, y+20); system("pause");
	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ ȭ�鿡 ����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= printf�� ȭ�鿡 ���𰡸� ������ִ� ������ �Ѵ�");

	gotoxy(x - 8, y); textcolor(10); printf("printf ���� 2 : "); textcolor(15);
	gotoxy(x, y + 1); printf("printf�� \\n�� ����ϸ� ������ ����ش�. (����)");
	gotoxy(x, y + 2); printf("\\ �� EnterŰ �ٷ� ���� �ִ�");
	gotoxy(x, y + 6); printf("printf(\"�ȳ�\\n������\"); -> �ȳ�");
	gotoxy(x + 27, y + 7); printf("������  �� ��µȴ�");
	gotoxy(x, y + 9); printf("printf(\"Hello\\nWorld\"); -> Hello");
	gotoxy(x + 27, y + 10); printf("World   �� ��µȴ�");

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_2() {
	int x = 10, y = 6;

	gotoxy(2, 1); textcolor(10); printf("[ ������ �� �����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= ������ ���� ���� �� �ִ� �����̴�");

	gotoxy(x - 8, y); textcolor(10); printf("���� ����� : "); textcolor(15);
	gotoxy(x, y + 1); printf("int box; -> box��� ����(����)�� �����.");
	gotoxy(x, y + 2); printf("box = 1; -> box�� 1�� �����Ѵ�.");
	
	gotoxy(x - 8, y + 5); textcolor(10); printf("���� : "); textcolor(15);
	gotoxy(x, y + 7); printf("#include <stdio.h>");
	gotoxy(x, y + 8); printf("int main()");
	gotoxy(x, y + 9); printf("{");
	gotoxy(x, y + 10); printf("	int box;");
	gotoxy(x, y + 11); printf("	box = 1;");
	gotoxy(x, y + 13); printf("	return 0;");
	gotoxy(x, y + 14); printf("}");

	gotoxy(0, y + 20); system("pause");
	system("cls");
	char line1[] = "int�� ���۵� ������ ����Ҷ��� %d�� ����Ѵ�.";
	char line12[] = "printf(\"%d\", box);";

	gotoxy(2, 1); textcolor(10); printf("[ ������ �� �����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= ������ ���� ���� �� �ִ� �����̴�");

	gotoxy(x - 8, y); textcolor(10); printf("������ ����� �� ����ϱ� : "); textcolor(15);
	gotoxy(x, y + 1); printf("%s", line1);
	
	gotoxy(x - 8, y + 4); textcolor(10); printf("���� : "); textcolor(15);
	gotoxy(x, y + 6); printf("#include <stdio.h>");
	gotoxy(x, y + 7); printf("int main()");
	gotoxy(x, y + 8); printf("{");
	gotoxy(x, y + 9); printf("	int box;");
	gotoxy(x, y + 10); printf("	box = 1;");
	gotoxy(x, y + 11); printf("	%s //�̶� �ֵ���ǥ(\"\")�κа� �ƴ� �κ��� �����ؾ��Ѵ�", line12); 
	gotoxy(x, y + 13); printf("	return 0;");
	gotoxy(x, y + 14); printf("}");

	gotoxy(x, y + 16); printf("= 1 ���.");

	gotoxy(0, y + 20); system("pause");
	system("cls");

	gotoxy(2, 1); textcolor(10); printf("[ ������ �� �����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= ������ ���� ���� �� �ִ� �����̴�");

	gotoxy(x - 8, y); textcolor(10); printf("�ٸ� Ÿ���� ���ڵ� ���캸�� : "); textcolor(15);
	char line1_[] = "char�� ���۵� ������ %c(���Ϲ���) �Ǵ� %s�� ����Ѵ�.";
	char line4[] = "float�� ���۵� ������ %f�� ����Ѵ�.";
	gotoxy(x, y + 1); printf("char �� ���ڸ� �����Ѵ�. %s", line1_);
	gotoxy(x, y + 2); printf("ex) A, b, Hello, weather ��");
	gotoxy(x, y + 4); printf("float �� �Ҽ��� �����Ѵ�. %s", line4);
	gotoxy(x, y + 5); printf("ex) 3.14, 2.1, 5.5543 ��");

	gotoxy(x - 8, y + 8); textcolor(10); printf("���� : "); textcolor(15);
	char line10[] = "printf(\"%c\", text);";
	char line14[] = "printf(\"%s\", longtext);";
	char line17[] = "printf(\"%f\", pi);";
	gotoxy(x, y + 10); printf("char text = 'a';");
	gotoxy(x, y + 11); printf("%s //a ���", line10);
	gotoxy(x, y + 13); printf("char longtext[] = \"arrow\";");
	gotoxy(x, y + 14); printf("%s //arrow ���", line14);
	gotoxy(x, y + 16); printf("float pi = 3.14;");
	gotoxy(x, y + 17); printf("%s //3.14 ���", line17);

	gotoxy(0, y + 20); system("pause");
	return;
}

void lrn_3() {
	int x = 10, y = 6;

	system("mode con cols=100 lines=37");

	gotoxy(2, 1); textcolor(10); printf("[ �����ϰ� �ڵ� ������ �����Ű�� ]");
	gotoxy(2, 2); textcolor(15); printf("= �ݺ����� ���𰡸� �ݺ���Ų��");

	gotoxy(x - 8, y); textcolor(10); printf("for �ݺ��� �⺻ ���� : "); textcolor(15);
	gotoxy(x, y + 1); printf("for(int i = 0;  i < 3;  i++)");
	gotoxy(x, y + 2); printf("       �ʱ��   ���ǽ�  ��ȭ��");
	gotoxy(x, y + 4); printf("�ʱ��: �ݺ��� ���۽� ���.");
	gotoxy(x, y + 5); printf("���ǽ�: �ݺ��� ����. ������ �ɽ� �ݺ����� ����.");
	gotoxy(x, y + 6); printf("��ȭ��: �ݺ����� �ѹ� ����� ������ ������ ��");

	gotoxy(x - 8, y + 9); textcolor(10); printf("���� : "); textcolor(15);
	gotoxy(x, y + 10); printf("#include <stdio.h>");
	gotoxy(x, y + 11); printf("int main()");
	gotoxy(x, y + 12); printf("{");
	gotoxy(x, y + 13); printf("	for(int i = 0; i < 3; i++) //3�� �ݺ�");
	gotoxy(x, y + 14); printf("	{");
	gotoxy(x, y + 15); printf("	    printf(\"Hello\\n\");");
	gotoxy(x, y + 16); printf("	}");
	gotoxy(x, y + 18); printf("	return 0;");
	gotoxy(x, y + 19); printf("}");

	gotoxy(x, y + 21); printf("= Hello");
	gotoxy(x, y + 22); printf("  Hello");
	gotoxy(x, y + 23); printf("  Hello");
	gotoxy(x, y + 24); printf("���.");

	gotoxy(0, y + 28); system("pause");
	return;
}

void lrn_4() {
	int x = 10, y = 6;

	gotoxy(2, 1); textcolor(10); printf("[ ��ȣ�� ����ϱ� ]");
	gotoxy(2, 2); textcolor(15); printf("= �����ڴ� ���𰡸� �����Ѵ�");

	gotoxy(x - 8, y); textcolor(10); printf("������ �Ұ� : "); textcolor(15);
	gotoxy(x, y + 2); printf("https://studyc.tistory.com/5");

	gotoxy(0, y + 20); system("pause");
	return;
}