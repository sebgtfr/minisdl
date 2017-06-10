//
// main.cpp for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Thu Nov 12 19:55:07 2015 sebastien le-maire
// Last update Wed Jan 27 15:22:20 2016 Sébastien Le Maire
//

#include <iostream>
#include <stdlib.h>
#include "wolf.h"

static bool		keypress(msdl::Screen &screen,
				 SDLKey key, SDLMod mode, void *param)
{
  int		move;
  t_game	*game;

  if (key == SDLK_ESCAPE)
    return (false);
  game = (t_game *)param;
  if (key == SDLK_UP || key == SDLK_DOWN)
    {
      move = (key == SDLK_UP) ? 1 : -1;
      move = (COND_SIMULT_KEY_LSHIFT) ? (move * 2) : move;
      game->play->set_move_up_down(move);
    }
  else if (key == SDLK_LEFT || key == SDLK_RIGHT)
    {
      move = (key == SDLK_LEFT) ? 6 : -6;
      game->play->set_move_left_right(move);
    }
  else if (key == SDLK_f)
    screen.switch_fullscreen();
  return (true);
}

static bool		keyrelease(__attribute__((unused))msdl::Screen &screen,
				   SDLKey key,
				   __attribute__((unused))SDLMod mode,
				   void *param)
{
  t_game	*game;

  game = (t_game *)param;
  if (key == SDLK_UP || key == SDLK_DOWN)
    game->play->set_move_up_down(0);
  else if (key == SDLK_LEFT || key == SDLK_RIGHT)
    game->play->set_move_left_right(0);
  return (true);
}

static bool	wolf(msdl::Screen &screen, void *param)
{
  t_game	*game;

  game = (t_game *)param;
  game->play->move(game->field);
  raycasting(screen, game);
  screen.update();
  return (true);
}

int		main(void)
{
  msdl::Screen	screen;
  msdl::Event	event;
  t_game	game;

  game.music = new msdl::Music();
  if ((!(get_file(game))) || (!(msdl::activate_music())) ||
      (!(game.music->init(MUSIC_PATH))) ||
      (!(screen.init(FULLSCREEN_ON, WIN_X, WIN_Y, "Wolf3D Minisdl c++ !"))))
    return (EXIT_FAILURE);
  game.music->play();
  event.set_key(keypress, keyrelease);
  event.set_fct_loop(wolf);
  event.state(MSDL_MOUSE_EVENT, false);
  event.loop(screen, &game, 50);
  delete game.field;
  delete game.play;
  delete game.music;
  msdl::desactivate_music();
  return (EXIT_SUCCESS);
}
