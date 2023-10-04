#include <stdio.h>
#include <string.h>

int berland_word_index(char word[]) {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    int first_letter_position = strchr(alphabet, word[0]) - alphabet;
    int second_letter_position = strchr(alphabet, word[1]) - alphabet;
    int index = first_letter_position * 26 + second_letter_position - first_letter_position;
    if (first_letter_position > second_letter_position) {
        index = index + 1;
    }
    return index;
}

int main() {
    int t;
    scanf("%d", &t);
    char s[t][3]; // Assuming each word has exactly two lowercase letters

    for (int i = 0; i < t; i++) {
        scanf("%s", s[i]);
    }

    int index[t];
    for (int i = 0; i < t; i++) {
        index[i] = berland_word_index(s[i]);
    }

    for (int i = 0; i < t; i++) {
        printf("%d\n", index[i]);
    }

    return 0;
}
