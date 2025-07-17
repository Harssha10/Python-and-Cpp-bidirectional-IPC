# Python-and-Cpp-bidirectional-IPC via Shared memory

Bidirectional Interprocess communication between python and C++ processes via shared memory in linux based machine.

* Used mutex locks for synchronization.

* multihtreading for controlling input and reading data for each process.

## To run :
* First run cpp_shm.cpp which creates the shared memory:
```
g++ cpp_shm.cpp -o shm
./shm
```
* Then run py_shm.py
```
Python3 py_shm.py
```


## Version info:
Python: Python 3.12.3

C++   : g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0



[INFO:]  Still have to manage the warning by python resource tracker which throws warning for not dealing with the shared memory , since Cpp process created it.
