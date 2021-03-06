//헤더파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define stdyr 2021 //stdyr=2021
#define _CRT_SECURE_NO_WARNINGS
#pragma once //헤더파일 중복 제거

//구조체 선언
typedef struct schedule {
    struct schedule* next;
    char subj[100];
    char srttm[20];
    char endtm[20];
} plan;

//함수선언
void date(void);
void scdul(void);
void dlscdul(void);
void lkscdul(void);
int leapyear(int);

//배열 초기화
plan* cal[10][13][32] = { NULL, };

int main() {
    int a; //사용자 입력 변수

    printf("|| 모드 선택 ||\n1. 달력 / 2. 종료 >> ");
    scanf_s("%d", &a);

    switch (a) {
    case 1: date(); break;
    case 2: break;
    default: printf("\n\n잘못입력되었습니다\n"); break;
    }

    return 0;
}

//달력
void date(void) {
    int year, month, b; //사용자 입력변수
    int chk = 0, sum = 0, k = 0; //저장용 변수
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //기본 일수

    printf("\n몇년 몇월을 볼지 입력해주세요\n\nex)2021 03 >> ");
    scanf_s("%d %d", &year, &month);

    //입력 날짜가 이상한지 아닌지 확인
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

    //0년부터 작년까지 며칠인지 계산
    sum = 365;
    for (int i = 1; i < year; i++) {
        if (leapyear(i))
            sum += 366;
        else
            sum += 365;
    }

    //입력한 달까지 며칠인지 계산
    for (int i = 0; i < month - 1; i++) {
        sum += basicyear[i];
    }

    //1월1일 무슨 요일인지 계산
    k = sum % 7;

    Sleep(500);
    system("cls");

    printf("\n%24d년 %d월\n\n", year, month);

    printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
    printf("===================================================\n");

    //시작 요일에 맞춰 정렬
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

    printf("\n\n1. 일정추가 / 2. 일정삭제 / 3. 일정보기 / 4. 종료 >> ");
    scanf_s("%d", &b);

    switch (b) {
    case 1: scdul(); break;
    case 2: dlscdul();  break;
    case 3: lkscdul(); break;
    case 4: break;
    default: printf("\n\n잘못입력되었습니다\n"); break;
    }
}

//일정추가
void scdul(void) {
    int yea, mont, day, a; //사용자 입력 변수
    char subj[200], srttm[20], endtm[20]; //저장용 변수
    char nyan[20] = { 0, }; //복사용 변수
    char dal[20] = { 0, }; //복사용 변수
    char ill[20] = { 0, }; //복사용 변수
    plan* new = (plan*)malloc(sizeof(plan));
    new->next = NULL;

    printf("\n일정을 추가할 날짜를 입력해주세요(2021년부터)\n\nex)2021 03 07 >> ");
    scanf_s(" %d %d %d", &yea, &mont, &day);

    if (yea < stdyr)
        return 0;

    system("cls");
    printf("\n%24d년 %d월 %d일\n", yea, mont, day);

    //이미 일정이 있을경우
    if (cal[yea - stdyr][mont][day] != NULL) {
        int num = 0, NUM = 0; //저장용 변수
        char e; //사용자 입력 변수
        char iary[100]; //파일읽기용 변수
        char sa[20], ve[20]; //저장용 변수

        printf("\n\n이미 일정이 있습니다.\n추가하시겠습니까?(y/n) >> ");
        scanf_s(" %c", &e);

        switch (e) {
        case 'y': break;
        case 'n': date(); return 0;
        default: printf("\n\n잘못입력되었습니다"); return 0;
        }

        printf("\n\n일정을 시작할 시간을 입력해주세요 ex)15:17 >> ");
        scanf_s(" %s", new->srttm, sizeof(new->srttm));
        printf("일정을 끝낼 시간을 입력해주세요 ex)15:25 >> ");
        scanf_s(" %s", new->endtm, sizeof(new->endtm));
        printf("일정 내용을 입력해주세요 >> ");
        scanf_s(" %s", new->subj, sizeof(new->subj));

        //추가 완료 확인
        printf("\n추가 내용 : %s\n", new->srttm);
        printf("추가 내용 : %s\n", new->endtm);
        printf("추가 내용 : %s", new->subj);

        //시간순으로 다시 배열
        struct schedule* curr = cal[yea - stdyr][mont][day];
        while (curr != NULL) {

            if (curr->next != NULL) {
                strcpy(sa, curr->next->srttm);
                char* ptr = strtok(sa, ":");
                num = atoi(ptr); //저장 내용
                strcpy(ve, new->srttm);
                char* str = strtok(ve, ":");
                NUM = atoi(str); //입력 받은 내용

                if (num < NUM)
                    curr = curr->next;

                else {
                    new->next = curr->next;
                    curr->next = new;
                    break;
                }
            }

            else {
                curr->next = new;
                break;
            }
        }
    }

    //일정이 없을경우
    else {
        cal[yea - stdyr][mont][day] = new;

        printf("\n\n일정을 시작할 시간을 입력해주세요 ex)15:17 >> ");
        scanf_s(" %s", new->srttm, sizeof(new->srttm));
        printf("일정을 끝낼 시간을 입력해주세요 ex)15:25 >> ");
        scanf_s(" %s", new->endtm, sizeof(new->endtm));
        printf("일정 내용을 입력해주세요 >> ");
        scanf_s(" %s", new->subj, sizeof(new->subj));

        printf("\n추가 내용 : %s\n", cal[yea - stdyr][mont][day]->srttm);
        printf("추가 내용 : %s\n", cal[yea - stdyr][mont][day]->endtm);
        printf("추가 내용 : %s", cal[yea - stdyr][mont][day]->subj);
    }

    Sleep(2300);
    system("cls");
    printf("|| 모드 선택 ||\n1. 달력 / 2. 일정추가 / 3. 일정삭제 / 4. 일정보기 / 5. 종료 >> ");
    scanf_s("%d", &a);

    switch (a) {
    case 1: date(); break;
    case 2: scdul(); break;
    case 3: dlscdul(); break;
    case 4: lkscdul(); break;
    case 5: break;
    default: printf("\n\n잘못입력되었습니다\n"); break;
    }

}

