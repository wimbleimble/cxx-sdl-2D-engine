#include "Renderer.h"
#include "Err.h"

#include "Layer.h"
#include "State.h"
#include "Actor.h"


Renderer::Renderer(const WindowParams& windowParams,
	const RenderParams& renderParams)
	: _window{ SDL_CreateWindow(windowParams.title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		windowParams.width,
		windowParams.height,
		SDL_WINDOW_SHOWN) },
	_renderer{},
	_winWidth{ windowParams.width },
	_winHeight{ windowParams.height },
	_renderWidth{ renderParams.width },
	_renderHeight{ renderParams.height }
{
	if (_window == nullptr)
		throw Err(SDL_GetError(), Err::Type::SDL);

	_renderer = SDL_CreateRenderer(_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);

	if (_renderer == nullptr)
	{
		SDL_DestroyWindow(_window);
		throw Err(SDL_GetError(), Err::Type::SDL);
	}
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(_window);
	if (_renderer != nullptr)
		SDL_DestroyRenderer(_renderer);
}

int Renderer::widthScale() const
{
	return winWidth() / renderWidth();
}

int Renderer::heightScale() const
{
	return winHeight() / renderHeight();
}

int Renderer::winWidth() const
{
	return _winWidth;
}

int Renderer::winHeight() const
{
	return _winHeight;
}

int Renderer::renderWidth() const
{
	return _renderWidth;
}

int Renderer::renderHeight() const
{
	return _renderHeight;
}

SDL_Renderer* Renderer::context()
{
	return _renderer;
}

void Renderer::renderState(State* state, double deltaTime)
{
	SDL_RenderClear(_renderer);

	for (const Layer& layer : state->scene())
		for (Actor* actor : layer)
			if (actor->visible())
				actor->render(*this, state->camera(), deltaTime);

	SDL_RenderPresent(_renderer);
}
void Renderer::renderTexture(SDL_Texture* texture,
	const SDL_Rect& srcRect,
	const SDL_Rect& dstRect,
	const double angle,
	const SDL_RendererFlip flip)
{
	const int wScale{ widthScale() };
	const int hScale{ heightScale() };

	const SDL_Rect scaledDst{
		dstRect.x * wScale,
		dstRect.y * hScale,
		dstRect.w * wScale,
		dstRect.h * hScale
	};

	SDL_RenderCopyEx(_renderer,
		texture,
		&srcRect,
		&scaledDst,
		angle,
		nullptr,
		flip);
}