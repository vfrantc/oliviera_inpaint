#include <stdlib.h>
#include <string.h>

void c_oliviera(unsigned char *src, unsigned char* mask, unsigned char* dst, int height, int width)
{
  int i, j;
  int index, iter;

  float kernel[3][3] = {{0.073235, 0.176765, 0.073235},
                         {0.176765, 0.000000, 0.176765},
                         {0.073235, 0.176765, 0.073235}};

  float* temp = (float*) malloc(sizeof(float) * height * width);
  memset(temp,  0, (sizeof(float) * height * width));

  // How to compute number of iterations???
  for(iter=0; iter < 200; iter++)
  {
    // Copy known data
    for(index=0; index < height*width; index++)
    {
      if (mask[index] != 255)
      {
        temp[index] = src[index];
      }
    }

    // Convolution with restoration kernel
    for (i = 1; i < (height - 1); i++)
    {
      for (j = 1; j < (width - 1); j++)
      {
        if (mask[i*width + j] == 255)
        {
          temp[i*width + j] = kernel[0][0]*temp[(i-1)*width + (j-1)] + kernel[0][1]*temp[(i-1)*width + (j)] + kernel[0][2]*temp[(i-1)*width + (j+1)] \
                            + kernel[1][0]*temp[( i )*width + (j-1)] + kernel[1][1]*temp[( i )*width + (j)] + kernel[1][2]*temp[( i )*width + (j+1)] \
                            + kernel[2][0]*temp[(i+1)*width + (j-1)] + kernel[2][1]*temp[(i+1)*width + (j)] + kernel[2][2]*temp[(i+1)*width + (j+1)];
        }
        index++;
      }
    }
  }

  memcpy(dst, src, sizeof(unsigned char) * height * width);
  for(index=0; index < height*width; index++)
  {
    if (mask[index] == 255)
    {
      dst[index] = temp[index];
    }
  }
  free(temp);

  return ;
}
