#!/usr/bin/env python3.4
import numpy as np
import cv2
import sys

import inpaint
import qa

if __name__ == '__main__':
    grayscale = cv2.imread('data/lena.jpg', 0)
    mask = cv2.imread('data/mask.png',0)

    inpainted = inpaint.oliviera(grayscale, mask)
    cv2.imwrite('result.png', inpainted)
    error = qa.psnr(grayscale, inpainted)
    print ('error = {0}'.format(error))
