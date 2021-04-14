#ifndef TILEATLAS_H
#define TILEATLAS_H
#include <vector>

#include "Sprite.h"

class TileAtlas
{
	Sprite _sprite;
	std::vector<SDL_Rect> _tiles;

public:

	TileAtlas() = default;
	TileAtlas(SDL_Renderer* context,
		const std::string& path);

	// mabybe inplement some sort of sharing semantics so that two objects with
	// the same tilemap can use the same instance. its deleted for now tho
	TileAtlas(const TileAtlas& sprite) = delete;

	~TileAtlas();

	const Sprite& sprite() const;

	int registerTile(int x, int y, int width, int height);

	int numTiles() const;

	const SDL_Rect& operator[](int index) const;
};

#endif