# HPC Lab Assignments

This repository contains the assignments for the High-Performance Computing (HPC) Lab. The assignments focus on designing and implementing parallel algorithms to solve various computational problems using multiple processors.

## Syllabus

The lab assignments cover the following topics:

1. **Vector and Matrix Operations**: 
   - **Addition of Two Large Vectors**: Design and implement a parallel algorithm to efficiently add two large vectors.
   - **Vector and Matrix Multiplication**: Develop a parallel algorithm for multiplying a vector with a matrix.
   - **Matrix Multiplication (N x N arrays)**: Create a parallel algorithm for multiplying two N x N arrays using N² processors.

2. **Parallel Sorting Algorithms**:
   - **Bubble Sort**: Based on the existing sequential algorithm, design and implement a parallel version of Bubble Sort that utilizes all available resources.
   - **Merge Sort**: Adapt the existing sequential Merge Sort algorithm to a parallel version, optimizing resource utilization.

## Tech Stack

- **Programming Languages**: C++
- **Parallel Computing Libraries**: OpenMP
- **Development Environment**: Visual Studio Code (VSCode), HPC cluster

## Installation

To run these assignments locally, ensure you have the following set up:

1. **C++ Compiler**: Install a compatible C++ compiler (e.g., GCC or MSVC).
2. **OpenMP**: Ensure OpenMP is installed and properly configured.
3. **VSCode**: Use Visual Studio Code with the necessary extensions for C++ development.
4. **HPC Access**: Access to an HPC cluster with multiple processors (if required).

## Running Tests

To test the parallel algorithms:

1. **Compile the code** using a C++ compiler with OpenMP support.
2. **Run the executable** on an HPC cluster or a system with multiple cores.
3. **Validate the output** by comparing it with the results of sequential algorithms for correctness.

Example commands:
```bash
g++ -fopenmp Assignment1_a.cpp -o Assignment1_a
./Assignment1_a
```
## Usage/Examples

To run the vector addition assignment:

1. Clone the repository.
2. Navigate to the directory containing the assignment.
3. Compile the code using a C++ compiler with OpenMP support.
4. Run the compiled executable.

```bash
git clone https://github.com/piyush-ghanghav/hpc_lab.git
cd hpc_lab/
g++ -fopenmp Assignment1_a.cpp -o Assignment1_a
./Assignment1_a
```


## Acknowledgements

Special thanks to the course instructor B. J. Dange Sir for their guidance and support throughout the HPC lab sessions.


## Feedback

If you have any feedback, please reach out at [piyushghanghav@gmail.com].
