##
## Makefile<3> for minisdl in /home/le-mai_s/librairie/minisdl1.x/sources
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Fri Aug  7 10:36:59 2015 sebastien le-maire
## Last update Sun May 15 20:15:58 2016 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CFLAGS		+= -g -g3 -ggdb

endif

PATH_LIB	= ./
PATH_LIB_SRCS	= $(PATH_LIB)srcs/

NAME_LIB_MSDL	= $(PATH_LIB)libmsdl.a

# need to compile your program with :
# -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -L./${PATH_MSDL} -lmsdl

CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I./include

SRCS_LIB_MSDL	= $(PATH_LIB_SRCS)msdl_pixel_put.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_image.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_save_image.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_cpy_image.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_destroy_image.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_event.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_poll_event.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_tmp_event.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_time.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_fct_event.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_end_loop.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_music.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_cpy_music.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_handles_music.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_state_music.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_sound.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_convert.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_ttf.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)addon_opengl.c
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)minisdl.c

OBJS_LIB_MSDL	= $(SRCS_LIB_MSDL:.c=.o)

AR		= ar rc

RAN		= ranlib

RM		= rm -fr

###################### DECO #######################

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\t\t\033[01;32m[COMPILE]\033[00m \t=> $<"

##################################################

all: $(NAME_LIB_MSDL)

$(NAME_LIB_MSDL): print_compile_lib $(OBJS_LIB_MSDL)
	@echo -e "\033[01;33mCREATE LIBRARY\033[00m"
	@$(AR) $(NAME_LIB_MSDL) $(OBJS_LIB_MSDL)
	@echo -e "\t\t\033[01;33m[AR]\033[00m \t\t=> $(NAME_LIB_MSDL)"
	@$(RAN) $(NAME_LIB_MSDL)
	@echo -e "\t\t\033[01;33m[RAN]\033[00m \t\t=> $(NAME_LIB_MSDL)"

clean:
	@echo -e "\033[01;31mDELETE OBJECTS\033[00m"
	@$(RM) $(OBJS_LIB_MSDL)

fclean: clean
	@echo -e "\033[01;31mDELETE LIBRARY\033[00m"
	@$(RM) $(NAME_LIB_MSDL)

re: fclean all

print_compile_lib:
	@echo -e "\033[01;32mCOMPILE LIBRARY\033[00m"

.PHONY: all clean fclean re print_compile_lib
