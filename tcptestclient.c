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


#include "mpi.h"
int main( int argc, char **argv )
{
   MPI_Comm server;
   double buf[MAX_DATA];
   char port_name[MPI_MAX_PORT_NAME];
   MPI_Init( &argc, &argv );
   strcpy(port_name, argv[1] );/* assume server’s name is cmd-line arg */
   MPI_Comm_connect( port_name, MPI_INFO_NULL, 0, MPI_COMM_WORLD,
   &server );
   while (!done) {
      tag = 2; /* Action to perform */
      MPI_Send( buf, n, MPI_DOUBLE, 0, tag, server );
      /* etc */
   }
   MPI_Send( buf, 0, MPI_DOUBLE, 0, 1, server );
   MPI_Comm_disconnect( &server );
   MPI_Finalize();
   return 0;
}


