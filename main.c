
#include <SDL3/SDL.h>
#include <stdio.h>

#include "src/platform.h"
#include "src/app.h"
#include "src/engine.h"

#define INCBIN_STYLE INCBIN_STYLE_SNAKE
#define INCBIN_PREFIX app_data_

#define ASSETS_ROOT_PATH "./"
#define ASSET_PATH(file) ASSETS_ROOT_PATH file 

#define app_asset_embed_text(name, path) INCTXT(name, path)
#define app_asset_embed(name, path) INCBIN(name, path)
#define app_asset_data(name) GBL_GLUE(app_data_, GBL_GLUE(name, _data))
#define app_asset_end_ptr(name) GBL_GLUE(app_data_, GBL_GLUE(name, end))
#define app_asset_size(name) GBL_GLUE(app_data_, GBL_GLUE(name, size))

#include "deps/incbin.h"

// Main loop flag
int quit = 0;
Rect2D* my_rect;
SDL_Event e;
SDL_Window* window = NULL;
SDL_GLContext gl_context = {0};

app_asset_embed_text(test_text, ASSET_PATH("test.txt"));

static inline bool (app_setup)(void){
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("SDL3 Window Example", 640, 480, SDL_WINDOW_OPENGL);
    if (window == NULL) {
        fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }
	SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetSwapInterval(1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	gl_context = SDL_GL_CreateContext(window);
	
	platform_GL_setup();
	
	SDL_GL_MakeCurrent(window, gl_context);
	
	//init gl
	glViewport(0, 0, 640, 480);
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

	printf(app_asset_data(test_text));

	my_rect = Rect2D_create("x", -0.85f, "y", 0.25f, "w", .5f, "h", .5f);
	//Input_pressed();
	return true;
}

static inline void (app_update)(void){
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) {
            quit = 1;
        }
    }
	
	glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RECT2D_GET_CLASS(my_rect)->pFnDraw(my_rect);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}

static inline void (app_teardown)(void){
	SDL_GL_DestroyContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char* argv[]){    
	if(!app_setup())
		return 1;
	
	while(!quit){
		app_update();
	}
	
	app_teardown();

	return 0;
}

