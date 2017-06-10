/*
** msdl_time.c for minisdl in /home/le-mai_s/recode/SDL/minisdl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Thu May 28 23:05:41 2015 sebastien le-maire
** Last update Sun Jun  7 15:33:29 2015 sebastien le-maire
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include "minisdl.h"

void	msdl_sleep(int millisecond)
{
  SDL_Delay(millisecond);
}

unsigned int	msdl_get_time(void)
{
  return (SDL_GetTicks());
}

void	msdl_add_timer(t_timer *timer, int period,
		       Uint32 (*fct_callback)(), void *param)
{
  timer->id_timer = SDL_AddTimer(period, fct_callback, param);
}

void	msdl_destroy_timer(t_timer *timer)
{
  SDL_RemoveTimer(timer->id_timer);
}
