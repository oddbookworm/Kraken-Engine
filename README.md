# DurkGame
<p align="center">
  <img src="https://img.shields.io/badge/license-MIT-blue.svg">
  <a href="https://app.codacy.com/gh/durkisneer1/DurkGame/dashboard?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade"><img src="https://app.codacy.com/project/badge/Grade/17028e01d32f4441be4bd5e37edb94ce"/></a>
</p>
DurkGame is an extention of SDL2. There will be different object types to inherit from in the future such as `CharacterBody`s, `RigidBody`s, and `PhysicsBody`s. Eventually, I plan to also implement handy mathematical functions such as pathfinding and raycasting.

# Documentation
I don't have a documentation page yet, but I plan on making one soon.
In the very least, here is a basic window setup program using DurkGame:
```c++
#include <DurkGame.hpp>

const dk::math::Vector2 WIN_SIZE = {800, 600};

int main() {
	dk::init();

	SDL_Window* window = DK_Display::setMode("DurkGame", WIN_SIZE);
	SDL_Renderer* renderer = DK_Display::setRenderer(window);
	dk::time::Clock clock;

	SDL_Event event;
	bool run = true;
	while (run) {
		float deltaTime = clock.tick(60) / 1000.0f;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					run = false;
					break;
			}
		}

		dk::display::cls(renderer);
		dk::display::fill(renderer, {40, 40, 40});
		dk::display::flip(renderer);
	}

	dk::quit(window, renderer);
    return 0;
}
```

# License
[MIT](LICENSE) @ Derrick Martinez

DurkGame is a non-profit, free, and open-source extended library for SDL2.
