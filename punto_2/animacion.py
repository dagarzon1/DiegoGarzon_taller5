import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("cuerda.txt")
x=np.linspace(0.0,200,100)

for i in range(0,2):
	plt.scatter(x,data[:,i], label='%i'%i)
plt.legend()
plt.savefig("cuerda.pdf")

