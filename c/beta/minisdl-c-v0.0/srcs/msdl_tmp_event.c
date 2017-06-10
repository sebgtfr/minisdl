/*
** msdl_tmp_event.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed Jun 10 21:58:05 2015 sebastien le-maire
** Last update Wed Jun 10 22:10:53 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_tmp_keypress_event(t_msdl *msdl, t_event *event,
				  void (*fct)(), void *param)
{
  SDL_WaitEvent(&(event->ev));
  if (fct && event->ev.type == SDL_KEYDOWN)
    fct(msdl, event->ev.key.keysym.sym, event->ev.key.keysym.mod, param);
}

void	msdl_tmp_keyrelease_event(t_msdl *msdl, t_event *event,
				    void (*fct)(), void *param)
{
  SDL_WaitEvent(&(event->ev));
  if (fct && event->ev.type == SDL_KEYUP)
    fct(msdl, event->ev.key.keysym.sym, event->ev.key.keysym.mod, param);
}

void	msdl_tmp_mousepress_event(t_msdl *msdl, t_event *event,
				    void (*fct)(), void *param)
{
  SDL_WaitEvent(&(event->ev));
  if (fct && event->ev.type == SDL_MOUSEBUTTONDOWN)
    {
      msdl->ms.x = event->ev.button.x;
      msdl->ms.y = event->ev.button.y;
      fct(msdl, event->ev.button.button, msdl->ms, param);
    }
}

void	msdl_tmp_mouserelease_event(t_msdl *msdl, t_event *event,
				    void (*fct)(), void *param)
{
  SDL_WaitEvent(&(event->ev));
  if (fct && event->ev.type == SDL_MOUSEBUTTONUP)
    {
      msdl->ms.x = event->ev.button.x;
      msdl->ms.y = event->ev.button.y;
      fct(msdl, event->ev.button.button, msdl->ms, param);
    }
}

void	msdl_tmp_mousemotion_event(t_msdl *msdl, t_event *event,
				     void (*fct)(), void *param)
{
  SDL_WaitEvent(&(event->ev));
  if (fct && event->ev.type == SDL_MOUSEMOTION)
    fct(msdl, event->ev.button.x, event->ev.button.x, param);
}
