/*
** mogl_transformation.c for miniopengl in /home/le-mai_s/librairie/miniopengl_tmp
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat Jun  6 19:23:41 2015 sebastien le-maire
** Last update Sat Jun  6 19:36:31 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_translation(double x, double y, double z)
{
  glTranslated(x, y, z);
}

void	mogl_rotation(double angle, double x, double y, double z)
{
  glRotated(angle, x, y, z);
}

void	mogl_scale(float x, float y, float z)
{
  glScalef(x, y, z);
}
