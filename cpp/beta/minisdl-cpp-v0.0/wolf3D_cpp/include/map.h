/*
** map.h for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Thu Nov 12 20:23:37 2015 sebastien le-maire
** Last update Sun Nov 15 16:26:15 2015 sebastien le-maire
*/

#ifndef MAP_H_
# define MAP_H_

class	map
{
 public:
  map();
  map(const unsigned int width, const unsigned int height);
  ~map();

  void	        set_elem(const unsigned int x, const unsigned int y,
			 const int elem);

  int		get_elem(const unsigned int x, const unsigned int y) const;

  unsigned int	width(void) const;

  unsigned int	height(void) const;

  bool	        validate(void) const;

 private:
  int		**m_map;
  unsigned int	m_width;
  unsigned int	m_height;
};

#endif /* !MAP_H_ */
