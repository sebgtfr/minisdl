/*
** addon_opengl.c for minisdl/opengl in /home/le-mai_s/librairie/minisdl1.x
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sat Jun  6 08:31:49 2015 sebastien le-maire
** Last update Tue Jun 23 09:49:39 2015 sebastien le-maire
*/

#include "minisdl.h"

int     msdl_add_mogl(t_msdl *msdl, void (*fct_miniopengl)())
{
  msdl->fct_mogl = fct_miniopengl;
  return (EXIT_SUCCESS);
}
