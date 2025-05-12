#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 9
#define COLS 9
#define PASSWORD "2025"

char seats[ROWS][COLS];

// 初始化所有座位為 '*'
void initializeSeats() {
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            seats[i][j] = '*';
}

// 顯示目前座位表
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

// 登入畫面（密碼輸入最多三次）
int login() {
    char input[10];
    int attempts = 3;
    while (attempts > 0) {
        printf("請輸入4位數密碼：");
        scanf("%s", input);
        if (strcmp(input, PASSWORD) == 0) {
            printf("登入成功！\n");
            return 1;
        } else {
            attempts--;
            printf("密碼錯誤，剩餘%d次機會。\n", attempts);
        }
    }
    return 0;
}

// 主選單
void showMenu() {
    printf("\n[Booking System]---------\n");
    printf("a. Available seats\n");
    printf("b. Arrange for you\n");
    printf("c. Choose by yourself\n");
    printf("d. Exit\n");
    printf("Your choice: ");
}

// 自動安排座位（連續1~4位）
void autoArrange() {
    int num;
    printf("請輸入座位數量 (1-4)：");
    scanf("%d", &num);

    if (num < 1 || num > 4) {
        printf("輸入無效。\n");
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
                printf("已安排座位在第%d列，第%d到第%d行。\n", 9 - i, j + 1, j + num);
                success = 1;
                break;
            }
        }
    }
    if (!success) {
        printf("沒有可用的連續座位。\n");
    }
    showSeats();
}

// 手動選擇座位
void manualChoose() {
    int row, col;
    char input[10];

    while (1) {
        printf("請輸入欲選擇的座位 (列-行，例如 5-7)，輸入 0 結束：");
        scanf("%s", input);

        if (strcmp(input, "0") == 0) break;

        if (sscanf(input, "%d-%d", &row, &col) != 2) {
            printf("格式錯誤，請再試一次。\n");
            continue;
        }

        if (row < 1 || row > 9 || col < 1 || col > 9) {
            printf("超出範圍。\n");
            continue;
        }

        int i = 9 - row;
        int j = col - 1;

        if (seats[i][j] == '*') {
            seats[i][j] = '@';
            printf("成功選擇座位 %d-%d。\n", row, col);
        } else {
            printf("該座位已被佔用。\n");
        }

        showSeats();
    }
}

int main() {
    initializeSeats();
    if (!login()) {
        printf("超過登入次數限制，系統結束。\n");
        return 0;
    }

    char choice;
    do {
        showMenu();
        scanf(" %c", &choice); // 注意空格以吃掉換行字元

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
                printf("是否繼續使用系統？(y/n)：");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    choice = 'x'; // 回主選單
                } else {
                    printf("感謝使用，系統結束。\n");
                }
                break;
            }
            default:
                printf("輸入錯誤，請重新選擇。\n");
        }

    } while (choice != 'd');

    return 0;
}
