Install mpi:

wget https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.1.tar.bz2

tar jxvf openmpi-4.0.1.tar.bz2

cd openmpi/

./configure --prefix=/home/siyiq/tools/mpi --exec-prefix=/home/siyiq/tools/mpi |& tee config.out

make -j 48 |& tee make.out

make install |& tee make.out

export $PATH=/home/siyiq/tools/mpi:$PATH

vim makefile : MPICC?=/home/siyiq/tools/mpi/bin/mpicc

make

./mpi_hello_world

tag#0$description#master$port#36943$ifname#192.168.187.160$











