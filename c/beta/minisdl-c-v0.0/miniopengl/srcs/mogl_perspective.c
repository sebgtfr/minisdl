/*
xo** mogl_perspective.c for miniopengl in /home/le-mai_s/librairie/miniopengl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sun Jun  7 13:20:20 2015 sebastien le-maire
** Last update Sun Jun  7 14:31:28 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_init_perspective(int field_of_view, int ratio_screen,
			      int distance_min, int distance_max)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(field_of_view, (double)ratio_screen,
		 distance_min, distance_max);
  glEnable(GL_DEPTH_TEST);
}

void	mogl_init_cam_target(t_cam *cam, float x, float y, float z)
{
  cam->tgt_x = x;
  cam->tgt_y = y;
  cam->tgt_z = z;
}

void	mogl_init_cam_vertical_vector(t_cam *cam, float x,
				      float y, float z)
{
  cam->vert_x = x;
  cam->vert_y = y;
  cam->vert_z = z;
}

void	mogl_place_cam(float cam_x, float cam_y, float cam_z, t_cam *cam)
{
  gluLookAt(cam_x, cam_y, cam_z,
	    cam->tgt_x, cam->tgt_y, cam->tgt_z,
	    cam->vert_x, cam->vert_y, cam->vert_z);
}

void	mogl_point3d(double x, double y, double z, int color)
{
  int	r;
  int	g;
  int	b;

  r = color >> 16;
  g = (color >> 8) - (r << 8);
  b = color - ((g << 8) + (r << 16));
  glColor3ub((unsigned char)r, (unsigned char)g, (unsigned char)b);
  glVertex3d(x, y, z);
}
