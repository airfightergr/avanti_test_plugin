#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#if IBM
#include <windows.h>
#endif
#if LIN
#include <GL/gl.h>
#endif
#if __GNUC__ && APL
#include <OpenGL/gl.h>
#endif
#if __GNUC__ && IBM
#include <GL/gl.h>
#endif


GLuint loadImage(const char *filename);



#endif // IMAGE_LOADER_H
