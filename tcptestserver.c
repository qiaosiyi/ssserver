#include<mpi.h>
#include<stdio.h>
#include<stdlib.h>

int size, rank, msg;

int main(int argc, char *argv[]){
   MPI_Comm cliente;
   MPI_Status status;
   char portname[MPI_MAX_PORT_NAME];

   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);

   MPI_Open_port(MPI_INFO_NULL, portname);
   printf("portname: %s\n", portname);
   MPI_Comm_accept(portname, MPI_INFO_NULL, 0, MPI_COMM_SELF, &cliente);
   printf("client connected\n");
   MPI_Recv(&msg, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, cliente, &status);
   printf("msg: %d\n", msg);
   MPI_Comm_free(&cliente);
   MPI_Close_port(portname);
   MPI_Finalize();
}
                          
#include "mpi.h"
int main( int argc, char **argv )
{
   MPI_Comm client;
   MPI_Status status;
   char port_name[MPI_MAX_PORT_NAME];
   double buf[MAX_DATA];
   int size, again;
   MPI_Init( &argc, &argv );
   MPI_Comm_size(MPI_COMM_WORLD, &size);
   if (size != 1) error(FATAL, "Server too big");
   MPI_Open_port(MPI_INFO_NULL, port_name);
   printf("server available at %s\n",port_name);
   while (1) {
      MPI_Comm_accept( port_name, MPI_INFO_NULL, 0, MPI_COMM_WORLD,
      &client );
      again = 1;
      while (again) {
         MPI_Recv( buf, MAX_DATA, MPI_DOUBLE,
         MPI_ANY_SOURCE, MPI_ANY_TAG, client, &status );
         switch (status.MPI_TAG) {
            case 0: MPI_Comm_free( &client );
            MPI_Close_port(port_name);
            MPI_Finalize();
            return 0;
            case 1: MPI_Comm_disconnect( &client );
            again = 0;
            break;
            case 2: /* do something */
            ...
            default:
            /* Unexpected message type */
            MPI_Abort( MPI_COMM_WORLD, 1 );
         }
      }
   }
}
