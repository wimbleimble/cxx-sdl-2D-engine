#ifndef CHANGESTATEMESSAGE_H
#define CHANGESTATEMESSAGE_H
#include "Message.h"
#include "State.h"

class ChangeStateMessage : public Message
{
	State* _state;
	
public:
	ChangeStateMessage();

	virtual ~ChangeStateMessage();

	virtual void exec();
	virtual void undo();
};

#endif