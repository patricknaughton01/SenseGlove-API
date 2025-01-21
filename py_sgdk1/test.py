import time
import build.py_sgdk1 as py_sgdk1

glove = py_sgdk1.SGGloveWrapper(True)
for _ in range(10):
    print(glove.getConfig())
    time.sleep(0.01)
