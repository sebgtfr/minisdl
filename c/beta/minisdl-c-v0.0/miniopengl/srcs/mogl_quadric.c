/*
** mogl_quadric.c for miniopengl in /home/le-mai_s/librairie/miniopengl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed Jun 17 17:40:14 2015 sebastien le-maire
** Last update Wed Jun 17 18:15:03 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_init_quadric(t_quadric *quadric, int slices)
{
  quadric->q = gluNewQuadric();
  quadric->s = slices;
}

void	mogl_quadric_style(t_quadric *quadric, int style)
{
  gluQuadricDrawStyle(quadric->q, style);
}

void	mogl_destroy_quadric(t_quadric *quadric)
{
  gluDeleteQuadric(quadric->q);
}
