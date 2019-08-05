#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int size, rank;
char * msg_string;
int main(int argc, char *argv[]){
   MPI_Comm servidor;
   int msg, tag, dest;
   char portname[MPI_MAX_PORT_NAME];
   char* msg_string;
   msg_string = (char *) malloc(256);
   strcpy(msg_string, "World!");
   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   printf("Trying connect to : \n");
   gets(portname);
   MPI_Comm_connect(portname, MPI_INFO_NULL, 0, MPI_COMM_WORLD, &servidor);
   msg = 42; tag = 0; dest = 0;
   MPI_Send(msg_string, 7, MPI_CHAR, dest, tag, servidor);
   printf("client mpi rank = %d, size = %d, dest = %d, tag = %d\n",rank, size, dest, tag);
   MPI_Comm_disconnect(&servidor);
   MPI_Finalize();
}


