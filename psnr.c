#include <math.h>

double c_psnr(unsigned char* orig, unsigned char* distorted, int height, int width)
{
    double mse = 0.0;
    int i;
    for(i=0; i < height*width; i++)
    {
        double diff = orig[i] - distorted[i];
        mse += (diff * diff) / (height*width);
    }
    return 10.0 * log10((255.0*255.0)/mse);
}
