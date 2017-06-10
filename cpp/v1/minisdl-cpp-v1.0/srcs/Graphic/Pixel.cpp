//
// Pixel.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Fri Jun  3 23:49:10 2016 Sébastien Le Maire
// Last update Sat Jun 18 21:50:52 2016 Sébastien Le Maire
//

#include "SDL.h"
#include "Minisdl_exception.hpp"
#include "Minisdl_pixel.hpp"

namespace			MSDL
{
  /*
  ** Ctors
  */
  Pixel::Pixel(void) : pix32(0)
  {
  };

  Pixel::Pixel(Uint8 const &i) : pix8(i)
  {
  };

  Pixel::Pixel(Uint16 const &i) : pix16(i)
  {
  };

  Pixel::Pixel(Uint32 const &i) : pix32(i)
  {
  };

  Pixel::Pixel(Sint8 const &i) : pix8(i)
  {
  };

  Pixel::Pixel(Sint16 const &i) : pix16(i)
  {
  };

  Pixel::Pixel(Sint32 const &i) : pix32(i)
  {
  };

  Pixel::Pixel(MSDL::Pixel const &pixel) : pix32(pixel.pix32)
  {
  };

  /*
  ** Operator =
  */
  MSDL::Pixel			&Pixel::operator=(Uint8 const &i)
  {
    this->pix8 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(Uint16 const &i)
  {
    this->pix16 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(Uint32 const &i)
  {
    this->pix32 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(Sint8 const &i)
  {
    this->pix8 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(Sint16 const &i)
  {
    this->pix16 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(Sint32 const &i)
  {
    this->pix32 = i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator=(MSDL::Pixel const &pixel)
  {
    if (this != &pixel)
      this->pix32 = pixel.pix32;
    return (*this);
  }

  /*
  ** Pixel::Operator []
  */
  Uint8				&Pixel::operator[](Uint8 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](Uint16 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](Uint32 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](Sint8 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](Sint16 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](Sint32 const &i)
  {
    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[i]);
  };

  Uint8				&Pixel::operator[](MSDL::ComponantPixel const &i)
  {
    Uint8			index = static_cast<Uint8>(i);

    if (i > 3)
      throw MSDL::Exception(MSDL::Exception::PIXEL_COMPONANT_OUT_RANGE);
    return (this->componant[index]);
  };

  /*
  ** Operator +=
  */
  MSDL::Pixel			&Pixel::operator+=(Uint8 const &i)
  {
    this->pix8 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(Uint16 const &i)
  {
    this->pix16 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(Uint32 const &i)
  {
    this->pix32 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(Sint8 const &i)
  {
    this->pix8 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(Sint16 const &i)
  {
    this->pix16 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(Sint32 const &i)
  {
    this->pix32 += i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator+=(MSDL::Pixel const &pixel)
  {
    this->pix32 += pixel.pix32;
    return (*this);
  }

  /*
  ** Operator -=
  */
  MSDL::Pixel			&Pixel::operator-=(Uint8 const &i)
  {
    this->pix8 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(Uint16 const &i)
  {
    this->pix16 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(Uint32 const &i)
  {
    this->pix32 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(Sint8 const &i)
  {
    this->pix8 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(Sint16 const &i)
  {
    this->pix16 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(Sint32 const &i)
  {
    this->pix32 -= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator-=(MSDL::Pixel const &pixel)
  {
    this->pix32 -= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator *=
  */
  MSDL::Pixel			&Pixel::operator*=(Uint8 const &i)
  {
    this->pix8 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(Uint16 const &i)
  {
    this->pix16 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(Uint32 const &i)
  {
    this->pix32 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(Sint8 const &i)
  {
    this->pix8 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(Sint16 const &i)
  {
    this->pix16 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(Sint32 const &i)
  {
    this->pix32 *= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator*=(MSDL::Pixel const &pixel)
  {
    this->pix32 *= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator /=
  */
  MSDL::Pixel			&Pixel::operator/=(Uint8 const &i)
  {
    this->pix8 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(Uint16 const &i)
  {
    this->pix16 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(Uint32 const &i)
  {
    this->pix32 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(Sint8 const &i)
  {
    this->pix8 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(Sint16 const &i)
  {
    this->pix16 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(Sint32 const &i)
  {
    this->pix32 /= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator/=(MSDL::Pixel const &pixel)
  {
    this->pix32 /= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator %=
  */
  MSDL::Pixel			&Pixel::operator%=(Uint8 const &i)
  {
    this->pix8 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(Uint16 const &i)
  {
    this->pix16 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(Uint32 const &i)
  {
    this->pix32 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(Sint8 const &i)
  {
    this->pix8 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(Sint16 const &i)
  {
    this->pix16 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(Sint32 const &i)
  {
    this->pix32 %= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator%=(MSDL::Pixel const &pixel)
  {
    this->pix32 %= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator &=
  */
  MSDL::Pixel			&Pixel::operator&=(Uint8 const &i)
  {
    this->pix8 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(Uint16 const &i)
  {
    this->pix16 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(Uint32 const &i)
  {
    this->pix32 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(Sint8 const &i)
  {
    this->pix8 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(Sint16 const &i)
  {
    this->pix16 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(Sint32 const &i)
  {
    this->pix32 &= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator&=(MSDL::Pixel const &pixel)
  {
    this->pix32 &= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator |=
  */
  MSDL::Pixel			&Pixel::operator|=(Uint8 const &i)
  {
    this->pix8 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(Uint16 const &i)
  {
    this->pix16 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(Uint32 const &i)
  {
    this->pix32 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(Sint8 const &i)
  {
    this->pix8 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(Sint16 const &i)
  {
    this->pix16 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(Sint32 const &i)
  {
    this->pix32 |= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator|=(MSDL::Pixel const &pixel)
  {
    this->pix32 |= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator ^=
  */
  MSDL::Pixel			&Pixel::operator^=(Uint8 const &i)
  {
    this->pix8 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(Uint16 const &i)
  {
    this->pix16 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(Uint32 const &i)
  {
    this->pix32 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(Sint8 const &i)
  {
    this->pix8 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(Sint16 const &i)
  {
    this->pix16 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(Sint32 const &i)
  {
    this->pix32 ^= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator^=(MSDL::Pixel const &pixel)
  {
    this->pix32 ^= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator <<=
  */
  MSDL::Pixel			&Pixel::operator<<=(Uint8 const &i)
  {
    this->pix8 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(Uint16 const &i)
  {
    this->pix16 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(Uint32 const &i)
  {
    this->pix32 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(Sint8 const &i)
  {
    this->pix8 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(Sint16 const &i)
  {
    this->pix16 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(Sint32 const &i)
  {
    this->pix32 <<= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator<<=(MSDL::Pixel const &pixel)
  {
    this->pix32 <<= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator >>=
  */
  MSDL::Pixel			&Pixel::operator>>=(Uint8 const &i)
  {
    this->pix8 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(Uint16 const &i)
  {
    this->pix16 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(Uint32 const &i)
  {
    this->pix32 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(Sint8 const &i)
  {
    this->pix8 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(Sint16 const &i)
  {
    this->pix16 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(Sint32 const &i)
  {
    this->pix32 >>= i;
    return (*this);
  };

  MSDL::Pixel			&Pixel::operator>>=(MSDL::Pixel const &pixel)
  {
    this->pix32 >>= pixel.pix32;
    return (*this);
  }

  /*
  ** Operator +
  */
  MSDL::Pixel			Pixel::operator+(Uint8 const &i) const
  {
    return (this->pix8 + i);
  };

  MSDL::Pixel			Pixel::operator+(Uint16 const &i) const
  {
    return (this->pix16 + i);
  };

  MSDL::Pixel			Pixel::operator+(Uint32 const &i) const
  {
    return (this->pix32 + i);
  };

  MSDL::Pixel			Pixel::operator+(Sint8 const &i) const
  {
    return (this->pix8 + i);
  };

  MSDL::Pixel			Pixel::operator+(Sint16 const &i) const
  {
    return (this->pix16 + i);
  };

  MSDL::Pixel			Pixel::operator+(Sint32 const &i) const
  {
    return (this->pix32 + i);
  };

  MSDL::Pixel			Pixel::operator+(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 + pixel.pix32);
  }

  /*
  ** Operator -
  */
  MSDL::Pixel			Pixel::operator-(Uint8 const &i) const
  {
    return (this->pix8 - i);
  };

  MSDL::Pixel			Pixel::operator-(Uint16 const &i) const
  {
    return (this->pix16 - i);
  };

  MSDL::Pixel			Pixel::operator-(Uint32 const &i) const
  {
    return (this->pix32 - i);
  };

  MSDL::Pixel			Pixel::operator-(Sint8 const &i) const
  {
    return (this->pix8 - i);
  };

  MSDL::Pixel			Pixel::operator-(Sint16 const &i) const
  {
    return (this->pix16 - i);
  };

  MSDL::Pixel			Pixel::operator-(Sint32 const &i) const
  {
    return (this->pix32 - i);
  };

  MSDL::Pixel			Pixel::operator-(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 - pixel.pix32);
  }

  /*
  ** Operator *
  */
  MSDL::Pixel			Pixel::operator*(Uint8 const &i) const
  {
    return (this->pix8 * i);
  };

  MSDL::Pixel			Pixel::operator*(Uint16 const &i) const
  {
    return (this->pix16 * i);
  };

  MSDL::Pixel			Pixel::operator*(Uint32 const &i) const
  {
    return (this->pix32 * i);
  };

  MSDL::Pixel			Pixel::operator*(Sint8 const &i) const
  {
    return (this->pix8 * i);
  };

  MSDL::Pixel			Pixel::operator*(Sint16 const &i) const
  {
    return (this->pix16 * i);
  };

  MSDL::Pixel			Pixel::operator*(Sint32 const &i) const
  {
    return (this->pix32 * i);
  };

  MSDL::Pixel			Pixel::operator*(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 * pixel.pix32);
  }

  /*
  ** Operator /
  */
  MSDL::Pixel			Pixel::operator/(Uint8 const &i) const
  {
    return (this->pix8 / i);
  };

  MSDL::Pixel			Pixel::operator/(Uint16 const &i) const
  {
    return (this->pix16 / i);
  };

  MSDL::Pixel			Pixel::operator/(Uint32 const &i) const
  {
    return (this->pix32 / i);
  };

  MSDL::Pixel			Pixel::operator/(Sint8 const &i) const
  {
    return (this->pix8 / i);
  };

  MSDL::Pixel			Pixel::operator/(Sint16 const &i) const
  {
    return (this->pix16 / i);
  };

  MSDL::Pixel			Pixel::operator/(Sint32 const &i) const
  {
    return (this->pix32 / i);
  };

  MSDL::Pixel			Pixel::operator/(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 / pixel.pix32);
  }

  /*
  ** Operator %
  */
  MSDL::Pixel			Pixel::operator%(Uint8 const &i) const
  {
    return (this->pix8 % i);
  };

  MSDL::Pixel			Pixel::operator%(Uint16 const &i) const
  {
    return (this->pix16 % i);
  };

  MSDL::Pixel			Pixel::operator%(Uint32 const &i) const
  {
    return (this->pix32 % i);
  };

  MSDL::Pixel			Pixel::operator%(Sint8 const &i) const
  {
    return (this->pix8 % i);
  };

  MSDL::Pixel			Pixel::operator%(Sint16 const &i) const
  {
    return (this->pix16 % i);
  };

  MSDL::Pixel			Pixel::operator%(Sint32 const &i) const
  {
    return (this->pix32 % i);
  };

  MSDL::Pixel			Pixel::operator%(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 % pixel.pix32);
  }

  /*
  ** Operator &
  */
  MSDL::Pixel			Pixel::operator&(Uint8 const &i) const
  {
    return (this->pix8 & i);
  };

  MSDL::Pixel			Pixel::operator&(Uint16 const &i) const
  {
    return (this->pix16 & i);
  };

  MSDL::Pixel			Pixel::operator&(Uint32 const &i) const
  {
    return (this->pix32 & i);
  };

  MSDL::Pixel			Pixel::operator&(Sint8 const &i) const
  {
    return (this->pix8 & i);
  };

  MSDL::Pixel			Pixel::operator&(Sint16 const &i) const
  {
    return (this->pix16 & i);
  };

  MSDL::Pixel			Pixel::operator&(Sint32 const &i) const
  {
    return (this->pix32 & i);
  };

  MSDL::Pixel			Pixel::operator&(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 & pixel.pix32);
  }

  /*
  ** Operator |
  */
  MSDL::Pixel			Pixel::operator|(Uint8 const &i) const
  {
    return (this->pix8 | i);
  };

  MSDL::Pixel			Pixel::operator|(Uint16 const &i) const
  {
    return (this->pix16 | i);
  };

  MSDL::Pixel			Pixel::operator|(Uint32 const &i) const
  {
    return (this->pix32 | i);
  };

  MSDL::Pixel			Pixel::operator|(Sint8 const &i) const
  {
    return (this->pix8 | i);
  };

  MSDL::Pixel			Pixel::operator|(Sint16 const &i) const
  {
    return (this->pix16 | i);
  };

  MSDL::Pixel			Pixel::operator|(Sint32 const &i) const
  {
    return (this->pix32 | i);
  };

  MSDL::Pixel			Pixel::operator|(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 | pixel.pix32);
  }

  /*
  ** Operator ^
  */
  MSDL::Pixel			Pixel::operator^(Uint8 const &i) const
  {
    return (this->pix8 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(Uint16 const &i) const
  {
    return (this->pix16 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(Uint32 const &i) const
  {
    return (this->pix32 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(Sint8 const &i) const
  {
    return (this->pix8 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(Sint16 const &i) const
  {
    return (this->pix16 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(Sint32 const &i) const
  {
    return (this->pix32 ^ i);
  };

  MSDL::Pixel			Pixel::operator^(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 ^ pixel.pix32);
  }

  /*
  ** Operator <<
  */
  MSDL::Pixel			Pixel::operator<<(Uint8 const &i) const
  {
    return (this->pix8 << i);
  };

  MSDL::Pixel			Pixel::operator<<(Uint16 const &i) const
  {
    return (this->pix16 << i);
  };

  MSDL::Pixel			Pixel::operator<<(Uint32 const &i) const
  {
    return (this->pix32 << i);
  };

  MSDL::Pixel			Pixel::operator<<(Sint8 const &i) const
  {
    return (this->pix8 << i);
  };

  MSDL::Pixel			Pixel::operator<<(Sint16 const &i) const
  {
    return (this->pix16 << i);
  };

  MSDL::Pixel			Pixel::operator<<(Sint32 const &i) const
  {
    return (this->pix32 << i);
  };

  MSDL::Pixel			Pixel::operator<<(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 << pixel.pix32);
  }

  /*
  ** Operator >>
  */
  MSDL::Pixel			Pixel::operator>>(Uint8 const &i) const
  {
    return (this->pix8 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(Uint16 const &i) const
  {
    return (this->pix16 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(Uint32 const &i) const
  {
    return (this->pix32 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(Sint8 const &i) const
  {
    return (this->pix8 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(Sint16 const &i) const
  {
    return (this->pix16 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(Sint32 const &i) const
  {
    return (this->pix32 >> i);
  };

  MSDL::Pixel			Pixel::operator>>(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 >> pixel.pix32);
  }

  /*
  ** Logical Operator
  ** Operator !
  */
  bool				Pixel::operator!(void) const
  {
    return (!this->pix32);
  }

  /*
  ** Operator &&
  */
  bool				Pixel::operator&&(Uint8 const &i) const
  {
    return (this->pix8 && i);
  }

  bool				Pixel::operator&&(Uint16 const &i) const
  {
    return (this->pix16 && i);
  }

  bool				Pixel::operator&&(Uint32 const &i) const
  {
    return (this->pix32 && i);
  }

  bool				Pixel::operator&&(Sint8 const &i) const
  {
    return (this->pix8 && static_cast<Uint8>(i));
  }

  bool				Pixel::operator&&(Sint16 const &i) const
  {
    return (this->pix16 && static_cast<Uint16>(i));
  }

  bool				Pixel::operator&&(Sint32 const &i) const
  {
    return (this->pix32 && static_cast<Uint32>(i));
  }

  bool				Pixel::operator&&(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 && pixel.pix32);
  }

  /*
  ** Operator ||
  */
  bool				Pixel::operator||(Uint8 const &i) const
  {
    return (this->pix8 || i);
  }

  bool				Pixel::operator||(Uint16 const &i) const
  {
    return (this->pix16 || i);
  }

  bool				Pixel::operator||(Uint32 const &i) const
  {
    return (this->pix32 || i);
  }

  bool				Pixel::operator||(Sint8 const &i) const
  {
    return (this->pix8 || static_cast<Uint8>(i));
  }

  bool				Pixel::operator||(Sint16 const &i) const
  {
    return (this->pix16 || static_cast<Uint16>(i));
  }

  bool				Pixel::operator||(Sint32 const &i) const
  {
    return (this->pix32 || static_cast<Uint32>(i));
  }

  bool				Pixel::operator||(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 || pixel.pix32);
  }

  /*
  ** Comparison Operator
  ** Operator ==
  */
  bool				Pixel::operator==(Uint8 const &i) const
  {
    return (this->pix8 == i);
  }

  bool				Pixel::operator==(Uint16 const &i) const
  {
    return (this->pix16 == i);
  }

  bool				Pixel::operator==(Uint32 const &i) const
  {
    return (this->pix32 == i);
  }

  bool				Pixel::operator==(Sint8 const &i) const
  {
    return (this->pix8 == static_cast<Uint8>(i));
  }

  bool				Pixel::operator==(Sint16 const &i) const
  {
    return (this->pix16 == static_cast<Uint16>(i));
  }

  bool				Pixel::operator==(Sint32 const &i) const
  {
    return (this->pix32 == static_cast<Uint32>(i));
  }

  bool				Pixel::operator==(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 == pixel.pix32);
  }

  /*
  ** Operator !=
  */
  bool				Pixel::operator!=(Uint8 const &i) const
  {
    return (this->pix8 != i);
  }

  bool				Pixel::operator!=(Uint16 const &i) const
  {
    return (this->pix16 != i);
  }

  bool				Pixel::operator!=(Uint32 const &i) const
  {
    return (this->pix32 != i);
  }

  bool				Pixel::operator!=(Sint8 const &i) const
  {
    return (this->pix8 != static_cast<Uint8>(i));
  }

  bool				Pixel::operator!=(Sint16 const &i) const
  {
    return (this->pix16 != static_cast<Uint16>(i));
  }

  bool				Pixel::operator!=(Sint32 const &i) const
  {
    return (this->pix32 != static_cast<Uint32>(i));
  }

  bool				Pixel::operator!=(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 != pixel.pix32);
  }

  /*
  ** Operator <
  */
  bool				Pixel::operator<(Uint8 const &i) const
  {
    return (this->pix8 < i);
  }

  bool				Pixel::operator<(Uint16 const &i) const
  {
    return (this->pix16 < i);
  }

  bool				Pixel::operator<(Uint32 const &i) const
  {
    return (this->pix32 < i);
  }

  bool				Pixel::operator<(Sint8 const &i) const
  {
    return (this->pix8 < static_cast<Uint8>(i));
  }

  bool				Pixel::operator<(Sint16 const &i) const
  {
    return (this->pix16 < static_cast<Uint16>(i));
  }

  bool				Pixel::operator<(Sint32 const &i) const
  {
    return (this->pix32 < static_cast<Uint32>(i));
  }

  bool				Pixel::operator<(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 < pixel.pix32);
  }

  /*
  ** Operator >
  */
  bool				Pixel::operator>(Uint8 const &i) const
  {
    return (this->pix8 > i);
  }

  bool				Pixel::operator>(Uint16 const &i) const
  {
    return (this->pix16 > i);
  }

  bool				Pixel::operator>(Uint32 const &i) const
  {
    return (this->pix32 > i);
  }

  bool				Pixel::operator>(Sint8 const &i) const
  {
    return (this->pix8 > static_cast<Uint8>(i));
  }

  bool				Pixel::operator>(Sint16 const &i) const
  {
    return (this->pix16 > static_cast<Uint16>(i));
  }

  bool				Pixel::operator>(Sint32 const &i) const
  {
    return (this->pix32 > static_cast<Uint32>(i));
  }

  bool				Pixel::operator>(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 > pixel.pix32);
  }

  /*
  ** Operator <=
  */
  bool				Pixel::operator<=(Uint8 const &i) const
  {
    return (this->pix8 <= i);
  }

  bool				Pixel::operator<=(Uint16 const &i) const
  {
    return (this->pix16 <= i);
  }

  bool				Pixel::operator<=(Uint32 const &i) const
  {
    return (this->pix32 <= i);
  }

  bool				Pixel::operator<=(Sint8 const &i) const
  {
    return (this->pix8 <= static_cast<Uint8>(i));
  }

  bool				Pixel::operator<=(Sint16 const &i) const
  {
    return (this->pix16 <= static_cast<Uint16>(i));
  }

  bool				Pixel::operator<=(Sint32 const &i) const
  {
    return (this->pix32 <= static_cast<Uint32>(i));
  }

  bool				Pixel::operator<=(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 <= pixel.pix32);
  }

  /*
  ** Operator >=
  */
  bool				Pixel::operator>=(Uint8 const &i) const
  {
    return (this->pix8 >= i);
  }

  bool				Pixel::operator>=(Uint16 const &i) const
  {
    return (this->pix16 >= i);
  }

  bool				Pixel::operator>=(Uint32 const &i) const
  {
    return (this->pix32 >= i);
  }

  bool				Pixel::operator>=(Sint8 const &i) const
  {
    return (this->pix8 >= static_cast<Uint8>(i));
  }

  bool				Pixel::operator>=(Sint16 const &i) const
  {
    return (this->pix16 >= static_cast<Uint16>(i));
  }

  bool				Pixel::operator>=(Sint32 const &i) const
  {
    return (this->pix32 >= static_cast<Uint32>(i));
  }

  bool				Pixel::operator>=(MSDL::Pixel const &pixel) const
  {
    return (this->pix32 >= pixel.pix32);
  }

  /*
  ** Extern operator
  ** Operator << with std::ostream for debug
  */
  std::ostream			&operator<<(std::ostream &os,
					    MSDL::Pixel const &pixel)
  {
    os << pixel.pix32;
    return (os);
  }
}
