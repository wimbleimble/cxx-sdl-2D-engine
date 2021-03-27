#ifndef ERROR_H
#define ERROR_H
#include <string>

class Err
{
public:

	enum class Type
	{
		SDL,
		SDLImage,
		SDLHandler
	};

private:

	const std::string _info;
	const Type _type;
public:

	Err() = delete;
	Err(const std::string& info, Type type);

	const std::string& info() const;
	Type type() const;
};

#endif