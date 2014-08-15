/////
///// \file	framerate.h
/////	\brief	Based on SDL2_gfx. Thanks
/////	\date	15 août 2014
///// \author	Nico_user
/////
//#ifndef FRAMERATE_H_
//#define FRAMERATE_H_
//
///// === INCLUDES	================================================================================
//#include <chrono>
//
////#include "SDL2_gfx/SDL2_framerate.h"
//
///// === NAMESPACE	================================================================================
///// \namespace	xxx
//namespace sdl
//{
//
///// === CLASS	====================================================================================
///// \class
///// \brief
///// \date	15 août 2014
///// \author	Nico_user
//class Framerate
//{
//public:
//	/*!
//	 \brief Highest possible rate supported by framerate controller in Hz (1/s).
//	 */
//	static const uint8_t FPS_UPPER_LIMIT = 200;
//
//	/*!
//	 \brief Lowest possible rate supported by framerate controller in Hz (1/s).
//	 */
//	static const uint8_t FPS_LOWER_LIMIT = 1;
//
//	/*!
//	 \brief Default rate of framerate controller in Hz (1/s).
//	 */
//	static const uint8_t FPS_DEFAULT = 30;
//
//	/// === PUBLIC DECLARATIONS	====================================================================
//	Framerate(uint8_t frame_rate = FPS_DEFAULT);
//
//	uint8_t getFPS() const;
//	void update();
//
//private:
//	/// === PRIVATE DECLARATIONS	================================================================
//
//	/// === PRIVATE ATTRIBUTS	====================================================================
//	uint32_t framecount;
//	float rateticks;
//	uint32_t baseticks;
//	uint32_t lastticks;
//	uint32_t rate;
//
//	std::chrono::system_clock::time_point start_time_;
//};
//
///// === INLINE DEFINITIONS	========================================================================
//
//}
//
//#endif	/// FRAMERATE_H_///// === END OF FILE	================================================================================
