///
/// \file	window.cpp
///	\brief	
///	\date	13 juin 2014
/// \author	Nico_user
///

#include <window.h>
using namespace sdl;

/// === INCLUDES	================================================================================

/// === NAMESPACES	================================================================================
using namespace std;

/// === PUBLIC DEFINITIONS	========================================================================

//Window::Window(const string& title, int x, int y, int w, int h, const EFlags flags)
//{
//
//}

/// ------------------------------------------------------------------------------------------------
//Window(const std::string& title, EPos x, int y, int w, int h, const EFlags flags);

/// ------------------------------------------------------------------------------------------------
Window::Window(const std::string& title, int x, EPos y, int w, int h, const EFlags flags)
{
	window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (window_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Window::Window(	const string& title,
				EPos x,
				EPos y,
				int w,
				int h,
				const EFlags flags) throw (SDL_Exception)
{
	window_ = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);

	if (window_ == nullptr) throw SDL_Exception();
}

/// ------------------------------------------------------------------------------------------------
Window::~Window()
{
	SDL_DestroyWindow(window_);
}

/// ------------------------------------------------------------------------------------------------
void Window::setTitle(const std::string& title)
{
	SDL_SetWindowTitle(window_, title.c_str());
}

/// === PRIVATE DEFINITIONS	========================================================================

/// === END OF FILES	============================================================================
