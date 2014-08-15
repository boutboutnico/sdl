///
/// \file	font.cpp
///	\brief	
///	\date	15 août 2014
/// \author	Nico_user
///

#include <font.h>
using namespace sdl;

/// === INCLUDES	================================================================================

/// === NAMESPACES	================================================================================

/// === PUBLIC DEFINITIONS	========================================================================
Font::Font(const std::string& filename, uint16_t size) throw (SDL_Exception) :
		filename_(filename), size_(size)
{
	font_ = TTF_OpenFont(filename.c_str(), size);

	if (font_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Font::Font(const Font& font) throw (SDL_Exception) :
		filename_(font.filename_), size_(font.size_)
{
	font_ = TTF_OpenFont(font.filename_.c_str(), font.size_);

	if (font_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Font::~Font()
{
	TTF_CloseFont(font_);
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
