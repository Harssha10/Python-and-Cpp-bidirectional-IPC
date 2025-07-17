# Python-and-Cpp-bidirectional-IPC via Shared memory

Bidirectional Interprocess communication between python and C++ via shared memory.

* Used mutex locks for synchronization.

* multihtreading for controlling input and reading data for each process.

[INFO:]  Still have to manage the warning by python resource tracker which throws warning for not dealing with the shared memory , since Cpp process created it.
