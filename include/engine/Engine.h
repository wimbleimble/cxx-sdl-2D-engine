#ifndef ENGINE_H 
#define ENGINE_H
#include <vector>
#include <string>

#include "SDL.h"

#include "SDLHandler.h"
#include "Renderer.h"
#include "Input.h"

class State;
class Engine
{
private:
	const SDLHandler _sdl;
	Renderer _renderer;
	Input _input;
	State* _state;
	bool _run;
	double _deltaTime;

	void setState(State* state);

public:
	Engine(const Renderer::WindowParams& windowParams = { "Title", 1280, 720 },
		const Renderer::RenderParams& renderParams = { 320, 180 });
	~Engine();

	const Renderer& renderer() const;
	Renderer& renderer();
	const Input& input();
	State* state();
	double deltaTime() const;

	int exec(State* entryState);
};

#endif