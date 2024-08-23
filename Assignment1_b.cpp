// 1. Vector and Matrix Operations- Design parallel algorithm to  
//     b. Multiply Vector and Matrix  

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<omp.h>

using namespace std;

// Function to create a random vector
vector<int> create_random_vector(int size){

    vector<int> vec(size);

    for(int i = 0; i<size; i++){
        vec[i] = rand()%100;
    }
    return vec;
}

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


// Function to multiply the vector with matrix 

vector<int> multiply_vector_and_matrix_serial(const vector<int> &vec, const vector< vector<int>> &matrix, int num_threads){

    int n = vec.size();
    vector<int> result(n); 

    for(int i = 0; i<n; i++){
        result[i] = 0;
        for(int j = 0; j<n;j++){
            result[i] += vec[j] * matrix[i][j];
        }
    }
    return result;
}
vector<int> multiply_vector_and_matrix_parallel(const vector<int> &vec, const vector< vector<int>> &matrix, int num_threads){

    int n = vec.size();
    vector<int> result(n); 

    #pragma omp parallel for num_threads(num_threads)
    for(int i = 0; i<n; i++){
        result[i] = 0;
        for(int j = 0; j<n;j++){
            result[i] += vec[j] * matrix[i][j];
        }
    }
    return result;
}
int main(){
    
    int n = 1000;
    int num_threads = 8;

    vector<int> A = create_random_vector(n);
    vector<vector<int>> mat = create_random_matrix(n);

    double start_time = omp_get_wtime();
    vector<int> serial_result = multiply_vector_and_matrix_serial(A,mat,num_threads);
    double end_time = omp_get_wtime();

    double serial_time = end_time - start_time;
    cout <<"Time taken for vector and matrix multiplication serially: "<< serial_time <<" seconds" <<endl;
    
    
    start_time = omp_get_wtime();
    vector<int> parallel_result = multiply_vector_and_matrix_serial(A,mat,num_threads);
    end_time = omp_get_wtime();

    double parallel_time = end_time - start_time;
    cout <<"Time taken for vector and matrix multiplication using omp (parallel): "<< parallel_time <<" seconds" <<endl;

    return 0;
}