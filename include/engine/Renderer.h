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

	int _renderWidth;
	int _renderHeight;


public:

	struct WindowParams
	{
		std::string title;
		int width;
		int height;
	};

	struct RenderParams
	{
		int width;
		int height;
	};

	Renderer(const WindowParams& windowParams,
		const RenderParams& renderParams);
	~Renderer();

	int winWidth() const;
	int winHeight() const;

	int renderWidth() const;
	int renderHeight() const;
	SDL_Renderer* context();

	int widthScale() const;
	int heightScale() const;

	void renderState(State* state, double deltaTime);
	void renderTexture(SDL_Texture* texture,
		const SDL_Rect& srcRect,
		const SDL_Rect& dstRect,
		const double angle = 0,
		const SDL_RendererFlip flip = SDL_FLIP_NONE);
};


#endif