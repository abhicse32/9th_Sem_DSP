#include <stdio.h>
#include <string.h>

int check_anagram(char *, char *);

void main() {
    int is_anagram;
    char word1[100], word2[100];
    scanf("%s %s", word1, word2);
    is_anagram = check_anagram(word1, word2);
    printf("%d\n", is_anagram);
}

int check_anagram(char *word1, char *word2) {
    int first_word[26] = {0}, second_word[26] = {0}, counter = 0;
    if (strlen(word1) != strlen(word2))
        return 0;
    while (word1[counter] != 0) {
        first_word[word1[counter] - 97]++;
        second_word[word2[counter] - 97]++;
        counter++;
    }
    for (counter = 0; counter < 26; counter++) {
        if (first_word[counter] != second_word[counter])
            return 0;
    }
    return 1;
}