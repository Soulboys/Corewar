/*
** EPITECH PROJECT, 2018
** my_nbrlen.c
** File description:
** my_nbrlen
*/

int my_nbrlen(int nbr)
{
    int i;

    for (i = 1; nbr > 9; i++) {
        nbr = nbr / 10;
    }
    return (i);
}
