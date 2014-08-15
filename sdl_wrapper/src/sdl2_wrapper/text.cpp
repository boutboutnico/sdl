///
/// \file	text.cpp
///	\brief	
///	\date	15 août 2014
/// \author	Nico_user
///

#include "text.h"
using namespace sdl;

/// === INCLUDES	================================================================================

/// === NAMESPACES	================================================================================

/// === PUBLIC DEFINITIONS	========================================================================
Text::Text(	Renderer& renderer,
			const Font& font,
			const std::string& text,
			const SDL_Color& color) throw (SDL_Exception) :
		font_(font), text_(text), color_(color)
{
	Surface surface(TTF_RenderText_Solid(font_.get(), text.c_str(), color));

	ptexture_ = new Texture(renderer, surface);
}

/// ------------------------------------------------------------------------------------------------
Text::~Text()
{
	delete ptexture_;
}

/// ------------------------------------------------------------------------------------------------
int Text::copy(const SDL_Rect* src, const SDL_Rect* dst)
{
	SDL_Rect rect = *dst;

	if (dst->w > ptexture_->getWidth()) rect.w = ptexture_->getWidth();
	if (dst->h > ptexture_->getHeight()) rect.h = ptexture_->getHeight();

	return ptexture_->copy(src, &rect);
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
