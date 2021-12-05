import numpy as np
from random import randrange
import matplotlib.pyplot as plt


lisZ=[]
dictZ={}
for i in range(1000):
  X1=randrange(5)
  X2=randrange(5)
  lisZ.append(X1+X2)
  if (X1+X2) not in dictZ.keys():
    dictZ[X1+X2]=1
  else :
    dictZ[X1+X2]+=1

bins=list(dictZ.keys())
count=list(dictZ.values())

plt.bar(bins,count)
plt.show()