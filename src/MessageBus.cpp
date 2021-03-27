#include "MessageBus.h"

MessageBus::MessageBus()
	:_bus{ (int)Message::Type::MAX_TYPES }
{
}

void MessageBus::postMessage(const MessageBus::Message& message)
{
	_bus[(int)message.type].push(message);
}

MessageBus::Message MessageBus::pollMessage(MessageBus::Message::Type type)
{
	if (_bus[(int)type].size() == 0)
		return Message({ "NULL", type });
	


}