//
// Minisdl_image.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs/Graphic
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Wed Aug 17 16:44:50 2016 Sébastien Le Maire
// Last update Wed Aug 24 13:46:17 2016 Sébastien Le Maire
//

#ifndef MINISDL_IMAGE_HPP_
# define MINISDL_IMAGE_HPP_

namespace			MSDL
{
  class				Image : public MSDL::Surface
  {
  public: /* ctor & dtor */
    Image(Uint16 const width, Uint16 const height,
	  MSDL::Pixel const &color = _MSDL_BLACK_);
    Image(char const *imageName);
    ~Image(void);

  public: /* Methods */
    void			setTransparency(MSDL::Pixel const &color);
    void			setAlpha(Uint8 const alpha);
  };
}

#endif /* !MINISDL_IMAGE_HPP_ */
