#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>

#include "Actor.h"

class TileAtlas;

class TileMap : public Actor
{
	int _tileWidth;
	int _tileHeight;

	std::vector<std::vector<int>> _map;

public:

	TileMap(SDL_Renderer* context,
		const std::string& path,
		int tileWidth,
		int tileHeight,
		int mapWidth,
		int mapHeight);
	~TileMap();

	void setTile(int x, int y, int index);
	virtual int width() const;
	virtual int height() const;

	const TileAtlas& atlas() const;
	TileAtlas& atlas();

	virtual void update() {}
	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime);
	virtual bool visible() const;
};

#endif