#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int size, rank;
char * msg;
int main(int argc, char *argv[]){
   MPI_Comm cliente;
   MPI_Status status;
   char portname[MPI_MAX_PORT_NAME];
   msg = (char *) malloc(256);
   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   MPI_Open_port(MPI_INFO_NULL, portname);
   printf("%s\n", portname);
   MPI_Comm_accept(portname, MPI_INFO_NULL, 0, MPI_COMM_SELF, &cliente);
   printf("client connected\n");
   MPI_Recv(msg, 256, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG, cliente, &status);
   printf("server mpi rank = %d ,size = %d, source = %d, tag = %d\n",rank,size,status.MPI_SOURCE,status.MPI_TAG);
   printf("msg: %s\n", msg);
   MPI_Comm_free(&cliente);
   MPI_Close_port(portname);
   MPI_Finalize();
   free(msg);
}

