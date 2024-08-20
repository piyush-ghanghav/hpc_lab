// Design parallel algorithm to  
// a) Add two large vectors  

#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<omp.h>


using namespace std;

// Funtion to create vectors with random values.

vector<int> generate_random_vector(int size){
    vector<int> vec(size);

    for(int i = 0; i<size;i++){
        vec[i] = rand()% 100;       // Random values between 0-100
    }
    return vec;
}

//Funtion to add vectors serially

vector<int> add_vectors_serial(vector<int> &A,vector<int> &B){
    int n = A.size();
    vector<int> C(n);

     for(int i =0; i<n;i++){
        C[i] = A[i] + B[i];
    }

    return C;

}

// Function to add vectors parallely using omp 

vector<int> add_vectors_parallel(vector<int> &A,vector<int> &B, int num_threads){
    int n = A.size();
    vector<int> C(n);

    #pragma omp parallel for num_threads(num_threads)
    
    for(int i =0; i<n;i++){
        C[i] = A[i] + B[i];
    }

    return C;
}

int main(){

    srand(time(0));
    int n = 100000000;
    int num_threads = 8;

    vector<int> A = generate_random_vector(n);
    vector<int> B = generate_random_vector(n);

    double start_time = omp_get_wtime();
    vector<int> C_serial = add_vectors_serial(A, B);
    double end_time = omp_get_wtime();

    double serial_time = end_time - start_time;
    cout <<"Time taken for serial addition: "<< serial_time <<" seconds" <<endl;
   

   
    start_time = omp_get_wtime();
    vector<int> C_parallel = add_vectors_parallel(A, B, num_threads);
    end_time = omp_get_wtime();

    double parallel_time = end_time - start_time;
    cout <<"Time taken for parallel addition: "<< parallel_time <<" seconds" <<endl;

    cout << "First 10 elements of vector C (Serial): ";
    for (int i = 0; i < 10; i++) {
        cout << C_serial[i] << " ";
    }
    cout <<endl;

    cout << "First 10 elements of vector C (Parallel): ";
    for (int i = 0; i < 10; i++) {
        cout << C_parallel[i] << " ";
    }
    cout <<endl;

    return 0;
}