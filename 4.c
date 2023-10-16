#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int isAlphanumeric(char c) {
    return (isalpha(c) || isdigit(c));
}
char toLower(char c) {
    return tolower(c);
}
void sanitizeString(char *str) {
    int len = strlen(str);
    char sanitized[len];
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isAlphanumeric(str[i])) {
            sanitized[j++] = toLower(str[i]);
        }
    }

    sanitized[j] = '\0';

    strcpy(str, sanitized);
}
int countPunctuationMarks(char sentence[]) {
    char punctuationMarks[] = ",.!;?";
    int count = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        for (int j = 0; punctuationMarks[j] != '\0'; j++) {
            if (sentence[i] == punctuationMarks[j]) {
                count++;
                break;
            }
        }
    }

    return count;
}
int isPalindrome(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return 0; 
        }
    }
    return 1; 
}
int main() {
    char text[1000];int open;int closed;
    printf("Enter a sequence\n");
    fgets(text,sizeof(text),stdin);
    open = 0;closed = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '(') {
            open++;
        } else if (text[i] == ')') {
            closed++;
        }
    }
    if (open==closed){
        printf("is correctly \n");
    }else{
        printf("isn't correctly\n");
    }
    char a[1000];char b[1000];bool l;
    printf("Enter 2 strings \n");
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
    int len1 = strlen(a);
    int len2 = strlen(b);

    int foundAll = 1;

    for (int i = 0; i < len2; i++) {
        char currentChar = b[i];
        if (strchr(a, currentChar) == NULL) {
            foundAll = 0;
            break;
        }
    }
    if (foundAll){
        printf("is a rotation\n");
    }
    else{
        printf("isn't a rotation\n");
    }
    char c[1000];
    printf("Enter a string\n");
    fgets(c,sizeof(c),stdin);
    sanitizeString(c);
    if (isPalindrome(c)) {
        printf("It's a palindrome!\n");
    } else {
        printf("It's not a palindrome.\n");
    }
    char sent[1000];
    printf("Enter a sentence: ");
    fgets(sent, sizeof(sent), stdin);

    int CountP = countPunctuationMarks(sent);
    printf("Number of punctuation marks: %d\n", CountP);
    return 0;
}
