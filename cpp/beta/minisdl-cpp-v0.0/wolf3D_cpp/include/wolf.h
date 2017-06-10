/*
** wolf.h for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Nov 12 20:03:22 2015 sebastien le-maire
** Last update Wed Jan 27 15:22:24 2016 Sébastien Le Maire
*/

#ifndef WOLF_H_
# define WOLF_H_

# include "minisdl.hpp"
# include "map.h"
# include "player.h"

# define WIN_X		(1920)
# define WIN_Y		(1080)

# define MUSIC_PATH	"./musics/luigi_mansion_theme.wav"

typedef	struct		s_game
{
  map			*field;
  player	        *play;
  msdl::Music		*music;
}			t_game;

bool		get_file(t_game &game);
void		raycasting(msdl::Screen &screen, t_game *game);

#endif /* !WOLF_H_ */
