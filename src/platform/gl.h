#ifndef PLATFORM_GL_H_
#define PLATFORM_GL_H_

 #if defined(__DREAMCAST__)
	#include "GL/gl.h"
	#include "GL/glu.h"
	#define glCheckError() 
	#define platform_GL_setup()
#else
	#include <deps/glad/3_3/glad.h>
	#include <SDL3/SDL_opengl.h>
	
	extern GLenum glCheckError_(const char *file, int line);
	#define glCheckError() glCheckError_(__FILE__, __LINE__) 
	#define platform_GL_setup() GBL_STMT_START {int version = gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress); GBL_UNUSED(version); } GBL_STMT_END
	
#endif


#endif //PLATFORM_GL_H_