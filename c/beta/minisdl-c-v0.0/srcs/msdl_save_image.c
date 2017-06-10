/*
** msdl_save_image.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Fri May 29 15:33:39 2015 sebastien le-maire
** Last update Fri May 29 15:37:36 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minisdl.h"

int	msdl_save_image(t_img *param_img, char *name_img)
{
  if ((param_img->img = IMG_Load(name_img)) == NULL)
    return (1);
  return (0);
}
