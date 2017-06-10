/*
** msdl_destroy_img.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Thu May 28 11:49:57 2015 sebastien le-maire
** Last update Thu May 28 11:51:29 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_destroy_image(t_img *param_img)
{
  SDL_FreeSurface(param_img->img);
}
