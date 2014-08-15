///
/// \file	text.h
///	\brief	
///	\date	15 août 2014
/// \author	Nico_user
///
#ifndef TEXTE_H_
#define TEXTE_H_

/// === INCLUDES	================================================================================
#include <SDL2/SDL_ttf.h>

#include "sdl.h"
#include "renderer.h"
#include "texture.h"
#include "font.h"

/// === NAMESPACE	================================================================================
/// \namespace	xxx
namespace sdl
{

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	15 août 2014
/// \author	Nico_user
class Text
{
public:
	Text(	Renderer& renderer,
			const Font& font,
			const std::string& text,
			const SDL_Color& color) throw (SDL_Exception);

	virtual ~Text();

	int copy(const SDL_Rect* src = NULL, const SDL_Rect* dst = NULL);

	/// === PUBLIC DECLARATIONS	====================================================================

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	Font font_;
	std::string text_;
	SDL_Color color_;
	Texture* ptexture_;
};

/// === INLINE DEFINITIONS	========================================================================

}

#endif	/// TEXTE_H_/// === END OF FILE	================================================================================
