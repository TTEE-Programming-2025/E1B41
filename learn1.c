#include <stdio.h>
#include <stdlib.h>

// �M����J�w�İ�
void clearInputBuffer() {
    while (getchar() != '\n');
}

int main() {
    char name[] = "�L����";  // �������A���W�r
    char studentID[] = "E1B41"; // �������A���Ǹ�
    int password;
    char inputChar;

    
    // ��ܭӤH���D�]�ܤ� 20 ��^
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

   
    
    system("pause");  // ���ݨϥΪ̫���
    system("cls");    // �M���e��

    // �n�D��J�K�X
    while (1) {
        printf("Enter the password: ");
        scanf("%d", &password);
        clearInputBuffer();  // �M����J�w�İ�

        if (password == 2024) {
            printf("Password correct. Welcome!\n");
            break;
        } else {
            printf("Incorrect password. Try again.\n");
        }
    }

    system("pause");
    system("cls");

    // �i�J���
    while (1) {
        printf("----------------------------------\n");
        printf("  'A' ~ 'Z' : Uppercase\n");
        printf("  'a' ~ 'z' : Lowercase\n");
        printf("  '0' ~ '9' : Digit\n");
        printf("  Otherwise : Your name & ID\n");
        printf("----------------------------------\n");
        printf("Enter a character: ");

        scanf(" %c", &inputChar);
        clearInputBuffer();  // �M����J�w�İ�

        // �P�_��J����
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
// �o�ӵ{���R�����ڽƲߤF�����e�Ѯv�ұЪ����e�����ڦ��R�����m��
