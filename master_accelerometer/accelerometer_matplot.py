# -*- coding: utf-8 -*-
"""
Created on Tue Aug  3 17:25:05 2021

@author: jjw12
"""

import matplotlib.pyplot as plt
import serial
import numpy as np

first_3d = plt.figure()
first_axes = plt.axes(projection='3d')

first_axes.set_xlabel('X axis')
first_axes.set_ylabel('Y axis')
first_axes.set_zlabel('Z axis')

x=0
y=0
z=0

first_axes.scatter3D(x,y,z)

plt.show()

ser = serial.Serial(port='COM5',baudrate=9600)

while True:
    if ser.readable():
        res = ser.readline().decode()[:-1]
        a = [int(x) for x in res.split(',')]
        print(a)