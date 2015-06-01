import cython
import numpy as np
cimport numpy as np

cdef extern double c_psnr(unsigned char* orig, unsigned char* distorted, int m, int n)

@cython.boundscheck(False)
@cython.wraparound(False)
def psnr(np.ndarray[unsigned char, ndim=2, mode="c"] orig not None, np.ndarray[unsigned char, ndim=2, mode="c"] distorted):
    cdef int m, n
    cdef double result

    m, n = orig.shape[0], orig.shape[1]
    result = c_psnr(&orig[0,0], &distorted[0,0], m, n)
    return result
