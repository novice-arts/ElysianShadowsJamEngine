#include <SDL3/SDL.h>
#include <stdio.h>

#include <src/platform.h>
#include <src/engine.h>

#include "project.h"

Rect2D* my_rect;
app_asset_embed_text(test_text, ASSET_PATH(test.txt));

void print_test(){
    printf(app_asset_data(test_text));
    printf("Hello from test!\n");
}

void project_setup(){
    print_test();
	my_rect = Rect2D_create("x", -0.85f, "y", 0.25f, "w", .5f, "h", .5f);
}

void project_update(){}

void project_render(){
    glClearColor(0.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RECT2D_GET_CLASS(my_rect)->pFnDraw(my_rect);

    SDL_GL_SwapWindow(SDL_GL_GetCurrentWindow());
}