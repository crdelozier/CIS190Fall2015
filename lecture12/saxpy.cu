#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/transform.h>
#include <thrust/functional.h>

#include <iostream>

struct saxpy_functor
{
    const float a;

    saxpy_functor(float _a) : a(_a) {}

    __host__ __device__
        float operator()(const float& x, const float& y) const { 
            return a * x + y;
        }
};
void saxpy_host(float A, thrust::host_vector<float>& X, thrust::host_vector<float>& Y)
{
    thrust::transform(X.begin(), X.end(), Y.begin(), Y.begin(), saxpy_functor(A));
}

void saxpy(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y, 
     thrust::device_vector<float>& Z)
{
    thrust::transform(X.begin(), X.end(), Y.begin(), Z.begin(), saxpy_functor(A));
}


void saxpy_slow(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y)
{
    thrust::device_vector<float> temp(X.size());
   
    // temp <- A
    thrust::fill(temp.begin(), temp.end(), A);
    
    // temp <- A * X
    thrust::transform(X.begin(), X.end(), temp.begin(), temp.begin(), thrust::multiplies<float>());

    // Y <- A * X + Y
    thrust::transform(temp.begin(), temp.end(), Y.begin(), Y.begin(), thrust::plus<float>());
}

int main(){
    thrust::host_vector<float> X_H(100);
    thrust::host_vector<float> Y_H(100);
    thrust::host_vector<float> Z_H(100);    

    thrust::device_vector<float> X_D(100);
    thrust::device_vector<float> Y_D(100);
    thrust::device_vector<float> Z_D(100);

    for(int c = 0; c < 100; c++){
    	    X_H[c] = (float)c;
	    Y_H[c] = (float)(100-c);
    }

    X_D = X_H;
    Y_D = Y_H;

    try {
        saxpy_slow(5.0,X_D,Y_D);
    }catch(thrust::system_error &e){
        std::cerr << "Error accessing vector element: " << e.what() << std::endl;
        exit(-1);
    }

    Z_H = Z_D;
    Y_H = Y_D;

    for(int c = 0; c < 10; c++){
    	    std::cout << Y_H[c] << "\n";
    }

    return 0;
}