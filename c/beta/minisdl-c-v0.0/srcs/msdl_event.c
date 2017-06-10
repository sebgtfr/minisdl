/*
** msdl_event.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May 27 20:11:14 2015 sebastien le-maire
** Last update Wed Nov 11 19:16:32 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_key_autorepeaton(int wait, int period)
{
  SDL_EnableKeyRepeat(wait, period);
}

void	msdl_key_event(t_msdl *msdl, void (*fct_keypress)(),
		       void (*fct_keyrelease)())
{
  msdl->key[0] = fct_keypress;
  msdl->key[1] = fct_keyrelease;
}

void	msdl_mouse_event(t_msdl *msdl, void (*fct_mousepress)(),
			 void (*fct_mouserelease)(), void (*fct_mousemotion)())
{
  msdl->mouse[0] = fct_mousepress;
  msdl->mouse[1] = fct_mouserelease;
  msdl->motion = fct_mousemotion;
}

void		msdl_event_loop(t_msdl *msdl, void *param)
{
  SDL_Event	event;

  msdl->continu = 1;
  while (msdl->continu)
    {
      if (msdl->fct_loop != NULL || msdl->fct_mogl != NULL)
	msdl_poll_event(msdl, param, &event);
      else
	{
	  SDL_WaitEvent(&event);
	  if (event.type == SDL_QUIT)
	    msdl->continu = 0;
	  else if (msdl->key[0] && event.type == SDL_KEYDOWN)
	    msdl->key[0](msdl, event.key.keysym.sym, event.key.keysym.mod, param);
	  else if (msdl->key[1] && event.type == SDL_KEYUP)
	    msdl->key[1](msdl, event.key.keysym.sym, event.key.keysym.mod, param);
	  else
	    msdl_event_next(msdl, param, &event);
	}
      if (msdl->fct_loop)
	msdl->fct_loop(msdl, param);
      if (msdl->fct_mogl)
	msdl->fct_mogl(param);
    }
}

void		msdl_event_next(t_msdl *msdl, void *param,
				SDL_Event *event)
{
  if (msdl->mouse[0] && event->type == SDL_MOUSEBUTTONDOWN)
    {
      msdl->ms.x = event->button.x;
      msdl->ms.y = event->button.y;
      msdl->mouse[0](msdl, event->button.button, msdl->ms, param);
    }
  else if (msdl->mouse[1] && event->type == SDL_MOUSEBUTTONUP)
    {
      msdl->ms.x = event->button.x;
      msdl->ms.y = event->button.y;
      msdl->mouse[1](msdl, event->button.button, msdl->ms, param);
    }
  else if (msdl->motion && event->type == SDL_MOUSEMOTION)
    msdl->motion(msdl, event->button.x, event->button.y, param);
}
