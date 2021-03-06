//
// System.hpp for Minisdl2.0 in /home/le-mai_s/librairie/Minisdl/cpp/v2/minisdl-cpp-v2.0/srcs/System
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Jun 10 12:17:43 2017 Sébastien Le Maire
// Last update Sun Jun 11 11:40:28 2017 Sébastien Le Maire
//

#ifndef SYSTEM_HPP_
# define SYSTEM_HPP_

# define __MSDL_SYSTEM_NBMODULES__	(2)

namespace				MSDL
{
  class					System
  {
  public: /* Subclass*/
    enum				Module
      {
					ALL_OFF = 0,
					TIMER = 1,
					AUDIO = 2,
					ALL_ON = 3
      };

  public: /* public static */
    static int				m_audioFrequency;

  private: /* Private static */
    static Uint32 const			m_modulesSDL[__MSDL_SYSTEM_NBMODULES__];

  public: /* ctor & dtor */
    System(MSDL::System::Module const &modulesSystem = MSDL::System::ALL_OFF);
    ~System(void);

  public: /* Methods */
    void				init(MSDL::System::Module const &modulesSystem);
    void				close(MSDL::System::Module const &modulesSystem);

  private: /* Private Methods */
    Uint32				moduleOnSDL(MSDL::System::Module const &modulesSystem) const;

  private: /* Private static Methods */
    static void				activateAudio(void);
    static void				desactivateAudio(void);

  private:
    MSDL::System::Module		m_moduleOn;

  };
}

MSDL::System::Module		operator|(MSDL::System::Module const &m1,
					  MSDL::System::Module const &m2);
MSDL::System::Module		&operator|=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2);
MSDL::System::Module		operator&(MSDL::System::Module const &m1,
					  MSDL::System::Module const &m2);
MSDL::System::Module		&operator&=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2);
MSDL::System::Module		&operator^=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2);
MSDL::System::Module		&operator++(MSDL::System::Module &m);

#endif /* !SYSTEM_HPP_ */
