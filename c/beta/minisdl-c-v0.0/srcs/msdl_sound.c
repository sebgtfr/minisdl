/*
** msdl_sound.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Jun  1 11:24:23 2015 sebastien le-maire
** Last update Tue Jun 23 18:53:39 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

void	msdl_alloc_channels(int nb_channels)
{
  Mix_AllocateChannels(nb_channels);
}

void	msdl_sound_init(t_sound *sound, char *name_sound)
{
  sound->s = Mix_LoadWAV(name_sound);
}

int	msdl_volume_sound(t_sound *sound, unsigned int volume)
{
  if (volume > 128)
    return (-1);
  Mix_VolumeChunk(sound->s, volume);
  return (EXIT_SUCCESS);
}

void	msdl_play_sound(t_sound *sound, int period)
{
  Mix_PlayChannel(-1, sound->s, period);
}

void	msdl_destroy_sound(t_sound *sound)
{
  Mix_FreeChunk(sound->s);
}
