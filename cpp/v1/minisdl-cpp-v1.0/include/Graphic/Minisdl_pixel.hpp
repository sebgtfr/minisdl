//
// Minisdl_pixel.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/include
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Fri Jun  3 23:50:19 2016 Sébastien Le Maire
// Last update Wed Aug 17 17:46:33 2016 Sébastien Le Maire
//

#ifndef MINISDL_PIXEL_HPP_
# define MINISDL_PIXEL_HPP_

# include <iostream>

namespace			MSDL
{
#  if SDL_BYTEORDER == SDL_BIG_ENDIAN

#   define MSDL_ENDIAN_IDX	(-8)
#   define MSDL_ENDIAN_DEC	(16)
#   define MSDL_ENDIAN_INV     	(0)

  enum			        ComponantPixel
    {
				A = 0,
				R,
				G,
				B,
    };

  /*
  ** Basic Colors
  */
# define _MSDL_BLACK_		(0x000000FF)
# define _MSDL_RED_		(0x0000FFFF)
# define _MSDL_GREEN_		(0x00FF00FF)
# define _MSDL_BLUE_		(0xFF0000FF)
# define _MSDL_WHITE_		(0xFFFFFFFF)
  /*
  ** Extra Colors
  */
# define _MSDL_PURPLE_		(0x990066FF)
# define _MSDL_BROWN_		(0x002958FF)
# define _MSDL_YELLOW_		(0x07D8EFFF)
# define _MSDL_ORANGE_		(0xFFED7F10)
# define _MSDL_ORANGE_		(0x107FEDFF)
# define _MSDL_GREY_		(0x7F7F7FFF)

  /*
  ** Color Mask
  */
# define _MSDL_RMASK_		(0xFF000000)
# define _MSDL_GMASK_		(0x00FF0000)
# define _MSDL_BMASK_		(0x0000FF00)
# define _MSDL_AMASK_		(0x000000FF)

#  else

#   define MSDL_ENDIAN_IDX	(-8)
#   define MSDL_ENDIAN_DEC	(0)
#   define MSDL_ENDIAN_INV     	(16)

    enum			ComponantPixel
    {
				B = 0,
				G,
				R,
				A,
    };

  /*
  ** Basic Colors
  */
# define _MSDL_BLACK_		(0xFF000000)
# define _MSDL_RED_		(0xFFFF0000)
# define _MSDL_GREEN_		(0xFF00FF00)
# define _MSDL_BLUE_		(0xFF0000FF)
# define _MSDL_WHITE_		(0xFFFFFFFF)
  /*
  ** Extra Colors
  */
# define _MSDL_PURPLE_		(0xFF660099)
# define _MSDL_BROWN_		(0xFF582900)
# define _MSDL_YELLOW_		(0xFFEFD807)
# define _MSDL_ORANGE_		(0xFFED7F10)
# define _MSDL_GREY_		(0xFF7F7F7F)

  /*
  ** Color Mask
  */
# define _MSDL_RMASK_		(0x000000FF)
# define _MSDL_GMASK_		(0x0000FF00)
# define _MSDL_BMASK_		(0x00FF0000)
# define _MSDL_AMASK_		(0xFF000000)

# endif /* !SDL_BYTEORDER == SDL_BIG_ENDIAN */

  union				Pixel
  {
    Uint32			pix32;
    Uint16			pix16;
    Uint8			pix8;
    Uint8			componant[4];

    /*
    ** Ctors
    */
    Pixel(void);
    Pixel(Uint8 const &i);
    Pixel(Uint16 const &i);
    Pixel(Uint32 const &i);
    Pixel(Sint8 const &i);
    Pixel(Sint16 const &i);
    Pixel(Sint32 const &i);
    Pixel(MSDL::Pixel const &pixel);

    /*
    ** Operator =
    */
    MSDL::Pixel			&operator=(Uint8 const &i);
    MSDL::Pixel			&operator=(Uint16 const &i);
    MSDL::Pixel			&operator=(Uint32 const &i);
    MSDL::Pixel			&operator=(Sint8 const &i);
    MSDL::Pixel			&operator=(Sint16 const &i);
    MSDL::Pixel			&operator=(Sint32 const &i);
    MSDL::Pixel			&operator=(MSDL::Pixel const &pixel);

    /*
    ** Operator []
    */
    Uint8			&operator[](Uint8 const &i);
    Uint8			&operator[](Uint16 const &i);
    Uint8			&operator[](Uint32 const &i);
    Uint8			&operator[](Sint8 const &i);
    Uint8			&operator[](Sint16 const &i);
    Uint8			&operator[](Sint32 const &i);
    Uint8			&operator[](MSDL::ComponantPixel const &i);

