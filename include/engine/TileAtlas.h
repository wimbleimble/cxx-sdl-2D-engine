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

	virtual SDL_Rect srcRect(double deltaTime);

	virtual int width();
	virtual int height();

	void registerTile(int x, int y, int width, int height);

	const SDL_Rect const* operator[](int index) const;
	TileAtlas& operator=(const TileAtlas& sprite);
};

#endif