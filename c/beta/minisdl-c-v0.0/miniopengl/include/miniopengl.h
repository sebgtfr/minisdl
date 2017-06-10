/*
** miniopengl.h for miniopengl in /home/le-mai_s/librairie/miniopengl_tmp
** 
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
** 
** Started on  Sat Jun  6 08:20:22 2015 sebastien le-maire
** Last update Wed Jun 17 18:41:00 2015 sebastien le-maire
*/

#ifndef MINIOPENGL_H_
# define MINIOPENGL_H_

# include "minisdl.h"
# include <GL/gl.h>
# include <GL/glu.h>
/*
** Command compilation is : -lSDL -lSDL_image -lSDL_mixer -L[relatif way] -lmsdl
** for compile minisdl and add of compile miniopengl:
**  -lGL -lGLU -L[relatif way] -lmogl
*/


typedef	struct	s_cam
{
  float		tgt_x;
  float		tgt_y;
  float		tgt_z;
  float		vert_x;
  float		vert_y;
  float	        vert_z;
}		t_cam;

typedef	struct	s_quadric
{
  GLUquadric	*q;
  int		s;
  int		s_t;
  int		s_h;
}		t_quadric;

void	mogl_create_object(int figure, void (*fct_draw)(), void *param);
/*
** For figure :
** GL_POINTS = create point.
** GL_LINES = create line, point linked 2 by 2.
** GL_LINE_STRIP = create line, point linked from first to last.
** GL_LINE_LOOP = GL_LINE_STRIP but the last is link to first.
** GL_TRIANGLES = 3 points forms triangles full.
** GL_TRIANGLE_STRIP = Triangles are link by 2 points.
** GL_TRIANGLE_FAN = The first point is link by all triangle.
** GL_QUADS = 4 points forms quadrilatere full.
** GL_QUAD_STRIP = quadrilatere are link by 2 points.
** GL_POLYGON = if more of 4 points, create full polygon.
** prototype of fct_draw : void    fct_draw(void *param);
*/

void	mogl_point2d(double x, double y, int color);
void	mogl_clear_window(void);
void	mogl_update_window(void);
/*
** Switch with msdl_update_window to minisdl.
*/

void	mogl_reference_win_size(int size_win_x, int size_win_y);

/*
** Transformation stuff
*/

void	mogl_init_matrix(int mode);
/*
** For mode :
** GL_PROJECTION = definition of projection mode. (orthogonal, perpective,...)
** This option should be use in function mogl_init_perspective.
** GL_MODELVIEW = place item in scene
** GL_TEXTURE = place texture.
*/

void	mogl_save_matrix(void);
/*
** stacked matrix on top of the stack
*/

void	mogl_apply_matrix(void);
/*
** unstack matrix on top of the stack and applied.
*/

void	mogl_reset_matrix(void);
/*
** reset matrix to origin matrix (identity matrix)
*/

void	mogl_translation(double x, double y, double z);
void	mogl_rotation(double angle, double x, double y, double z);
void	mogl_scale(float x, float y, float z);


/*
** 3D perspective stuff
*/

void	mogl_init_perspective(int field_of_view, int ratio_screen,
			      int distance_min, int distance_max);
void	mogl_init_cam_target(t_cam *cam, float x, float y, float z);
void	mogl_init_cam_vertical_vector(t_cam *cam, float x,
				      float y, float z);
void	mogl_place_cam(float cam_x, float cam_y, float cam_z, t_cam *cam);
/*
** You need to initialize position of target and position of vertical vector
** to place cam.
*/

void	mogl_point3d(double x, double y, double z, int color);

/*
** Quadric stuff
*/

void	mogl_init_quadric(t_quadric *quadric, int slices);
/*
** slices is number of vertical line to form quadric
*/

void	mogl_quadric_style(t_quadric *quadric, int style);
/*
** 3 macros :
** GLU_POINT : draw fig with point.
** GLU_LINE : draw fig with line.
** GLU_FILL : choice by default, draw fig full..
*/

void	mogl_destroy_quadric(t_quadric *quadric);
void	mogl_create_sphere(t_quadric *sphere, int rayon, int stacks);
void	mogl_create_cylinder(t_quadric *cylinder, int base, int stacks);
void	mogl_create_disk(t_quadric *disk, int ray_intern, int ray_extern);
void	mogl_pdisk_cylinder(t_quadric *pdisk_cylinder, int start_top,
			    int sweep_height);
/*
** For cylinder, give top and height.
** For partial disk, give start of angle and distance of start.
*/

void	mogl_create_partial_disk(t_quadric *p_disk, int ray_intern,
				 int ray_extern);

#endif /* !MINIOPENGL_H_ */
