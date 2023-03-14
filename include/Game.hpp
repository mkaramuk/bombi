#ifndef GAME_HPP
# define GAME_HPP
# include <exception>
# include <vector>
# include <SDL2/SDL.h>
# include "Tile.hpp"

using std::vector;

class Game
{
public:
	Game(const char *title, int width, int height);
	~Game();

	void			initGame();
	void			handleEvents();
	void			loop();
	void			render();
	void			addTile(Tile *tile);

	SDL_Renderer	*getRenderer() const;

	class CannotInitSDLException : public std::exception
	{
	public:
		const char *what() throw();
	};

private:
	vector<Tile*>	*tiles;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	bool			is_running;
	const char		*title;
	int				width;
	int				height;
};

#endif