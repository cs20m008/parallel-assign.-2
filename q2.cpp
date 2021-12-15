#include <iostream>
#include <cstdlib>
#include <mpi/mpi.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
       a[i]=rand%100;
    }

    int process_no,int rankk;
    
    
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rankk);
    MPI_Comm_size(MPI_COMM_WORLD, &process_no);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
   if(rank+1==process_no)
   {
       MPI_Send(arr, n, MPI_INT,0, 0, MPI_COMM_WORLD);
   }
   else
   {
        MPI_Send(arr, n, MPI_INT,rankk+1, 0, MPI_COMM_WORLD);
   }
   if(rankk==0)
   {
       MPI_Recv(arr, n, MPI_INT,process_no-1, 0, MPI_COMM_WORLD, &status);
   }
   else
   {
       MPI_Recv(arr, n, MPI_INT,rankk-1, 0, MPI_COMM_WORLD, &status);
   }
   for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    MPI_Finalize();
    return 0;
}