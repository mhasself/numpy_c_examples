import numpy as np
import chelpers as ch

M = np.random.random(size=(7000,7000))
u = np.random.random(size=(7000))
v = np.random.random(size=(7000))

import time
trials = 100
t = time.time()
for i in xrange(trials):
    X = np.dot(u, np.dot(M, v))

print 'dot-dot: ', time.time() - t, X

t = time.time()
for i in xrange(trials):
    X =  ch.contract(u, M, v)

print 'chelpers: ', time.time() - t, X


