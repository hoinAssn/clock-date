//헤더파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#define stdyr 2021
#pragma once //헤더파일 중복 제거

//구조체 선언
typedef struct schedule {
    char subj;
    char srttm;
    char endtm;
} plan;

//함수선언
void hour(void);
void date(void);
void scdul(void);
int leapyear(int);

plan* cal[10][13][32] = { NULL, };

int main() {
	int a, b; //사용자 입력 변수

	printf("|| 모드 선택 ||\n1. 시계 / 2. 달력 >> ");
	scanf_s("%d", &a, sizeof(a));

	switch (a) {
		case 1: hour(); break;
		case 2: date(); break;
        default: printf("\n\n잘못입력되었습니다\n"); return 0;
	}

    printf("\n\n1. 일정추가 / 2. 종료 >> ");
    scanf_s("%d", &b, sizeof(b));

    switch (b) {
        case 1: scdul(); break;
        case 2: return 0;
        default: printf("\n\n잘못입력되었습니다\n"); return 0;
    }

	return 0;
}

//시계
void hour(void) {
	
}

//달력
void date(void) {
    int year, month;
    int chk = 0, sum = 0, k = 0;
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	printf("\n몇년 몇월을 볼지 입력해주세요\n\nex)2018 03 >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

    if (month > 12 || month < 1 || year < 0) {
        printf("\n입력하신 날짜가 형식에 맞지 않습니다\n다시 입력해주세요");
        Sleep(3000);
        system("cls");
        date();
        return 0;
    }

    if (leapyear(year)) {
        chk = 1;
        basicyear[1]++;
    }
    else
        chk = 0;
    
    sum = 365;
    for (int i = 1; i < year; i++) {
        if (leapyear(i))
            sum += 366;
        else
            sum += 365;
    }

    for (int i = 0; i < month - 1; i++) {
        sum += basicyear[i];
    }

    k = sum % 7;

	Sleep(500);
	system("cls");

	printf("\n%24d년 %d월\n\n", year, month);

    printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
    printf("===================================================\n");

    for (int j = 0; j < k; j++) {
        printf("\t");
    }

    for (int i = 1; i <= basicyear[month - 1]; i++) {

        printf("%d\t", i);
        if (k == 6) {
            k = -1;
            printf("\n");
        }
        k++;
    }

    printf("\n");
}

//일정
void scdul(void) {
    int yea, mont, day; //사용자 입력 변수
    plan* new = malloc(sizeof(plan));

    time_t tnow;
    struct tm* t;
    time(&tnow);
    t = (struct tm*)localtime(&tnow);
    
    printf("\n일정을 추가할 날짜를 입력해주세요(2021년부터)\n\nex)2018 03 07 >> ");
    scanf_s("%d %d %d", &yea, &mont, &day, sizeof(yea), sizeof(mont), sizeof(day));

    system("cls");
    printf("\n%24d년 %d월 %d일\n", yea, mont, day);

    if (strcmp(cal[yea - stdyr][mont][day], NULL) != 0) {
        printf("이미 일정이 있습니다"); //나중에 수정
        return 0;
    }

    cal[yea - stdyr][mont][day] = new;
    new=
}

//윤년계산
int leapyear(int a) {
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}