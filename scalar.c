#include <stdio.h>
#include <omp.h>

/*! Calculating the dot (scalar) product of 2 vectors */
int dot(int v[], int w[], int size) {
    int sum = 0;

    #pragma omp parallel for reduction(+:sum)
    for (int i=0;i<size;i++){
        sum += v[i]*w[i];
    } 

    return sum;
}

int main(int argc, char** argv) {

    // Example arrays
    int v[] = {1,1,1,1,1};
    int w[] = {1,1,1,1,1};
    int size = 5;

    // Calculate and Output scalar product
    int scalar_product = dot(v,w,size);
    printf("Scalar product: %d\n",scalar_product);

    return 0;
}