#include <thrust/host_vector.h>
#include <thrust/device_vector.h>
#include <thrust/sort.h>

#include <iostream>

int main(){
    // H has storage for 4 integers
    thrust::host_vector<int> H(1000);

    for(int c = 0; c < 1000; c++){
      H[c] = 1000-c;
    }

    for(int c = 0; c < 10; c++){
      std::cout << H[c] << "\n";
    }

    // Copy host_vector H to device_vector D
    //thrust::device_vector<int> D = H;

    thrust::sort(H.begin(),H.end());
    //thrust::sort(D.begin(),D.end());

    //H = D;

    for(int c = 0; c < 10; c++){
      std::cout << H[c] << "\n";
    }
    
    return 0;
}