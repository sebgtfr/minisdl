//
// main.cpp for test in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 19:46:19 2016 Sébastien Le Maire
// Last update Sat Jun 10 17:25:46 2017 Sébastien Le Maire
//

#include <iostream>
#include <unistd.h>
#include "Minisdl2/Minisdl.hpp"

int				main(void)
{
  try
    {
      MSDL::System		system;

      system.init(MSDL::System::ALL_ON);
      system.close(MSDL::System::ALL_OFF);
      system.init(MSDL::System::ALL_ON);
      system.init(MSDL::System::TIMER);
      system.init(MSDL::System::AUDIO);
    }
  catch (MSDL::Exception const &e)
    {
      std::cerr << e.what() << std::endl;
      return (1);
    }
  return (0);
}
