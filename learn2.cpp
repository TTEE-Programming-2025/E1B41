#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // �ϥ� getch()

#define PASSWORD 2025

void showWelcomeScreen();
int passwordCheck();
void showMenu();
void drawTriangle(char ch);
void multiplicationTable(int n);
char getChoice();
void clearScreen();
char toUpperCase(char ch);

int main() {
    int success = passwordCheck();
    if (!success) {
        printf("�K�X���~�T���A�{�������C\n");
        return 0;
    }

    char choice;
    while (1) {
        clearScreen();
        showMenu();
        choice = getChoice();

        switch (choice) {
            case 'A':
                clearScreen();
                char ch;
                printf("�п�J a ~ n �������r���G");
                scanf(" %c", &ch);
                if (ch >= 'a' && ch <= 'n') {
                    drawTriangle(ch);
                    printf("\n�����N���^�D���...\n");
                    getch();
                } else {
                    printf("���~�G�п�J a~n ���r���C\n");
                    printf("�����N�䭫�s��J...\n");
                    getch();
                }
                break;
            case 'B':
                clearScreen();
                int n;
                printf("�п�J1��9�������Ʀr�G");
                scanf("%d", &n);
                if (n >= 1 && n <= 9) {
                    multiplicationTable(n);
                    printf("\n�����N���^�D���...\n");
                    getch();
                } else {
                    printf("���~�G�п�J1��9���Ʀr�C\n");
                    printf("�����N�䭫�s��J...\n");
                    getch();
                }
                break;
            case 'C':
                clearScreen();
                char cont;
                printf("Continue? (y/n): ");
                scanf(" %c", &cont);
                cont = toUpperCase(cont);
                if (cont == 'Y') {
                    continue;
                } else if (cont == 'N') {
                    printf("�{�������A���¨ϥΡC\n");
                    return 0;
                } else {
                    printf("���~��J�A�����N�䭫�s���...\n");
                    getch();
                }
                break;
            default:
                printf("�L�Ī��ﶵ�A�Э��s��J�C\n");
                printf("�����N���^�D���...\n");
                getch();
                break;
        }
    }

    return 0;
}

void showWelcomeScreen() {
    printf("====================================================\n");
    printf("||                                                ||\n");
    printf("||         �w��ϥ� �ӤH���ʨt��                  ||\n");
    printf("||                                                ||\n");
    printf("||             �п�J�K�X�H�i�J�t��               ||\n");
    printf("====================================================\n");
    for (int i = 0; i < 20; i++) {
        printf("><><><>><><>()()()()()(::"">"""""")\n");
    }
}

int passwordCheck() {
    int password, attempts = 0;
    showWelcomeScreen();

    while (attempts < 3) {
        printf("�п�J4��ƱK�X�G");
        scanf("%d", &password);
        if (password == PASSWORD) {
            return 1;
        } else {
            printf("�K�X���~�A�Э��s��J�C\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    printf("------------------ �D��� ------------------\n");
    printf("| a. �e�X�����T����                          |\n");
    printf("| b. ��ܭ��k��                              |\n");
    printf("| c. ����                                    |\n");
    printf("---------------------------------------------\n");
    printf("�п�� (a/b/c)�G");
}

void drawTriangle(char ch) {
    int lines = ch - 'a' + 1; // �M�w�`�@���X��
    for (int i = 0; i < lines; i++) {
        for (char c = ch - i; c <= ch; c++) {
            printf("%c", c);
        }
        printf("\n");
    }
}

void multiplicationTable(int n) {
    printf("\n%d x %d �����k��G\n", n, n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }
}

char getChoice() {
    char ch;
    scanf(" %c", &ch);
    return toUpperCase(ch);
}

void clearScreen() {
    system("cls"); // Windows�M�̡AMac/Linux�Ч令 system("clear");
}

char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - ('a' - 'A');
    }
    return ch;
}
//�o�������o�Ӥ��ʦ��{���A���ڼ��x�F C �y��������P�_�B�j�鱱��P�禡�]�p�C
//�L�{���A�ھǷ|�F�p�󤣥� ctype.h �ۦ��ഫ�j�p�g�A�]�m�ߤF�p��ھڨϥΪ̿�J�ʺA���ͤ��P�������T���ΡC
//�o���g�����ڧ�[�F�ѵ{���y�{�W�������n�ʡA�]���ɤF�W�߸ѨM���D����O�A��ì�ܦh�C
