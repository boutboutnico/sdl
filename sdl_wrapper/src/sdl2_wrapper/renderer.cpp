///
/// \file	renderer.cpp
///	\brief	
///	\date	13 juin 2014
/// \author	Nico_user
///

#include <renderer.h>
using namespace sdl;

/// === INCLUDES	================================================================================

/// === NAMESPACES	================================================================================

/// === PUBLIC DEFINITIONS	========================================================================

Renderer::Renderer(Window& window, int driver_index, const EFlags flags) throw (SDL_Exception)
{
	renderer_ = SDL_CreateRenderer(window.get(), driver_index, flags);

	if (renderer_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer_);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha)
{
	return SDL_SetRenderDrawColor(renderer_, r, g, b, alpha);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setDrawBlendMode(EBlendMode mode)
{
	return SDL_SetRenderDrawBlendMode(renderer_, static_cast<SDL_BlendMode>(mode));
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setClipRect(const SDL_Rect* rect)
{
	return SDL_RenderSetClipRect(renderer_, rect);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setViewport(const SDL_Rect* rect)
{
	return SDL_RenderSetViewport(renderer_, rect);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setLogicalSize(int w, int h)
{
	return SDL_RenderSetLogicalSize(renderer_, w, h);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::setScale(float scaleX, float scaleY)
{
	return SDL_RenderSetScale(renderer_, scaleX, scaleY);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::clear()
{
	return SDL_RenderClear(renderer_);
}

/// ------------------------------------------------------------------------------------------------
void Renderer::present()
{
	SDL_RenderPresent(renderer_);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::drawLine(int x1, int y1, int x2, int y2)
{
	return SDL_RenderDrawLine(renderer_, x1, y1, x2, y2);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::drawPoint(int x, int y)
{
	return SDL_RenderDrawPoint(renderer_, x, y);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::drawPoints(std::vector<const SDL_Point*>& points)
{
	return SDL_RenderDrawPoints(renderer_, *points.data(), points.size());
}

/// ------------------------------------------------------------------------------------------------
int Renderer::drawRect(const SDL_Rect* rect)
{
	return SDL_RenderDrawRect(renderer_, rect);
}

/// ------------------------------------------------------------------------------------------------
int Renderer::fillRect(const SDL_Rect* rect)
{
	return SDL_RenderFillRect(renderer_, rect);
}

/// ------------------------------------------------------------------------------------------------
//int Renderer::drawCircle(int n_cx, int n_cy, int radius, Uint32 pixel)
//{
//
//}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
