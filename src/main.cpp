#include "Game.hpp"
#include "Map.hpp"

int main()
{
	Map map("maps/demo_map.bom");
	map.checkMap();
	Game *game = new Game("Bombi",	map.getMapWidth() * 32,
									map.getMapHeight() * 32);
	game->initGame();


	for (int i = 0; i < map.getMapHeight(); i++)
	{
		for (int j = 0; j < map.getMapWidth(); j++)
		{
			char *tile;

			if (map.getElement(j, i) == '1')
				tile = (char *)"assets/wall.png";
			else if (map.getElement(j, i) == '0')
				tile = (char *)"assets/grass.png";
			else
				continue ;
			game->addTile(new Tile(game->getRenderer(), j * 32, i * 32, tile));
		}
	}

	game->loop();

	return (0);
}