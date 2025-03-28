# da-itik_sistem_odev_2
# Dağıtık Hesaplama: MPI + OpenMP + Docker

## 🚀 Proje Açıklaması

Bu projede Docker kullanarak çok düğümlü bir dağıtık sistem kuruldu. MPI ile düğümler arası veri paylaşımı, OpenMP ile her düğüm içinde çok çekirdekli paralel işlem gerçekleştirilmiştir.

## 🔧 Kurulum

```bash
git clone https://github.com/kullanici_adi/mpi_docker_project.git
cd mpi_docker_project
docker compose build --no-cache
docker compose up
