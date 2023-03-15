#include <exception>
#include "Game.hpp"

Game::Game(const char *title, int width = -1, int height = -1)
{
	this->title = title;
	if (width == -1)
		this->width = 500;
	else
		this->width = width;

	if (height == -1)
		this->height = 500;
	else
		this->height = height;

	this->tiles = new vector<Tile *>();
}

Game::~Game()
{
	if (this->renderer)
		SDL_DestroyRenderer(this->renderer);

	if (this->window)
		SDL_DestroyWindow(this->window);

	if (SDL_WasInit(SDL_INIT_EVERYTHING) != 0)
		SDL_Quit();

	for (int i = 0; i < this->tiles->size(); i++)
		delete this->tiles->at(i);

	delete this->tiles;
}

void	Game::addTile(Tile *tile)
{
	this->tiles->push_back(tile);
}

void	Game::loop()
{
	while (this->is_running)
	{
		this->handleEvents();
		this->render();
	}
}

void	Game::handleEvents()
{
	SDL_Event 		event;

	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			this->is_running = false;
			break ;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				this->is_running = false;
			break ;
	}
}

void	Game::render()
{
	SDL_RenderClear(this->renderer);

	vector<Tile *>::iterator it;
	for (it = this->tiles->begin(); it < this->tiles->end(); it++)
		(*it)->render();
	
	SDL_RenderPresent(this->renderer);
}

void	Game::initGame()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		this->window = SDL_CreateWindow(this->title,
										SDL_WINDOWPOS_CENTERED,
										SDL_WINDOWPOS_CENTERED,
										this->width,
										this->height,
										0);
		if (!this->window)
			throw Game::CannotInitSDLException();
		
		this->renderer = SDL_CreateRenderer(this->window, -1, 0);
		if (!this->renderer)
		{
			SDL_DestroyWindow(this->window);
			throw Game::CannotInitSDLException();
		}
		this->is_running = true;
	}
	else
		throw Game::CannotInitSDLException();
}

SDL_Renderer	*Game::getRenderer() const
{
	return (this->renderer);
}

const char	*Game::CannotInitSDLException::what() throw()
{
	return "SDL initialization failed";
}