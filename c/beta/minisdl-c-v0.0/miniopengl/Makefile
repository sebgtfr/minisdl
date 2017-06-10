##
## Makefile<3> for minisdl in /home/le-mai_s/librairie/minisdl1.x/sources
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Fri Aug  7 10:36:59 2015 sebastien le-maire
## Last update Tue May 31 17:18:37 2016 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CFLAGS		+= -g -g3 -ggdb

endif

PATH_LIB	= ./
PATH_LIB_SRCS	= $(PATH_LIB)srcs/

NAME_LIB_MOGL	= $(PATH_LIB)libmogl.a

# need to compile your program with :
# -L{path/minisdl-c-v0.0} -lmsdl -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lGL -lGLU

CFLAGS		+= -Wall -Wextra -Werror
CFLAGS		+= -I./include/
CFLAGS		+= -I../include/

SRCS_LIB_MOGL	= $(PATH_LIB_SRCS)mogl_matrix.c
SRCS_LIB_MOGL	+= $(PATH_LIB_SRCS)mogl_transformation.c
SRCS_LIB_MOGL	+= $(PATH_LIB_SRCS)mogl_perspective.c
SRCS_LIB_MOGL	+= $(PATH_LIB_SRCS)mogl_quadric.c
SRCS_LIB_MOGL	+= $(PATH_LIB_SRCS)mogl_figure_quadric.c
SRCS_LIB_MOGL	+= $(PATH_LIB_SRCS)miniopengl.c

OBJS_LIB_MOGL	= $(SRCS_LIB_MOGL:.c=.o)

AR		= ar rc

RAN		= ranlib

RM		= rm -fr

###################### DECO #######################

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\t\t\033[01;32m[COMPILE]\033[00m \t=> $<"

##################################################

all: $(NAME_LIB_MOGL)

$(NAME_LIB_MOGL): print_compile_lib $(OBJS_LIB_MOGL)
	@echo -e "\033[01;33mCREATE LIBRARY\033[00m"
	@$(AR) $(NAME_LIB_MOGL) $(OBJS_LIB_MOGL)
	@echo -e "\t\t\033[01;33m[AR]\033[00m \t\t=> $(NAME_LIB_MOGL)"
	@$(RAN) $(NAME_LIB_MOGL)
	@echo -e "\t\t\033[01;33m[RAN]\033[00m \t\t=> $(NAME_LIB_MOGL)"

clean:
	@echo -e "\033[01;31mDELETE OBJECTS\033[00m"
	@$(RM) $(OBJS_LIB_MOGL)

fclean: clean
	@echo -e "\033[01;31mDELETE LIBRARY\033[00m"
	@$(RM) $(NAME_LIB_MOGL)

re: fclean all

print_compile_lib:
	@echo -e "\033[01;32mCOMPILE LIBRARY\033[00m"

.PHONY: all clean fclean re print_compile_lib
