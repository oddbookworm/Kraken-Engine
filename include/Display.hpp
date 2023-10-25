#pragma once
#include <SDL.h>
#include <iostream>


namespace DK_Display {
	SDL_Window* setMode(const char* title, int width, int height);
	SDL_Renderer* setRenderer(SDL_Window* window);
	void cls(SDL_Renderer* renderer);
	void flip(SDL_Renderer* renderer);
}

