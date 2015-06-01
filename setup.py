#!/usr/bin/env python3.4

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

import numpy

setup(
    cmdclass = {'build_ext': build_ext},
    ext_modules = [Extension("inpaint", sources=["inpaint.pyx", "oliviera.c"], include_dirs=[numpy.get_include()]), Extension("qa",sources=["qa.pyx", "psnr.c"], include_dirs=[numpy.get_include()])])
