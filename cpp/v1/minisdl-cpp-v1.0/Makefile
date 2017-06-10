##
## Makefile for minisdl-cpp-v1.0 in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0
## 
## Made by Sébastien Le Maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Tue May 31 17:55:04 2016 Sébastien Le Maire
## Last update Sat Jun 10 12:11:06 2017 Sébastien Le Maire
##

ifeq ($(DEBUG), yes)

CXXFLAGS		+= -g -g3 -ggdb

endif

export LD_LIBRARY_PATH	= ${PWD}/SDL/lib/

PATH_LIBRARY		= ./
PATH_INCLUDE		= ./include/
PATH_SRCS		= ./srcs/
PATH_SDL		= ./SDL/include/

#Path srcs category
PATH_SRCS_GENERAL	= ${PATH_SRCS}General/
PATH_SRCS_GRAPHIC	= ${PATH_SRCS}Graphic/
PATH_SRCS_ERROR		= ${PATH_SRCS}Error/

#Path include category
PATH_INCLUDE_GENERAL	= ${PATH_INCLUDE}General/
PATH_INCLUDE_GRAPHIC	= ${PATH_INCLUDE}Graphic/
PATH_INCLUDE_ERROR	= ${PATH_INCLUDE}Error/

NAME			= $(PATH_LIBRARY)libmsdl.a

CXXFLAGS		+= -Wall -Wextra -Werror
CXXFLAGS		+= -I${PATH_SDL}
CXXFLAGS		+= -I${PATH_INCLUDE}
CXXFLAGS		+= -I${PATH_INCLUDE_GENERAL}
CXXFLAGS		+= -I${PATH_INCLUDE_GRAPHIC}
CXXFLAGS		+= -I${PATH_INCLUDE_ERROR}

# General sources
SRCS			= $(PATH_SRCS_GENERAL)System.cpp

# Error sources
SRCS			+= $(PATH_SRCS_ERROR)Exception.cpp

# Graphical sources
SRCS			+= $(PATH_SRCS_GRAPHIC)Pixel.cpp
SRCS			+= $(PATH_SRCS_GRAPHIC)Surface.cpp
SRCS			+= $(PATH_SRCS_GRAPHIC)Window.cpp
SRCS			+= $(PATH_SRCS_GRAPHIC)Image.cpp

OBJS			= $(SRCS:.cpp=.o)

AR			= ar rc

RAN			= ranlib

RM			= rm -f

#################### CUSTOM ####################

.cpp.o:
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo -e "\t\t\033[01;32m[COMPILE]\033[00m \t=> $<"

################################################

all: $(NAME)

$(NAME): print_compile_lib $(OBJS)
	@echo -e "\033[01;33mCREATE LIBRARY\033[00m"
	@$(AR) $(NAME) $(OBJS)
	@echo -e "\t\t\033[01;33m[AR]\033[00m \t\t=> $(NAME)"
	@$(RAN) $(NAME)

clean:
	@echo -e "\033[01;31mDELETE OBJECTS\033[00m"
	@$(RM) $(OBJS)

fclean: clean
	@echo -e "\033[01;31mDELETE LIBRARY\033[00m"
	@$(RM) $(NAME)

re: fclean all

print_compile_lib:
	@echo -e "\033[01;32mCOMPILE LIBRARY\033[00m"

.PHONY: all clean fclean print_compile_lib re
