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
		Window window("Drawing Primitives", Window::CENTERED, Window::CENTERED, 600, 600,
				Window::SHOWN);

		Renderer renderer(window, -1, Renderer::ACCELERATED);

		/// Set background
		renderer.setDrawColor(0, 255, 255, 255);
		renderer.clear();
		renderer.present();
		SDL_Delay(1000);

		/// Draw line
		renderer.setDrawColor(255, 0, 0, 255);
		renderer.drawLine(10, 10, 490, 490);
		renderer.present();
		SDL_Delay(1000);

		/// Draw doted line
		renderer.setDrawColor(0, 0, 0, 255);
		for (int i = 0; i < 47; i++)
		{
			renderer.drawPoint(490 - i * 10, 10 + i * 10);
		}
		renderer.present();
		SDL_Delay(1000);

		/// Draw rectangle
		SDL_Rect rect =
		{ 260, 10, 230, 230, };
		renderer.setDrawColor(0, 255, 0, 255);
		renderer.drawRect(&rect);
//		renderer.present();
//		SDL_Delay(1000);

		rect.x = 10;
		rect.y = 260;
		renderer.setDrawBlendMode(EBlendMode::BLEND);
		renderer.setDrawColor(0, 0, 255, 128);
		renderer.fillRect(&rect);
		renderer.present();
		SDL_Delay(1000);

		/// Draw Points
		srand(time(0));

		vector<const SDL_Point*> points;
		for (int i = 0; i < 10000; i++)
		{
			SDL_Point* point = new SDL_Point;
			point->x = rand() % 500;
			point->y = rand() % 500;

			points.push_back(point);
		}
		renderer.setDrawColor(128, 128, 128, 255);
		renderer.drawPoints(points);
		renderer.present();
		SDL_Delay(3000);

		cout << "SDL2: Quit" << endl;
		return 0;

	} catch (const SDL_Exception& err)
	{
		cerr << "Error SDL: " << err.what() << endl;
	}

	return 1;
}
/// === END OF FILE	================================================================================
