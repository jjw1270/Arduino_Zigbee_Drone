# -*- coding: utf-8 -*-
"""
Created on Tue Aug  3 17:25:05 2021

@author: jjw12
"""

import matplotlib.pyplot as plt
import serial
import numpy as np
from itertools import product, combinations
from matplotlib.patches import FancyArrowPatch
from mpl_toolkits.mplot3d import proj3d

class Arrow3D(FancyArrowPatch):

    def __init__(self, xs, ys, zs, *args, **kwargs):
        FancyArrowPatch.__init__(self, (0, 0), (0, 0), *args, **kwargs)
        self._verts3d = xs, ys, zs

    def draw(self, renderer):
        xs3d, ys3d, zs3d = self._verts3d
        xs, ys, zs = proj3d.proj_transform(xs3d, ys3d, zs3d, renderer.M)
        self.set_positions((xs[0], ys[0]), (xs[1], ys[1]))
        FancyArrowPatch.draw(self, renderer)

fig = plt.figure()
ax = fig.gca(projection = '3d')
#ax.set_aspect("equal")

ax.scatter([0],[0],[0],color="black",s=5)
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
x = np.cos(u)*np.sin(v)
y = np.sin(u)*np.sin(v)
z = np.cos(v)
ax.plot_wireframe(x, y, z)

a = Arrow3D([0, 1], [0, 1], [0, 1], mutation_scale=20,
            lw=1, arrowstyle="-|>", color="k")
ax.add_artist(a)
plt.show()

line = []

ser = serial.Serial(
    port='COM21',
    baudrate=9600
)

while True:
    if ser.readable():
        res = ser.readline().decode()[:-1]
        a = [int(x) for x in res.split(',')]
        ax.quiver(0,0,0,a[0],a[1],a[2],arrow_length_ratio=0.1)
        
        
