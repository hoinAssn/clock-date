#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

void hour(void);
void date(void);
int leapyear(int);
void printscreen(void);

int main() {
	system("mode con cols=40 lines=10");
	int a;

	printf("1. �ð� / 2. �޷� >> ");
	scanf_s("%d", &a, sizeof(a));

	switch (a) {
		case 1: hour(); break;
		case 2: date(); break;
		default: break;
	}

	return 0;
}
void hour(void) {
	printf("Hello");
}

void date(void) {
    int year, month;
    int chk = 0, sum = 0, k = 0;
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	printf("\n\n��� ����� ���� �Է����ּ���\n\nex)2018 03 >> ");
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
	system("mode con cols=109 lines=25");

	printf("\n%47d�� %d��\n\n", year, month);
	printscreen();
}

int leapyear(int a) {
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}

void printscreen(void) {
	printf("     ---------------------------------------------------------------------------------------------------     ");
	printf("     |     SUN     |     MON     |     TUE     |     WED     |     THU     |     FRI     |     SAT     |     ");
	printf("     ---------------------------------------------------------------------------------------------------     ");

}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <math.h>
#include <time.h>

int leapyear(int);

int main() {
    int year; // ����� �Է� ����
    int month; // ����� �Է� ����
    int k; // ����� ����
    int sum = 0; // ������ ��� �� ��� ����
    int chk = 0; // ���� Ȯ�� ����
    int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }; // �⺻ 1~12�� �ϼ�

    printf("��� ����� ���� �Է����ּ���\n\n\nex)2018 03 >> ");
    scanf_s("%d %d", &year, &month, sizeof(year), sizeof(month));

    //���� Ȯ��
    if (leapyear(year)) {
        chk = 1;
        basicyear[1]++;
    }
    else
        chk = 0;

    //0����� �۳���� ��ĥ���� ��
    sum = 365;
    for (int i = 1; i < year; i++) {
        if (leapyear(i))
            sum += 366;
        else
            sum += 365;
    }

    //�Է��� �ޱ��� ��ĥ���� 
    for (int i = 0; i < month - 1; i++) {
        sum += basicyear[i];
    }

    //1��1�� ���� �������� ���
    k = sum % 7;

    system("cls");

    //���
    printf("\n%47d�� %d��\n\n", year, month);
    printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
    printf("===================================================\n");

    //���� ���Ͽ� ���� ����
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
int leapyear(int a) {
    if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
        return 1;
    }
    else {
        return 0;
    }
}*/