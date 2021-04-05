#ifndef RENDERER_H
#define RENDERER_H
#include <string>

#include "SDL.h"

class State;

class Renderer
{

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	int _winWidth;
	int _winHeight;

public:

	struct WindowParams
	{
		std::string title;
		int width;
		int height;
	};

	Renderer(const WindowParams& windowParams);
	~Renderer();

	int winWidth() const;
	int winHeight() const;
	SDL_Renderer* renderer();

	void renderState(State* state, double deltaTime);
	void renderTexture(SDL_Texture* texture,
		const SDL_Rect& srcRect,
		const SDL_Rect& dstRect);
};


#endif