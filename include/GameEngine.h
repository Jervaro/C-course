#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <vector>
#include "System.h"

// Spelmotor klass
namespace MyGameEngine
{
	class Sprite;

	class GameEngine
	{
	public:
		void add(Sprite *comp);
		void remove(Sprite *comp);
		void run();

	private:
		std::vector<Sprite *> comps;   	// Vector för alla components.
		std::vector<Sprite *> added;   	// Vector för nya components som ska läggas till i comps efter iterering.
		std::vector<Sprite *> removed; 	// Vector för components som ska tas bort från comps efter iterering.
	};

	// Global GameEngine
	extern GameEngine globalGameEngine;
}
#endif