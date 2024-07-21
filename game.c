//***************************************************************************
//  PROGRAMME : game.c
//  DATE      : 21/07/2024
//  OBJET     : Mastermind
//  AUTEUR(S) : Arrieumerlou Pablo Benfrid Gaultier Lara Florian
//***************************************************************************


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "utils.h"

#define MAX_ATTEMPTS 10

static char *secret_combination;

void init_game() {
    srand(time(NULL));
    secret_combination = (char *)malloc(COMBINATION_LENGTH * sizeof(char));
    generate_combination(secret_combination, COMBINATION_LENGTH);
}

void play_game() {
    int attempts = 0;
    char guess[COMBINATION_LENGTH];
    
    printf("Bienvenue au jeu de Mastermind!\n");
    printf("Devinez la combinaison de %d couleurs (R, V, B, J, O, M).\n", COMBINATION_LENGTH);
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Essai %d/%d : ", attempts + 1, MAX_ATTEMPTS);
        get_guess(guess, COMBINATION_LENGTH);
        
        int correct_position, correct_color;
        evaluate_guess(secret_combination, guess, COMBINATION_LENGTH, &correct_position, &correct_color);
        
        if (correct_position == COMBINATION_LENGTH) {
            printf("Félicitations! Vous avez trouvé la combinaison secrète!\n");
            return;
        } else {
            printf("Couleurs bien placées: %d, Couleurs correctes mais mal placées: %d\n", correct_position, correct_color);
        }
        
        attempts++;
    }
    
    printf("Désolé, vous avez épuisé tous vos essais. La combinaison secrète était : ");
    print_combination(secret_combination, COMBINATION_LENGTH);
}

void cleanup_game() {
    free(secret_combination);
}