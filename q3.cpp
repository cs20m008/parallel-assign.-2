#include <iostream>
#include <cstdlib>
#include <mpi/mpi.h>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    int n;
 n = atoi(argv[1]);
    /*vector<int>a(n);
    for(int i=0;i<n;i++){
       a[i]=rand%100;
    }*/

    int process_no,int rankk;
    
    
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &pn
    int sum1;
    int x=n/process_no;
    int start=(rankk)*x;
    int end=start+x;
    vector<int>a(end-start);
    sum1=0;int j=0
    for(int i=start;i<end;i++)
    {   a[j]=i;
        sum1=sum1+a[j];
        j++;
    }
    if (rank == 0)
    {
        int sum=0,temp;
        for(int i=1;i<process_no-1;i++){
            MPI_Recv(&temp,1,MPI_INT,i,0,MPI_COMM_WORLD,&status);
            sum=sum+temp;
        }
        cout<<sum<<endl;
    }
    else
    {
        MPI_Send(&sum,1,MPI_INT,0,0,MPI_COMM_WORLD);
    }
    MPI_Finalize();
    return 0;
}
