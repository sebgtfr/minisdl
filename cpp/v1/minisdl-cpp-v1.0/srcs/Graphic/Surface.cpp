//
// Surface.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Fri Jun  3 21:47:30 2016 Sébastien Le Maire
// Last update Wed Aug 17 17:26:23 2016 Sébastien Le Maire
//

#include "SDL.h"
#include "Minisdl_exception.hpp"
#include "Minisdl_pixel.hpp"
#include "Minisdl_surface.hpp"

namespace			MSDL
{
  Surface::Surface(void) : m_surface(NULL)
  {
  }

  Surface::~Surface(void)
  {
    if (this->m_surface)
      SDL_FreeSurface(this->m_surface);
  }

  /*
  ** Methods
  */

  void				Surface::putPixel(Uint16 const x, Uint16 const y,
						  MSDL::Pixel const color)
  {
    if ((x > this->m_surface->w) || (y > this->m_surface->h))
      return ;

    Uint8			bpp = this->m_surface->format->BytesPerPixel;
    MSDL::Pixel			*pix = (reinterpret_cast<MSDL::Pixel *>
					((static_cast<Uint8 *>
					  (this->m_surface->pixels) + y *
					  this->m_surface->pitch + x * bpp)));
    Uint8			index = 0;

    switch (bpp)
      {
      case 1:
	pix->pix8 = color.pix8;
	break;
      case 2:
	pix->pix16 = color.pix16;
	break;
      case 3:
	for (; index < 3; ++index)
	  pix->componant[index] = (color.pix32 >> (MSDL_ENDIAN_DEC +
						  (MSDL_ENDIAN_IDX * index))) & 0xFF;
	break;
      case 4:
	pix->pix32 = color.pix32;
	break;
      default:
	break;
      }
  }

  MSDL::Pixel  			Surface::getPixel(Uint16 const x, Uint16 const y)
  {
    Uint8			bpp = this->m_surface->format->BytesPerPixel;
    MSDL::Pixel			*pix = (reinterpret_cast<MSDL::Pixel *>
					((static_cast<Uint8 *>
					  (this->m_surface->pixels) + y *
					  this->m_surface->pitch + x * bpp)));
    MSDL::Pixel			ret = 0;

    if (bpp == 3)
      ret.pix32 = ((pix->componant[0] << MSDL_ENDIAN_DEC)
		   | (pix->componant[1] << 8)
		   | (pix->componant[2] << MSDL_ENDIAN_INV));
    else
      ret = *pix;
    return (ret);
  }

  void				Surface::clear(MSDL::Pixel const pixel)
  {
    if (SDL_FillRect(this->m_surface, NULL,
		     SDL_MapRGB(this->m_surface->format, pixel.componant[MSDL::R],
				pixel.componant[MSDL::G], pixel.componant[MSDL::B])))
      throw MSDL::Exception(MSDL::Exception::CLEAR_SURFACE);
  }

  int				Surface::width(void) const
  {
    return (this->m_surface->w);
  }

  int				Surface::height(void) const
  {
    return (this->m_surface->h);
  }

  SDL_Surface			*Surface::getSurface(void) const
  {
    return (this->m_surface);
  }

  void				Surface::blit(MSDL::Surface const &surface,
					      Sint16 const x, Sint16 const y,
					      MSDL::Surface::Rect const *rect)
  {
    if ((x < this->m_surface->w) && (y < this->m_surface->h))
      {
	SDL_Rect		dst;
	SDL_Rect		src;

	if (rect)
	  src = rect->getRect();
	else
	  {
	    src.x = 0;
	    src.y = 0;
	    src.w = surface.width();
	    src.h = surface.height();
	  }
	if (x < 0)
	  {
	    dst.x = 0;
	    dst.w = this->m_surface->w;
	    src.x += (-x);
	    src.w = ((src.w > (-x)) ? (src.w - (-x)) : 0);
	  }
	else
	  {
	    dst.x = x;
	    dst.w = this->m_surface->w - x;
	  }
	if (y < 0)
	  {
	    dst.y = 0;
	    dst.h = this->m_surface->h;
	    src.y += (-y);
	    src.h = ((src.h > (-y)) ? (src.h - (-y)) : 0);
	  }
	else
	  {
	    dst.y = y;
	    dst.h = this->m_surface->h - y;
	  }
	if (src.x < 0)
	  {
	    src.w = ((src.w > (-(src.x))) ? (src.w - (-(src.x))) : 0);
	    src.x = 0;
	  }
	if (src.y < 0)
	  {
	    src.h = ((src.h > (-(src.y))) ? (src.h - (-(src.y))) : 0);
	    src.y = 0;
	  }
        if ((dst.w && dst.h) && (src.w && src.h))
	  {
	    if (src.w > dst.w)
	      src.w = dst.w;
	    if (src.h > dst.h)
	      src.h = dst.h;
	    if (SDL_BlitSurface(surface.m_surface, &src, this->m_surface, &dst))
	      throw MSDL::Exception(MSDL::Exception::BLIT_SURFACE);
	  }
      }
  }

  /*
  ** SubObject
  */

  Surface::Rect::Rect(Sint16 x, Sint16 y, Uint16 width, Uint16 height)
    : m_decX(0), m_decY(0), m_width(width), m_height(height)
  {
    if (x < 0)
      {
	this->m_decX = -x;
        this->m_rect.x = 0;
      }
    else
      this->m_rect.x = x;
    if (y < 0)
      {
	this->m_decY = -y;
	this->m_rect.y = 0;
      }
    else
      this->m_rect.y = y;
    this->m_rect.w = (width < this->m_decX) ? 0 : (width - this->m_decX);
    this->m_rect.h = (height < this->m_decY) ? 0 : (height - this->m_decY);
  }

  Surface::Rect::~Rect(void)
  {
  }

  /*
  ** Accessor
  */

  void				Surface::Rect::setX(Sint16 const x)
  {
    if (x < 0)
      {
	this->m_decX = -x;
        this->m_rect.x = 0;
      }
    else
      {
	this->m_rect.x = x;
	this->m_decX = 0;
      }
    this->m_rect.x = x;
    this->m_rect.w = ((this->m_width < this->m_decX) ? 0 :
		      (this->m_width - this->m_decX));
  }

  void				Surface::Rect::setY(Sint16 const y)
  {
    if (y < 0)
      {
	this->m_decY = -y;
	this->m_rect.y = 0;
      }
    else
      {
	this->m_rect.y = y;
	this->m_decY = 0;
      }
    this->m_rect.h = ((this->m_height < this->m_decY) ? 0 :
		      (this->m_height - this->m_decY));
  }

  void				Surface::Rect::setWidth(Uint16 const width)
  {
    this->m_width = width;
    this->m_rect.w = (width < this->m_decX) ? 0 : (width - this->m_decX);
  }

  void				Surface::Rect::setHeight(Uint16 const height)
  {
    this->m_height = height;
    this->m_rect.h = (height < this->m_decY) ? 0 : (height - this->m_decY);
  }

  Sint16 			Surface::Rect::getX(void) const
  {
    return (this->m_rect.x);
  }

  Sint16 			Surface::Rect::getY(void) const
  {
    return (this->m_rect.y);
  }

  Uint16 			Surface::Rect::getWidth(void) const
  {
    return (this->m_rect.w);
  }

  Uint16 			Surface::Rect::getHeight(void) const
  {
    return (this->m_rect.h);
  }

  SDL_Rect const		&Surface::Rect::getRect(void) const
  {
    return (this->m_rect);
  }
}
