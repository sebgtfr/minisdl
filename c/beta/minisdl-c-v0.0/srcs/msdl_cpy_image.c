/*
** msdl_cpy_image.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Tue Jun  2 10:26:04 2015 sebastien le-maire
** Last update Tue Jun  2 10:28:03 2015 sebastien le-maire
*/

#include "minisdl.h"

void	msdl_cpy_image(t_img *img_dest, t_img *img_src)
{
  img_dest->img = img_src->img;
}
