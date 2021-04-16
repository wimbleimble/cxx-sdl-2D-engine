#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <functional>

class Animation
{
	int _startFrame;
	int _length;
	int _frameRate;
	std::vector<std::function<void()>> _frameCallbacks;
	std::function<void()> _endCallback;

public:
	// dunno why i need this. hope it doesn't cause problems later
	Animation() = default;
	Animation(int startFrame, int length, int frameRate);
	~Animation();

	int startFrame() const;
	int length() const;
	int frameRate() const;

	// call held callbacks
	void callFrame(int index) const;
	void callEnd() const;

	void onFrame(int index,
		const std::function<void()>& callback);
	void onEnd(const std::function<void()>& callback);

};

#endif