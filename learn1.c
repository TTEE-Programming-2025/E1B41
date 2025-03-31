#include <stdio.h>
#include <stdlib.h>

// 清除輸入緩衝區
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    char name[] = "林鼎祐";  // 替換為你的名字
    char studentID[] = "E1B41"; // 替換為你的學號
    int password;
    char inputChar;

    
    // 顯示個人標題（至少 20 行）
    printf("==========================================\n");
    printf("=                                          =\n");
    printf("=             Welcome to My Program        =\n");
    printf("=                                          =\n");
    printf("==========================================\n");
    printf("\n");
    printf("  Name       : %s\n", name);
    printf("  Student ID : %s\n", studentID);
    printf("\n");
    printf("==========================================\n");
    printf("= This is a simple C program for practice =\n");
    printf("= Please follow the instructions below    =\n");
    printf("==========================================\n");
    printf("\n");
    printf("Instructions:\n");
    printf("1. Enter the correct password to proceed.\n");
    printf("2. Input a character and see its category.\n");
    printf("3. Press any key to continue...\n");
    printf("\n");
    printf("==========================================\n");

   
    
    system("pause");  // 等待使用者按鍵
    system("cls");    // 清除畫面

    // 要求輸入密碼
    while (1) {
        printf("Enter the password: ");
        scanf("%d", &password);
        clearInputBuffer();  // 清除輸入緩衝區

        if (password == 2024) {
            printf("Password correct. Welcome!\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
        }
    }

    system("pause");
    system("cls");

    // 進入選單
    while (1) {
        printf("----------------------------------\n");
        printf("  'A' ~ 'Z' : Uppercase\n");
        printf("  'a' ~ 'z' : Lowercase\n");
        printf("  '0' ~ '9' : Digit\n");
        printf("  Otherwise : Your name & ID\n");
        printf("----------------------------------\n");
        printf("Enter a character: ");

        scanf(" %c", &inputChar);
        clearInputBuffer();  // 清除輸入緩衝區

        // 判斷輸入類型
        if (inputChar >= 'A' && inputChar <= 'Z') {
            printf("Uppercase\n");
        } else if (inputChar >= 'a' && inputChar <= 'z') {
            printf("Lowercase\n");
        } else if (inputChar >= '0' && inputChar <= '9') {
            printf("Digit\n");
        } else {
            printf("Name: %s\n", name);
            printf("Student ID: %s\n", studentID);
        break;
        }

        printf("Press any key to continue...");
        system("pause");
        system("cls");
    }

    return 0;
}
// 這個程式充分讓我複習了期中前老師所教的內容並讓我有充分的練習
