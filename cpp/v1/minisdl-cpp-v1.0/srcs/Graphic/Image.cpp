//
// Image.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs/Graphic
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Wed Aug 17 16:44:34 2016 Sébastien Le Maire
// Last update Wed Aug 24 13:45:01 2016 Sébastien Le Maire
//

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Minisdl_exception.hpp"
#include "Minisdl_pixel.hpp"
#include "Minisdl_surface.hpp"
#include "Minisdl_image.hpp"

namespace			MSDL
{

  Image::Image(Uint16 const width, Uint16 const height, MSDL::Pixel const &color)
  {
    if ((!(this->m_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height, 32,
						 _MSDL_RMASK_, _MSDL_GMASK_,
						  _MSDL_BMASK_, _MSDL_AMASK_))) ||
	(SDL_FillRect(this->m_surface, NULL, SDL_MapRGB(this->m_surface->format,
							color.componant[MSDL::R],
							color.componant[MSDL::G],
							color.componant[MSDL::B]))))
      throw MSDL::Exception(MSDL::Exception::INIT_IMAGE_SURFACE);
  }

  Image::Image(char const *imageName)
  {
    SDL_Surface			*image;

    if ((!(image = IMG_Load(imageName))) ||
	(!(this->m_surface = SDL_DisplayFormat(image))))
      throw MSDL::Exception(MSDL::Exception::INIT_IMAGE_LOAD);
    SDL_FreeSurface(image);
  }

  Image::~Image(void)
  {
  }

  /*
  ** Methods
  */

  void				Image::setTransparency(MSDL::Pixel const &color)
  {
    if (SDL_SetColorKey(this->m_surface, SDL_SRCCOLORKEY,
			SDL_MapRGB(this->m_surface->format,
				   color.componant[MSDL::R],
				   color.componant[MSDL::G],
				   color.componant[MSDL::B])))
      throw MSDL::Exception(MSDL::Exception::IMAGE_TRANSPARENCY);
  }

  void				Image::setAlpha(Uint8 const alpha)
  {
    if (SDL_SetAlpha(this->m_surface, SDL_SRCALPHA, alpha))
      throw MSDL::Exception(MSDL::Exception::IMAGE_ALPHA);
  }

}
