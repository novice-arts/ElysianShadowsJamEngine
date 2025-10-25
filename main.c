#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include <SDL3/SDL.h>
#include <stdio.h>

#include "src/engine.h"

// Main loop flag
int quit = 0;
Rect2D* my_rect;
SDL_Event e;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

#ifdef __EMSCRIPTEN__
#define mainloop() emscripten_set_main_loop(mainloop, 0, 1);
static void (mainloop)(void){
	if(!quit){
		// Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_EVENT_QUIT) {
                quit = 1;
            }
        }

        // Clear screen
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF); // green
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red
		//SDL_RenderFillRect(renderer, &(SDL_FRect){0.0f, 0.0f, 200.0f, 200.0f});
		RECT2D_GET_CLASS(my_rect)->pFnDraw(my_rect, renderer);

        // Update screen
        SDL_RenderPresent(renderer);
	} else{
		emscripten_cancel_main_loop();
		// Destroy renderer
		SDL_DestroyRenderer(renderer);

		// Destroy window
		SDL_DestroyWindow(window);

		// Quit SDL subsystems
		SDL_Quit();
	}
	
}
#else 
static void (mainloop)(void){
	// Main loop
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_EVENT_QUIT) {
                quit = 1;
            }
        }

        // Clear screen
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF); // green
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Red
		//SDL_RenderFillRect(renderer, &(SDL_FRect){0.0f, 0.0f, 200.0f, 200.0f});
		RECT2D_GET_CLASS(my_rect)->pFnDraw(my_rect, renderer);

        // Update screen
        SDL_RenderPresent(renderer);
    }
	// Destroy renderer
    SDL_DestroyRenderer(renderer);

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();
}
#endif

int main(int argc, char* argv[]){

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("SDL3 Window Example", 800, 600, SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    
	my_rect = Rect2D_create("x", 50.0f, "y", 50.0f, "w", 150.0f, "h", 150.0f);
    
	mainloop();

	return 0;
}

