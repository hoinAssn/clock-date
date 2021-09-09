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

	printf("1. 시계 / 2. 달력 >> ");
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

	printf("몇년 몇월을 볼지 입력해주세요 (ex:2008 10) >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

	if (month > 12) {
		printf("\n입력하신 날짜가 12월보다 큽니다 다시 입력해주세요");
		Sleep(2000);
		system("cls");
		date();
	}

	else if (month < 1) {
		printf("\n입력하신 날짜가 1월보다 작습니다 다시 입력해주세요");
		Sleep(2000);
		system("cls");
		date();
	}

	Sleep(500);
	system("cls");

	printf("\n%47d년 %d월\n\n", year, month);
	printscreen();
	/*if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d년은 윤년입니다.", year);dfadfa
	else
		printf("%d년은 윤년이 아닙니다.", year);*/
}

void printscreen(void) {
	printf("     ---------------------------------------------------------------------------------------------------     ");
	printf("     |     MON     |     TUE     |     WED     |     THU     |     FRI     |     SAT     |     SUN     |     ");
	printf("     ---------------------------------------------------------------------------------------------------     ");
}