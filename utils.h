//***************************************************************************
//  PROGRAMME : utils.h
//  DATE      : 21/07/2024
//  OBJET     : Mastermind
//  AUTEUR(S) : Arrieumerlou Pablo Benfrid Gaultier Lara Florian
//***************************************************************************

#ifndef UTILS_H
#define UTILS_H

#define NUM_COLORS 6
#define COMBINATION_LENGTH 4

void generate_combination(char *combination, int length);
void get_guess(char *guess, int length);
void evaluate_guess(char *secret, char *guess, int length, int *correct_position, int *correct_color);
void print_combination(char *combination, int length);

#endif