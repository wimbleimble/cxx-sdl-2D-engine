#ifndef BUTTON_H
#define BUTTON_H
#include <string>

#include "SDL.h"

#include "Ui.h"

class AnimatedSprite;
class Input;

class Button : public Ui
{
	enum class State
	{
		Normal,
		Hover,
		Clicked,
		MAX_STATES
	};

	State _state;

public:
	static constexpr int speed{ 5 };
	Button(SDL_Renderer* context,
		const std::string& path,
		int width,
		int height,
		int frames);
	~Button();

	virtual void update();
	virtual bool visible() const;

	bool mouseOver(const Renderer& renderer,
		const Input& input,
		const Camera& camera) const;

	AnimatedSprite* animatedSprite();

	const Vec2& v() const;
	void setV(const Vec2& v);
};

#endif