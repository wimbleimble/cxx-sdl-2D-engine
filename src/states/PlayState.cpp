#include "PlayState.h"

#include <iostream>

#include "Engine.h"
#include "TileAtlas.h"

PlayState::PlayState(Engine* engine)
	: State{ (int)Layers::NUM_LAYERS },
	bg{ engine->renderer().context(), "tiles.png", 64, 64, 32, 32 }
{
	std::cout << "Entered PlayState\n";
	bg.atlas().registerTile(0, 8, 16, 16);
	bg.atlas().registerTile(17, 8, 16, 16);
	bg.atlas().registerTile(0, 56, 16, 16);

	for (int row{}; row < bg.width(); ++row)
	{
		for (int col{}; col < bg.height(); ++col)
		{
			if ((row + col) % 2 == 0)
				bg.setTile(row, col, 0);
			else if ((row + col) % 3 == 0)
				bg.setTile(row, col, 1);
			else if ((row + col) % 5 == 0)
				bg.setTile(row, col, 2);
		}
	}

	_scene[(int)Layers::Background].addActor(&bg);
}

PlayState::~PlayState() {}

void PlayState::enter(Engine* engine)
{
}

State* PlayState::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* PlayState::update(Engine* engine)
{
	Vec2 cameraV(
		(int)engine->input().keyStates()[SDL_SCANCODE_I] * Vec2(0, -speed)
		+ (int)engine->input().keyStates()[SDL_SCANCODE_K] * Vec2(0, speed)
		+ (int)engine->input().keyStates()[SDL_SCANCODE_J] * Vec2(-speed, 0)
		+ (int)engine->input().keyStates()[SDL_SCANCODE_L] * Vec2(speed, 0)
	);

	_camera.position() += cameraV;
	return nullptr;
}

void PlayState::exit(Engine* engine)
{
}