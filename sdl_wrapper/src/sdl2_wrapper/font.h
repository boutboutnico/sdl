///
/// \file	font.h
///	\brief	
///	\date	15 août 2014
/// \author	Nico_user
///
#ifndef FONT_H_
#define FONT_H_

/// === INCLUDES	================================================================================
#include <string>

#include <SDL2/SDL_ttf.h>

#include "sdl.h"

/// === NAMESPACE	================================================================================
/// \namespace	sdl
namespace sdl
{

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	15 août 2014
/// \author	Nico_user
class Font
{
public:
	/// === PUBLIC DECLARATIONS	====================================================================
	Font(const std::string& filename, uint16_t size) throw (SDL_Exception);
	Font(const Font& font) throw (SDL_Exception);
	virtual ~Font();

	inline TTF_Font* get() const
	{
		return font_;
	}

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	TTF_Font* font_;
	std::string filename_;
	uint16_t size_;
};

/// === INLINE DEFINITIONS	========================================================================

}

#endif	/// FONT_H_/// === END OF FILE	================================================================================
