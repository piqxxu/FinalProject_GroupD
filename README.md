repo ini dibuat untuk mengerjakan final project data structure :)

Study Case : Rekomendasi Rute Dari Telkom University Ke Indomaret Podomoro

Desain Algoritma
1. Fungsi findVertex
Input: Nama Indomaret yang ingin dicari.
Output: Pointer ke vertex yang sesuai atau nullptr jika tidak ditemukan.
Langkah:

Mulai dari head (vertex pertama).
Lakukan pencarian di linked list vertex.
Jika nama vertex ditemukan, kembalikan pointer ke vertex tersebut.
Jika tidak, kembalikan nullptr.

2. Fungsi createNewVertex
Input: Nama Indomaret (string).
Output: Pointer ke vertex baru.
Langkah:

Buat vertex baru menggunakan dynamic memory allocation.
Set nama vertex sesuai input.
Set firstEdge dan next menjadi nullptr.
Kembalikan pointer ke vertex baru.

3. Fungsi createNewEdge
Input: Nama tujuan (string) dan jarak (float).
Output: Pointer ke edge baru.
Langkah:

Buat edge baru menggunakan dynamic memory allocation.
Set tujuan (destindomaret) dan jarak sesuai input.
Set next menjadi nullptr.
Kembalikan pointer ke edge baru.

4. Fungsi insertVertex
Input: Nama Indomaret (string).
Output: -
Langkah:

Periksa apakah vertex dengan nama tersebut sudah ada menggunakan findVertex.
Jika sudah ada, tampilkan pesan dan hentikan fungsi.
Jika tidak ada, buat vertex baru menggunakan createNewVertex.
Tambahkan vertex baru ke akhir linked list:
Jika linked list kosong, set head ke vertex baru.
Jika tidak, iterasi hingga node terakhir, lalu tambahkan vertex di akhir.

5. Fungsi tambahJalur
Input: Nama vertex asal (from), nama vertex tujuan (to), dan jarak (jarak).
Output: -
Langkah:

Cari vertex asal dan tujuan menggunakan findVertex.
Jika salah satu vertex tidak ditemukan, tampilkan pesan kesalahan dan hentikan fungsi.
Buat edge baru menggunakan createNewEdge.
Tambahkan edge baru ke list edge dari vertex asal (di depan firstEdge).

6. Fungsi tampilkanGraf
Input: -
Output: Tampilan graf (vertex dan edge).
Langkah:

Iterasi semua vertex mulai dari head.
Untuk setiap vertex, iterasi semua edge yang terhubung.
Tampilkan nama vertex dan semua edge yang terhubung dengannya beserta jaraknya.

7. Fungsi cariJalurTercepat
Input: Vertex saat ini, tujuan (to), jarak saat ini, jarak terpendek, jalur saat ini, dan jalur terpendek.
Output: -
Langkah:

Jika vertex saat ini adalah tujuan, periksa apakah jarak saat ini lebih kecil dari jarak terpendek:
Jika ya, perbarui jarak terpendek dan jalur terpendek.
Iterasi semua edge dari vertex saat ini.
Untuk setiap edge, lakukan rekursi dengan:
Vertex tujuan dari edge tersebut.
Total jarak yang diperbarui.
Jalur yang diperbarui.

8. Fungsi jalurTercepat
Input: Nama vertex asal (from) dan tujuan (to).
Output: Jalur dan jarak terpendek.
Langkah:

Cari vertex asal dan tujuan menggunakan findVertex.
Jika salah satu vertex tidak ditemukan, tampilkan pesan kesalahan dan hentikan fungsi.
Inisialisasi jarak terpendek dengan nilai besar dan jalur terpendek dengan string kosong.
Panggil cariJalurTercepat untuk mencari jalur terpendek.
Jika jarak terpendek tetap besar, berarti jalur tidak ditemukan.
Jika ditemukan, tampilkan jarak dan jalur terpendek.

9. Fungsi busiestIntersection
Input: -
Output: Vertex dengan jalur terbanyak.
Langkah:

Iterasi semua vertex mulai dari head.
Hitung jumlah edge dari setiap vertex.
Jika jumlah edge lebih besar dari nilai maksimum sebelumnya, perbarui nilai maksimum dan nama vertex.
Setelah selesai, tampilkan nama vertex dengan jumlah edge terbanyak.

Algoritma Main Program
Tambahkan beberapa vertex menggunakan insertVertex.
Tambahkan beberapa jalur menggunakan tambahJalur.
Tampilkan graf menggunakan tampilkanGraf.
Cari jalur tercepat dari vertex tertentu ke vertex tujuan menggunakan jalurTercepat.
Cari persimpangan paling ramai menggunakan busiestIntersection.

