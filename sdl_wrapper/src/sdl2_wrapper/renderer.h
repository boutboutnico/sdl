///
/// \file	renderer.h
///	\brief	
///	\date	13 juin 2014
/// \author	Nico_user
///
#ifndef RENDERER_H_
#define RENDERER_H_

/// === INCLUDES	================================================================================
#include <sdl2/SDL.h>

#include <vector>

#include "sdl.h"
#include "window.h"

/// === NAMESPACE	================================================================================
/// \namespace	sdl
namespace sdl
{

/// === STRUCTURES	================================================================================
struct RGBA
{
	int r_;
	int g_;
	int b_;
	int alpha_;
};

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	13 juin 2014
/// \author	Nico_user
class Renderer
{
public:
	/// === PUBLIC ENUMERATIONS	====================================================================
	enum EFlags
	{
		SOFTWARE = ::SDL_RENDERER_SOFTWARE,
		ACCELERATED = ::SDL_RENDERER_ACCELERATED,
		PRESENTVSYNC = ::SDL_RENDERER_PRESENTVSYNC,
		TARGETTEXTURE = ::SDL_RENDERER_TARGETTEXTURE,
	};

	/// === PUBLIC DECLARATIONS	====================================================================
	Renderer(Window& window, int driver_index, const EFlags flags) throw (SDL_Exception);
	virtual ~Renderer();

	inline SDL_Renderer* get();

	int setDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha);
	int setDrawBlendMode(EBlendMode mode);

	int setClipRect(const SDL_Rect* rect);
	int setViewport(const SDL_Rect* rect);
	int setLogicalSize(int w, int h);
	int setScale(float scaleX, float scaleY);

	int clear();
	void present();

	int drawLine(int x1, int y1, int x2, int y2);

	int drawPoint(int x, int y);
	int drawPoints(std::vector<const SDL_Point*>& points);

	int drawRect(const SDL_Rect* rect);
	int fillRect(const SDL_Rect* rect);

//	int drawCircle();

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	SDL_Renderer* renderer_;
};

/// === INLINE DEFINITIONS	========================================================================
inline SDL_Renderer* Renderer::get()
{
	return renderer_;
}

}

#endif	/// RENDERER_H_/// === END OF FILE	================================================================================
