#include <string>
#include <iostream>
#include <fstream>
#include "Map.hpp"

Map::Map(const char *path)
{
	std::ifstream infile(path);

	if (infile.bad())
		return ;

	this->width = 0;
	this->height = 0;

	std::string line;
	while (std::getline(infile, line))
	{
		if (this->width < line.length())
			this->width = line.length() - 1; // To get rid of newline.

		this->map.push_back(string(line));
		this->height++;
	}
	infile.close();
}

Map::~Map()
{
}

char	Map::getElement(int x, int y) const
{
	return this->map.at(y).at(x);
}

int Map::getMapWidth() const
{
	return (this->width);
}

int		Map::getMapHeight() const
{
	return (this->height);
}

bool	Map::checkMap()
{
	// TODO: check map.
	return (true);
}