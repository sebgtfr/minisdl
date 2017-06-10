//
// System.cpp for Minisdl in /home/le-mai_s/librairie/Minisdl/cpp/v1/minisdl-cpp-v1.0/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Tue May 31 18:33:17 2016 Sébastien Le Maire
// Last update Wed Jul  6 16:45:58 2016 Sébastien Le Maire
//

#include "SDL.h"
#include "SDL_mixer.h"
#include "Minisdl_exception.hpp"
#include "Minisdl_system.hpp"

MSDL::System::Flags		operator|(MSDL::System::Flags const &f1,
					  MSDL::System::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return (static_cast<MSDL::System::Flags>(i1 | i2));
}

MSDL::System::Flags		&operator|=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::System::Flags>(i1 | i2)));
}

MSDL::System::Flags		operator&(MSDL::System::Flags const &f1,
					  MSDL::System::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return (static_cast<MSDL::System::Flags>(i1 & i2));
}

MSDL::System::Flags		&operator&=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::System::Flags>(i1 & i2)));
}

MSDL::System::Flags		&operator^=(MSDL::System::Flags &f1,
					    MSDL::System::Flags const &f2)
{
  Uint32			i1 = static_cast<Uint32>(f1);
  Uint32			i2 = static_cast<Uint32>(f2);

  return ((f1 = static_cast<MSDL::System::Flags>(i1 ^ i2)));
}

MSDL::System::Flags		&operator++(MSDL::System::Flags &f)
{
  f = (f) ?
    static_cast<MSDL::System::Flags>(static_cast<unsigned int>(f) << 1) :
    static_cast<MSDL::System::Flags>(1);
  return (f);
}

namespace			MSDL
{
  static unsigned int const	g_SDLFlags[_MSDL_SYSTEM_NBFLAGS_] =
    {
				SDL_INIT_TIMER,
				SDL_INIT_AUDIO
    };

  System::System(MSDL::System::Flags flagsSystem)
  {
    Uint32			flags = SDL_INIT_VIDEO;
    Uint8			i = 0;
    MSDL::System::Flags		msdlFlags = MSDL::System::ALL_OFF;

    while (i < _MSDL_SYSTEM_NBFLAGS_)
      {
	++msdlFlags;
	if (flagsSystem & msdlFlags)
	  flags |= g_SDLFlags[i];
	++i;
      }
    if (SDL_Init(flags))
      throw MSDL::Exception(MSDL::Exception::INIT_SYSTEM);
    this->m_flagsOn = flagsSystem;
    if (this->m_flagsOn & MSDL::System::AUDIO)
      this->activate_audio();
  }

  System::~System(void)
  {
    if (this->m_flagsOn & MSDL::System::AUDIO)
      this->desactivate_audio();
    SDL_Quit();
  }

  void				System::init(MSDL::System::Flags flagsSystem)
  {
    Uint32			flags = 0;
    Uint8			i = 0;
    MSDL::System::Flags		msdlFlags = MSDL::System::ALL_OFF;

    while (i < _MSDL_SYSTEM_NBFLAGS_)
      {
	++msdlFlags;
	if ((!(this->m_flagsOn & msdlFlags)) && (flagsSystem & msdlFlags))
	  flags |= g_SDLFlags[i];
	++i;
      }
    if (flags)
      {
	if (SDL_InitSubSystem(flags))
	  throw MSDL::Exception(MSDL::Exception::INIT_SYSTEM);
	this->m_flagsOn |= flagsSystem;
	if (flags & SDL_INIT_AUDIO)
	  this->activate_audio();
      }
  }

  void				System::close(MSDL::System::Flags flagsSystem)
  {
    Uint32			flags = 0;
    MSDL::System::Flags		msdlFlags = MSDL::System::ALL_OFF;

    while ((++msdlFlags) != MSDL::System::ALL_ON)
      if (((this->m_flagsOn & msdlFlags)) && (flagsSystem & msdlFlags))
	flags |= g_SDLFlags[static_cast<unsigned int>(msdlFlags) - 1];
    if (flags)
      {
	SDL_QuitSubSystem(flags);
	this->m_flagsOn ^= flagsSystem;
	if (flags & SDL_INIT_AUDIO)
	  this->desactivate_audio();
      }
  }

  /*
  ** Private Methods
  */

  void				System::activate_audio(void) const
  {
    if (Mix_OpenAudio(MSDL_AUDIO_FREQUENCY, MIX_DEFAULT_FORMAT,
		      MIX_DEFAULT_CHANNELS, 1024) == -1)
      throw MSDL::Exception(MSDL::Exception::INIT_AUDIO_SYSTEM);
  }

  void				System::desactivate_audio(void) const
  {
    Mix_CloseAudio();
  }
}
