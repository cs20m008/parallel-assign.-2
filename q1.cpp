#include <iostream>
#include <cstdlib>
#include <mpi/mpi.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    int n;
    n = atoi(argv[1]);

    vector<int>a(n);
    for(int i=0;i<n;i++){
       a[i]=rand%100;
    }

    int process_no;int rankk;
    
    
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rankk);
    MPI_Comm_size(MPI_COMM_WORLD, &process_no);
    int sum1;
    int x=n/process_no;
    int start=(rankk)*x;
    int end=start+x;
    sum1=0;
    for(int i=start;i<end;i++)
    {
        sum1=sum1+a[i];
    }
    if (rank == 0)
    {
        int temp;
        for(int i=1;i<process_no;i++){
            MPI_Recv(&temp,1,MPI_INT,i,0,MPI_COMM_WORLD,&status);
            sum1=sum1+temp;
        }
        cout<<sum1<<endl;
    }
    else
    {
        MPI_Send(&sum1,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
