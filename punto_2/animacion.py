import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

data=np.loadtxt("cuerda.txt")
x=np.linspace(0.0,100,500)
fig,sub=plt.subplots()

cuerda,=sub.plot(x,data[:,0])
a=plt.gca()
a.set_ylim([-1.5,1.5])

def update(i):
	cuerda.set_ydata(data[:,i])
	return cuerda

anim = FuncAnimation(fig,update,frames=np.arange(1,len(data[1])),interval=5)
anim.save('cuerda.gif', dpi=80, writer='imagemagick')



