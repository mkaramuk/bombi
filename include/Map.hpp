#ifndef MAP_HPP
# define MAP_HPP
# include <vector>
# include <string>

using std::vector;
using std::string;

class Map
{
public:
	Map(const char *path);
	~Map();

	int		getMapWidth() const;
	int		getMapHeight() const;
	char	getElement(int x, int y) const;
	bool	checkMap();

private:
	vector<string>	map;
	int				width;
	int				height;
};

#endif