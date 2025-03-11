#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", str);
}

void concatenate_strings(char str1[], char str2[]) {
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
}

void check_palindrome(char str[]) {
    int len = strlen(str);
    int is_palindrome = 1;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }
    if (is_palindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

void copy_string(char str[], char copy[]) {
    strcpy(copy, str);
    printf("Copied string: %s\n", copy);
}

void string_length(char str[]) {
    printf("Length of the string: %d\n", strlen(str));
}

void char_frequency(char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

void count_vowels_consonants(char str[]) {
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
}

void count_blank_spaces_digits(char str[]) {
    int spaces = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            spaces++;
        } else if (isdigit(str[i])) {
            digits++;
        }
    }
    printf("Number of blank spaces: %d\n", spaces);
    printf("Number of digits: %d\n", digits);
}

void show_menu() {
    printf("\nChoose an option:\n");
    printf("1. Reverse a string\n");
    printf("2. Concatenate two strings\n");
    printf("3. Check if the string is a palindrome\n");
    printf("4. Copy a string\n");
    printf("5. Get length of the string\n");
    printf("6. Find frequency of a character in the string\n");
    printf("7. Find number of vowels and consonants\n");
    printf("8. Find number of blank spaces and digits\n");
    printf("9. Exit\n");
}

int main() {
    char str[100], str2[100], copy[100], ch;
    int choice;
    
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 9) {
            printf("Exiting the application. Goodbye!\n");
            break;
        }

        printf("Enter a string: ");
        getchar(); 
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0'; 
        
        switch (choice) {
            case 1:
                reverse_string(str);
                break;
            case 2:
                printf("Enter the second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0'; 
                concatenate_strings(str, str2);
                break;
            case 3:
                check_palindrome(str);
                break;
            case 4:
                copy_string(str, copy);
                break;
            case 5:
                string_length(str);
                break;
            case 6:
                printf("Enter the character to check its frequency: ");
                scanf("%c", &ch);
                char_frequency(str, ch);
                break;
            case 7:
                count_vowels_consonants(str);
                break;
            case 8:
                count_blank_spaces_digits(str);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }

        printf("Do you want to continue? (y/n): ");
        getchar();
        ch = getchar();
        if (ch != 'y' && ch != 'Y') {
            printf("Exiting the application. Goodbye!\n");
            break;
        }
    }
    return 0;
}

