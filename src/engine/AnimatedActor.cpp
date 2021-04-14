#include "AnimatedActor.h" 

#include "Renderer.h"
#include "Camera.h"

AnimatedActor::AnimatedActor(SDL_Renderer* context,
	const std::string& path,
	int width,
	int height,
	int frames)
	: Actor{ width, height },
	_animator{ context, path, width, height, frames }
{
}

AnimatedActor::~AnimatedActor() {}

bool AnimatedActor::visible() const { return true; }

const Animator& AnimatedActor::animator() const
{
	return _animator;
}
Animator& AnimatedActor::animator()
{
	return _animator;
}

void AnimatedActor::render(Renderer& renderer,
	const Camera& camera,
	double deltaTime)
{
	const SDL_Rect srcRect{ _animator.srcRect(deltaTime) };
	const SDL_Rect dstRect{
		(_position.x() - width() / 2)
		- (camera.position().x() - renderer.renderWidth() / 2),

		(_position.y() - height() / 2)
		- (camera.position().y() - renderer.renderHeight() / 2),

		width(),

		height()
	};
	renderer.renderTexture(_animator.sprite().texture(), srcRect, dstRect);
}