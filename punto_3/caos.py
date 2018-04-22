import numpy as np
import matplotlib.pyplot as plt

data=np.loadtxt("caos.txt")
q2=data[:,0]
p2=data[:,1]
plt.scatter(p2,q2,label="q2 vs. p2")
plt.xlabel("p2")
plt.ylabel("q2")
plt.title("q2 vs. p2")
plt.legend()
plt.savefig("caos.pdf")
