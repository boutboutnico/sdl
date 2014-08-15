/*
 * texture.cpp
 *
 *  Created on: 10 juin 2014
 *      Author: Nico_user
 */

#include "texture.h"
using namespace sdl;

/// === INCLUDES	================================================================================
#include <iostream>
#include <cstddef>

/// === NAMESPACES	================================================================================
using namespace std;

/// === PUBLIC DEFINITIONS	========================================================================

Texture::Texture(Renderer& renderer, Surface& surface) throw (SDL_Exception) :
		renderer_(renderer.get())
{
//	SDL_SetColorKey(surface.surface_, SDL_TRUE, 0);

	texture_ = SDL_CreateTextureFromSurface(renderer_, surface.get());

	if (texture_ == nullptr) throw SDL_Exception();

	SDL_QueryTexture(texture_, NULL, NULL, &w_, &h_);

//	SDL_SetRenderTarget(renderer_, texture_);
//	SDL_RenderClear(renderer_);
//	SDL_SetRenderTarget(renderer_, NULL);
}

/// ------------------------------------------------------------------------------------------------
//Texture::Texture(Renderer& renderer, const std::string filename) throw (SDL_Exception)
//{
//
//}

/// ------------------------------------------------------------------------------------------------
Texture::~Texture()
{
	if (texture_ != nullptr) SDL_DestroyTexture(texture_);
}

/// ------------------------------------------------------------------------------------------------
int Texture::setColorMod(uint8_t r, uint8_t g, uint8_t b)
{
	return SDL_SetTextureColorMod(texture_, r, g, b);
}

/// ------------------------------------------------------------------------------------------------
int Texture::setBlendMode(EBlendMode mode)
{
	return SDL_SetTextureBlendMode(texture_, static_cast<SDL_BlendMode>(mode));
}

/// ------------------------------------------------------------------------------------------------
int Texture::setAlphaMode(Uint8 alpha)
{
	return SDL_SetTextureAlphaMod(texture_, alpha);
}

/// ------------------------------------------------------------------------------------------------
int Texture::copy(const SDL_Rect* src, const SDL_Rect* dst)
{
	return SDL_RenderCopy(renderer_, texture_, src, dst);
}

/// ------------------------------------------------------------------------------------------------
int Texture::copyEx(const SDL_Rect* src,
					const SDL_Rect* dst,
					const double angle,
					const SDL_Point* center,
					const SDL_RendererFlip flip)
{
	return SDL_RenderCopyEx(renderer_, texture_, src, dst, angle, center, flip);
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
