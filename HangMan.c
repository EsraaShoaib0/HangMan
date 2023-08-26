/* 
Name: Esraa El-Shoaiby
Hangman is a guessing game for two or more players. 
One player thinks of a word, phrase, or
sentence and the other tries to guess it by suggesting letters or 
numbers within a certain number of guesses.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 5
#define MAX_WORD_LENGTH 25

int main() {
	char answer ='y';
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int NoOfTries = 0;
    int i;
	while(answer == 'y'){
    printf("First player please enter the word to be gueesed by the second player ^_^: \n");
    scanf("%s", word);
    int wordLength;
    wordLength = strlen(word);

    for (i = 0; i < wordLength; i++) {
        guessed[i] = '_';
    }
    guessed[wordLength] = '\0';

    while (NoOfTries < MAX_TRIES) {
        char guess;
        int found = 0;

        printf("\nWord: %s\n", guessed);
        printf("Tries Remaining: %d\n", MAX_TRIES - NoOfTries);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        for (i = 0; i < wordLength; i++) {
            if (tolower(word[i]) == guess) {
                guessed[i] = word[i];
                found = 1;
            }
        }

        if (!found) {
            NoOfTries++;
            printf("Incorrect guess!\n");
        }

        if (strcmp(word, guessed) == 0) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
			break;
        }
    }
	if(NoOfTries == MAX_TRIES)
    printf("\nSorry, you ran out of tries. The word was: %s\n", word);
    printf("Do you want to start again! (y/n)");
     scanf(" %c", &answer);

	}

    return 0;
}