///
/// \file	window.h
///	\brief	
///	\date	13 juin 2014
/// \author	Nico_user
///
#ifndef WINDOW_H_
#define WINDOW_H_

/// === INCLUDES	================================================================================
#include <sdl2/SDL.h>

#include <string>

#include "sdl_exception.h"

/// === NAMESPACE	================================================================================
/// \namespace	sdl
namespace sdl
{

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	13 juin 2014
/// \author	Nico_user
class Window
{
public:
	/// === PUBLIC ENUMERATIONS	====================================================================

	enum EPos
	{
		CENTERED = SDL_WINDOWPOS_CENTERED, UNDEFINED = SDL_WINDOWPOS_UNDEFINED,
	};

	enum EFlags
	{
		FULLSCREEN = ::SDL_WINDOW_FULLSCREEN,
		OPENGL = ::SDL_WINDOW_OPENGL,
		SHOWN = ::SDL_WINDOW_SHOWN,
		HIDDEN = ::SDL_WINDOW_HIDDEN,
		BORDERLESS = ::SDL_WINDOW_BORDERLESS,
		RESIZABLE = ::SDL_WINDOW_RESIZABLE,
		MINIMIZED = ::SDL_WINDOW_MINIMIZED,
		MAXIMIZED = ::SDL_WINDOW_MAXIMIZED,
		INPUT_GRABBED = ::SDL_WINDOW_INPUT_GRABBED,
		INPUT_FOCUS = ::SDL_WINDOW_INPUT_FOCUS,
		MOUSE_FOCUS = ::SDL_WINDOW_MOUSE_FOCUS,
		FULLSCREEN_DESKTOP = ::SDL_WINDOW_FULLSCREEN_DESKTOP,
		FOREIGN = ::SDL_WINDOW_FOREIGN,
		ALLOW_HIGHDPI = ::SDL_WINDOW_ALLOW_HIGHDPI,
	};

	/// === PUBLIC DECLARATIONS	====================================================================

//	Window(const std::string& title, int x, int y, int w, int h, const EFlags flags);
//	Window(const std::string& title, EPos x, int y, int w, int h, const EFlags flags);
	Window(const std::string& title, int x, EPos y, int w, int h, const EFlags flags);
	Window(	const std::string& title,
			EPos x,
			EPos y,
			int w,
			int h,
			const EFlags flags) throw (SDL_Exception);
	virtual ~Window();

	inline SDL_Window* get() const;

	void setTitle(const std::string& title);

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
	SDL_Window* window_;
};

/// === INLINE DEFINITIONS	========================================================================

inline SDL_Window* Window::get() const
{
	return window_;
}

}

#endif	/// WINDOW_H_/// === END OF FILE	================================================================================