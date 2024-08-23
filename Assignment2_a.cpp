// 2. Parallel sorting Algorithms- for Bubble Sort and Merger Sort, based on existing sequential algorithms, 
// design and implement parallel algorithm utilizing all resources available. 


// a) Bubble sort


#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#include<omp.h>

using namespace std;

vector<int> generate_random_array(int size){

    vector<int> vec(size);

    for(int i =0; i<size; i++){
        vec[i] = rand()%100;
    } 

    return vec;
}

vector<int> serial_bubble_sort(vector<int> Arr){

    for(int i = 0; i<Arr.size(); i++){
        
        for(int j = 0; j<Arr.size()-i-1; j++){

            if(Arr[j]>Arr[j+1]){
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
    return Arr;
}
vector<int> parallel_bubble_sort(vector<int> Arr){

    for(int i = 0; i<Arr.size(); i++){

        int first = i%2;
        
        #pragma omp parallel for shared(Arr,first)
        for(int j = first; j<Arr.size()-1; j+=2){

            if(Arr[j]>Arr[j+1]){
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
    return Arr;
}

void print(vector<int> Arr){

    for(int i=0; i< Arr.size(); i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n = 10000;
    srand(time(0));
    omp_set_num_threads(4);

    vector<int> Arr = generate_random_array(n);
    vector<int> Arr_copy = Arr;
    // cout<<"\nRandom Array:";
    // print(Arr);


    double start_time = omp_get_wtime();
    vector<int> serially_sorted_array = serial_bubble_sort(Arr);
    double end_time = omp_get_wtime();

    double serial_time = end_time - start_time;
    cout<<"\nSerial Bubble sort execution time: "<<serial_time;

    // cout<<"\nSerially Sorted Array:";
    // print(serially_sorted_array);


    start_time = omp_get_wtime();
    vector<int> parallel_sorted_array = parallel_bubble_sort(Arr_copy);
    end_time = omp_get_wtime();

    double parallel_time = end_time - start_time;
    cout<<"\nParallel Bubble sort execution time: "<<parallel_time<<endl;

    // cout<<"\nParallel Sorted Array:";
    // print(parallel_sorted_array);

    return 0;
}
