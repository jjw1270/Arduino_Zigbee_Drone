import serial

ser = serial.Serial(port='COM5',baudrate=9600)

while True:
    if ser.readable():
        res = ser.readline().decode()[:-1]
        a = [int(x) for x in res.split(',')]
        print(a)