    /*
    ** Arithmetic Operators
    ** Operator +=
    */
    MSDL::Pixel			&operator+=(Uint8 const &i);
    MSDL::Pixel			&operator+=(Uint16 const &i);
    MSDL::Pixel			&operator+=(Uint32 const &i);
    MSDL::Pixel			&operator+=(Sint8 const &i);
    MSDL::Pixel			&operator+=(Sint16 const &i);
    MSDL::Pixel			&operator+=(Sint32 const &i);
    MSDL::Pixel			&operator+=(MSDL::Pixel const &pixel);

    /*
    ** Operator -=
    */
    MSDL::Pixel			&operator-=(Uint8 const &i);
    MSDL::Pixel			&operator-=(Uint16 const &i);
    MSDL::Pixel			&operator-=(Uint32 const &i);
    MSDL::Pixel			&operator-=(Sint8 const &i);
    MSDL::Pixel			&operator-=(Sint16 const &i);
    MSDL::Pixel			&operator-=(Sint32 const &i);
    MSDL::Pixel			&operator-=(MSDL::Pixel const &pixel);

    /*
    ** Operator *=
    */
    MSDL::Pixel			&operator*=(Uint8 const &i);
    MSDL::Pixel			&operator*=(Uint16 const &i);
    MSDL::Pixel			&operator*=(Uint32 const &i);
    MSDL::Pixel			&operator*=(Sint8 const &i);
    MSDL::Pixel			&operator*=(Sint16 const &i);
    MSDL::Pixel			&operator*=(Sint32 const &i);
    MSDL::Pixel			&operator*=(MSDL::Pixel const &pixel);

    /*
    ** Operator /=
    */
    MSDL::Pixel			&operator/=(Uint8 const &i);
    MSDL::Pixel			&operator/=(Uint16 const &i);
    MSDL::Pixel			&operator/=(Uint32 const &i);
    MSDL::Pixel			&operator/=(Sint8 const &i);
    MSDL::Pixel			&operator/=(Sint16 const &i);
    MSDL::Pixel			&operator/=(Sint32 const &i);
    MSDL::Pixel			&operator/=(MSDL::Pixel const &pixel);

    /*
    ** Operator %=
    */
    MSDL::Pixel			&operator%=(Uint8 const &i);
    MSDL::Pixel			&operator%=(Uint16 const &i);
    MSDL::Pixel			&operator%=(Uint32 const &i);
    MSDL::Pixel			&operator%=(Sint8 const &i);
    MSDL::Pixel			&operator%=(Sint16 const &i);
    MSDL::Pixel			&operator%=(Sint32 const &i);
    MSDL::Pixel			&operator%=(MSDL::Pixel const &pixel);

    /*
    ** Operator &=
    */
    MSDL::Pixel			&operator&=(Uint8 const &i);
    MSDL::Pixel			&operator&=(Uint16 const &i);
    MSDL::Pixel			&operator&=(Uint32 const &i);
    MSDL::Pixel			&operator&=(Sint8 const &i);
    MSDL::Pixel			&operator&=(Sint16 const &i);
    MSDL::Pixel			&operator&=(Sint32 const &i);
    MSDL::Pixel			&operator&=(MSDL::Pixel const &pixel);

    /*
    ** Operator |=
    */
    MSDL::Pixel			&operator|=(Uint8 const &i);
    MSDL::Pixel			&operator|=(Uint16 const &i);
    MSDL::Pixel			&operator|=(Uint32 const &i);
    MSDL::Pixel			&operator|=(Sint8 const &i);
    MSDL::Pixel			&operator|=(Sint16 const &i);
    MSDL::Pixel			&operator|=(Sint32 const &i);
    MSDL::Pixel			&operator|=(MSDL::Pixel const &pixel);

    /*
    ** Operator ^=
    */
    MSDL::Pixel			&operator^=(Uint8 const &i);
    MSDL::Pixel			&operator^=(Uint16 const &i);
    MSDL::Pixel			&operator^=(Uint32 const &i);
    MSDL::Pixel			&operator^=(Sint8 const &i);
    MSDL::Pixel			&operator^=(Sint16 const &i);
    MSDL::Pixel			&operator^=(Sint32 const &i);
    MSDL::Pixel			&operator^=(MSDL::Pixel const &pixel);

    /*
    ** Operator <<=
    */
    MSDL::Pixel			&operator<<=(Uint8 const &i);
    MSDL::Pixel			&operator<<=(Uint16 const &i);
    MSDL::Pixel			&operator<<=(Uint32 const &i);
    MSDL::Pixel			&operator<<=(Sint8 const &i);
    MSDL::Pixel			&operator<<=(Sint16 const &i);
    MSDL::Pixel			&operator<<=(Sint32 const &i);
    MSDL::Pixel			&operator<<=(MSDL::Pixel const &pixel);

