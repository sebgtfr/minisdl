/*
** miniopengl.c for miniopengl in /home/le-mai_s/librairie/miniopengl_tmp
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat Jun  6 09:41:08 2015 sebastien le-maire
** Last update Mon Jun  8 10:27:45 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_create_object(int figure, void (*fct_draw)(), void *param)
{
  glBegin(figure);
  fct_draw(param);
  glEnd();
}

void	mogl_point2d(double x, double y, int color)
{
  int	r;
  int	g;
  int	b;

  r = color >> 16;
  g = (color >> 8) - (r << 8);
  b = color - ((g << 8) + (r << 16));
  glColor3ub((unsigned char)r, (unsigned char)g, (unsigned char)b);
  glVertex2d(x, y);
}

void	mogl_clear_window(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void	mogl_update_window(void)
{
  glFlush();
  SDL_GL_SwapBuffers();
}

void	mogl_reference_win_size(int size_win_x, int size_win_y)
{
  gluOrtho2D(0, size_win_x, 0, size_win_y);
}
