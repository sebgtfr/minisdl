//
// parsing.cpp for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Fri Nov 13 22:06:24 2015 sebastien le-maire
// Last update Sat Nov 14 23:41:26 2015 sebastien le-maire
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "wolf.h"

static player	*get_player_elem(std::ifstream &file, player *play)
{
  std::string   line;
  std::string	elem[3] = {"pos_x=", "pos_y=", "angle="};
  double	pos_angle[3] = {-1, -1, -1};
  int		i;
  int		j;

  i = -1;
  while (((++i) < 3) && (getline(file, line)))
    {
      j = 0;
      while (elem[j].compare(line.substr(0, 6)))
	++j;
      if (j < 3)
	pos_angle[j] = atof(line.c_str() + 6);
    }
  i = -1;
  while ((++i) < 3)
    if (pos_angle[i] < 0)
      {
	std::cerr << "Error: " << elem[i].substr(0, 5);
	return (NULL);
      }
  play = new player(pos_angle[0], pos_angle[1], pos_angle[2]);
  return (play);
}

static bool	get_elem_line(const char *line, map *field,
			      const unsigned int y)
{
  unsigned int	x;
  unsigned int	i;

  x = 0;
  i = 0;
  while (line[i] && (x < field->width()))
    {
      if (line[i] == '0' || line[i] == '1')
	{
	  field->set_elem(x, y, line[i] - '0');
	  ++x;
	}
      ++i;
    }
  if ((x != field->width()) || (line[i]))
    {
      std::cerr << "Error: line " << (y + 1) << " of map is invalid !"
		<< std::endl;
      return (false);
    }
  return (true);
}

static bool	get_elem_map(std::ifstream &file, map *field)
{
  std::string	line;
  unsigned int	y;
  bool		begin_get_elem;

  y = 0;
  begin_get_elem = false;
  while ((getline(file, line)) && (y < field->height()))
    {
      if (line != "")
	{
	  if (begin_get_elem)
	    {
	      if (!(get_elem_line(line.c_str(), field, y++)))
		return (false);
	    }
	  else if ((!begin_get_elem) && (!line.compare("map=")))
	    begin_get_elem = true;
	}
    }
  return (true);
}

static bool	get_size_map(std::ifstream &file, unsigned int *size)
{
  int		i;
  int		j;
  int		nb;
  std::string	sizestr[2] = {"width=", "height="};
  std::string	line;

  i = -1;
  while (((++(i)) < 2) && (getline(file, line)))
    {
      j = -1;
      while ((++(j)) < 2)
	{
	  if ((!(sizestr[j].compare(line.substr(0, 6 + j)))) &&
	      ((nb = atoi(line.c_str() + (6 + j))) >= 0))
	    size[j] = (unsigned int)nb;
	}
    }
  i = -1;
  while ((++(i)) < 2)
    if (!size[i])
      {
	std::cerr << "Error: " << sizestr[i].substr(0, 5 + i);
	return (false);
      }
  return (true);
}

bool		get_file(t_game &game)
{
  std::ifstream	file;
  std::string	filename;
  unsigned int  size[2] = {0, 0};

  std::cout << "Entrez le nom du ficher contenant la map : ";
  std::cin >> filename;
  file.open(filename.c_str(), std::ios::in);
  if (file.fail())
    {
      std::cerr << "Error: " << filename << " open failed !" << std::endl;
      return (false);
    }
  if ((!(game.play = get_player_elem(file, game.play))) ||
      (!(get_size_map(file, size))))
    {
      std::cerr << " is missing or is invalid !" << std::endl;
      return (false);
    }
  game.field = new map(size[0], size[1]);
  if ((!(get_elem_map(file, game.field))) || (!(game.field->validate())) ||
      (!(game.play->validate(game.field))))
    return (false);
  file.close();
  return (true);
}
