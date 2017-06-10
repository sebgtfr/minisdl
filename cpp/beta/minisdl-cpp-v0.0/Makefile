##
## Makefile for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Mon Nov  9 20:11:18 2015 sebastien le-maire
## Last update Sun May 15 20:43:14 2016 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CXXFLAGS	+= -g -g3 -ggdb

endif

PATH_LIB	= ./
PATH_LIB_SRCS	= $(PATH_LIB)srcs/

NAME_LIB_MSDL	= $(PATH_LIB)libmsdl.a

CXXFLAGS	= -Wall -Wextra -Werror
cXXFLAGS	+= -I./include

# need to compile your program with :
# -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -L./${PATH_MSDL} -lmsdl

SRCS_LIB_MSDL	= $(PATH_LIB_SRCS)msdl_font.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_timer.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_sound.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_music.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_event.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_image.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_screen.cpp
SRCS_LIB_MSDL	+= $(PATH_LIB_SRCS)msdl_surface.cpp

OBJS_LIB_MSDL	= $(SRCS_LIB_MSDL:.cpp=.o)

AR		= ar rc

RAN		= ranlib

RM		= rm -f

###################### DECO #######################

.cpp.o:
	@$(CXX) $(cXXFLAGS) -c $< -o $@
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
