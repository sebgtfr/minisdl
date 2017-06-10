/*
** msdl_state_audio.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Mon Jun  1 11:19:31 2015 sebastien le-maire
** Last update Mon Jun  1 11:20:12 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

int	msdl_playing_mode(void)
{
  return (Mix_PlayingMusic());
}

int	msdl_paused_mode(void)
{
  return (Mix_PausedMusic());
}
