from __future__ import print_function

import numpy as np
import chelpers as ch
import time

M = np.random.random(size=(7000,7000))
u = np.random.random(size=(7000))
v = np.random.random(size=(7000))

print('Running time trials of a contraction operation.')
print('Each run will print out the time elapsed, and the result of the computation.')
print()
print('Do not be surprised if numpy is faster!  That code is optimized and might ')
print('be using multiple threads.')

trials = 100
t = time.time()
for i in range(trials):
    X = np.dot(u, np.dot(M, v))

print('  numpy dot-dot:  %8.3f s   %9e' % (time.time() - t, X))

t = time.time()
for i in range(trials):
    X =  ch.contract(u, M, v)

print('  chelpers:       %8.3f s   %9e' % (time.time() - t, X))


