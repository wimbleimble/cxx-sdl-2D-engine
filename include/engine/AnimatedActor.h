#ifndef ANIMATEDACTOR_H
#define ANIMATEDACTOR_H
#include "Actor.h"

#include "Animator.h"

class AnimatedActor : public Actor
{
	Animator _animator;

public:
	AnimatedActor(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	virtual ~AnimatedActor();

	virtual bool visible() const;

	const Animator& animator() const;
	Animator& animator();

	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime);
};

#endif