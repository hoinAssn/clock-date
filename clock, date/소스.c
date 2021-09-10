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

	printf("몇년 몇월을 볼지 입력해주세요 ex)2008 10\n(단, 2000년부터 2050년까지만 가능합니다) >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

	if (year < 2000 || month>12 || month < 1) {
		printf("\n입력하신 날짜가 2000년보다 작거나 12월보다 크거나 1월보다 작습니다 다시 입력해주세요");
		Sleep(2000);
		system("cls");
		date();
	}

	else if (year > 2050 || month>12 || month < 1) {
		printf("\n입력하신 날짜가 2000년보다 작거나 12월보다 크거나 1월보다 작습니다 다시 입력해주세요");
		Sleep(2000);
		system("cls");
		date();
	}

	Sleep(500);
	system("cls");
	system("mode con cols=109 lines=25");

	printf("\n%47d년 %d월\n\n", year, month);
	printscreen();
	/*if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		printf("%d년은 윤년입니다.", year);dfadfa
	else
		printf("%d년은 윤년이 아닙니다.", year);*/
}

void printscreen(void) {
	printf("     ---------------------------------------------------------------------------------------------------     ");
	printf("     |     SUN     |     MON     |     TUE     |     WED     |     THU     |     FRI     |     SAT     |     ");
	printf("     ---------------------------------------------------------------------------------------------------     ");

}