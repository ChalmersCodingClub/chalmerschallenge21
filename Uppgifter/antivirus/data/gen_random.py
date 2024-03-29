#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

min_b = int(cmdlinearg('min_b', -1000000000))
max_b = int(cmdlinearg('max_b',  1000000000))

n = int(cmdlinearg('n'))
print(n)

a = [random.randint(2, n)]
for i in range(1, n): a.append(random.randint(1, i))
print(' '.join(map(str, a)))

b = [random.randint(min_b, max_b) for i in range(n)]
print(' '.join(map(str, b)))
