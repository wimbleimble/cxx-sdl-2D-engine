#ifndef BUTTON_H
#define BUTTON_H
#include <string>
#include <functional>

#include "SDL.h"

#include "Ui.h"

class AnimatedSprite;
class Input;

class Button : public Ui
{
	std::function<void()> _callback;

	void activate() const;

public:
	static constexpr int speed{ 5 };
	Button(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	~Button();

	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);
	virtual bool visible() const;

	AnimatedSprite* animatedSprite();

	const Vec2& v() const;
	void setV(const Vec2& v);

	void onClick(std::function<void()> callback);
};

#endif