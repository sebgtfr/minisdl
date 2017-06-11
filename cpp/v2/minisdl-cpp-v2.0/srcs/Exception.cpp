//
// Exception.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 19:17:00 2016 Sébastien Le Maire
// Last update Sun Jun 11 12:03:29 2017 Sébastien Le Maire
//

#include "SDL2/SDL.h"
#include <sstream>
#include <iomanip>
#include <string>
#include "MSDL2/Exception.hpp"

static std::string const	g_msg_error[MSDL::Exception::LAST] =
  {
    "Initialisation of the Minisdl's systems failed",
    "Initialisation of audio's system failed",
    /*"Initialisation of window failed",
    "Clear surface failed",
    "Blit of surface failed",
    "Update window failed, An error occurred during swap of the window's buffers.",
    "An error occurred during image's initialisation, creation of surface failed.",
    "An error occurred during image's initialisation, loading and creation of image failed.",
    "Setting of transparency failed",
    "Setting of alpha failed",*/
    /* <- END SDL ERROR, BEGIN MSDL ERROR -> */
    "Index use for pixel's componant is out of range"
  };

namespace			MSDL
{
  /*
  ** Exception class
  */
  Exception::Exception(MSDL::Exception::CodeError codeError) : exception()
  {
    std::ostringstream		oss;

    oss << std::setfill('0') << std::setw(2) << static_cast<unsigned int>(codeError);
    this->m_msg = ("Error [" + oss.str() + "] => " +
		   g_msg_error[static_cast<Uint32>(codeError)] + " !");
    if (codeError < MSDL::Exception::NO_SDL_ERROR)
      this->m_msg = (this->m_msg + "\nSDL => \"" + SDL_GetError() + "\"");
  }

  Exception::~Exception() throw()
  {
  }

  char const			*Exception::what() const throw()
  {
    return (this->m_msg.c_str());
  }
}
