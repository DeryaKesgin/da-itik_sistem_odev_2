
#include <mpi.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 120
#define NUM_THREADS 4

int main(int argc, char** argv) {
    int rank, size;
    int data[ARRAY_SIZE];
    int local_sum = 0, global_sum = 0;
    int chunk_size;

    printf("🔥 Yeni versiyon çalışıyor!\n");
    fflush(stdout);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("\n🔵 [MPI] Rank 0 başlatıldı. Toplam işlemci sayısı: %d\n", size);
        printf("🔵 [MPI] Veri oluşturuluyor...\n");
        fflush(stdout);
        srand(42);
        for (int i = 0; i < ARRAY_SIZE; i++) {
            data[i] = rand() % 10;
        }
        printf("🔵 [MPI] Veri dağıtılacak (Scatter)...\n");
        fflush(stdout);
    }

    chunk_size = ARRAY_SIZE / size;
    int local_data[chunk_size];

    MPI_Scatter(data, chunk_size, MPI_INT, local_data, chunk_size, MPI_INT, 0, MPI_COMM_WORLD);
    printf("🟡 [MPI] Rank %d veriyi aldı. Chunk boyutu: %d\n", rank, chunk_size);
    fflush(stdout);

    printf("🟡 [OpenMP] Rank %d paralel işlem başlatıyor (%d thread)...\n", rank, NUM_THREADS);
    fflush(stdout);

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int thread_id = omp_get_thread_num();
        int local_thread_sum = 0;

        #pragma omp for
        for (int i = 0; i < chunk_size; i++) {
            local_thread_sum += local_data[i];
        }

        #pragma omp atomic
        local_sum += local_thread_sum;

        #pragma omp critical
        {
            printf("🧵 [OpenMP] Rank %d - Thread %d → Parçalı toplam: %d\n", rank, thread_id, local_thread_sum);
            fflush(stdout);
        }
    }

    printf("✅ [OpenMP] Rank %d tamamlandı. Local toplam: %d\n", rank, local_sum);
    fflush(stdout);

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\n🎯 [MPI] Tüm local toplamlar birleştirildi.\n");
        printf("🎉 [Sonuç] Global Toplam: %d\n", global_sum);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}
