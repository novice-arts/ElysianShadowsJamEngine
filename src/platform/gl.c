#include "gl.h"
#include <stdio.h>
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