// 2. Parallel sorting Algorithms- for Bubble Sort and Merger Sort, based on existing sequential algorithms, 
// design and implement parallel algorithm utilizing all resources available. 


// b) Merge sort

#include<iostream>
#include<algorithm>
#include<ctime>
#include<vector>
#include<omp.h>

using namespace std;

vector<int> generate_random_vector(int size){
    vector<int> v(size);
    for(int i =0; i<size; i++){
        v[i] = rand()%100;
    }
    return v;
}

void merge(vector<int> &Arr, int left, int mid, int right){

    int n1 = mid - left + 1;    // size
    int n2 = right - mid ;      //+1-1 =0

    vector<int> L(n1), R(n2);

    for(int i = 0; i<n1; i++){
        L[i] = Arr[left + i];
    }
    for(int j =0; j<n2; j++){
        R[j] = Arr[mid + j  + 1];
    }
    int i = 0, j= 0 , k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            Arr[k] = L[i];
            i++;
        }
        else {
            Arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        Arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        Arr[k] = R[j];
        j++;
        k++;
    }


}

void serial_merge_sort(vector<int> &Arr,int left, int right){
   
   if(left>= right) return;

    int  mid = left + (right - left)/2;
    serial_merge_sort(Arr,left, mid);
    serial_merge_sort(Arr,mid+1, right);
    merge(Arr,left, mid, right);
}

void parallel_merge_sort(vector<int> &Arr,int left, int right){
   
   if(left>= right) return;

    int  mid = left + (right - left)/2;

    #pragma omp parallel sections
    {
    
        #pragma omp section
        {
            parallel_merge_sort(Arr,left, mid);
        }
        #pragma omp section
        {
            parallel_merge_sort(Arr,mid+1, right);
        }
    
    }
    merge(Arr,left, mid, right);
}

// void printVector(vector<int>& arr)
// {
//     for (int i = 0; i < arr.size(); i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

int main(){


    srand(time(0));
    omp_set_num_threads(4);
    

    int N = 100000;
    // cin>> N;

    vector<int> Arr = generate_random_vector(N);
    vector<int> p_Arr = Arr;


    // cout << "Random vector is \n";
    // printVector(Arr);


    double start_time = omp_get_wtime();
    serial_merge_sort(Arr, 0, N - 1);
    double end_time = omp_get_wtime();

    double serial_time = end_time- start_time;
    cout <<"\n Serial Execution time : " <<serial_time;

    // cout << "\nSorted vector is \n";
    // printVector(Arr);
   
    start_time = omp_get_wtime();
    parallel_merge_sort(p_Arr, 0, N - 1);
    end_time = omp_get_wtime();

    double parallel_time = end_time- start_time;
    cout <<"\n Parallel Execution time : " <<parallel_time<<endl;

    // cout << "\nSorted vector is \n";
    // printVector(Arr);
    return 0 ;
}