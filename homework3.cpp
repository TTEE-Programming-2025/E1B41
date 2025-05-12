#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9
#define PASSWORD "2025"

char seats[ROWS][COLS];

// ��l�ƩҦ��y�쬰 '*'
void initializeSeats() {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            seats[i][j] = '*';
}

// ��ܥثe�y���
void showSeats() {
    printf("  123456789\n");
    for (int i = 0; i < ROWS; ++i) {
        printf("%d ", 9 - i);
        for (int j = 0; j < COLS; ++j) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// �n�J�e���]�K�X��J�̦h�T���^
int login() {
    char input[10];
    int attempts = 3;
    while (attempts > 0) {
        printf("�п�J4��ƱK�X�G");
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            printf("�n�J���\�I\n");
            return 1;
        } else {
            attempts--;
            printf("�K�X���~�A�Ѿl%d�����|�C\n", attempts);
        }
    }
    return 0;
}

// �D���
void showMenu() {
    printf("\n[Booking System]---------\n");
    printf("a. Available seats\n");
    printf("b. Arrange for you\n");
    printf("c. Choose by yourself\n");
    printf("d. Exit\n");
    printf("Your choice: ");
}

// �۰ʦw�Ʈy��]�s��1~4��^
void autoArrange() {
    int num;
    printf("�п�J�y��ƶq (1-4)�G");
    scanf("%d", &num);

    if (num < 1 || num > 4) {
        printf("��J�L�ġC\n");
        return;
    }

    int success = 0;
    for (int i = 0; i < ROWS && !success; i++) {
        for (int j = 0; j <= COLS - num; j++) {
            int k;
            for (k = 0; k < num; k++) {
                if (seats[i][j + k] != '*') break;
            }
            if (k == num) {
                for (k = 0; k < num; k++) {
                    seats[i][j + k] = '@';
                }
                printf("�w�w�Ʈy��b��%d�C�A��%d���%d��C\n", 9 - i, j + 1, j + num);
                success = 1;
                break;
            }
        }
    }
    if (!success) {
        printf("�S���i�Ϊ��s��y��C\n");
    }
    showSeats();
}

// ��ʿ�ܮy��
void manualChoose() {
    int row, col;
    char input[10];

    while (1) {
        printf("�п�J����ܪ��y�� (�C-��A�Ҧp 5-7)�A��J 0 �����G");
        scanf("%s", input);

        if (strcmp(input, "0") == 0) break;

        if (sscanf(input, "%d-%d", &row, &col) != 2) {
            printf("�榡���~�A�ЦA�դ@���C\n");
            continue;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9) {
            printf("�W�X�d��C\n");
            continue;
        }

        int i = 9 - row;
        int j = col - 1;

        if (seats[i][j] == '*') {
            seats[i][j] = '@';
            printf("���\��ܮy�� %d-%d�C\n", row, col);
        } else {
            printf("�Ӯy��w�Q���ΡC\n");
        }

        showSeats();
    }
}

int main() {
    initializeSeats();
    if (!login()) {
        printf("�W�L�n�J���ƭ���A�t�ε����C\n");
        return 0;
    }

    char choice;
    do {
        showMenu();
        scanf(" %c", &choice); // �`�N�Ů�H�Y������r��

        switch (choice) {
            case 'a':
                showSeats();
                break;
            case 'b':
                autoArrange();
                break;
            case 'c':
                manualChoose();
                break;
            case 'd': {
                char confirm;
                printf("�O�_�~��ϥΨt�ΡH(y/n)�G");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    choice = 'x'; // �^�D���
                } else {
                    printf("�P�¨ϥΡA�t�ε����C\n");
                }
                break;
            }
            default:
                printf("��J���~�A�Э��s��ܡC\n");
        }

    } while (choice != 'd');

    return 0;
}
