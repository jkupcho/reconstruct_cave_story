#include "game.h"
#include "SDL/SDL.h"
#include <iostream>

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	screen_ = SDL_SetVideoMode(640, 480, 32, SDL_FULLSCREEN);
	eventLoop();
}

Game::~Game() {
	SDL_FreeSurface(screen_);
	SDL_Quit();
}

void Game::eventLoop() {
	// while (running) ~ 60 Hz
	//	Handle input.

	// update() Move the player. Move projectiles. Check collisions.
	// draw()

	SDL_Event event;
	bool running = true;
	while(running) {
		const int start_time_ms = SDL_GetTicks();
		while(SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE) {
						running = false;
					}
					break;
				default:
					break;
			}
		}
		update();
		draw();
		// This loop lasts 1/60th of a second
		//				   1000/60ths ms
		// Offset delay by how long this loop took to run as to not wait too long (subtract start time in milliseconds).
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 /* ms* */ / 60 /*fps*/ - elapsed_time_ms /*ms*/ );
	}
}

void Game::update() {

}

void Game::draw() {

}