/// \file	main.cpp

/// === INCLUDES	================================================================================
#include <SDL2/SDL.h>

#include <sdl.h>
#include <window.h>
#include <texture.h>
#include <renderer.h>
#include <surface.h>

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

/// === NAMESPACE	================================================================================
using namespace std;
using namespace sdl;

/// ------------------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	cout << "SDL2: Hello World" << endl;

	try
	{
		SDL sdl(EInit::VIDEO | EInit::TIMER);

		/// Création de la fenêtre
		Window window("Drawing More", 50, Window::CENTERED, 600, 600, Window::SHOWN);

		Renderer renderer(window, -1, Renderer::ACCELERATED);

		Surface surface("res/fpsdl.bmp");
		Texture texture(renderer, surface);
		texture.copy(NULL, NULL);
		renderer.present();

//		/// Change colours
//		for (int i = 0; i < 255; i++)
//		{
//			renderer.clear();
//			texture.setColorMod(255 - i, 255 - i, 255);
//			texture.copy(NULL, NULL);
//			renderer.present();
//			SDL_Delay(20);
//		}
//		texture.setColorMod(255, 255, 255);
//
//		/// Fade out
//		renderer.setDrawColor(0, 255, 255, 255);
//		texture.setBlendMode(EBlendMode::BLEND);
//		for (int i = 0; i < 255; i++)
//		{
//			renderer.clear();
//			texture.setAlphaMode(255 - i);
//			texture.copy(NULL, NULL);
//			renderer.present();
//			SDL_Delay(20);
//		}

		/// Change clip rectangle and change colours
		SDL_Rect rect =
		{ 100, 100, 190, 190 };

		renderer.setClipRect(&rect);
		for (int i = 0; i < 255; i++)
		{
			texture.setColorMod(255 - i, 255 - i, i);
			texture.copy();
			renderer.present();
			SDL_Delay(20);
		}
		texture.setColorMod(255, 255, 255);
		renderer.setClipRect(NULL);

		/// Change viewport and change colours
		rect =
		{	10, 10, 190, 190};
		renderer.setViewport(&rect);
		for (int i = 0; i < 255; i++)
		{
			texture.setColorMod(255 - i, 255 - i, i);
			texture.copy();
			renderer.present();
			SDL_Delay(20);
		}
		renderer.setViewport(NULL);

		/// Setting logical size resolution
		renderer.clear();
		renderer.setLogicalSize(640, 480);
		for (int i = 0; i < 255; i++)
		{
			texture.setColorMod(255 - i, 255 - i, i);
			texture.copy();
			renderer.present();
			SDL_Delay(20);
		}
		renderer.setLogicalSize(600, 600);
		texture.setColorMod(255, 255, 255);

		/// Rotate
		SDL_Point point =
		{ 250, 250 };
		for (int i = 0; i < 359; i++)
		{
			renderer.clear();
			texture.copyEx(NULL, NULL, i, &point, SDL_FLIP_NONE);
			renderer.present();
			SDL_Delay(5);
		}

		/// Scale
		for (int i = 500; i >= 1; i--)
		{
			renderer.clear();
			renderer.setScale(i, i);
			texture.copy();
			renderer.present();
			SDL_Delay(5);
		}

		SDL_Delay(5000);
		cout << "SDL2: Quit" << endl;
		return 0;

	} catch (const SDL_Exception& err)
	{
		cerr << "Error SDL: " << err.what() << endl;
	}

	return 1;
}
/// === END OF FILE	================================================================================
