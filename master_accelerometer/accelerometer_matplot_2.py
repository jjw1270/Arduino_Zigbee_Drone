# -*- coding: utf-8 -*-
"""
Created on Sun Aug  8 15:47:14 2021

@author: jjw12
"""

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

first_3d = plt.figure()
first_axes = plt.axes(projection='3d')

first_axes.set_xlabel('X axis')
first_axes.set_ylabel('Y axis')
first_axes.set_zlabel('Z axis')

point = np.linspace(0,15,100)

x = np.sin(point)
y = np.cos(point)
z = x*y

first_axes.plot3D(x,y,z)

plt.show()