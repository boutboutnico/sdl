/// \file	main.cpp

/// === INCLUDES	================================================================================
#include <sdl.h>
#include <window.h>
#include <texture.h>
#include <renderer.h>
#include <surface.h>
#include <font.h>
#include <text.h>

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

	bool b_done = false;
	SDL_Event event;

	try
	{
		SDL sdl(EInit::VIDEO | EInit::TIMER, EInit_Lib::SDL_TTF);

		/// Création de la fenêtre
		Window window("Ma première application SDL2", Window::UNDEFINED, Window::UNDEFINED, 640,
				480, Window::SHOWN);

		Renderer renderer(window, -1, Renderer::ACCELERATED);

		/// Init Framerate manager
		FPSmanager manager;
		SDL_initFramerate(&manager);
		SDL_setFramerate(&manager, 60);

		/// Init font
		SDL_Color black =
		{ 0, 0, 0 };
		Text text(renderer, Font("res/font/arial.ttf", 12), "Test sdl wrapper", black);

		while (b_done == false)
		{
			/// Handle events
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					b_done = true;
					break;
				case SDL_KEYUP:
//					if (event.key.keysym.sym == SDLK_f) b_fast_mode = !b_fast_mode;
					//else if (event.key.keysym.sym == SDLK_ESCAPE) moteur.echangeFonctions();
					break;
				case SDL_MOUSEBUTTONUP:
					//moteur.clic(event.button.x, event.button.y);
					break;
				default:
					break;
				}
			}

			/// Background
			renderer.setDrawColor(255, 0, 0, 255);
			renderer.clear();

			Surface surface("./res/penguin.bmp");
			Texture texture(renderer, surface);

			SDL_Rect dest =
			{ 640 / 2 - texture.getWidth() / 2, 480 / 2 - texture.getHeight() / 2,
					texture.getWidth(), texture.getHeight() };

			texture.copy(NULL, &dest);

			dest =
			{	50,50,100,100};
			text.copy(NULL, &dest);

			renderer.present();

			/// Update and Display current FrameRate
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
