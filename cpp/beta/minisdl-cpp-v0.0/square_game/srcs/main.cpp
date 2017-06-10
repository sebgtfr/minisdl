//
// main.cpp for carre in /home/le-mai_s/librairie/minisdl_cpp/carre_game/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Nov 23 20:07:39 2015 sebastien le-maire
// Last update Wed Jan 27 15:25:14 2016 Sébastien Le Maire
//

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "square.h"

static bool		keypress(__attribute__((unused))msdl::Screen &screen,
				 SDLKey key,
				 __attribute__((unused))SDLMod mode,
				 __attribute__((unused))void *param)
{
  if (key == SDLK_ESCAPE)
    return (false);
  return (true);
}

int		main(void)
{
  msdl::Screen	screen;
  msdl::Event	event;
  msdl::Font	*font;

  msdl::Font::init_ttf();
  font = new msdl::Font();
  if ((!(screen.init(ALL_OFF, WIN_X, WIN_Y, "Square game !"))) ||
      (!(font->load(PATH_FONT))) ||
      (!(font->write<std::string>(static_cast<std::string>("Square !"),
				  screen.get_surface(),
				  msdl::Font::SHADED,
				  (WIN_X / 2) - (50 * 3),
				  50, 0, 0xC1C1C1))) ||
      (!(font->write<double>(3.14,
      			  screen.get_surface(),
      			  msdl::Font::SHADED,
      			  (WIN_X / 2) - (50 * 3),
      			  250, 0, 0xC1C1C1))))
    return (EXIT_FAILURE);

  screen.update();
  event.set_key(keypress);
  event.state();
  event.loop(screen, NULL, 50);
  delete font;
  msdl::Font::close_ttf();
  return (EXIT_SUCCESS);
}
