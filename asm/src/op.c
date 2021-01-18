/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Tue Mar 22 16:44:20 2011 Astek
*/

#include "../include/my.h"
#include "lib.h"
#include "op.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", &fct_live, 0},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", &fct_ld, 1},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", &fct_st, 1},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", &fct_add, 1},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", &fct_sub, 1},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3", &fct_and, 1},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", &fct_xor, 1},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", &fct_or, 1}/*,
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", &fct_zjmp, 0},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", &fct_ldi, 1},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", &fct_sti, 1},
    {"fork", 1, {T_DIR}, 12, 800, "fork", &fct_fork, 0},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", &fct_lld, 1},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", &fct_lldi, 1},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", &fct_lfork, 0},
    {"aff", 1, {T_REG}, 16, 2, "aff", &fct_aff, 0},
    {0, 0, {0}, 0, 0, 0, 0}*/
  };
