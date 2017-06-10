//
// raycasting.cpp for wolf3d_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Nov 14 21:33:41 2015 sebastien le-maire
// Last update Mon Nov 23 20:54:03 2015 sebastien le-maire
//

#include "wolf.h"
#include <iostream>

unsigned int	draw(const unsigned int *window, const unsigned int *wall_data,
		     t_game *game, msdl::Screen &screen)
{
  msdl::Image	*wall;
  unsigned int	pix;

  if (window[1] > wall_data[2])
    {
      pix = window[1] - (screen.height() / 2) - 20;
      if (pix > 0xFF)
	pix = 0xFF;
      screen.put_pixel(window[0], window[1], (pix << 8));
      return (window[1]);
    }
  wall = new msdl::Image();
  pix = 0x66 / game->play->get_distance(game->field);
  wall->init(1, wall_data[0] * 2, ((pix << 16) | (pix << 8) | pix));
  screen.blit(*wall, window[0], window[1]);
  delete wall;
  return (wall_data[2]);
}

void		raycasting(msdl::Screen &screen, t_game *game)
{
  unsigned int  window[2];
  unsigned int  wall_data[3];

  window[0] = 0;
  while (window[0] < screen.width())
    {
      game->play->init_virtual_screen(screen.width(), window[0]);
      wall_data[0] = (screen.height() /
		      (2 * game->play->get_distance(game->field)));
      window[1] = 0;
      wall_data[1] = ((screen.height() / 2) - wall_data[0]);
      wall_data[2] = ((screen.height() / 2) + wall_data[0]);
      while (window[1] < screen.height())
	{
	  if (window[1] < wall_data[1])
	    screen.put_pixel(window[0], window[1], 0x003366);
	  else
	    window[1] = draw(window, wall_data, game, screen);
	  ++window[1];
	}
      ++window[0];
    }
}
