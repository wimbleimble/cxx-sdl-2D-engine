#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H
#include <string>
#include <vector>
#include <queue>

#include "Message.h"

class MessageBus
{
	std::vector<std::queue<Message*>> _bus;
public:


	MessageBus();
	~MessageBus();

	Message* poll(Message::Type type);
	void post(Message* msg);
};

#endif