//������� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <time.h>
#define stdyr 2021
#define _CRT_SECURE_NO_WARNINGS
#pragma once //������� �ߺ� ����

//����ü ����
typedef struct schedule {
    struct schedule* next;
    char subj[100];
    char srttm[20];
    char endtm[20];
} plan;

//�Լ�����
void date(void);
void scdul(void);
void listfirst(plan* List);
void lkscdul(void);
int leapyear(int);

//�迭 �ʱ�ȭ
plan* cal[10][13][32] = { NULL, };

int main() {
	int a; //����� �Է� ����

	printf("|| ��� ���� ||\n1. �޷� / 2. ���� >> ");
	scanf_s("%d", &a, sizeof(a));

	switch (a) {
		case 1: date(); break;
        case 2: break;
        default: printf("\n\n�߸��ԷµǾ����ϴ�\n"); break;
	}

	return 0;
}

//�޷�
void date(void) {
    int year, month, b; //����� �Էº���
    int chk = 0, sum = 0, k = 0; //����� ����
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //�⺻ �ϼ�

	printf("\n��� ����� ���� �Է����ּ���\n\nex)2021 03 >> ");
	scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

    if (month > 12 || month < 1 || year < 0) {
        printf("\n�Է��Ͻ� ��¥�� ���Ŀ� ���� �ʽ��ϴ�\n�ٽ� �Է����ּ���");
        Sleep(3000);
        system("cls");
        date();
        return 0;
    }

    //����Ȯ��
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

    printf("\n\n1. �����߰� / 2. �������� / 3. ���� >> ");
    scanf_s("%d", &b, sizeof(b));

    switch (b) {
        case 1: scdul(); break;
        case 2: lkscdul();  break;
        case 3: break;
        default: printf("\n\n�߸��ԷµǾ����ϴ�\n"); break;
    }
}

//�����߰�
void scdul(void) {
    int yea, mont, day, a; //����� �Է� ����
    char subj[200], srttm[20], endtm[20]; //����� ����
    char nyan[20] = { 0, }; //����� ����
    char dal[20] = { 0, }; //����� ����
    char ill[20] = { 0, }; //����� ����
    plan* new = (plan*)malloc(sizeof(plan));
    
    printf("\n������ �߰��� ��¥�� �Է����ּ���(2021�����)\n\nex)2021 03 07 >> ");
    scanf_s("%d %d %d", &yea, &mont, &day, sizeof(yea), sizeof(mont), sizeof(day));

    if (yea < 2021)
        return 0;
    
    system("cls");
    printf("\n%24d�� %d�� %d��\n", yea, mont, day);

    strcat(itoa(yea, nyan, 10), ".");
    strcat(nyan, itoa(mont, dal, 10));
    strcat(nyan, ".");
    strcat(nyan, itoa(day, ill, 10));
    strcat(nyan, ".txt");

    FILE* fs;
    fopen_s(&fs, nyan, "r");

    if (fs != NULL) { //���� ����Ʈ ��
        int num = 0, NUM = 0; //����� ����
        char e; //����� �Է� ����
        char iary[100]; //�����б�� ����
        
        printf("�̹� ������ �ֽ��ϴ�.\n�߰��Ͻðڽ��ϱ�?(y/n) >> ");
        scanf_s("%c", e, sizeof(e));

        switch (e) {
        case 'y': break;
        case 'n': date(); return 0;
        default: printf("\n\n�߸��ԷµǾ����ϴ�"); return 0;
        }

        cal[yea - stdyr][mont][day] = new;

        printf("\n\n������ ������ �ð��� �Է����ּ��� ex)15:17 >> ");
        scanf_s(" %s", new->srttm, sizeof(new->srttm));
        printf("������ ���� �ð��� �Է����ּ��� ex)15:25 >> ");
        scanf_s(" %s", new->endtm, sizeof(new->endtm));
        printf("���� ������ �Է����ּ��� >> ");
        scanf_s(" %s", new->subj, sizeof(new->subj));

        struct schedule* plan = malloc(sizeof(struct schedule));
        plan->next = NULL;

        fgets(iary, 100, fs);
        char* ptr = strtok(iary, ":");
        num = atoi(ptr);
        char* str = strtok(new->srttm, ":");
        NUM = atoi(str);

        if (num < NUM) {
            struct schedule* newNode = malloc(sizeof(struct schedule));
            newNode->next = List->next;

            List->next = newNode;
        }

        /*struct schedule* node1 = malloc(sizeof(struct schedule));
        plan->next = node1;

        strcpy(node1->srttm, iary);
        fgets(iary, 100, fs);
        strcpy(node1->endtm, iary);
        fgets(iary, 100, fs);
        strcpy(node1->subj, iary);

        struct schedule* node2 = malloc(sizeof(struct schedule));
        node1->next = node2;
        node2->next = NULL;*/
    }

    if (cal[yea - stdyr][mont][day] != NULL) {
        printf("\n�̹� ������ �ֽ��ϴ�"); //���߿� ����
        return 0;
    }

    cal[yea - stdyr][mont][day] = new;
    
    printf("\n\n������ ������ �ð��� �Է����ּ��� ex)15:17 >> ");
    scanf_s(" %s", new->srttm, sizeof(new->srttm));
    printf("������ ���� �ð��� �Է����ּ��� ex)15:25 >> ");
    scanf_s(" %s", new->endtm, sizeof(new->endtm));
    printf("���� ������ �Է����ּ��� >> ");
    scanf_s(" %s", new->subj, sizeof(new->subj));

    /*struct schedule* head = malloc(sizeof(struct schedule));
    struct schedule* node1 = malloc(sizeof(struct schedule));
    head->next = node1;
    node1->srttm = new->srttm;
    node1->endtm = new->endtm;
    node1->subj = new->subj;*/
    
    strcpy(srttm, new->srttm);
    strcpy(endtm, new->endtm);
    strcpy(subj, new->subj);

    fopen_s(&fs, nyan, "w"); //���� �̸��� \ / : * ? < > | ��� �Ұ�

    if (fs == NULL) { //fs�� NULL�̸� ������� ������ ����
        fopen_s(&fs, nyan, "w");
    }

    strcat(srttm, "\n");
    strcat(endtm, "\n");

    fputs(srttm, fs);
    fputs(endtm, fs);
    fputs(subj, fs);
    fclose(fs);
    free(new);

    system("cls");
    Sleep(1000);
    printf("���� �߰� ����!");
    Sleep(1000);
    system("cls");

    printf("|| ��� ���� ||\n1. �޷� / 2. ���� >> ");
    scanf_s("%d", &a, sizeof(a));

    switch (a) {
        case 1: date(); break;
        case 2: break;
        default: printf("\n\n�߸��ԷµǾ����ϴ�\n"); break;
    }

}

void listfirst(plan* List) {
    struct schedule* newNode = malloc(sizeof(struct schedule));
    newNode->next = List->next;
    
    List->next = newNode;
}

//��������
void lkscdul(void) {
    printf("Hi");
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