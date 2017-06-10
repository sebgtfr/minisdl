//
// Window.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/include/Graphic
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue Jun 28 13:18:50 2016 Sébastien Le Maire
// Last update Wed Aug 17 17:24:27 2016 Sébastien Le Maire
//

#include <SDL/SDL.h>
#include "Minisdl_exception.hpp"
#include "Minisdl_pixel.hpp"
#include "Minisdl_surface.hpp"
#include "Minisdl_image.hpp"
#include "Minisdl_window.hpp"

MSDL::Window::Flags		operator|(MSDL::Window::Flags const &f1,
					  MSDL::Window::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return (static_cast<MSDL::Window::Flags>(i1 | i2));
}

MSDL::Window::Flags		&operator|=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::Window::Flags>(i1 | i2)));
}

MSDL::Window::Flags		operator&(MSDL::Window::Flags const &f1,
					  MSDL::Window::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return (static_cast<MSDL::Window::Flags>(i1 & i2));
}

MSDL::Window::Flags		&operator&=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::Window::Flags>(i1 & i2)));
}

MSDL::Window::Flags		&operator^=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::Window::Flags>(i1 ^ i2)));
}

MSDL::Window::Flags		&operator++(MSDL::Window::Flags &f)
{
  f = ((f) ? (static_cast<MSDL::Window::Flags>(static_cast<unsigned int>(f) << 1)) :
       static_cast<MSDL::Window::Flags>(1));
  return (f);
}

namespace			MSDL
{
  static unsigned int const	g_SDLFlags[_MSDL_WINDOW_NBFLAGS_] =
    {
				SDL_RESIZABLE,
				SDL_FULLSCREEN,
				SDL_NOFRAME
    };

  Window::Window(Uint16 width, Uint16 height,
		 MSDL::Window::Flags winFlags, std::string const &title,
		 MSDL::Pixel color, Uint8 bpp)
  {
    Uint32			flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    MSDL::Window::Flags		msdlFlags = MSDL::Window::ALL_OFF;
    Uint8			idx = 0;

    if (winFlags & MSDL::Window::OPENGL)
      {
	flags = SDL_OPENGL;
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
      }
    else
      while (idx < _MSDL_WINDOW_NBFLAGS_)
	{
	  if (winFlags & (++msdlFlags))
	    flags |= g_SDLFlags[idx];
	  ++idx;
	}
    if (!(this->m_surface = SDL_SetVideoMode(width, height, bpp, flags)))
      throw MSDL::Exception(MSDL::Exception::INIT_WINDOW);
    if (!title.empty() && (!(flags & SDL_NOFRAME)))
      SDL_WM_SetCaption(title.c_str(), NULL);
    if (SDL_FillRect(this->m_surface, NULL,
		     SDL_MapRGB(this->m_surface->format,
				color.componant[MSDL::R],
				color.componant[MSDL::G],
				color.componant[MSDL::B])))
      throw MSDL::Exception(MSDL::Exception::INIT_WINDOW);
    SDL_Flip(this->m_surface);
  }

  Window::~Window(void)
  {
  }

  /*
  ** Methods
  */

  void				Window::update(void) const
  {
    if (SDL_Flip(this->m_surface))
      throw MSDL::Exception(MSDL::Exception::UPDATE_WINDOW);
  }

  void				Window::setIcon(MSDL::Image const &icon) const
  {
    SDL_WM_SetIcon(icon.getSurface(), NULL);
  }

  void				Window::reverseFlags(MSDL::Window::Flags winFlags)
  {
    SDL_Surface			*window = SDL_GetVideoSurface();

    if (window)
      {
	MSDL::Window::Flags	msdlFlags = MSDL::Window::ALL_OFF;
	Uint8			idx = 0;
	Uint32			flags = 0;

	while (idx != _MSDL_WINDOW_NBFLAGS_)
	  {
	    if (winFlags & (++msdlFlags))
	      flags |= g_SDLFlags[idx];
	    ++idx;
	  }
	if (winFlags & MSDL::Window::OPENGL)
	  flags |= SDL_OPENGL;
	flags = ((!(window->flags & SDL_OPENGL)) &&
		 (winFlags & MSDL::Window::OPENGL)) ?
	  (SDL_OPENGL) : (window->flags ^ flags);
	if (window->flags & SDL_OPENGL)
	  {
	    if (flags & SDL_OPENGL)
	      return ;
	    flags |= SDL_HWSURFACE | SDL_DOUBLEBUF;
	  }
	if (!(window = SDL_SetVideoMode(0, 0, 0, flags)))
	  throw MSDL::Exception(MSDL::Exception::INIT_WINDOW);
	SDL_FreeSurface(this->m_surface);
	this->m_surface = window;
      }
  }
}
