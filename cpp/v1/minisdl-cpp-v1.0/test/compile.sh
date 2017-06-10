#!/bin/sh

SOURCES="main.cpp"
PATH_INCLUDE="../include/"
INCLUDE="-I../SDL/include/ -I${PATH_INCLUDE} -I${PATH_INCLUDE}General -I${PATH_INCLUDE}Graphic -I${PATH_INCLUDE}Error"
PATH_LIBRARY="-L../ -L../SDL/lib/"
LIBRARY="-lSDL -lSDL_mixer -lSDL_image -lmsdl"

g++ -Wall -Wextra -Werror -g -g3 -ggdb $SOURCES $INCLUDE $PATH_LIBRARY $LIBRARY
