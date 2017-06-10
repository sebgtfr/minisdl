/*
** minisdl.h for minisdl in /home/le-mai_s/recode/SDL/test1
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed May 27 17:37:12 2015 sebastien le-maire
** Last update Fri Aug  7 10:47:56 2015 sebastien le-maire
*/

#ifndef MINISDL_H_
# define MINISDL_H_

# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <SDL/SDL_mixer.h>
# include "minisdl_macro.h"

int		msdl_init(t_msdl *msdl, char choice_opt);
int		msdl_window(t_msdl *msdl, int width,
			    int height, char *title);
void		msdl_pixel_put(t_msdl *msdl, int x, int y, unsigned int color);
void		msdl_clear_window(t_msdl *msdl);
void		msdl_update_window(t_msdl *msdl);
void		msdl_end(t_msdl *msdl);
void		msdl_surface_init_pos(t_surface *pos_size, int x, int y);
void		msdl_surface_init_size(t_surface *pos_size, int x, int y);
int		msdl_create_surface(t_msdl *msdl, t_surface *pos_size,
				    int color);
void		msdl_put_icon(char *name_img);
int		msdl_save_image_bmp(t_img *param_img, char *name_img);
int		msdl_save_image(t_img *param_img, char *name_img);
void		msdl_add_transparence_to_color_in_image(t_img *param_img,
							int color);
void		msdl_add_alpha_to_image(t_img *param_img, char transparency);
void		msdl_cpy_image(t_img *img_dest, t_img *img_src);
void		msdl_put_image(t_msdl *msdl, t_img *param_img, int x, int y);
void		msdl_destroy_image(t_img *param_img);

void		msdl_key_autorepeaton(int wait, int period);
void		msdl_key_event(t_msdl *msdl, void (*fct_keypress)(),
			       void (*fct_keyrelease)());
void		msdl_tmp_keypress_event(t_msdl *msdl, t_event *event,
					void (*fct)(), void *param);
void		msdl_tmp_keyrelease_event(t_msdl *msdl, t_event *event,
					  void (*fct)(), void *param);
void		msdl_mouse_event(t_msdl *msdl, void (*fct_mousepress)(),
				 void (*fct_mouserelease)(),
				 void (*fct_mousemotion)());
void		msdl_tmp_mousepress_event(t_msdl *msdl, t_event *event,
					  void (*fct)(), void *param);
void		msdl_tmp_mouserelease_event(t_msdl *msdl, t_event *event,
					    void (*fct)(), void *param);
void		msdl_tmp_mousemotion_event(t_msdl *msdl, t_event *event,
					   void (*fct)(), void *param);
void		msdl_fct_event(t_msdl *msdl, void (*fct_main)());
int		msdl_add_mogl(t_msdl *msdl, void (*fct_miniopengl)());
void		msdl_event_loop(t_msdl *msdl, void *param);
void		msdl_poll_event(t_msdl *msdl, void *param, SDL_Event *event);
void		msdl_event_next(t_msdl *msdl, void *param, SDL_Event *event);
void		msdl_end_loop(t_msdl *msdl);
void		msdl_sleep(int millisecond);
unsigned int	msdl_get_time(void);
void		msdl_add_timer(t_timer *timer, int period,
			       Uint32 (*fct_callback)(), void *param);
void		msdl_destroy_timer(t_timer *timer);
int		msdl_music_init(int frequency);
void		msdl_save_music(t_music *music, char *name_music);
void		msdl_play_music(t_music *music, int loop);
void		msdl_cpy_music(t_music *dest, t_music *src);
void		msdl_destroy_music(t_music *music);
void		msdl_music_end(void);
void		msdl_pause_music(void);
void		msdl_regain_music(void);
void		msdl_replay_music(void);
int		msdl_volume_music(unsigned int volume);
void		msdl_stop_music(void);
int		msdl_playing_mode(void);
int		msdl_paused_mode(void);
void		msdl_alloc_channels(int nb_channels);
void		msdl_sound_init(t_sound *sound, char *name_sound);
int		msdl_volume_sound(t_sound *sound, unsigned int volume);
void		msdl_play_sound(t_sound *sound, int period);
void		msdl_cpy_sound(t_sound *dest, t_sound *src);
void		msdl_destroy_sound(t_sound *sound);

#endif /* !MINISDL_H_ */
