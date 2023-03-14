#ifndef TILE_HPP
# define TILE_HPP
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>

class Tile
{
public:
	Tile(SDL_Renderer *renderer, int x, int y, const char *path);
	~Tile();

	void	render();

private:
	SDL_Texture 	*texture;
	SDL_Renderer	*renderer;
	int				x;
	int				y;
};

#endif