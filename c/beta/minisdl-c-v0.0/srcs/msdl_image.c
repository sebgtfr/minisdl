/*
** msdl_image.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed May 27 19:00:03 2015 sebastien le-maire
** Last update Sun Jun  7 15:11:48 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

int	msdl_save_image_bmp(t_img *param_img, char *name_img)
{
  if ((param_img->img = SDL_LoadBMP(name_img)) == NULL)
    return (1);
  return (0);
}

void		msdl_put_image(t_msdl *msdl, t_img *param_img, int x, int y)
{
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  SDL_BlitSurface(param_img->img, NULL, msdl->scrn, &pos);
}

void	msdl_put_icon(char *name_img)
{
  SDL_WM_SetIcon(IMG_Load(name_img), NULL);
}

void	msdl_add_transparence_to_color_in_image(t_img *param_img,
						int color)
{
  int		r;
  int		g;
  int		b;

  r = color >> 16;
  g = (color >> 8) - (r << 8);
  b = color - ((g << 8) + (r << 16));
  SDL_SetColorKey(param_img->img, SDL_SRCCOLORKEY,
		  SDL_MapRGB(param_img->img->format, r, g, b));
}

void	msdl_add_alpha_to_image(t_img *param_img, char transparency)
{
  SDL_SetAlpha(param_img->img, SDL_SRCALPHA, ((int)transparency));
}
