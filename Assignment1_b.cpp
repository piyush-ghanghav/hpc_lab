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

vector<int> multiply_vector_and_matrix(const vector<int> &vec, const vector< vector<int>> &matrix, int num_threads){

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
    
    int n = 100;
    int num_threads = 8;

    vector<int> A = create_random_vector(n);
    vector<vector<int>> mat = create_random_matrix(n);

    double start_time = omp_get_wtime();
    vector<int> result = multiply_vector_and_matrix(A,mat,num_threads);
    double end_time = omp_get_wtime();

    double multiplication_time = end_time - start_time;
    cout <<"Time taken for vector and matrix multiplication using omp: "<< multiplication_time <<" seconds" <<endl;

    return 0;
}