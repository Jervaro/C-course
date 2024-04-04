#include "System.h"

// Spelmotor klass.
namespace MyGameEngine
{
	System::System()
	{
		// initiera SDL.
		SDL_Init(SDL_INIT_EVERYTHING);

		win = SDL_CreateWindow("GameDemo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, 0); // Magiska nummer, inte bra!!!!
		ren = SDL_CreateRenderer(win, -1, 0);

		// Ljud/Mixer Init och felhantering.
		if (Mix_OpenAudio(
				22050,		  // Frequency
				AUDIO_S16SYS, // Format
				2,			  // No of channels
				4096		  // Buffer chunk size
				) != 0)
		{
			// Init failed.
			std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
		}
		// Ladda in musikfil.
		musik = Mix_LoadWAV((constants::gResPath + "sounds/bgMusic.wav").c_str());
		// Spela musiken.
		Mix_PlayChannel(-1, musik, -1);

		// TTF Init och felhantering av font inläsning.
		TTF_Init();
		font = TTF_OpenFont((constants::gResPath + "fonts/arial.ttf").c_str(), 36);
		if (!font)
		{
			std::cerr << "TTF_OpenFont Error: couldnt load in font." << TTF_GetError() << std::endl;
		}
	}

	System::~System()
	{
		// Musik/Ljud
		Mix_FreeChunk(musik);
		Mix_CloseAudio();

		// TTF/Fonts
		TTF_CloseFont(font);
		TTF_Quit();

		// SDL
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}

	void System::PlayMusic()
	{
		// Spela musiken.
		Mix_Resume(-1);
	}

	void System::StopMusic()
	{
		// Spela musiken.
		Mix_Pause(-1);
	}

	int System::get_Width() const
	{
		return screenWidth;
	}

	int System::get_Height() const
	{
		return screenHeight;
	}

	int System::get_Score() const
	{
		return score;
	}

	void System::set_Score(int score)
	{
		this->score = score;
	}

	void System::increaseScore()
	{
		score++;
	}

	SDL_Renderer *System::get_ren() const
	{
		return ren;
	}

	TTF_Font *System::get_font() const
	{
		return font;
	}

	//  Global system.
	System sys;
}
