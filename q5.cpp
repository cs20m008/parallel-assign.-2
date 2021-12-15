#include <mpi.h>
#include <stdio.h>

const int n=100;

int main(int argc, char *argv[]) {
  int i;
  int rankk;
  int process_no;
  double product;
 
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &process_no);
  MPI_Comm_rank(MPI_COMM_WORLD, &rankk);
  
  int x = n / process_no;  
  double y[x];
  double z[x];
  for(i = 0; i < x; i++) {
    y[i] = 0.02 * (i + rankk * x);
    z[i] = 0.01 * (i + rankk * x);
  }
  double local_prod;
  for (int i = 0; i < x; i++) {
    local_prod += y[i]*z[i];
  }
  MPI_Reduce(&local_prod, &prod, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  if (rankk == 0) {
    printf("dotProduct = %f\n", product);
  }  
  MPI_Finalize();

  return 0;
}
