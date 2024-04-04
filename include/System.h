#ifndef SYSTEM_H
#define SYSTEM_H

#include "Constants.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include <iostream>

// Spelmotorklass
namespace MyGameEngine
{
	// Ändrade från struct till class för class medlemmar är default private.
	class System
	{
	public:
		System();  // Konstruktor
		~System(); // Destruktor
		void PlayMusic();
		void StopMusic();
		SDL_Renderer *get_ren() const;
		TTF_Font *get_font() const;
		int get_Width() const;
		int get_Height() const;
		int get_Score() const;
		void set_Score(int score);
		void increaseScore();

	private:
		SDL_Window *win;
		SDL_Renderer *ren;
		SDL_DisplayMode display;
		Mix_Chunk *musik;

		TTF_Font *font;

		int screenWidth = 1200;
		int screenHeight = 800;
		int score = 0;
		double buffer = 1.5;
	};
	// Extern sys in system.cpp
	extern System sys;
}
#endif
