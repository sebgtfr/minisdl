//
// player.cpp for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Thu Nov 12 20:07:59 2015 sebastien le-maire
// Last update Mon Nov 16 21:32:28 2015 sebastien le-maire
//

#include <iostream>
#include <math.h>
#include "player.h"

player::player(const double pos_x, const double pos_y, const double angle)
{
  m_pos_player[0] = pos_x;
  m_pos_player[1] = pos_y;
  m_angle = angle;
  m_move_up_down = 0;
  m_move_left_right = 0;
}

player::~player()
{
}

void		player::move(map *map)
{
  double	pos[2];

  pos[0] = m_pos_player[0] + (0.08 * m_move_up_down) * cos(RAD(m_angle));
  pos[1] = m_pos_player[1] + (0.08 * m_move_up_down) * sin(RAD(m_angle));
  if (((int)pos[0] > 0) && ((unsigned int)pos[0] < map->width()) &&
      ((int)pos[1] > 0) && ((unsigned int)pos[1] < map->height()) &&
      (map->get_elem((unsigned int)pos[0], (unsigned int)pos[1]) == 0))
    {
      m_pos_player[0] = pos[0];
      m_pos_player[1] = pos[1];
    }
  m_angle += m_move_left_right;
}

void		player::init_virtual_screen(const unsigned int win_x,
					    const unsigned int columns)
{
  double	tmp;

  m_pos_virtual_screen[0] = 0.5;
  m_pos_virtual_screen[1] = (((win_x / 2) - ((double)columns)) / win_x);
  tmp = m_pos_virtual_screen[0];
  m_pos_virtual_screen[0] = (((tmp) * cos(RAD(m_angle))) -
			     (m_pos_virtual_screen[1] * sin(RAD(m_angle))));
  m_pos_virtual_screen[1] = (((tmp) * sin(RAD(m_angle))) +
			     (m_pos_virtual_screen[1] * cos(RAD(m_angle))));
  m_pos_virtual_screen[0] += m_pos_player[0];
  m_pos_virtual_screen[1] += m_pos_player[1];
}

double		player::get_distance(map *map)
{
  double	pos[2];
  unsigned int	i;

  m_distance = 1;
  i = 0;
  while (i < 2)
    {
      pos[i] = (double)(m_pos_player[i] + m_distance *
			(m_pos_virtual_screen[i] - m_pos_player[i]));
      ++i;
    }
  while (map->get_elem(pos[0], pos[1]) == 0)
    {
      m_distance += 0.005;
      i = 0;
      while (i < 2)
	{
	  pos[i] = (double)(m_pos_player[i] + m_distance *
			    (m_pos_virtual_screen[i] - m_pos_player[i]));
	  ++i;
	}
    }
  return (m_distance);
}

void		player::set_move_up_down(const int move_up_down)
{
  m_move_up_down = move_up_down;
}

void		player::set_move_left_right(const int move_left_right)
{
  m_move_left_right = move_left_right;
}

void		player::set_angle(const int angle)
{
  m_angle = (double)angle;
}

bool		player::validate(map *field) const
{
  if (field->get_elem((unsigned int)m_pos_player[0],
		      (unsigned int)m_pos_player[1]))
    {
      std::cerr << "Error: player should be on path !" << std::endl;
      return (false);
    }
  return (true);
}

double		player::get_angle(void) const
{
  return (m_angle);
}
