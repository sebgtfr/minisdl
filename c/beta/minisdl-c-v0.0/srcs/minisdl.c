/*
** minisdl.c for minisdl in /home/le-mai_s/recode/SDL/test1
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May 27 17:33:58 2015 sebastien le-maire
** Last update Wed Nov 11 19:20:11 2015 sebastien le-maire
*/

#include "minisdl.h"

int	msdl_init(t_msdl *msdl, char choice_opt)
{
  msdl->key[0] = NULL;
  msdl->key[1] = NULL;
  msdl->mouse[0] = NULL;
  msdl->mouse[1] = NULL;
  msdl->motion = NULL;
  msdl->fct_loop = NULL;
  msdl->fct_mogl = NULL;
  msdl->opt_win = choice_opt;
  msdl->font = NULL;
  msdl->text = NULL;
  msdl->style = SOLID;
  msdl->solid_blended[SOLID] = NULL;
  msdl->solid_blended[BLENDED] = NULL;
  if (CT1 || CT2 || CT3 || CTO1 || CTO2 || CTO3)
    return (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER));
  else if (CA1 || CA2 || CA3 || CAO1 || CAO2 || CAO3)
    return (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO));
  else if (CTA1 || CTA2 || CTA3 || CTAO1 || CTAO2 || CTAO3)
    return (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO));
  else if (CVONLY1 || CVONLY2 || CVONLY3 || CO1 || CO2 || CO3)
    return (SDL_Init(SDL_INIT_VIDEO));
  else
    return (-1);
}

int	msdl_window(t_msdl *msdl, int width, int height, char *title)
{
  if (CT1 || CA1 || CTA1 || CVONLY1)
    msdl->scrn = SDL_SetVideoMode(width, height, 32,
				    SDL_HWSURFACE | SDL_DOUBLEBUF);
  else if (CT2 || CA2 || CTA2 || CVONLY2)
    msdl->scrn = SDL_SetVideoMode(width, height, 32,
				    SDL_HWSURFACE | SDL_DOUBLEBUF |
				    SDL_RESIZABLE);
  else if (CT3 || CA3 || CTA3 || CVONLY3)
    msdl->scrn = SDL_SetVideoMode(width, height, 32,
				    SDL_HWSURFACE | SDL_DOUBLEBUF |
				    SDL_FULLSCREEN);
  else if (CO1 || CTO1 || CAO1 || CTAO1)
    msdl->scrn = SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
  else if (CO2 || CTO2 || CAO2 || CTAO2)
    msdl->scrn = SDL_SetVideoMode(width, height, 32, SDL_OPENGL |
				    SDL_RESIZABLE);
  else if (CO3 || CTO3 || CAO3 || CTAO3)
    msdl->scrn = SDL_SetVideoMode(width, height, 32, SDL_OPENGL |
				    SDL_FULLSCREEN);
  if (!(msdl->scrn))
    return (1);
  SDL_WM_SetCaption(title, NULL);
  if (SDL_FillRect(msdl->scrn, NULL, SDL_MapRGB(msdl->scrn->format, 0, 0, 0)))
    return (2);
  return (0);
}

void	msdl_clear_window(t_msdl *msdl)
{
  SDL_FillRect(msdl->scrn, NULL, SDL_MapRGB(msdl->scrn->format, 0, 0, 0));
}

void	msdl_update_window(t_msdl *msdl)
{
  SDL_Flip(msdl->scrn);
}

void	msdl_end(t_msdl *msdl)
{
  if (CA1 || CA2 || CA3 || CTA1 || CTA2 || CTA3)
    Mix_CloseAudio();
  SDL_Quit();
}
