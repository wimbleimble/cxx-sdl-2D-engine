#include "FlippyState.h"
#include "Engine.h"
#include "AnimatedSprite.h"
#include "WelpState.h"

#include <iostream>

FlippyState::FlippyState(Engine* engine)
	: State{ (int)Layers::MAX_LAYERS },
	vriska{ engine->renderer(), "vriska.png", 70, 88, 138 },
	karkat{ engine->renderer(), "karkat.png", 67, 88, 141 },
	smiley{ engine->renderer(), "smiley.png" }
{
	vriska.setZIndex(69);

	_scene[(int)Layers::OBJECTS].addActor(&vriska);
	_scene[(int)Layers::OBJECTS].addActor(&karkat);
	_scene[(int)Layers::UI].addActor(&smiley);

	vriska.animatedSprite()->addAnimation("WalkDown", 16, 9, 30);
	vriska.animatedSprite()->addAnimation("WalkLeft", 44, 8, 30);
	vriska.animatedSprite()->addAnimation("WalkRight", 25, 9, 30);
	vriska.animatedSprite()->addAnimation("WalkUp", 34, 8, 30);
	vriska.animatedSprite()->addAnimation("Idle", 0, 1, 30);
	vriska.animatedSprite()->setAnimation("Idle");

	karkat.animatedSprite()->addAnimation("WalkDown", 16, 9, 30);
	karkat.animatedSprite()->addAnimation("WalkLeft", 44, 8, 30);
	karkat.animatedSprite()->addAnimation("WalkRight", 25, 9, 30);
	karkat.animatedSprite()->addAnimation("WalkUp", 34, 8, 30);
	karkat.animatedSprite()->addAnimation("Idle", 16, 9, 7);
	karkat.animatedSprite()->setAnimation("Idle");
}

FlippyState::~FlippyState()
{
}

void FlippyState::enter(Engine* engine)
{
}

State* FlippyState::handleEvent(Engine* engine, SDL_Event event)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_SPACE:
		_scene[(int)Layers::OBJECTS].removeActor(&vriska);
		_scene[(int)Layers::BACKGROUND].addActor(&vriska);
		break;
	case SDLK_TAB:
		return new WelpState(engine);
	}
	return nullptr;
}

State* FlippyState::update(Engine* engine)
{
	const Uint8* k{ SDL_GetKeyboardState(nullptr) };
	vriska.setV(
		(int)k[SDL_SCANCODE_UP] * Vec2(0, -vriska.speed)
		+ (int)k[SDL_SCANCODE_DOWN] * Vec2(0, vriska.speed)
		+ (int)k[SDL_SCANCODE_LEFT] * Vec2(-vriska.speed, 0)
		+ (int)k[SDL_SCANCODE_RIGHT] * Vec2(vriska.speed, 0)
	);
	Vec2 cameraV(
		(int)k[SDL_SCANCODE_I] * Vec2(0, -vriska.speed)
		+ (int)k[SDL_SCANCODE_K] * Vec2(0, vriska.speed)
		+ (int)k[SDL_SCANCODE_J] * Vec2(-vriska.speed, 0)
		+ (int)k[SDL_SCANCODE_L] * Vec2(vriska.speed, 0)
	);

	if (k[SDL_SCANCODE_UP])
		vriska.animatedSprite()->setAnimation("WalkUp");
	else if (k[SDL_SCANCODE_DOWN])
		vriska.animatedSprite()->setAnimation("WalkDown");
	else if (k[SDL_SCANCODE_LEFT])
		vriska.animatedSprite()->setAnimation("WalkLeft");
	else if (k[SDL_SCANCODE_RIGHT])
		vriska.animatedSprite()->setAnimation("WalkRight");
	else
		vriska.animatedSprite()->setAnimation("Idle");

	vriska.position() += vriska.v();
	_camera.position() += cameraV;
	return nullptr;
}
void FlippyState::exit(Engine* engine)
{
}