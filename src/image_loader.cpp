#include "image_loader.h"
#include "acfutils/log.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/gl.h>



GLuint loadImage(const char *filename) {

  int width, height, nrChannels;
  unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
  if (!data) {
    logMsg("Failed to load image");
    return 0;
  }

  // Generate texture ID
  GLuint textureID;
  glGenTextures(1, &textureID);

  // Bind texture
  glBindTexture(GL_TEXTURE_2D, textureID);

  // Upload to GPU
  GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;
  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

  // Set texture parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Free image data
  stbi_image_free(data);

  return textureID;

}


