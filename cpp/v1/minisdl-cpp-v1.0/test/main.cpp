//
// main.cpp for test in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 19:46:19 2016 Sébastien Le Maire
// Last update Wed Aug 24 14:10:14 2016 Sébastien Le Maire
//

#include <iostream>
#include <unistd.h>
#include "Minisdl.hpp"

int				main(void)
{
  try
    {
      MSDL::System		system;
      MSDL::Window		window(500, 500, MSDL::Window::ALL_OFF,
      				       "MiniSDL V1.0");
      MSDL::Image		image(500, 500, _MSDL_WHITE_);
      MSDL::Image		aurore("./aurore.jpg");
      MSDL::Surface::Rect      	r(1000, 300, 400, 400);

      for (unsigned int i = 200; i < 300; ++i)
      	for (unsigned int j = 200; j < 300; ++j)
      	  window.putPixel(j, i, _MSDL_PURPLE_);
      window.update();
      sleep(1);
      window.blit(image, 250, 250);
      window.update();
      sleep(1);
      window.blit(image, -250, -250);
      window.update();
      sleep(1);
      window.blit(aurore, 50, 50, &r);
      window.update();
      sleep(1);
    }
  catch (MSDL::Exception const &e)
    {
      std::cerr << e.what() << std::endl;
      return (1);
    }
  return (0);
}
