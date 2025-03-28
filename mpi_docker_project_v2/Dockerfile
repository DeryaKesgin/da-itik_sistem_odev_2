
FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    openmpi-bin \
    openmpi-common \
    libopenmpi-dev

WORKDIR /mpi_project
COPY ./mpi_project /mpi_project
RUN mpicc -fopenmp mpi_sum.c -o mpi_sum && chmod +x mpi_sum

CMD ["mpirun", "--allow-run-as-root", "-np", "3", "./mpi_sum"]
