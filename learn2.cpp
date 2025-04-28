#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // 使用 getch()

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
        printf("密碼錯誤三次，程式結束。\n");
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
                printf("請輸入 a ~ n 之間的字元：");
                scanf(" %c", &ch);
                if (ch >= 'a' && ch <= 'n') {
                    drawTriangle(ch);
                    printf("\n按任意鍵返回主選單...\n");
                    getch();
                } else {
                    printf("錯誤：請輸入 a~n 的字元。\n");
                    printf("按任意鍵重新輸入...\n");
                    getch();
                }
                break;
            case 'B':
                clearScreen();
                int n;
                printf("請輸入1到9之間的數字：");
                scanf("%d", &n);
                if (n >= 1 && n <= 9) {
                    multiplicationTable(n);
                    printf("\n按任意鍵返回主選單...\n");
                    getch();
                } else {
                    printf("錯誤：請輸入1到9的數字。\n");
                    printf("按任意鍵重新輸入...\n");
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
                    printf("程式結束，謝謝使用。\n");
                    return 0;
                } else {
                    printf("錯誤輸入，按任意鍵重新選擇...\n");
                    getch();
                }
                break;
            default:
                printf("無效的選項，請重新輸入。\n");
                printf("按任意鍵返回主選單...\n");
                getch();
                break;
        }
    }

    return 0;
}

void showWelcomeScreen() {
    printf("====================================================\n");
    printf("||                                                ||\n");
    printf("||         歡迎使用 個人互動系統                  ||\n");
    printf("||                                                ||\n");
    printf("||             請輸入密碼以進入系統               ||\n");
    printf("====================================================\n");
    for (int i = 0; i < 20; i++) {
        printf("><><><>><><>()()()()()(::"">"""""")\n");
    }
}

int passwordCheck() {
    int password, attempts = 0;
    showWelcomeScreen();

    while (attempts < 3) {
        printf("請輸入4位數密碼：");
        scanf("%d", &password);
        if (password == PASSWORD) {
            return 1;
        } else {
            printf("密碼錯誤，請重新輸入。\n");
            attempts++;
        }
    }
    return 0;
}

void showMenu() {
    printf("------------------ 主選單 ------------------\n");
    printf("| a. 畫出直角三角形                          |\n");
    printf("| b. 顯示乘法表                              |\n");
    printf("| c. 結束                                    |\n");
    printf("---------------------------------------------\n");
    printf("請選擇 (a/b/c)：");
}

void drawTriangle(char ch) {
    int lines = ch - 'a' + 1; // 決定總共有幾行
    for (int i = 0; i < lines; i++) {
        for (char c = ch - i; c <= ch; c++) {
            printf("%c", c);
        }
        printf("\n");
    }
}

void multiplicationTable(int n) {
    printf("\n%d x %d 的乘法表：\n", n, n);
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
    system("cls"); // Windows清屏，Mac/Linux請改成 system("clear");
}

char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - ('a' - 'A');
    }
    return ch;
}
//這次完成這個互動式程式，讓我熟悉了 C 語言的條件判斷、迴圈控制與函式設計。
//過程中，我學會了如何不用 ctype.h 自行轉換大小寫，也練習了如何根據使用者輸入動態產生不同的直角三角形。
//這次經驗讓我更加了解程式流程規劃的重要性，也提升了獨立解決問題的能力，收穫很多。
