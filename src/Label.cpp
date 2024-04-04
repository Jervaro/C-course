#include "Label.h"

using namespace std;

// Spel klass.
using namespace MyGameEngine;
Label *Label::getInstance(std::string txt, int x, int y, int w, int h)
{
	return new Label(txt, x, y, w, h);
}

Label::Label(std::string txt, int x, int y, int w, int h) : Sprite(x, y, w, h)
{
	text = txt;
	// Surface (inladdning av bild och felhantering)
	surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {255, 0, 0});
	if (!surf)
	{
		std::cerr << "Error loading surface in label: " << SDL_GetError() << std::endl;
	}

	// Texture skapning och felhantering.
	texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
	if (!texture)
	{
		std::cerr << "Error loading texture label: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(surf);
}

string Label::getText() const
{
	return text;
}

void Label::setText(std::string newText)
{
	text = newText;
	SDL_DestroyTexture(texture);

	// Surface (inladdning av bild och felhantering)
	SDL_Surface *surf = TTF_RenderText_Solid(sys.get_font(), text.c_str(), {255, 0, 0}); // Röd färg = 255, 0, 0
	if (!surf)
	{
		std::cerr << "Error loading surface in label setText: " << SDL_GetError() << std::endl;
	}

	// Texture skapning och felhantering.
	texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
	if (!texture)
	{
		std::cerr << "Error loading texture in label setText: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(surf);
}
