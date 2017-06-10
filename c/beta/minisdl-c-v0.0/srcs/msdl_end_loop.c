/*
** msdl_end_loop.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Fri May 29 10:00:33 2015 sebastien le-maire
** Last update Fri May 29 10:01:59 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_end_loop(t_msdl *msdl)
{
  msdl->continu = 0;
}
