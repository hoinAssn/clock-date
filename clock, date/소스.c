//������� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#define stdyr 2021
#pragma once //������� �ߺ� ����

//����ü ����
typedef struct schedule {
    char subj;
    char srttm;
    char endtm;
} plan;

//�Լ�����
void hour(void);
void date(void);
void scdul(void);
int leapyear(int);

plan* cal[10][13][32] = { NULL, };

int main() {
	int a, b; //����� �Է� ����

	printf("|| ��� ���� ||\n1. �ð� / 2. �޷� >> ");
	scanf_s("%d", &a, sizeof(a));

	switch (a) {
		case 1: hour(); break;
		case 2: date(); break;
        default: printf("\n\n�߸��ԷµǾ����ϴ�\n"); return 0;
	}

    printf("\n\n1. �����߰� / 2. ���� >> ");
    scanf_s("%d", &b, sizeof(b));

    switch (b) {
        case 1: scdul(); break;
        case 2: return 0;
        default: printf("\n\n�߸��ԷµǾ����ϴ�\n"); return 0;
    }

	return 0;
}

//�ð�
void hour(void) {
	
}

//�޷�
void date(void) {
    int year, month;
    int chk = 0, sum = 0, k = 0;
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	printf("\n��� ����� ���� �Է����ּ���\n\nex)2018 03 >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

    if (month > 12 || month < 1 || year < 0) {
        printf("\n�Է��Ͻ� ��¥�� ���Ŀ� ���� �ʽ��ϴ�\n�ٽ� �Է����ּ���");
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

	printf("\n%24d�� %d��\n\n", year, month);

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

//����
void scdul(void) {
    int yea, mont, day; //����� �Է� ����
    plan* new = malloc(sizeof(plan));

    time_t tnow;
    struct tm* t;
    time(&tnow);
    t = (struct tm*)localtime(&tnow);
    
    printf("\n������ �߰��� ��¥�� �Է����ּ���(2021�����)\n\nex)2018 03 07 >> ");
    scanf_s("%d %d %d", &yea, &mont, &day, sizeof(yea), sizeof(mont), sizeof(day));

    system("cls");
    printf("\n%24d�� %d�� %d��\n", yea, mont, day);

    if (strcmp(cal[yea - stdyr][mont][day], NULL) != 0) {
        printf("�̹� ������ �ֽ��ϴ�"); //���߿� ����
        return 0;
    }

    cal[yea - stdyr][mont][day] = new;
    new=
}

//������
int leapyear(int a) {
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}