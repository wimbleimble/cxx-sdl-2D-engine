#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

class Message
{
public:
	enum class Type
	{
		Video,
		Audio,
		Engine,
		MAX_TYPES
	};

protected:
	Type type;

public:
	virtual ~Message() {}

	virtual void exec() = 0;
	virtual void undo() = 0;

};

#endif