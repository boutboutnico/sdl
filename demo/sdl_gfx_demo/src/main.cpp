/// \file	main.cpp

/// === INCLUDES	================================================================================
#include <sdl.h>
#include <window.h>
#include <texture.h>
#include <renderer.h>
#include <surface.h>

#include <stdio.h>
#include <iostream>

#include "SDL2_gfx/SDL2_framerate.h"

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
		Window window("Ma première application SDL2", Window::UNDEFINED, Window::UNDEFINED, 640,
				480, Window::SHOWN);

//		Renderer renderer(window, -1, Renderer::ACCELERATED);
//
//		/// Background
//		renderer.setDrawColor(255, 0, 0, 255);
//		renderer.clear();
//
//		Surface surface("./res/penguin.bmp");
//		Texture texture(renderer, surface);
//
//		SDL_Rect dest =
//		{ 640 / 2 - texture.getWidth() / 2, 480 / 2 - texture.getHeight() / 2, texture.getWidth(),
//				texture.getHeight() };
//
//		texture.copy(NULL, &dest);
////		texture.copy(NULL, NULL);
//		renderer.present();
//
//		/// Attendre trois secondes, que l'utilisateur voit la fenêtre
//		SDL_Delay(3000);


		FPSmanager manager;
		//Initialisation
		SDL_initFramerate(&manager);

		SDL_setFramerate(&manager,60);


		while(true)
		{
//		  ...
//		  // Demander au moteur de dessiner la scene
//		  moteur.gereScene();
		  SDL_framerateDelay(&manager);
		}


		cout << "SDL2: Quit" << endl;
		return 0;

	} catch (const SDL_Exception& err)
	{
		cerr << "Error SDL: " << err.what() << endl;
	}

	return 1;
}
/// === END OF FILE	================================================================================
