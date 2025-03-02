#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reversing(char *str) 
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) 
	{
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
    printf("After Reversing the String we get: %s\n", str);
}

// Function to concatenate two strings
void concatenat(char *str1, char *str2) {
    strcat(str1, str2);
    printf("After Concatenated String we get: %s\n", str1);
}

// Function to check if a string is a palindrome
void palindrome(char *str) 
{
    int length = strlen(str);
    int flag = 1;
    for (int i = 0; i < length / 2; i++) 
	{
        if (str[i] != str[length - i - 1]) 
		{
            flag = 0;
            break;
        }
    }
    if (flag)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

// Function to copy a string
void copy(char *source, char *destination) {
    strcpy(destination, source);
    printf("After Copied String we get: %s\n", destination);
}

// Function to find length of a string
void length(char *str) {
    printf("The Length of written String is: %ld\n", strlen(str));
}

// Function to find frequency of a character in a string
void character_frequency(char *str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            count++;
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

// Function to count vowels and consonants
void count_vowels_consonants(char *str) {
    int vowels = 0, consonants = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }
    printf("Vowels: %d, Consonants: %d\n", vowels, consonants);
}

// Function to count blank spaces and digits
void count_spaces_digits(char *str) {
    int spaces = 0, digits = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i]))
            spaces++;
        else if (isdigit(str[i]))
            digits++;
    }
    printf("Blank Spaces: %d, Digits: %d\n", spaces, digits);
}

// Main function with menu-driven approach
int main() {
    char str1[100], str2[100], choice;
    char ch;
    
    while (1) {
        printf("\nString Operations Menu:\n");
        printf("1. Reverse a String\n");
        printf("2. Concatenation\n");
        printf("3. Check Palindrome\n");
        printf("4. Copy a String\n");
        printf("5. Find Length of String\n");
        printf("6. Frequency of Character\n");
        printf("7. Count Vowels and Consonants\n");
        printf("8. Count Spaces and Digits\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        getchar(); // Clear input buffer
        
        switch (choice) {
            case '1':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                reversing(str1);
                break;
            case '2':
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = 0;
                concatenat(str1, str2);
                break;
            case '3':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                palindrome(str1);
                break;
            case '4':
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                copy(str1, str2);
                break;
            case '5':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                length(str1);
                break;
            case '6':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                printf("Enter character to find frequency: ");
                scanf(" %c", &ch);
                character_frequency(str1, ch);
                break;
            case '7':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                count_vowels_consonants(str1);
                break;
            case '8':
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = 0;
                count_spaces_digits(str1);
                break;
            case '9':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

