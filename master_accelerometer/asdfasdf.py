import matplotlib.pyplot as plt

i = 0
retFile = open("./result.txt", "w")
data = [ i for i in range(30,1,-1) ]
while(i<30):
    x = data[i]
    plt.plot(i,x,'o')
    i+=1
    retFile.write('i:{}, data:{}\n'.format(str(i),str(data[i])))
    plt.pause(0.1)
plt.show()
retFile.close()

print("finish")
