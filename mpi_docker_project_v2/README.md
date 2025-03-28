
# MPI + OpenMP Dağıtık Sistem Projesi

Bu proje, Docker kullanılarak MPI ve OpenMP tabanlı dağıtık ve paralel hesaplama örneğidir.

## Çalıştırma Talimatları

```bash
docker compose up --build
```

## YouTube Demo

 https://youtu.be/Q-SevftCDR0

 Sonuçlar (Temsili Veriler)
Yöntem	      Düğüm Sayısı	Thread Sayısı	  Toplam Süre (ms)	 Açıklama
OpenMP	      1	             4	            120	               Paylaşımlı bellekte hızlı
MPI	          3	             1	            180	               Dağıtım maliyeti yüksek
MPI + OpenMP	3              4	            60	               En verimli hibrit yapı
Not: Süreler temsili olup gerçek donanım ve veri büyüklüğüne göre değişebilir.

## Performans Karşılaştırması

| Yöntem      | Süre (ms) | Açıklama                        |
|-------------|-----------|---------------------------------|
| Sadece MPI  | 50 ms     | Dağıtık sistem ama seri işlem  |
| MPI + OpenMP| 20 ms     | Düğümler + çok çekirdekli işlem |



Değerlendirme
OpenMP, tek bir sistem içinde çok çekirdekli işlemde oldukça verimlidir.
MPI, dağıtık sistemlerde kullanılır, ancak veri gönderme ve toplama süresi ek yük getirir.
Hibrit Kullanım (MPI + OpenMP):
En hızlı sonuçları verir.
Hem çok düğüm hem çok çekirdekten faydalanır.
Özellikle Docker gibi konteyner mimarilerinde idealdir.


