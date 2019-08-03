Install MPICH-3

wget http://www.mpich.org/static/downloads/3.2.1/mpich-3.2.1.tar.gz

tar xvf mpich-3.2.1.tar.gz

mkdir tools
cd tools
mkdir mpi

cd ../../mpich-3.2.1

./configure --prefix=$HOME/tools/mpi --exec_prefix=$HOME/tools/mpi --disable-fortran

make -j 8

make install

export PATH=$HOME/tools/mpi/bin:$PATH
