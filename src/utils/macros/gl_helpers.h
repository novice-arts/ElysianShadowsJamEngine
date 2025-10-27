
#define GL_DRAW(mode) for(int i = (glBegin(mode), 1); i != 0; i = (glEnd(), 0))
#define GL_FINISH continue
#define GL_HALT	  continue
#define GL_BREAK  continue



//PSEUDO APIs
#define glQuad(x, y, w, h, z) \
		glVertex3f(x,	  y + h,  z);\
		glVertex3f(x + w, y + h,  z);\
		glVertex3f(x + w, 	  y,  z);\
		glVertex3f(x, 		  y,  z)
