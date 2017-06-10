/*
** msdl_poll_event.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Jun 10 17:13:41 2015 sebastien le-maire
** Last update Mon Oct 26 22:03:24 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_poll_event(t_msdl *msdl, void *param, SDL_Event *event)
{
  while(SDL_PollEvent(event))
    {
      if (event->type == SDL_QUIT)
	msdl->continu = 0;
      else if (msdl->key[0] && event->type == SDL_KEYDOWN)
	msdl->key[0](msdl, event->key.keysym.sym, event->key.keysym.mod, param);
      else if (msdl->key[1] && event->type == SDL_KEYUP)
	msdl->key[1](msdl, event->key.keysym.sym, event->key.keysym.mod, param);
      else
	msdl_event_next(msdl, param, event);
    }
}
