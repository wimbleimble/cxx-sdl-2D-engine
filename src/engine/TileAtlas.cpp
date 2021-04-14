#include "TileAtlas.h"

#include <cassert>

TileAtlas::TileAtlas(SDL_Renderer* context, const std::string& path)
	: _sprite{ context, path },
	_tiles{}
{
}

TileAtlas::~TileAtlas() {}

const Sprite& TileAtlas::sprite() const { return _sprite; }

int TileAtlas::registerTile(int x, int y, int width, int height)
{
	assert(x + width < _sprite.width() && y + height < _sprite.height());
	_tiles.push_back({ x, y, width, height });
	return _tiles.size();
}

int TileAtlas::numTiles() const
{
	return _tiles.size();
}

const SDL_Rect& TileAtlas::operator[](int index) const
{
	assert(index < _tiles.size());
	return _tiles[index];
}