    /*
    ** Operator >>=
    */
    MSDL::Pixel			&operator>>=(Uint8 const &i);
    MSDL::Pixel			&operator>>=(Uint16 const &i);
    MSDL::Pixel			&operator>>=(Uint32 const &i);
    MSDL::Pixel			&operator>>=(Sint8 const &i);
    MSDL::Pixel			&operator>>=(Sint16 const &i);
    MSDL::Pixel			&operator>>=(Sint32 const &i);
    MSDL::Pixel			&operator>>=(MSDL::Pixel const &pixel);

    /*
    ** Operator +
    */
    MSDL::Pixel			operator+(Uint8 const &i) const;
    MSDL::Pixel			operator+(Uint16 const &i) const;
    MSDL::Pixel			operator+(Uint32 const &i) const;
    MSDL::Pixel			operator+(Sint8 const &i) const;
    MSDL::Pixel			operator+(Sint16 const &i) const;
    MSDL::Pixel			operator+(Sint32 const &i) const;
    MSDL::Pixel			operator+(MSDL::Pixel const &pixel) const;

    /*
    ** Operator -
    */
    MSDL::Pixel			operator-(Uint8 const &i) const;
    MSDL::Pixel			operator-(Uint16 const &i) const;
    MSDL::Pixel			operator-(Uint32 const &i) const;
    MSDL::Pixel			operator-(Sint8 const &i) const;
    MSDL::Pixel			operator-(Sint16 const &i) const;
    MSDL::Pixel			operator-(Sint32 const &i) const;
    MSDL::Pixel			operator-(MSDL::Pixel const &pixel) const;

    /*
    ** Operator *
    */
    MSDL::Pixel			operator*(Uint8 const &i) const;
    MSDL::Pixel			operator*(Uint16 const &i) const;
    MSDL::Pixel			operator*(Uint32 const &i) const;
    MSDL::Pixel			operator*(Sint8 const &i) const;
    MSDL::Pixel			operator*(Sint16 const &i) const;
    MSDL::Pixel			operator*(Sint32 const &i) const;
    MSDL::Pixel			operator*(MSDL::Pixel const &pixel) const;

    /*
    ** Operator /
    */
    MSDL::Pixel			operator/(Uint8 const &i) const;
    MSDL::Pixel			operator/(Uint16 const &i) const;
    MSDL::Pixel			operator/(Uint32 const &i) const;
    MSDL::Pixel			operator/(Sint8 const &i) const;
    MSDL::Pixel			operator/(Sint16 const &i) const;
    MSDL::Pixel			operator/(Sint32 const &i) const;
    MSDL::Pixel			operator/(MSDL::Pixel const &pixel) const;

    /*
    ** Operator %
    */
    MSDL::Pixel			operator%(Uint8 const &i) const;
    MSDL::Pixel			operator%(Uint16 const &i) const;
    MSDL::Pixel			operator%(Uint32 const &i) const;
    MSDL::Pixel			operator%(Sint8 const &i) const;
    MSDL::Pixel			operator%(Sint16 const &i) const;
    MSDL::Pixel			operator%(Sint32 const &i) const;
    MSDL::Pixel			operator%(MSDL::Pixel const &pixel) const;

    /*
    ** Logical Operator
    ** Operator &
    */
    MSDL::Pixel			operator&(Uint8 const &i) const;
    MSDL::Pixel			operator&(Uint16 const &i) const;
    MSDL::Pixel			operator&(Uint32 const &i) const;
    MSDL::Pixel			operator&(Sint8 const &i) const;
    MSDL::Pixel			operator&(Sint16 const &i) const;
    MSDL::Pixel			operator&(Sint32 const &i) const;
    MSDL::Pixel			operator&(MSDL::Pixel const &pixel) const;

    /*
    ** Operator |
    */
    MSDL::Pixel			operator|(Uint8 const &i) const;
    MSDL::Pixel			operator|(Uint16 const &i) const;
    MSDL::Pixel			operator|(Uint32 const &i) const;
    MSDL::Pixel			operator|(Sint8 const &i) const;
    MSDL::Pixel			operator|(Sint16 const &i) const;
    MSDL::Pixel			operator|(Sint32 const &i) const;
    MSDL::Pixel			operator|(MSDL::Pixel const &pixel) const;

    /*
    ** Operator ^
    */
    MSDL::Pixel			operator^(Uint8 const &i) const;
    MSDL::Pixel			operator^(Uint16 const &i) const;
    MSDL::Pixel			operator^(Uint32 const &i) const;
    MSDL::Pixel			operator^(Sint8 const &i) const;
    MSDL::Pixel			operator^(Sint16 const &i) const;
    MSDL::Pixel			operator^(Sint32 const &i) const;
    MSDL::Pixel			operator^(MSDL::Pixel const &pixel) const;

