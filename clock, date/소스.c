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
	system("mode con cols=50 lines=10");
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

	printf("��� ����� ���� �Է����ּ��� ex)2008 10\n(��, 2000����� 2050������� �����մϴ�) >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

	if (year < 2000 || month>12 || month < 1) {
		printf("\n�Է��Ͻ� ��¥�� 2000�⺸�� �۰ų� 12������ ũ�ų� 1������ �۽��ϴ� �ٽ� �Է����ּ���");
		Sleep(2000);
		system("cls");
		date();
	}

	else if (year > 2050 || month>12 || month < 1) {
		printf("\n�Է��Ͻ� ��¥�� 2000�⺸�� �۰ų� 12������ ũ�ų� 1������ �۽��ϴ� �ٽ� �Է����ּ���");
		Sleep(2000);
		system("cls");
		date();
	}

	Sleep(500);
	system("cls");
	system("mode con cols=109 lines=25");

	printf("\n%47d�� %d��\n\n", year, month);
	printscreen();
	/*if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d���� �����Դϴ�.", year);dfadfa
	else
		printf("%d���� ������ �ƴմϴ�.", year);*/
}

void printscreen(void) {
	printf("     ---------------------------------------------------------------------------------------------------     ");
	printf("     |     SUN     |     MON     |     TUE     |     WED     |     THU     |     FRI     |     SAT     |     ");
	printf("     ---------------------------------------------------------------------------------------------------     ");

}