//일정삭제
void dlscdul(void) {
    int yea, mont, day, a; //사용자 입력 변수
    int num = 0, NUM = 0; //저장용 변수
    char subj[200]; //사용자 입력 변수
    plan* new = (plan*)malloc(sizeof(plan));
    new->next = NULL;

    printf("\n일정을 삭제할 날짜를 입력해주세요(2021년부터)\n\nex)2021 03 07 >> ");
    scanf_s(" %d %d %d", &yea, &mont, &day);

    //일정이 있는지 확인
    if (cal[yea - stdyr][mont][day] == NULL) {
        printf("\n\n일정이 없어 삭제할 수 없습니다\n");
        date();
        return 0;
    }

    printf("삭제할 일정의 내용을 입력해주세요 >> ");
    scanf_s(" %s", subj, sizeof(subj));

    struct schedule* curr = cal[yea - stdyr][mont][day];

    //맨 앞 일정 지우기
    if (strcmp(curr->subj, subj) == 0) {
        struct schedule* removeNode = curr;
        cal[yea - stdyr][mont][day] = removeNode->next;

        free(removeNode);
    }

    //맨 앞 제외 일정 지우기
    else {
        while (curr != NULL) {

            if (curr->next != NULL) {

                if (strcmp(curr->next->subj, subj) != 0)
                    curr = curr->next;

                else {
                    struct schedule* removeNode = curr->next;
                    curr->next = removeNode->next;

                    free(removeNode);
                    break;
                }
            }

            else {
                printf("삭제할 맞는 일정이 없습니다");
                date();
                return 0;
            }
        }
    }

    system("cls");
    Sleep(1000);
    printf("일정 삭제 성공!"); //삭제 완료 확인
    Sleep(1500);
    system("cls");
    printf("|| 모드 선택 ||\n1. 달력 / 2. 일정추가 / 3. 일정삭제 / 4. 일정보기 / 5. 종료 >> ");
    scanf_s("%d", &a);

    switch (a) {
    case 1: date(); break;
    case 2: scdul(); break;
    case 3: dlscdul(); break;
    case 4: lkscdul(); break;
    case 5: break;
    default: printf("\n\n잘못입력되었습니다\n"); break;
    }
}

//일정보기
void lkscdul(void) {
    int a; //사용자 입력 변수
    int c = 0; //조건문 변수
    char b[100]; //사용자 입력 변수

    //배열 처음부터 전부 돌려 일정 출력
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= 12; j++) {
            for (int k = 1; k <= 31; k++) {

                struct schedule* curr = cal[i][j][k];
                while (curr != NULL) {
                    if (c == 0)
                        printf("\n%d년 %d월 %d일 일정", i + stdyr, j, k);

                    printf("\n%s\n%s\n%s\n", curr->srttm, curr->endtm, curr->subj);
                    curr = curr->next;
                    c++;
                }
                c = 0;
            }
        }
    }

    printf("\n아무거나 입력하시면 넘어갑니다 >> ");
    scanf_s(" %s", b, sizeof(b));
    Sleep(650);
    system("cls");

    printf("|| 모드 선택 ||\n1. 달력 / 2. 일정추가 / 3. 일정삭제 / 4. 일정보기 / 5. 종료 >> ");
    scanf_s("%d", &a);

    switch (a) {
    case 1: date(); break;
    case 2: scdul(); break;
    case 3: dlscdul(); break;
    case 4: lkscdul(); break;
    case 5: break;
    default: printf("\n\n잘못입력되었습니다\n"); break;
    }
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