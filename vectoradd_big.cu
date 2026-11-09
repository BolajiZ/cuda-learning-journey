#include <cstdio>

__global__ void addVectors(int* a, int* b, int* c, int n) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  if (i < n){
    c[i] = a[i] + b[i];
  }
}

int main() {
  int n = 1000000;
  int size = n * sizeof(int);

  // allocate the 3 arrays on a cpu heap
  int* h_a = new int[n];
  int* h_b = new int[n];
  int* h_c = new int[n];

  // filling the cpu with values
  for(int i = 0; i < n; i++) {
    h_a[i] = i;
    h_b[i] = i * 2;
  }

  // allocate memoery to gpu and add pointers

  int *d_a, *d_b, *d_c;
  cudaMalloc(&d_a, size);
  cudaMalloc(&d_b, size);
  cudaMalloc(&d_c, size);

  // copy the inputs to the gpu
  cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);


  //launch config
  int threadsPerBlock = 256;
  int numBlocks = (n + threadsPerBlock - 1) / threadsPerBlock;

  // timing setup
  cudaEvent_t start, stop;
  cudaEventCreate(&start);
  cudaEventCreate(&stop);

  // record start, launch kernel, record stop

  cudaEventRecord(start);
  addVectors<<<numBlocks,threadsPerBlock>>>(d_a, d_b, d_c, n);


  cudaEventRecord(stop);
  cudaEventSynchronize(stop);

  float ms = 0;
  cudaEventElapsedTime(&ms, start, stop);

  cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);

  // spot check
  printf("c[0] = %d\n", h_c[0]);
  printf("c[500000] = %d\n", h_c[500000]);
  printf("c[999999] = %d\n", h_c[999999]);
  printf("Kernel time: %f ms\n", ms);

  cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
  delete[] h_a; delete[] h_b; delete[] h_c;
  return 0;

}
