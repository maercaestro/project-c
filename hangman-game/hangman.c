// Hangman game made by Abu Huzaifah Bidin
// Created on 2-Mar-2025 13:50 hrs

// define the headers
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// define the global variables
#define MAX_TRIES 6
#define WORD_COUNT 10

//define list of words first
const char *wordList[WORD_COUNT] ={ "buku" , "meja" , "ayam","ikan", "buah", "epal", "cikgu", "kereta", "pencetak", "pisang"};

// Function prototypes
void displayHangman(int);
void playGame();
void clearBuffer();

//main function
int main()
{
    srand(time(NULL));
    printf("Selamat datang ke Hangman\n");
    playGame();
    return 0;

}

// Function to play the game
void playGame()
{
    int wordIndex = rand() % WORD_COUNT; // pick a random word from the selection
    const char *word = wordList[wordIndex];
    int wordLength = strlen(word);

    char guessedWord[wordLength + 1]; // word display
    char guessedLetters[26] = {0}; // track guessed letters
    int incorrectGuesses = 0;
    int guessed = 0;

    // initialize the guessed word with underscores
    for (int i = 0; i<wordLength; i++)
    {
        guessedWord[i] ='_';

    }
    guessedWord[wordLength] = '\0'; // null terminator, end of the strings when guessed word == wordlength

    while (incorrectGuesses < MAX_TRIES)
    {
        displayHangman(incorrectGuesses);
        printf("\nPerkataan:%s",guessedWord);
        printf("\nPercubaan yang tinggal:%d ",MAX_TRIES - incorrectGuesses);
        printf("\nHuruf yang dicuba: %s",guessedLetters);

        printf("\nTeka huruf: ");
        char guess;
        scanf("%c", &guess);
        clearBuffer(); // clear input buffer
        guess = tolower(guess); //convert to lower case

        // check if letter was already guessed
        if (strchr(guessedLetters,guess))
        {
            printf("\nHuruf %c dah diteka\n",guess);
            continue;

        }

        //add to guessed letters
        strncat(guessedLetters, &guess,1);

        int found = 0;
        for (int i=0; i < wordLength; i++)
        {
            if(word[i] == guess)
            {
                guessedWord[i] = guess;
                found = 1;


            }

        }

        if (!found)
        {
            printf("\nSalah teka, cuba lagi\n");
            incorrectGuesses++;

        }
        else
        {
            printf("\nPandai pun\n");
        }
        //check if the word is fully guessed
        if (strcmp(guessedWord, word) == 0)
        {
            guessed = 1;
            break;

        }


    }

    displayHangman(incorrectGuesses);
    if (guessed)
    {
        printf("\n Pandainya dia\n");
    }
    else
    {

        printf("\nGame over, kena mula balik\n");

    }


}
//function to display hangman status
void displayHangman(int tries)
{
    const char *hangmanStages[]= 
    {
        "   \n   \n   \n   \n   \n=====",
        "   |\n   |\n   |\n   |\n   |\n=====",
        " +---+\n   |\n   |\n   |\n   |\n=====",
        " +---+\n O |\n   |\n   |\n   |\n=====",
        " +---+\n O |\n | |\n   |\n   |\n=====",
        " +---+\n O |\n/| |\n   |\n   |\n=====",
        " +---+\n O |\n/|\\|\n/ \\|\n   |\n====="
    };
    printf("\n%s\n",hangmanStages[tries]);

}
//function to clear input buffer
void clearBuffer()
{
    while(getchar() != '\n');

}

