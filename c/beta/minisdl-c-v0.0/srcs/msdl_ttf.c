/*
** msdl_ttf.c for minisdl in /home/le-mai_s/librairie/minisdl1.x/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Fri Aug 14 15:41:27 2015 sebastien le-maire
** Last update Fri Aug 14 20:49:26 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

int	msdl_init_ttf(t_msdl *msdl, const char *font_name,
		      const unsigned int font_size,
		      const unsigned char style)
{
  if (TTF_Init() == -1)
    return (-1);
  if (!(msdl->font = TTF_OpenFont(font_name, font_size)))
    return (-1);
  msdl->solid_blended[SOLID] = TTF_RenderText_Solid;
  msdl->solid_blended[BLENDED] = TTF_RenderText_Blended;
  msdl->style = style;
  if (style > 2)
    return (1);
  return (0);
}

void	msdl_quit_ttf(t_msdl *msdl)
{
  TTF_CloseFont(msdl->font);
  TTF_Quit();
}

int		msdl_prep_txt(t_msdl *msdl, const char *txt,
			      int color, int color_shaded)
{
  SDL_Color	color_txt;
  SDL_Color	color_bg;

  color_txt.r = ((color >> 16) & 0xFF);
  color_txt.g = ((color >> 8) & 0xFF);
  color_txt.b = (color & 0xFF);
  if (msdl->style == SHADED)
    {
      color_bg.r = ((color_shaded >> 16) & 0xFF);
      color_bg.g = ((color_shaded >> 8) & 0xFF);;
      color_bg.b = (color_shaded & 0xFF);
      if (!(msdl->text =
	    TTF_RenderText_Shaded(msdl->font, txt, color_txt, color_bg)))
	return (1);
    }
  else
    if (!(msdl->text =
	  msdl->solid_blended[msdl->style](msdl->font, txt, color_txt)))
      return (1);
  return (0);
}

void		msdl_put_string(t_msdl *msdl, const int x, const int y)
{
  SDL_Rect	pos;

  pos.x = x;
  pos.y = y;
  SDL_BlitSurface(msdl->text, NULL, msdl->scrn, &pos);
}
