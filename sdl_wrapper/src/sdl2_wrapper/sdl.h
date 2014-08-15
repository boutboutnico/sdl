///
/// \file	sdl.h
///	\brief	
///	\date	11 juin 2014
/// \author	nboutin
///
#ifndef SDL_H_
#define SDL_H_

/// === INCLUDES	================================================================================
#include <SDL2/SDL.h>

#include <sdl_exception.h>

/// === NAMESPACE	================================================================================
/// \namespace	sdl
namespace sdl
{

/// === ENUMERATIONS	============================================================================
enum class EInit
{
	TIMER = SDL_INIT_TIMER,
	AUDIO = SDL_INIT_AUDIO,
	VIDEO = SDL_INIT_VIDEO,
	JOYSTICK = SDL_INIT_JOYSTICK,
	HAPTIC = SDL_INIT_HAPTIC,
	GAMECONTROLLER = SDL_INIT_GAMECONTROLLER,
	EVENTS = SDL_INIT_EVENTS,
	NOPARACHUTE = SDL_INIT_NOPARACHUTE,
	EVERYTHING = SDL_INIT_EVERYTHING,
};

enum class EInit_Lib
{
	SDL_TTF = 0
};

enum class EBlendMode
{
	NONE = SDL_BLENDMODE_NONE,
	BLEND = SDL_BLENDMODE_BLEND,
	ADD = SDL_BLENDMODE_ADD,
	MOD = SDL_BLENDMODE_MOD,
};

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	11 juin 2014
/// \author	nboutin
class SDL
{
public:
	/// === PUBLIC DECLARATIONS	====================================================================
	SDL(EInit flags) throw (SDL_Exception);
	SDL(EInit flags, EInit_Lib flags_lib) throw (SDL_Exception);
	virtual ~SDL();

	void quitSubSystem(EInit flags);

private:
	/// === PRIVATE DECLARATIONS	================================================================

	/// === PRIVATE ATTRIBUTS	====================================================================
};

inline EInit operator|(const EInit &a, const EInit &b)
{
//	EInit tmp = static_cast<EInit>((uint32_t) a | (uint32_t) b);
//	return tmp;

	return static_cast<EInit>((uint32_t) a | (uint32_t) b);

//	return static_cast<EInit>(a | b);
//	return (uint32_t)a | (uint32_t)b;
}

/// === INLINE DEFINITIONS	========================================================================

}

#endif	/// SDL_H_/// === END OF FILE	================================================================================
