/*
** msdl_convert.c for minisdl.h in /home/le-mai_s/librairie/minisdl1.x/sources
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Fri Aug 14 20:49:08 2015 sebastien le-maire
** Last update Fri Aug 14 22:04:50 2015 sebastien le-maire
*/

#include <stdlib.h>
#include "minisdl.h"

char		*msdl_init_string(int *nb, unsigned int *x,
				  unsigned int *d, int *s)
{
  if ((*nb) < 0)
    {
      (*nb) *= -1;
      ++(*x);
      (*s) = -1;
    }
  else
    (*s) = 1;
  while (((*nb) / (*d)) > 1)
    {
      ++(*x);
      (*d) *= 10;
    }
  return (malloc(sizeof(char) * ((*x) + 1)));
}

char		*msdl_int_to_char(int nb)
{
  unsigned int	x;
  unsigned int	d;
  unsigned int	y;
  char		*nbr;
  int		s;

  x = 0;
  d = 1;
  if (!(nbr = msdl_init_string(&nb, &x, &d, &s)))
    return (NULL);
  if (s < 0)
    nbr[0] = '-';
  y = (s < 0) ? 1 : 0;
  while (y < x)
    {
      d /= 10;
      nbr[y++] = ((nb / d) % 10) + '0';
    }
  nbr[y] = '\0';
  return (nbr);
}

unsigned int	msdl_strlen(char *str, char *str2)
{
  unsigned int	i;
  unsigned int	cpt;

  i = 0;
  cpt = 0;
  while (str[i])
    {
      ++cpt;
      ++i;
    }
  i = 0;
  while (str2[i])
    {
      ++cpt;
      ++i;
    }
  ++cpt;
  return (cpt);
}

char		*msdl_concat_string(char *dec, char *rel,
				    const unsigned int size)
{
  char		*tmp;
  unsigned int	x;
  unsigned int	y;

  if (!(tmp = malloc(sizeof(char) * (size + 1))))
    return (NULL);
  x = 0;
  y = 0;
  while (dec[x])
    tmp[y++] = dec[x++];
  if (rel[0])
    tmp[y++] = '.';
  x = 0;
  while (rel[x])
    tmp[y++] = rel[x++];
  tmp[y] = '\0';
  return (tmp);
}

char		*msdl_double_to_char(double nb, unsigned int rel)
{
  char		*nb_dec;
  char		*nb_rel;
  char		*nb_final;
  unsigned int	x;
  unsigned int	d;

  if (!(nb_dec = msdl_int_to_char(((int)nb))))
    return (NULL);
  nb = (nb < 0) ? -nb : nb;
  while (nb >= 1)
    --nb;
  rel = (rel > 6) ? 6: rel;
  d = 1;
  while (((rel)--) > 0)
    d *= 10;
  nb *= d;
  if (!(nb_rel = msdl_int_to_char(((int)nb))))
    return (NULL);
  x = msdl_strlen(nb_dec, nb_rel);
  if (!(nb_final = msdl_concat_string(nb_dec, nb_rel, x)))
    return (NULL);
  free(nb_dec);
  free(nb_rel);
  return (nb_final);
}
