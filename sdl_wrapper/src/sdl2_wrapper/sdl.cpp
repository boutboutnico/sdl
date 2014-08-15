///
/// \file	sdl.cpp
///	\brief	
///	\date	11 juin 2014
/// \author	nboutin
///

#include "sdl.h"
using namespace sdl;

/// === INCLUDES	================================================================================
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

/// === NAMESPACES	================================================================================

/// === PUBLIC DEFINITIONS	========================================================================

/// ------------------------------------------------------------------------------------------------
SDL::SDL(EInit flags) throw (SDL_Exception)
{
	if (SDL_Init(static_cast<Uint32>(flags)) != 0) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
SDL::SDL(EInit flags, EInit_Lib flags_lib) throw (SDL_Exception) :
		SDL(flags)
{
	if (TTF_WasInit() == 0 && TTF_Init() == -1)
	{
		throw SDL_Exception();
	}
}

/// ------------------------------------------------------------------------------------------------
SDL::~SDL()
{
	SDL_Quit();

	if (TTF_WasInit() == 1)
	{
		TTF_Quit();
	}
}

/// ------------------------------------------------------------------------------------------------
void SDL::quitSubSystem(EInit flags)
{
	SDL_QuitSubSystem(static_cast<Uint32>(flags));
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
