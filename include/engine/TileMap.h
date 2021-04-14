#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>

#include "Actor.h"
#include "TileAtlas.h"


class TileMap : public Actor
{
	int _tileWidth;
	int _tileHeight;

	TileAtlas _atlas;

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

	// this feels inefficient
	virtual State* handleEvent(Engine* engine, SDL_Event event);
	virtual State* update(Engine* engine);

	const TileAtlas& atlas() const;
	TileAtlas& atlas();

	virtual void update() {}
	virtual void render(Renderer& renderer,
		const Camera& camera,
		double deltaTime);
	virtual bool visible() const;
};

#endif