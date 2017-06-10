/*
** msdl_pixel_put.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May 27 18:36:15 2015 sebastien le-maire
** Last update Sun Sep 20 12:53:34 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_pixel_put(t_msdl *msdl, int x, int y, unsigned int color)
{
  ((unsigned int *)msdl->scrn->pixels)[POS] = color;
}

void		msdl_surface_init_pos(t_surface *pos_size, int x, int y)
{
  pos_size->xp = x;
  pos_size->yp = y;
}

void		msdl_surface_init_size(t_surface *pos_size, int x, int y)
{
  pos_size->xs = x;
  pos_size->ys = y;
}

int		msdl_create_surface(t_msdl *msdl, t_surface *pos_size,
				    int color)
{
  int		r;
  int		g;
  int		b;
  SDL_Surface	*pixel;
  SDL_Rect	pos;

  if (!(pixel = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF,
				     pos_size->xs, pos_size->ys,
				     32, 0, 0, 0, 0)))
    return (1);
  r = ((color >> 16) & 0xFF);
  g = ((color >> 8) & 0xFF);
  b = (color & 0xFF);
  SDL_FillRect(pixel, NULL, SDL_MapRGB(msdl->scrn->format, r, g, b));
  pos.x = pos_size->xp;
  pos.y = pos_size->yp;
  SDL_BlitSurface(pixel, NULL, msdl->scrn, &pos);
  SDL_FreeSurface(pixel);
  return (0);
}
