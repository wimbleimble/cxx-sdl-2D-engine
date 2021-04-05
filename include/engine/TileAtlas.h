#ifndef TILEATLAS_H
#define TILEATLAS_H
#include <vector>

#include "Sprite.h"

class TileAtlas : public Sprite
{
	void setWidth(int width);
	void setHeight(int height);

	std::vector<SDL_Rect> _tiles;

public:

	TileAtlas() = default;
	TileAtlas(SDL_Renderer* context,
		const std::string& path);
	TileAtlas(const TileAtlas& sprite);

	~TileAtlas();

	int registerTile(int x, int y, int width, int height);

	int numTiles() const;

	const SDL_Rect& operator[](int index) const;
	TileAtlas& operator=(const TileAtlas& sprite);
};

#endif