///
/// \file	sdl_exception.h
///	\brief	
///	\date	13 juin 2014
/// \author	nboutin
///
#ifndef SDL_EXCEPTION_H_
#define SDL_EXCEPTION_H_

/// === INCLUDES	================================================================================
#include <string>

/// === NAMESPACE	================================================================================
namespace sdl
{

/// === CLASS	====================================================================================
/// \class	
/// \brief
/// \date	13 juin 2014
/// \author	nboutin
class SDL_Exception: public std::exception
{
public:
	/// === PUBLIC DECLARATIONS	====================================================================
	SDL_Exception() noexcept;
	virtual ~SDL_Exception() noexcept;
	virtual const char* what() const noexcept;

private:
	/// === PRIVATE ATTRIBUTS	====================================================================
	std::string msg_;
};

/// === INLINE DEFINITIONS	========================================================================

}
#endif	/// SDL_EXCEPTION_H_/// === END OF FILE	================================================================================
