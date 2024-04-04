#ifndef LABEL_H
#define LABEL_H

#include "Sprite.h"

// Spel klass.
using namespace MyGameEngine;

class Label : public MyGameEngine::Sprite
{
public:
	static Label *getInstance(std::string txt, int x, int y, int w, int h);
	std::string getText() const;
	void setText(std::string newText);

protected:
	Label(std::string txt, int x, int y, int w, int h);

private:
	std::string text;
};

#endif