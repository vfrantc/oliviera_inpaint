import cython
import numpy as np
cimport numpy as np

cdef extern void c_oliviera(unsigned char* img, unsigned char* mask, unsigned char* dst, int height, int width)

@cython.boundscheck(False)
@cython.wraparound(False)
def oliviera(np.ndarray[unsigned char, ndim=2, mode="c"] input not None, np.ndarray[unsigned char, ndim=2, mode="c"] mask not None):
    cdef int m, n
    cdef np.ndarray[unsigned char, ndim=2, mode="c"] out = input.copy()
    m, n = input.shape[0], input.shape[1]
    c_oliviera(&input[0,0], &mask[0,0], &out[0,0], m, n)
    return out
