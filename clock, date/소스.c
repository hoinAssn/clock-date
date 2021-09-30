//헤더파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define stdyr 2021
#define _CRT_SECURE_NO_WARNINGS
#pragma once //헤더파일 중복 제거

//구조체 선언
typedef struct schedule {
    char subj[100];
    char srttm[20];
    char endtm[20];
} plan;

//함수선언
void hour(void);
void date(void);
void scdul(void);
void lkscdul(void);
int leapyear(int);

//배열 초기화
plan* cal[10][13][32] = { NULL, };

int main() {
	int a; //사용자 입력 변수

	printf("|| 모드 선택 ||\n1. 시계 / 2. 달력 / 3. 종료 >> ");
	scanf_s("%d", &a, sizeof(a));

	switch (a) {
		case 1: hour(); break;
		case 2: date(); break;
        case 3: break;
        default: printf("\n\n잘못입력되었습니다\n"); break;
	}

	return 0;
}

//시계
void hour(void) {
    printf("Hello");
}

//달력
void date(void) {
    int year, month, b; //사용자 입력변수
    int chk = 0, sum = 0, k = 0; //저장용 변수
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //기본 일수

	printf("\n몇년 몇월을 볼지 입력해주세요\n\nex)2021 03 >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

    if (month > 12 || month < 1 || year < 0) {
        printf("\n입력하신 날짜가 형식에 맞지 않습니다\n다시 입력해주세요");
        Sleep(3000);
        system("cls");
        date();
        return 0;
    }

    //윤달확인
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

    printf("\n\n1. 일정추가 / 2. 일정보기 / 3. 종료 >> ");
    scanf_s("%d", &b, sizeof(b));

    switch (b) {
        case 1: scdul(); break;
        case 2: lkscdul();  break;
        case 3: break;
        default: printf("\n\n잘못입력되었습니다\n"); break;
    }
}

//일정추가
void scdul(void) {
    int yea, mont, day, a; //사용자 입력 변수
    char subj[200], srttm[20], endtm[20]; //저장용 변수
    char nyan[20] = { 0, };
    char dal[20] = { 0, };
    char ill[20] = { 0, };
    plan* new = (plan*)malloc(sizeof(plan));
    
    printf("\n일정을 추가할 날짜를 입력해주세요(2021년부터)\n\nex)2021 03 07 >> ");
    scanf_s("%d %d %d", &yea, &mont, &day, sizeof(yea), sizeof(mont), sizeof(day));

    if (yea < 2021)
        return 0;
    
    system("cls");
    printf("\n%24d년 %d월 %d일\n", yea, mont, day);

    strcat(itoa(yea, nyan, 10), ".");
    strcat(itoa(yea, nyan, 10), itoa(mont, dal, 10));
    strcat(itoa(yea, nyan, 10), ".");
    strcat(itoa(yea, nyan, 10), itoa(day, ill, 10));
    strcat(itoa(yea, nyan, 10), ".txt");

    FILE* fs;
    fopen_s(&fs, yea, "r");

    if (fs != NULL) {
        printf("\n이미 일정이 있습니다");
        return 0;
    }

    if (cal[yea - stdyr][mont][day] != NULL) {
        printf("\n이미 일정이 있습니다"); //나중에 수정
        return 0;
    }

    cal[yea - stdyr][mont][day] = new;
    
    printf("\n\n일정을 시작할 시간을 입력해주세요 ex)15:17 >> ");
    scanf_s(" %s", new->srttm, sizeof(new->srttm));
    printf("일정을 끝낼 시간을 입력해주세요 ex)15:25 >> ");
    scanf_s(" %s", new->endtm, sizeof(new->endtm));
    printf("일정 내용을 입력해주세요 >> ");
    scanf_s(" %s", new->subj, sizeof(new->subj));

    strcpy(srttm, new->srttm);
    strcpy(endtm, new->endtm);
    strcpy(subj, new->subj);

    fopen_s(&fs, yea, "w"); //파일 이름에 \ / : * ? < > | 사용 불가

    if (fs == NULL) { //fs가 NULL이면 쓰기모드로 파일을 제작
        fopen_s(&fs, yea, "w");
    }

    strcat(srttm, "~");
    strcat(endtm, "\n");
    strcat(srttm, endtm);

    fputs(srttm, fs);
    fputs(endtm, fs);
    fputs(subj, fs);
    fclose(fs);
    free(new);

    system("cls");
    Sleep(1000);
    printf("일정 추가 성공!");
    Sleep(1000);
    system("cls");

    printf("|| 모드 선택 ||\n1. 시계 / 2. 달력 / 3. 종료 >> ");
    scanf_s("%d", &a, sizeof(a));

    switch (a) {
        case 1: hour(); break;
        case 2: date(); break;
        case 3: break;
        default: printf("\n\n잘못입력되었습니다\n"); break;
    }

}

//일정보기
void lkscdul(void) {
    printf("Hi");
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