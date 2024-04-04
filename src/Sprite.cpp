#include "Sprite.h"

namespace MyGameEngine
{
    // Spelmotor klass.
    Sprite::Sprite(std::string fileName, int x, int y, int w, int h)
    {
        // Sätter rect.
        rect = {x, y, w, h};

        // Surface (inladdning av bild och felhantering)
        surf = IMG_Load((constants::gResPath + fileName).c_str());
        if (!surf)
        {
            std::cerr << "Error loading surface in Sprite: " << SDL_GetError() << std::endl;
        }

        // Texture skapning och felhantering.
        texture = SDL_CreateTextureFromSurface(sys.get_ren(), surf);
        if (!texture)
        {
            std::cerr << "Error loading texture in Sprite: " << SDL_GetError() << std::endl;
        }
    }

    Sprite::Sprite(int x, int y, int w, int h)
    {
        // Sätter rect.
        rect = {x, y, w, h};
    }

    void Sprite::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), texture, NULL, &rect);
    }

    bool Sprite::checkCollisionHelper(Sprite *other)
    {
        const SDL_Rect &rect1 = getRect();
        const SDL_Rect &rect2 = other->getRect();

        if(SDL_HasIntersection(&rect1, &rect2) == SDL_TRUE){
            return true;
        }
        return false;
    }

    void Sprite::checkCollision(std::vector<Sprite *> comps)
    {
        for (Sprite *other : comps)
        {
            if (this != other && checkCollisionHelper(other))
            {
                handleCollision(other);
            }
        }
    }
}
