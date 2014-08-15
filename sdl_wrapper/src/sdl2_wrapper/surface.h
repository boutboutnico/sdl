/*
 * surface.h
 *
 *  Created on: 12 juin 2014
 *      Author: Nico_user
 */

#ifndef SURFACE_H_
#define SURFACE_H_

/// === INCLUDES	================================================================================
#include <string>

#include <SDL2/SDL.h>

#include "sdl_exception.h"

/// === NAMESPACE	================================================================================
namespace sdl
{
/// === CLASS	====================================================================================
class Surface
{
public:
	/// === PUBLIC DECLARATIONS	====================================================================
	Surface(const std::string& filename) throw (SDL_Exception);

	/// TODO remove, debug for sdl_ttf
	Surface(SDL_Surface* surface) throw (SDL_Exception);

	virtual ~Surface() noexcept;

	inline SDL_Surface* get() const
	{
		return surface_;
	}

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	SDL_Surface* surface_;
};

/// === INLINE DEFINITIONS	========================================================================
}

#endif	/// SURFACE_H_/// === END OF FILE	================================================================================
