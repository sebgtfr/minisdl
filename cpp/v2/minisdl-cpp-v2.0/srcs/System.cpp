//
// System.cpp for Minisdl2.0 in /home/le-mai_s/librairie/Minisdl/cpp/v2/minisdl-cpp-v2.0/srcs/System
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Jun 10 12:17:48 2017 Sébastien Le Maire
// Last update Sat Jun 10 17:23:54 2017 Sébastien Le Maire
//

#include "SDL_mixer.h"
#include "Minisdl2/Exception.hpp"
#include "Minisdl2/System.hpp"

MSDL::System::Module		operator|(MSDL::System::Module const &m1,
					  MSDL::System::Module const &m2)
{
  Uint32			i1 = static_cast<Uint32>(m1);
  Uint32			i2 = static_cast<Uint32>(m2);

  return (static_cast<MSDL::System::Module>(i1 | i2));
}

MSDL::System::Module		&operator|=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2)
{
  Uint32			i1 = static_cast<Uint32>(m1);
  Uint32			i2 = static_cast<Uint32>(m2);

  return ((m1 = static_cast<MSDL::System::Module>(i1 | i2)));
}

MSDL::System::Module		operator&(MSDL::System::Module const &m1,
					  MSDL::System::Module const &m2)
{
  Uint32			i1 = static_cast<Uint32>(m1);
  Uint32			i2 = static_cast<Uint32>(m2);

  return (static_cast<MSDL::System::Module>(i1 & i2));
}

MSDL::System::Module		&operator&=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2)
{
  Uint32			i1 = static_cast<Uint32>(m1);
  Uint32			i2 = static_cast<Uint32>(m2);

  return ((m1 = static_cast<MSDL::System::Module>(i1 & i2)));
}

MSDL::System::Module		&operator^=(MSDL::System::Module &m1,
					    MSDL::System::Module const &m2)
{
  Uint32			i1 = static_cast<Uint32>(m1);
  Uint32			i2 = static_cast<Uint32>(m2);

  return ((m1 = static_cast<MSDL::System::Module>(i1 ^ i2)));
}

MSDL::System::Module		&operator++(MSDL::System::Module &m)
{
  m = (m) ?
    static_cast<MSDL::System::Module>(static_cast<unsigned int>(m) << 1) :
    static_cast<MSDL::System::Module>(1);
  return (m);
}

namespace			MSDL
{
  Uint32 const			MSDL::System::m_modulesSDL[__MSDL_SYSTEM_NBMODULES__] =
    {
      SDL_INIT_TIMER,
      SDL_INIT_AUDIO
    };
  int				MSDL::System::m_audioFrequency = 44100;

  System::System(MSDL::System::Module const &modulesSystem) :
    m_moduleOn(MSDL::System::ALL_OFF)
  {
    Uint32 const		modules = this->moduleOnSDL(modulesSystem);

    if (SDL_Init(modules | SDL_INIT_VIDEO))
      throw MSDL::Exception(MSDL::Exception::INIT_SYSTEM);
    this->m_moduleOn = modulesSystem;
    if (this->m_moduleOn & MSDL::System::AUDIO)
      MSDL::System::activateAudio();
  }

  System::~System(void)
  {
    if (this->m_moduleOn & MSDL::System::AUDIO)
      MSDL::System::desactivateAudio();
    SDL_Quit();
  }

  void				System::init(MSDL::System::Module const &modulesSystem)
  {
    Uint32 const		modules = this->moduleOnSDL(modulesSystem);

    if (modules)
      {
	if (SDL_InitSubSystem(modules))
	  throw MSDL::Exception(MSDL::Exception::INIT_SYSTEM);
	this->m_moduleOn |= modulesSystem;
	if (modules & SDL_INIT_AUDIO)
	  MSDL::System::activateAudio();
      }
  }

  void				System::close(MSDL::System::Module const &modulesSystem)
  {
    Uint32 const		modules = this->moduleOnSDL(modulesSystem);

    if (modules)
      {
	SDL_QuitSubSystem(modules);
	this->m_moduleOn ^= modulesSystem;
	if (modules & SDL_INIT_AUDIO)
	  MSDL::System::desactivateAudio();
      }
  }

  /*
  ** Private Methods
  */
  Uint32			System::moduleOnSDL(MSDL::System::Module const &modulesSystem) const
  {
    Uint32			modules = 0;
    Uint8			i;
    MSDL::System::Module       	msdlModules = MSDL::System::ALL_OFF;

    for (i = 0; i < __MSDL_SYSTEM_NBMODULES__; ++i)
      {
	++msdlModules;
	if ((!(this->m_moduleOn & msdlModules)) && (modulesSystem & msdlModules))
	  modules |= MSDL::System::m_modulesSDL[i];
      }
    return (modules);
  }

  /*
  ** Private static functions
  */
  void				System::activateAudio(void)
  {
    if (Mix_OpenAudio(MSDL::System::m_audioFrequency, MIX_DEFAULT_FORMAT,
		      MIX_DEFAULT_CHANNELS, 1024) == -1)
      throw MSDL::Exception(MSDL::Exception::INIT_AUDIO_SYSTEM);
  }

  void				System::desactivateAudio(void)
  {
    Mix_CloseAudio();
  }
}
