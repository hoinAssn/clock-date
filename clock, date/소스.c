#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

void hour(void);
void date(void);
void printscreen(void);

int main() {
	system("mode con cols=109 lines=25");
	int a;

	printf("1. �ð� / 2. �޷� >> ");
	scanf_s("%d", &a, sizeof(a));
	switch (a) {
		case 1: hour(); break;
		case 2: date(); break;
		default: break;
	}
}

void hour(void) {
	printf("Hello");
}

void date(void) {
	int year, month;

	printf("��� ����� ���� �Է����ּ��� (ex:2008 10) >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

	if (month > 12) {
		printf("\n�Է��Ͻ� ��¥�� 12������ Ů�ϴ� �ٽ� �Է����ּ���");
		Sleep(2000);
		system("cls");
		date();
	}

	else if (month < 1) {
		printf("\n�Է��Ͻ� ��¥�� 1������ �۽��ϴ� �ٽ� �Է����ּ���");
		Sleep(2000);
		system("cls");
		date();
	}

	Sleep(500);
	system("cls");

	printf("\n%47d�� %d��\n\n", year, month);
	printscreen();
	/*if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d���� �����Դϴ�.", year);dfadfa
	else
		printf("%d���� ������ �ƴմϴ�.", year);*/
}

void printscreen(void) {
	printf("     ---------------------------------------------------------------------------------------------------     ");
	printf("     |     MON     |     TUE     |     WED     |     THU     |     FRI     |     SAT     |     SUN     |     ");
	printf("     ---------------------------------------------------------------------------------------------------     ");
}