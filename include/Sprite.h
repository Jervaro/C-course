#ifndef SPRITE_H
#define SPRITE_H

#include "GameEngine.h"

// Spelmotor klass
namespace MyGameEngine{
	class Sprite
	{
	public:
		virtual void mouseDown(int x, int y) {}
		virtual void mouseUp(int x, int y) {}
		virtual void leftArrow() {};
		virtual void leftArrowUp(){};
		virtual void rightArrow() {};
		virtual void rightArrowUp(){};
		virtual void upArrow() {};
		virtual void upArrowUp(){};
		virtual void downArrow() {};
		virtual void downArrowUp(){};
		virtual void spaceDown() {};
		virtual void spaceUp() {};

		virtual void tick(std::vector<Sprite*> comps, int loop){};
		virtual void checkCollision(std::vector<Sprite *> comps);
		virtual void handleCollision(Sprite* other){};
		virtual void draw() const;
		
		bool checkCollisionHelper(Sprite* other);
		void setRect(int x, int y, int w, int h) { rect = {x, y, w, h}; };
		void setRectX(int x) { rect = {x, rect.y, rect.y, rect.h}; };
		const SDL_Rect &getRect() const { return rect; };
		const int &getSize() const { return size; };

		// Destruktor
		virtual ~Sprite() {
			//std::cout << "Sprite destruktor" << std::endl;
			SDL_DestroyTexture(texture);
			SDL_FreeSurface(surf);
		};

	protected:
		Sprite(std::string fileName, int x, int y, int w, int h);
		// För osynliga sprites eller t.ex. Label.
		Sprite(int x, int y, int w, int h);
		// Protected för Label.
		SDL_Texture *texture;
		// Protected för Label.
		SDL_Surface *surf;

		// Protected för att subklasser ska kunna röra på sig.
		SDL_Rect rect;

	private:
		// Förbjuder tilldelnings operator.
		Sprite operator=(const Sprite &other) const = delete; // =operator
		// Förbjud kopiering.
		Sprite(const Sprite &) = delete;
		
		int size;
		int speed;
		
	};
}
#endif
