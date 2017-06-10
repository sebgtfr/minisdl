/*
** player.h for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Nov 12 20:07:33 2015 sebastien le-maire
** Last update Sun Nov 15 16:45:04 2015 sebastien le-maire
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# include "map.h"

# define RAD(a) (((a) * M_PI) / 180)

class	player
{
 public:
  player(const double pos_x, const double pos_y, const double angle);
  ~player();

  void	        move(map *map);

  void	        init_virtual_screen(const unsigned int win_x,
				    const unsigned int columns);

  double	get_distance(map *map);

  void		set_move_up_down(const int move_up_down);

  void		set_move_left_right(const int move_left_right);

  void		set_angle(const int angle);

  bool	        validate(map *map) const;

  double	get_angle(void) const;

 private:
  double	m_pos_player[2];
  double	m_pos_virtual_screen[2];
  int		m_move_up_down;
  int		m_move_left_right;
  double	m_angle;
  double        m_distance;

};

#endif /* !PLAYER_H_ */
