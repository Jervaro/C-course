#include "Sprite.h"
#include "GameEngine.h"

using namespace std;

#define FPS 60; // FPS Limit

// Spelmotor klass.
namespace MyGameEngine
{
	void GameEngine::add(Sprite *comp)
	{
		added.push_back(comp);
	}

	void GameEngine::remove(Sprite *comp)
	{
		removed.push_back(comp);
	}

	void GameEngine::run()
	{
		bool quit = false;
		bool musicOn = true;
		Uint32 tickInterval = 1000 / FPS; // <-- Används för att sätta FPS limit.

		int loop = 0; // <-- Initierar loopen.

		// SDL Händelseförlopp.
		while (!quit)
		{
			Uint32 nextTick = SDL_GetTicks() + tickInterval; // <-- Används för att sätta FPS limit.

			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
				case SDL_QUIT:
					quit = true;
					break;
				// Kontrollera player med pil-tangenterna.
				// KEYDOWN
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_m:
						if (musicOn)
						{
							sys.StopMusic();
							musicOn = false;
						}
						else
						{
							sys.PlayMusic();
							musicOn = true;
						}
						break;
					case SDLK_RIGHT:
						for (Sprite *c : comps)
						{
							c->rightArrow();
						}
						break;
					case SDLK_LEFT:
						for (Sprite *c : comps)
						{
							c->leftArrow();
						}
						break;
					case SDLK_UP:
						for (Sprite *c : comps)
						{
							c->upArrow();
						}
						break;
					case SDLK_DOWN:
						for (Sprite *c : comps)
						{
							c->downArrow();
						}
						break;
					case SDLK_SPACE:
						for (Sprite *c : comps)
						{
							c->spaceDown();
						}
						break;
					}
					break;
				// KEYUP
				case SDL_KEYUP:
					switch (event.key.keysym.sym)
					{
					case SDLK_RIGHT:
						for (Sprite *c : comps)
						{
							c->rightArrowUp();
						}
						break;
					case SDLK_LEFT:
						for (Sprite *c : comps)
						{
							c->leftArrowUp();
						}
						break;
					case SDLK_UP:
						for (Sprite *c : comps)
						{
							c->upArrowUp();
						}
						break;
					case SDLK_DOWN:
						for (Sprite *c : comps)
						{
							c->downArrowUp();
						}
						break;
					case SDLK_SPACE:
						for (Sprite *c : comps)
						{
							c->spaceUp();
						}
						break;
					}
					break;

				// Mus knappar
				case SDL_MOUSEBUTTONDOWN:
					for (Sprite *c : comps)
						c->mouseDown(event.button.x, event.button.y);
					break;
				case SDL_MOUSEBUTTONUP:
					for (Sprite *c : comps)
						c->mouseUp(event.button.x, event.button.y);
					break;
				}	// switch slut
			}		// inre while slut
			loop++; // <-- Ökar antalet varv efter varje loop.

			// Uppdaterar alla components genom anrop av tick medlemsfunktionen.
			for (Sprite *c : comps)
			{
				c->tick(comps, loop);
				c->checkCollision(comps);
			}

			// Uppdaterar comps med componenets från added efter iterationen ovanför är klar.
			for (Sprite *c : added)
			{
				comps.push_back(c);
			}
			added.clear(); // Tömmer added vektorn.

			// Tar bort components från comps.
			for (Sprite *c : removed)
			{
				for (vector<Sprite *>::iterator i = comps.begin(); i != comps.end();)
				{
					if (*i == c)
					{
						i = comps.erase(i); // erase() returnerar iteratorn till det första elementet som är kvar i vectorn.
						delete c;			// Tar bort objektet helt med delete.
					}
					else
					{
						i++;
					}
				}
			}

			removed.clear(); // Tömmer removed vektorn.

			// Utskrift av alla components.
			SDL_SetRenderDrawColor(sys.get_ren(), 255, 255, 255, 255);
			SDL_RenderClear(sys.get_ren());
			for (Sprite *c : comps)
				c->draw();
			SDL_RenderPresent(sys.get_ren());

			// Används för att sätta FPS limit.
			int delay = nextTick - SDL_GetTicks(); // Får reda på hur mkt tid det är kvar till nextTick.
			if (delay > 0)
			{
				SDL_Delay(delay);
			}
		} // yttre while
	}

	// Global GameEngine
	GameEngine globalGameEngine;
}
