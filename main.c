//***************************************************************************
//  PROGRAMME : main.c
//  DATE      : 21/07/2024
//  OBJET     : Mastermind
//  AUTEUR(S) : Arrieumerlou Pablo Benfrid Gaultier Lara Florian
//***************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main() {
    // Initialisation du jeu
    init_game();
    
    // Boucle de jeu principale
    play_game();
    
    // Nettoyage et fin du jeu
    cleanup_game();
    
    return 0;
}