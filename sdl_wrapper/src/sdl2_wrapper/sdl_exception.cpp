///
/// \file	sdl_exception.cpp
///	\brief	
///	\date	13 juin 2014
/// \author	nboutin
///

#include "sdl_exception.h"
using namespace sdl;

/// === INCLUDES	================================================================================
#include <SDL2/SDL.h>

/// === NAMESPACES	================================================================================
using namespace std;

/// === PUBLIC DEFINITIONS	========================================================================
SDL_Exception::SDL_Exception() noexcept :
exception(), msg_(SDL_GetError())
{

}

SDL_Exception::~SDL_Exception() noexcept
{

}

const char* SDL_Exception::what() const noexcept
{
	return msg_.c_str();
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
