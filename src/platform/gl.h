#ifndef PLATFORM_GL_H_
#define PLATFORM_GL_H_

 #if defined(__DREAMCAST__)
	#include "GL/gl.h"
	#include "GL/glu.h"
	#define glCheckError() 
	#define platform_GL_setup()
#else
	#include "../../../deps/glad/3_3/glad.h"
	#include <SDL3/SDL_opengl.h>
	
	GLenum glCheckError_(const char *file, int line)
	{
		GLenum errorCode;
		while ((errorCode = glGetError()) != GL_NO_ERROR)
		{
			
			switch (errorCode)
			{
				case GL_INVALID_ENUM:                  
					printf("ERROR \"INVALID_ENUM\":%d | %s | %d\n",  errorCode, file, line); break;
				case GL_INVALID_VALUE:                 
					printf("ERROR \"INVALID_VALUE\":%d | %s | %d\n", errorCode, file, line); break;
				case GL_INVALID_OPERATION:             
					printf("ERROR \"INVALID_OPERATION\":%d | %s | %d\n", errorCode, file, line); break;
				case GL_STACK_OVERFLOW:                
					printf("ERROR \"STACK_OVERFLOW\":%d | %s | %d\n", errorCode, file, line); break;
				case GL_STACK_UNDERFLOW:               
					printf("ERROR \"STACK_UNDERFLOW\":%d | %s | %d\n", errorCode, file, line); break;
				case GL_OUT_OF_MEMORY:                 
					printf("ERROR \"OUT_OF_MEMORY\":%d | %s | %d\n", errorCode, file, line); break;
				case GL_INVALID_FRAMEBUFFER_OPERATION: 
					printf("ERROR \"INVALID_FRAMEBUFFER_OPERATION\":%d | %s | %d\n", errorCode, file, line); break;
				default:
					printf("ERROR \"UNKNOWN\":%d | %s | %d\n", errorCode, file, line); break;
			}
			
		}
		return errorCode;
	}
	#define glCheckError() glCheckError_(__FILE__, __LINE__) 
	#define platform_GL_setup() GBL_STMT_START {int version = gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress); GBL_UNUSED(version); } GBL_STMT_END
	
#endif


#endif //PLATFORM_GL_H_