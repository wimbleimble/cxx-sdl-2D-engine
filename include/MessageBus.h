#ifndef MESSAGE_BUS_H
#define MESSAGE_BUS_H
#include <string>
#include <vector>
#include <queue>

class MessageBus
{
public:
	struct Message
	{
		enum class Type
		{
			Video,
			Audio,
			MAX_TYPES
		};

		std::string data;
		Type type;
	};

	MessageBus();
	~MessageBus();

	Message pollMessage(Message::Type type);

private:
	std::vector<std::queue<Message>> _bus;

	void postMessage(const Message& message);
};

#endif