    /*
    ** Operator <<
    */
    MSDL::Pixel			operator<<(Uint8 const &i) const;
    MSDL::Pixel			operator<<(Uint16 const &i) const;
    MSDL::Pixel			operator<<(Uint32 const &i) const;
    MSDL::Pixel			operator<<(Sint8 const &i) const;
    MSDL::Pixel			operator<<(Sint16 const &i) const;
    MSDL::Pixel			operator<<(Sint32 const &i) const;
    MSDL::Pixel			operator<<(MSDL::Pixel const &pixel) const;

    /*
    ** Operator >>
    */
    MSDL::Pixel			operator>>(Uint8 const &i) const;
    MSDL::Pixel			operator>>(Uint16 const &i) const;
    MSDL::Pixel			operator>>(Uint32 const &i) const;
    MSDL::Pixel			operator>>(Sint8 const &i) const;
    MSDL::Pixel			operator>>(Sint16 const &i) const;
    MSDL::Pixel			operator>>(Sint32 const &i) const;
    MSDL::Pixel			operator>>(MSDL::Pixel const &pixel) const;

    /*
    ** Logical Operator
    ** Operator !
    */
    bool			operator!(void) const;

    /*
    ** Operator &&
    */
    bool			operator&&(Uint8 const &i) const;
    bool			operator&&(Uint16 const &i) const;
    bool			operator&&(Uint32 const &i) const;
    bool			operator&&(Sint8 const &i) const;
    bool			operator&&(Sint16 const &i) const;
    bool			operator&&(Sint32 const &i) const;
    bool			operator&&(MSDL::Pixel const &pixel) const;

    /*
    ** Operator ||
    */
    bool			operator||(Uint8 const &i) const;
    bool			operator||(Uint16 const &i) const;
    bool			operator||(Uint32 const &i) const;
    bool			operator||(Sint8 const &i) const;
    bool			operator||(Sint16 const &i) const;
    bool			operator||(Sint32 const &i) const;
    bool			operator||(MSDL::Pixel const &pixel) const;

    /*
    ** Comparison Operator
    ** Operator ==
    */
    bool			operator==(Uint8 const &i) const;
    bool			operator==(Uint16 const &i) const;
    bool			operator==(Uint32 const &i) const;
    bool			operator==(Sint8 const &i) const;
    bool			operator==(Sint16 const &i) const;
    bool			operator==(Sint32 const &i) const;
    bool			operator==(MSDL::Pixel const &pixel) const;

    /*
    ** Operator !=
    */
    bool			operator!=(Uint8 const &i) const;
    bool			operator!=(Uint16 const &i) const;
    bool			operator!=(Uint32 const &i) const;
    bool			operator!=(Sint8 const &i) const;
    bool			operator!=(Sint16 const &i) const;
    bool			operator!=(Sint32 const &i) const;
    bool			operator!=(MSDL::Pixel const &pixel) const;

    /*
    ** Operator <
    */
    bool			operator<(Uint8 const &i) const;
    bool			operator<(Uint16 const &i) const;
    bool			operator<(Uint32 const &i) const;
    bool			operator<(Sint8 const &i) const;
    bool			operator<(Sint16 const &i) const;
    bool			operator<(Sint32 const &i) const;
    bool			operator<(MSDL::Pixel const &pixel) const;

    /*
    ** Operator >
    */
    bool			operator>(Uint8 const &i) const;
    bool			operator>(Uint16 const &i) const;
    bool			operator>(Uint32 const &i) const;
    bool			operator>(Sint8 const &i) const;
    bool			operator>(Sint16 const &i) const;
    bool			operator>(Sint32 const &i) const;
    bool			operator>(MSDL::Pixel const &pixel) const;

    /*
    ** Operator <=
    */
    bool			operator<=(Uint8 const &i) const;
    bool			operator<=(Uint16 const &i) const;
    bool			operator<=(Uint32 const &i) const;
    bool			operator<=(Sint8 const &i) const;
    bool			operator<=(Sint16 const &i) const;
    bool			operator<=(Sint32 const &i) const;
    bool			operator<=(MSDL::Pixel const &pixel) const;

    /*
    ** Operator >=
    */
    bool			operator>=(Uint8 const &i) const;
    bool			operator>=(Uint16 const &i) const;
    bool			operator>=(Uint32 const &i) const;
    bool			operator>=(Sint8 const &i) const;
    bool			operator>=(Sint16 const &i) const;
    bool			operator>=(Sint32 const &i) const;
    bool			operator>=(MSDL::Pixel const &pixel) const;
  };

  /*
  ** Extern operator
  ** Operator << with std::ostream for debug
  */
  std::ostream			&operator<<(std::ostream &os,
					    MSDL::Pixel const &pixel);
}

#endif /* !MINISDL_PIXEL_HPP_ */
