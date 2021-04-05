#include "TileAtlas.h"

#include <cassert>

TileAtlas::TileAtlas(SDL_Renderer* context, const std::string& path)
	: Sprite{ context, path },
	_tiles{}
{
}

TileAtlas::TileAtlas(const TileAtlas& sprite)
	: Sprite{ sprite },
	_tiles{ sprite._tiles }
{
}

TileAtlas::~TileAtlas()
{
}

int TileAtlas::registerTile(int x, int y, int width, int height)
{
	assert(x + width < sourceWidth() && y + height < sourceHeight());
	_tiles.push_back({ x, y, width, height });
	return _tiles.size();
}

int TileAtlas::numTiles() const
{
	return _tiles.size();
}

const SDL_Rect& TileAtlas::operator[](int index) const
{
	return _tiles[index];
}

TileAtlas& TileAtlas::operator=(const TileAtlas& sprite)
{
	_context = sprite._context;
	loadTexture(sprite._path);
	_width = sprite._width;
	_height = sprite._height;
	return *this;
}