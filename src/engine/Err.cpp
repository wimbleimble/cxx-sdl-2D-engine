#include "Err.h"

Err::Err(const std::string& info, Err::Type type)
	: _info{ info }, _type{ type }
{
}

const std::string& Err::info() const
{
	return _info;
}

Err::Type Err::type() const
{
	return _type;
}