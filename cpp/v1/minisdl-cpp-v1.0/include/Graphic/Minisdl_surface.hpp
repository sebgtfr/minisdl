//
// Minisdl_surface.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Fri Jun  3 21:48:59 2016 Sébastien Le Maire
// Last update Wed Aug 17 17:26:40 2016 Sébastien Le Maire
//

#ifndef MINISDL_SURFACE_HPP_
# define MINISDL_SURFACE_HPP_

namespace			MSDL
{
  class				Surface
  {
  public: /* Subobject */
    class			Rect
    {
    public: /* ctor & dtor */
      Rect(Sint16 x, Sint16 y, Uint16 width, Uint16 height);
      ~Rect(void);

    public: /* Accessor */
      void			setX(Sint16 const x);
      void			setY(Sint16 const y);
      void			setWidth(Uint16 const width);
      void			setHeight(Uint16 const height);
      Sint16			getX(void) const;
      Sint16			getY(void) const;
      Uint16			getWidth(void) const;
      Uint16			getHeight(void) const;
      SDL_Rect const		&getRect(void) const;

    private: /* Attribute */
      SDL_Rect			m_rect;
      Uint16			m_decX;
      Uint16			m_decY;
      Uint16			m_width;
      Uint16			m_height;
    };

  public: /* ctor & dtor */
    Surface(void);
    virtual ~Surface(void);

  public: /* Methods */
    virtual void       		putPixel(Uint16 const x, Uint16 const y,
					 MSDL::Pixel const color);
    virtual MSDL::Pixel		getPixel(Uint16 const x, Uint16 const y);
    virtual void		clear(MSDL::Pixel const pixel);
    virtual int	       	       	width(void) const;
    virtual int		       	height(void) const;
    virtual void		blit(MSDL::Surface const &surface,
				     Sint16 const x = 0, Sint16 const y = 0,
				     MSDL::Surface::Rect const *rect = NULL);
    virtual SDL_Surface		*getSurface(void) const;

  protected: /* Attribute */
    SDL_Surface			*m_surface;
  };
}

#endif /* !MINISDL_SURFACE_HPP_ */
