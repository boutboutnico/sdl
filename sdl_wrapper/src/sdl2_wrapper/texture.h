/*
 * texture.h
 *
 *  Created on: 10 juin 2014
 *      Author: Nico_user
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

/// === INCLUDES	================================================================================
#include <string>

#include <SDL2/SDL.h>

#include "sdl.h"
#include "renderer.h"
#include "surface.h"

/// === NAMESPACE	================================================================================
namespace sdl
{
/// === CLASS	====================================================================================
class Texture
{
public:
	/// === PUBLIC DECLARATIONS	====================================================================
	Texture(Renderer& renderer, Surface& surface) throw (SDL_Exception);
//	Texture(Renderer& renderer, const std::string filename) throw (SDL_Exception);
	virtual ~Texture();

	int setColorMod(uint8_t r, uint8_t g, uint8_t b);
	int setBlendMode(EBlendMode mode);
	int setAlphaMode(Uint8 alpha);

	int copy(const SDL_Rect* src = NULL, const SDL_Rect* dst = NULL);
	int copyEx(	const SDL_Rect* src,
				const SDL_Rect* dst,
				const double angle,
				const SDL_Point* center,
				const SDL_RendererFlip flip);

	inline int getWidth() const;
	inline int getHeight() const;

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	SDL_Renderer* renderer_;
	SDL_Texture* texture_;
	int w_;
	int h_;
};

/// === INLINE DEFINITIONS	========================================================================
inline int Texture::getWidth() const
{
	return w_;
}

/// ------------------------------------------------------------------------------------------------
inline int Texture::getHeight() const
{
	return h_;
}

}

#endif /* TEXTURE_H_ */
/// === END OF FILE	================================================================================
