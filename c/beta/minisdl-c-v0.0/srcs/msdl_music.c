/*
** msdl_music.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Mon Jun  1 09:58:34 2015 sebastien le-maire
** Last update Fri Jun  5 15:19:28 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

int	msdl_music_init(int frequency)
{
  return (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT,
			MIX_DEFAULT_CHANNELS, 1024));
}

void	msdl_save_music(t_music *music, char *name_music)
{
  music->m = Mix_LoadMUS(name_music);
}

void	msdl_destroy_music(t_music *music)
{
  Mix_FreeMusic(music->m);
}

void	msdl_play_music(t_music *music, int loop)
{
  Mix_PlayMusic(music->m, loop);
}

void	msdl_music_end(void)
{
  Mix_CloseAudio();
}
