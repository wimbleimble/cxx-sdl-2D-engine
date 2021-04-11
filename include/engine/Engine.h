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
	Engine(const Renderer::WindowParams& windowParams = { "Title", 640, 480 });
	~Engine();

	const Renderer& renderer() const;
	Renderer& renderer();
	const Input& input();
	double deltaTime() const;

	int exec(State* entryState);
};

#endif