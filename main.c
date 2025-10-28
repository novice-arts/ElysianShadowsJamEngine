
#include <SDL3/SDL.h>
#include <stdio.h>

#ifndef GIMBAL_ALREADY_INCLUDED
#define GIMBAL_ALREADY_INCLUDED
    #include <gimbal/gimbal_meta.h>
    #include <gimbal/gimbal_strings.h>
    #include <gimbal/gimbal_core.h>
#endif 
#include <src/platform.h>
#include <src/app.h>

// Main loop flag
int quit = 0;
SDL_Event e;
SDL_Window* window = NULL;
SDL_GLContext gl_context = {0};


static inline bool (app_setup)(void){
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Elysian Shadows", 640, 480, SDL_WINDOW_OPENGL);
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
	glShadeModel(GL_SMOOTH);
	
	project_setup();
	
	return true;
}

static inline void (app_update)(void){
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_EVENT_QUIT) {
            quit = 1;
        }
    }
	
	project_update();

	project_render();
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

