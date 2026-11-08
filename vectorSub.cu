#include <cstdio>


__global__ void vectorSub(int* a, int* b, int* c, int n) {
  int i = blockIdx.x * blockDim.x + threadIdx.x;
  if (i < n) {
    c[i] = a[i] - b[i];
  }
}

int main() {
  int n = 5;
  int size = n * sizeof(int);

  // host cpu data
  int h_a[5] = {50, 40, 30, 20, 10};
  int h_b[5] = {5, 4, 3, 2, 1};
  int h_c[5];

  //pointer to the gpu address
  int *d_a, *d_b, *d_c;
  cudaMalloc(&d_a, size);
  cudaMalloc(&d_b, size);
  cudaMalloc(&d_c, size);

  //copy to gpu
  cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);

  // launch
  int threadsPerBlock = 256;
  int numBlocks = (n + threadsPerBlock - 1) / threadsPerBlock;
  vectorSub<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c, n);
  printf("Launch status: %s\n", cudaGetErrorString(cudaGetLastError()));

  cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);

  for (int i = 0; i < n; i++) printf("%d - %d = %d\n", h_a[i], h_b[i], h_c[i]);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}
