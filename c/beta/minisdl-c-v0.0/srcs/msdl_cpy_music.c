/*
** msdl_cpy_music.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Thu Jun 11 11:52:24 2015 sebastien le-maire
** Last update Thu Jun 11 11:54:15 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

void	msdl_cpy_music(t_music *dest, t_music *src)
{
  dest->m = src->m;
}

void	msdl_cpy_sound(t_sound *dest, t_sound *src)
{
  dest->s = src->s;
}
