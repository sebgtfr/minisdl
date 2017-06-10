//
// Minisdl_window.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/include/Graphic
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue Jun 28 13:17:41 2016 Sébastien Le Maire
// Last update Wed Aug 17 17:24:42 2016 Sébastien Le Maire
//

#ifndef MINISDL_WINDOW_HPP_
# define MINISDL_WINDOW_HPP_

# define _MSDL_WINDOW_NBFLAGS_	(3)

namespace			MSDL
{
  class				Window : public MSDL::Surface
  {
  public: /* SubObjects */
    enum			Flags
      {
				ALL_OFF = 0,
				RESIZE = 1,
				FULLSCREEN = 2,
				NO_DECORATION = 4,
				OPENGL = 8,
      };

  public: /* ctor & dtor */
    Window(Uint16 width, Uint16 height,
	   MSDL::Window::Flags flags = MSDL::Window::ALL_OFF,
	   std::string const &title = "", MSDL::Pixel color = _MSDL_BLACK_,
	   Uint8 bpp = 32);
    ~Window(void);

  public: /* Methods */
    void		        update(void) const;
    void			reverseFlags(MSDL::Window::Flags winFlags);
    void			setIcon(MSDL::Image const &icon) const;
  };
}

MSDL::Window::Flags		operator|(MSDL::Window::Flags const &f1,
					  MSDL::Window::Flags const &f2);
MSDL::Window::Flags		&operator|=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2);
MSDL::Window::Flags		operator&(MSDL::Window::Flags const &f1,
					  MSDL::Window::Flags const &f2);
MSDL::Window::Flags		&operator&=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2);
MSDL::Window::Flags		&operator^=(MSDL::Window::Flags &f1,
					    MSDL::Window::Flags const &f2);
MSDL::Window::Flags		&operator++(MSDL::Window::Flags &f);

#endif /* !MINISDL_WINDOW_HPP_ */
