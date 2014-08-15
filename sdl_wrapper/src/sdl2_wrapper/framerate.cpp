/////
///// \file	framerate.cpp
/////	\brief
/////	\date	15 août 2014
///// \author	Nico_user
/////
//
//#include <framerate.h>
//using namespace sdl;
//
///// === INCLUDES	================================================================================
//
///// === NAMESPACES	================================================================================
//
///// === PUBLIC DEFINITIONS	========================================================================
//Framerate::Framerate(uint8_t frame_rate)
//{
//	framecount = 0;
//	rate = frame_rate;
//	rateticks = (1000.0f / (float) frame_rate);
//	baseticks = _getTicks();
//	lastticks = baseticks;
//}
//
///// ------------------------------------------------------------------------------------------------
//uint16_t Framerate::getFPS() const
//{
////	return (frame_count_ / (float) (SDL_GetTicks() - start_time_)) * 1000;
//}
//
///// ------------------------------------------------------------------------------------------------
//void Framerate::update()
//{
////	SDL_framerateDelay(&manager_);
//}
//
///// === PRIVATE DEFINITIONS	========================================================================
//
///// === END OF FILES	============================================================================
