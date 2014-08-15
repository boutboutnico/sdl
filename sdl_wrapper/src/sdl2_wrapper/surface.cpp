/*
 * surface.cpp
 *
 *  Created on: 12 juin 2014
 *      Author: Nico_user
 */

#include <surface.h>
using namespace sdl;

/// === INCLUDES	================================================================================

/// === NAMESPACES	================================================================================
using namespace std;

/// === PUBLIC DEFINITIONS	========================================================================
Surface::Surface(const string& filename) throw (SDL_Exception)
{
	surface_ = SDL_LoadBMP(filename.c_str());

	if (surface_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Surface::Surface(SDL_Surface* surface) throw (SDL_Exception)
{
	if (surface_ == nullptr) throw SDL_Exception();

	surface_ = surface;
}

/// ------------------------------------------------------------------------------------------------
Surface::~Surface()
{
	SDL_FreeSurface(surface_);
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
