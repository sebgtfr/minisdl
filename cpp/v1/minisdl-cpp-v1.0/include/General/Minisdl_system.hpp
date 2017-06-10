//
// System.hpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/include
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 18:32:34 2016 Sébastien Le Maire
// Last update Wed Jul  6 16:40:22 2016 Sébastien Le Maire
//

#ifndef MINISDL_SYSTEM_HPP_
# define MINISDL_SYSTEM_HPP_

# ifndef MSDL_AUDIO_FREQUENCY
#  define MSDL_AUDIO_FREQUENCY	(44100)
# endif /* !MSDL_AUDIO_FREQUENCY */

# define _MSDL_SYSTEM_NBFLAGS_	(2)

namespace			MSDL
{
  class				System
  {
  public: /* Subclass */
    enum			Flags
    {
				ALL_OFF = 0,
				TIMER = 1,
				AUDIO = 2,
				ALL_ON = 3
    };

  public: /* ctor & dtor */
    System(MSDL::System::Flags flagSystem = MSDL::System::ALL_OFF);
    ~System(void);

  public: /* Methods */
    void			init(MSDL::System::Flags flagsSystem);
    void			close(MSDL::System::Flags flagsSystem);

  private: /* Private Methods */
    void			activate_audio(void) const;
    void			desactivate_audio(void) const;

  private: /* Attribute */
    MSDL::System::Flags		m_flagsOn;
  };
}

MSDL::System::Flags		operator|(MSDL::System::Flags const &f1,
					  MSDL::System::Flags const &f2);
MSDL::System::Flags		&operator|=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2);
MSDL::System::Flags		operator&(MSDL::System::Flags const &f1,
					  MSDL::System::Flags const &f2);
MSDL::System::Flags		&operator&=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2);
MSDL::System::Flags		&operator^=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2);
MSDL::System::Flags		&operator++(MSDL::System::Flags &f);

#endif /* !MINISDL_SYSTEM_HPP_ */
