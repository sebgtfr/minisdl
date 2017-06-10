//
// map.cpp for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/include
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Thu Nov 12 20:23:42 2015 sebastien le-maire
// Last update Sun Nov 15 16:26:32 2015 sebastien le-maire
//

#include <iostream>
#include "map.h"

map::map()
{
}

map::map(const unsigned int width, const unsigned int height)
{
  unsigned int	i;

  i = 0;
  m_map = new int *[height];
  while (i < height)
    {
      m_map[i] = new int[width];
      ++i;
    }
  m_width = width;
  m_height = height;
}

map::~map()
{
  unsigned int	i;

  i = 0;
  while (i < m_height)
    {
      delete[] m_map[i];
      ++i;
    }
  delete[] m_map;
}

void		map::set_elem(const unsigned int x, const unsigned int y,
			      const int elem)
{
  m_map[y][x] = elem;
}

int		map::get_elem(const unsigned int x, const unsigned int y) const
{
  return (m_map[y][x]);
}

unsigned int	map::width(void) const
{
  return (m_width);
}

unsigned int	map::height(void) const
{
  return (m_height);
}

bool		map::validate(void) const
{
  unsigned int	y;
  unsigned int	x;

  y = 0;
  while (y < m_height)
    {
      x = 0;
      while (x < m_width)
	{
	  if ((((!x) || (x == (m_width - 1))) && (m_map[y][x] == 0)) ||
	      (((!y) || (y == (m_height - 1))) && (m_map[y][x] == 0)))
	    {
	      std::cerr << "Error: edge of map should not be a path !"
			<< std::endl;
	      return (false);
	    }
	  ++x;
	}
      ++y;
    }
  return (true);
}
