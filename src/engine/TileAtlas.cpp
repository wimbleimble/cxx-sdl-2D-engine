#include "TileAtlas.h"

TileAtlas::TileAtlas(SDL_Renderer* context, const std::string& path)
	: Sprite{ context, path }

{
}

TileAtlas::TileAtlas(const TileAtlas& sprite)
	: Sprite{ sprite }
{
}

TileAtlas::~TileAtlas()
{
}

SDL_Rect TileAtlas::srcRect(double deltaTime)
{
}

TileAtlas& TileAtlas::operator=(const TileAtlas& sprite)
{
	_context = sprite._context;
	loadTexture(sprite._path);
	_width = sprite._width;
	_height = sprite._height;
	return *this;
}