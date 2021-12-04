import matplotlib.pyplot as plt
import numpy as np
  
mb = [10,100,1000,10000,100000,1000000,10000000,100000000]
ff = [978, 999, 1001, 998, 1003, 995, 990, 1000]
bf = [992, 1352, 1995, 2008, 2008, 3983, 21948, 178730]
wf = [997, 1459, 1992, 2017, 2048, 4123, 19985,  179578]

plt.plot(mb, ff, label = "First Fit")
plt.plot(mb, bf, label = "Best Fit")
plt.plot(mb, wf, label = "Worst Fit")
plt.legend()
plt.show()