#!/bin/sh

NAME="test"
SOURCES="main.cpp"
PATH_INCLUDE="../include/"
INCLUDE="-I../SDL/include/ -I${PATH_INCLUDE}"
PATH_LIBRARY="-L../ -L../SDL/lib/"
LIBRARY="-lSDL2 -lSDL2_mixer -lSDL2_image -lmsdl2"

g++ -o $NAME -Wall -Wextra -Werror -g -g3 -ggdb $SOURCES $INCLUDE $PATH_LIBRARY $LIBRARY
