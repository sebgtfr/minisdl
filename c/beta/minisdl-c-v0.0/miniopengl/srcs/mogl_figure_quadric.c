/*
** mogl_figure_quadric.c for miniopengl in /home/le-mai_s/librairie/miniopengl
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Wed Jun 17 18:09:14 2015 sebastien le-maire
** Last update Wed Jun 17 18:38:39 2015 sebastien le-maire
*/

#include "miniopengl.h"

void	mogl_create_sphere(t_quadric *sphere, int rayon, int stacks)
{
  gluSphere(sphere->q, rayon, sphere->s, stacks);
}

void	mogl_create_cylinder(t_quadric *cylinder, int base, int stacks)
{
  gluCylinder(cylinder->q, base, cylinder->s_t, cylinder->s_h,
	      cylinder->s, stacks);
}

void	mogl_create_disk(t_quadric *disk, int ray_intern, int ray_extern)
{
  gluDisk(disk->q, ray_intern, ray_extern, disk->s, 1);
}

void	mogl_pdisk_cylinder(t_quadric *pdisk_cylinder, int start_top,
			    int sweep_height)
{
  pdisk_cylinder->s_t = start_top;
  pdisk_cylinder->s_h = sweep_height;
}

void	mogl_create_partial_disk(t_quadric *p_disk, int ray_intern,
				 int ray_extern)
{
  gluPartialDisk(p_disk->q, ray_intern, ray_extern, p_disk->s, 1,
		 p_disk->s_t, p_disk->s_h);
}
