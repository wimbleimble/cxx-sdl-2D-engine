#include "MessageBus.h"

MessageBus::MessageBus()
	:_bus{ (int)Message::Type::MAX_TYPES }
{
}

void MessageBus::post(const MessageBus::Message& message)
{
	_bus[(int)message.type].push(message);
}

bool MessageBus::poll(MessageBus::Message& msg)
{
	if (_bus[(int)msg.type].size() == 0)
		return false;
	msg = _bus[(int)msg.type].front();
	_bus[(int)msg.type].pop();
}