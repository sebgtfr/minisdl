//
// Minisdl_Exception.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/include
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 19:13:06 2016 Sébastien Le Maire
// Last update Sat Jun 10 13:50:35 2017 Sébastien Le Maire
//

#ifndef MINISDL_EXCEPTION_HPP_
# define MINISDL_EXCEPTION_HPP_

# include <string>
# include <exception>

namespace			MSDL
{
  class				Exception : public std::exception
  {
  public: /* Subclass */
    enum			CodeError
      {
				INIT_SYSTEM = 0,
				INIT_AUDIO_SYSTEM,
				/*INIT_WINDOW,
				CLEAR_SURFACE,
				BLIT_SURFACE,
				UPDATE_WINDOW,
				INIT_IMAGE_SURFACE,
				INIT_IMAGE_LOAD,
				IMAGE_TRANSPARENCY,
				IMAGE_ALPHA,*/
				LAST_SDL,
				NO_SDL_ERROR = MSDL::Exception::LAST_SDL,
			        PIXEL_COMPONANT_OUT_RANGE = MSDL::Exception::NO_SDL_ERROR,
				LAST
      };

  public: /* ctor & dtor */
    Exception(MSDL::Exception::CodeError codeError);
    virtual ~Exception(void) throw();

  public: /* Methods */
    virtual char const		*what() const throw();

  private: /* Attribute */
    std::string			m_msg;
  };
}

#endif /* !MINISDL_EXCEPTION_HPP_ */
