##
## Makefile for Minisdl2.0 in /home/le-mai_s/librairie/Minisdl/cpp/v2/minisdl-cpp-v2.0
## 
## Made by Sébastien Le Maire
## Login   <le-mai_s@epitech.net>
## 
## Started on  Sat Jun 10 12:03:44 2017 Sébastien Le Maire
## Last update Sun Jun 11 12:04:48 2017 Sébastien Le Maire
##

CXXFLAGS			=

ifeq ($(DEBUG), yes)

CXXFLAGS			+= -g -g3 -ggdb

endif

#export LD_LIBRARY_PATH		= ${PWD}/lib/SDL2/

PATH_RELEASE			= ./
PATH_SRCS			= ./srcs/
PATH_INCLUDE			= ./include/

NAME				= ${PATH_RELEASE}libmsdl2.a

CXXFLAGS			+= -Wall -Wextra -Werror
CXXFLAGS			+= -I${PATH_INCLUDE}

LDFLAGS				= -L./lib/SDL2/

# System sources
SRCS				= $(PATH_SRCS)System.cpp

# Error sources
SRCS				+= $(PATH_SRCS)Exception.cpp

OBJS				= $(SRCS:.cpp=.o)

AR				= ar rc

RAN				= ranlib

RM				= rm -f

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
