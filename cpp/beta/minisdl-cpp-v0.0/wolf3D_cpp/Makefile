##
## Makefile for wolf3D_cpp in /home/le-mai_s/librairie/minisdl_cpp/test
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Thu Nov 12 19:52:27 2015 sebastien le-maire
## Last update Sat Jan 23 23:25:56 2016 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CXXFLAGS	+= -g -g3 -ggdb

endif

PATH_SRCS	= ./srcs/

NAME		= wolf3D_cpp

CXXFLAGS	+= -Wall -Wextra -Werror
CXXFLAGS	+= -ansi -pedantic
CXXFLAGS	+= -I./include
CXXFLAGS	+= -I../include

LDFLAGS		+= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
LDFLAGS		+= -L../ -lmsdl

SRCS		+= $(PATH_SRCS)map.cpp
SRCS		+= $(PATH_SRCS)player.cpp
SRCS		+= $(PATH_SRCS)parsing.cpp
SRCS		+= $(PATH_SRCS)raycasting.cpp
SRCS		+= $(PATH_SRCS)main.cpp

OBJS		= $(SRCS:.cpp=.o)

CXX		= g++

RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
