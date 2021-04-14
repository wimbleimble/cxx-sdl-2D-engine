#include "TileMap.h"

#include <cassert>

#include "TileAtlas.h"
#include "Camera.h"
#include "Renderer.h"

TileMap::TileMap(SDL_Renderer* context,
	const std::string& path,
	int tileWidth,
	int tileHeight,
	int mapWidth,
	int mapHeight)
	:Actor{ mapWidth, mapHeight },
	_atlas{ context, path },
	_tileWidth{ tileWidth },
	_tileHeight{ tileHeight },
	_map(mapWidth, std::vector<int>(mapHeight, -1))
{
}

TileMap::~TileMap() {}

int TileMap::width() const
{
	return _map.size();
}

int TileMap::height() const
{
	return width() > 0 ? _map[0].size() : 0;
}

const TileAtlas& TileMap::atlas() const
{
	return _atlas;
}

TileAtlas& TileMap::atlas()
{
	return _atlas;
}

void TileMap::setTile(int x, int y, int index)
{
	assert(x < width() || y < height());
	assert(index < atlas().numTiles());
	_map[x][y] = index;
}

State* TileMap::handleEvent(Engine* engine, SDL_Event event)
{
	return nullptr;
}

State* TileMap::update(Engine* engine)
{
	return nullptr;
}

bool TileMap::visible() const
{
	return true;
}

void TileMap::render(Renderer& renderer,
	const Camera& camera,
	double deltaTime)
{
	for (int row{}; row < width(); ++row)
	{
		for (int col{}; col < height(); ++col)
		{
			if (_map[row][col] >= 0)
			{
				const SDL_Rect& srcRect{ atlas()[_map[row][col]] };
				const SDL_Rect dstRect{
					(position().x() + row * _tileWidth)
					- (camera.position().x() - renderer.renderWidth() / 2),

					(position().y() + col * _tileHeight)
					- (camera.position().y() - renderer.renderHeight() / 2),

					_tileWidth,

					_tileHeight
				};
				renderer.renderTexture(_atlas.sprite().texture(),
					srcRect,
					dstRect);
			}
		}
	}
}