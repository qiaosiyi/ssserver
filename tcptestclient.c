#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size, rank;
int main(int argc, char *argv[]){
   MPI_Comm servidor;
   int msg, tag, dest;
   char portname[MPI_MAX_PORT_NAME];

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   if (argc >= 2){
      printf("Trying connect to %s\n", argv[1]);
      strcpy(portname, argv[1]);
      MPI_Comm_connect(portname, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &servidor);
      msg = 42; tag = 0; dest = 0;
      MPI_Send(&msg, 1, MPI_INT, dest, tag, servidor);
      MPI_Comm_disconnect(&servidor);
   }
   MPI_Finalize();
}
