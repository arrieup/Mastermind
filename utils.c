//***************************************************************************
//  PROGRAMME : utils.c
//  DATE      : 21/07/2024
//  OBJET     : Mastermind
//  AUTEUR(S) : Arrieumerlou Pablo Benfrid Gaultier Lara Florian
//***************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

const char COLORS[NUM_COLORS] = {'R', 'V', 'B', 'J', 'O', 'M'};

void generate_combination(char *combination, int length) {
    for (int i = 0; i < length; i++) {
        combination[i] = COLORS[rand() % NUM_COLORS];
    }
}

void get_guess(char *guess, int length) {
    printf("Veuillez entrer votre combinaison (%d lettres parmi R, V, B, J, O, M) : ", length);
    for (int i = 0; i < length; i++) {
        scanf(" %c", &guess[i]);
        // Convertir en majuscule si l'utilisateur entre une lettre en minuscule
        if (guess[i] >= 'a' && guess[i] <= 'z') {
            guess[i] -= 'a' - 'A';
        }
    }
}

void evaluate_guess(char *secret, char *guess, int length, int *correct_position, int *correct_color) {
    int *checked_secret = (int *)calloc(length, sizeof(int));
    int *checked_guess = (int *)calloc(length, sizeof(int));
    
    *correct_position = 0;
    *correct_color = 0;
    
    // Vérifier les bonnes positions
    for (int i = 0; i < length; i++) {
        if (guess[i] == secret[i]) {
            (*correct_position)++;
            checked_secret[i] = 1;
            checked_guess[i] = 1;
        }
    }
    
    // Vérifier les bonnes couleurs
    for (int i = 0; i < length; i++) {
        if (!checked_guess[i]) {
            for (int j = 0; j < length; j++) {
                if (!checked_secret[j] && guess[i] == secret[j]) {
                    (*correct_color)++;
                    checked_secret[j] = 1;
                    break;
                }
            }
        }
    }
    
    free(checked_secret);
    free(checked_guess);
}

void print_combination(char *combination, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", combination[i]);
    }
    printf("\n");
}