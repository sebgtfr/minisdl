/*
** mogl_matrix.c for miniopengl in /home/le-mai_s/librairie/miniopengl_tmp
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat Jun  6 19:07:51 2015 sebastien le-maire
** Last update Sat Jun  6 19:46:02 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_init_matrix(int mode)
{
  glMatrixMode(mode);
  glLoadIdentity();
}

void	mogl_save_matrix(void)
{
  glPushMatrix();
}

void	mogl_apply_matrix(void)
{
  glPopMatrix();
}

void	mogl_reset_matrix(void)
{
  glLoadIdentity();
}
