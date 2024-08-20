// 1. Vector and Matrix Operations- Design parallel algorithm to 
//     c. Multiply two N × N arrays using n2 processors. 


#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<omp.h>


using namespace std;


// Function to create a random nXn matrix

vector<vector<int>> create_random_matrix(int size){
    
    vector<vector<int>> matrix(size,vector<int>(size));

    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++){
            matrix[i][j]  = rand()%100;
        }
    }
    return matrix;
}

// Function to multiply two matrices parallely using OpenMP

vector<vector<int>> multiply_matrices_parallel(vector<vector<int>> &A, vector<vector<int>> &B, int num_threads){
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));

    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int sum = 0;
            for(int k = 0; k < N; k++){
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    return C;
}

int main(){
    srand(time(0));
    int N = 1000;  // Size of the matrix
    int num_threads = 4;  // Number of threads

    vector<vector<int>> A = create_random_matrix(N);
    vector<vector<int>> B = create_random_matrix(N);

    double start_time = omp_get_wtime();
    vector<vector<int>> C = multiply_matrices_parallel(A, B, num_threads);
    double end_time = omp_get_wtime();

    double parallel_time = end_time - start_time;
    cout << "Time taken for parallel matrix multiplication: " << parallel_time << " seconds" << endl;

    return 0;
}