#include "Tile.hpp"

Tile::Tile(SDL_Renderer *renderer, int x, int y, const char *path)
{
	SDL_Surface *surface = IMG_Load(path);
	this->texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	this->renderer = renderer;
	this->x = x;
	this->y = y;
}

Tile::~Tile()
{
	if (this->texture)
		SDL_DestroyTexture(this->texture);
}

void	Tile::render()
{
	SDL_Rect rect = {this->x, this->y, 32, 32};
	SDL_RenderCopy(this->renderer, this->texture, NULL, &rect);
}