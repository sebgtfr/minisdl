/*
** msdl_handles_audio.c for minisdl in /home/le-mai_s/librairie/minisdl1.x
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Jun  1 10:51:01 2015 sebastien le-maire
** Last update Tue Jun 23 18:52:48 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

void	msdl_pause_music(void)
{
  Mix_PauseMusic();
}

void	msdl_regain_music(void)
{
  Mix_ResumeMusic();
}

void	msdl_replay_music(void)
{
  Mix_RewindMusic();
}

int	msdl_volume_music(unsigned int volume)
{
  if (volume > 128)
    return (-1);
  Mix_VolumeMusic(volume);
  return (0);
}

void	msdl_stop_music(void)
{
  Mix_HaltMusic();
}
