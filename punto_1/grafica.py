import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

voltaje=np.loadtxt("voltaje.txt")
vecX=np.loadtxt("vecX.txt")
vecY=np.loadtxt("vecY.txt")
X=np.linspace(0.0,5.0*10**(-2),512)
Y=np.linspace(0.0,5.0*10**(-2),512)

plt.contour(X,Y,voltaje)
plt.streamplot(X,Y,vecX,vecY) 
plt.savefig("placas.pdf")
