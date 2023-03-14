#include "Game.hpp"
#include "Map.hpp"

int main()
{
	Game *game = new Game("Bombi", 600, 600);
	game->initGame();

	Map map("maps/demo_map.bom");
	map.checkMap();

	for (int i = 0; i < map.getMapHeight(); i++)
		for (int j = 0; j < map.getMapWidth(); j++)
			if (map.getElement(j, i) == '1')
				game->addTile(new Tile(game->getRenderer(), j * 32, i * 32, "assets/wall.png"));

	game->loop();

	return (0);
}