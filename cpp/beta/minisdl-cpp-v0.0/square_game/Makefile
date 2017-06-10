##
## Makefile for square_game in /home/le-mai_s/librairie/minisdl_cpp/square_game
## 
## Made by sebastien le-maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Mon Nov 23 20:15:15 2015 sebastien le-maire
## Last update Mon Nov 23 20:15:24 2015 sebastien le-maire
##


ifeq ($(DEBUG), yes)

CXXFLAGS	+= -g -g3 -ggdb

endif

PATH_SRCS	= ./srcs/

NAME		= square_game

CXXFLAGS	+= -Wall -Wextra -Werror
CXXFLAGS	+= -ansi -pedantic
CXXFLAGS	+= -I./include
CXXFLAGS	+= -I../include

LDFLAGS		+= -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
LDFLAGS		+= -L../ -lmsdl

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
