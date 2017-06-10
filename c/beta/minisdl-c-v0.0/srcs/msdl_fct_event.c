/*
** msdl_fct_event.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu May 28 23:29:46 2015 sebastien le-maire
** Last update Wed Nov 11 19:16:58 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_fct_loop_event(t_msdl *msdl, void (*fct_main)())
{
  msdl->fct_loop = fct_main;
}
