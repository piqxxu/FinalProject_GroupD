#include "Graph.h"

int main() {
    // Menambahkan vertex
    insertVertex("Telkom University");
    insertVertex("Jalur A");
    insertVertex("Jalur B");
    insertVertex("Indomaret Podomoro");

    // Menambahkan jalur
    tambahJalur("Telkom University", "Jalur A", 1.2);
    tambahJalur("Jalur A", "Jalur B", 0.5);
    tambahJalur("Jalur A", "Indomaret Podomoro", 1.4);
    tambahJalur("Jalur B", "Indomaret Podomoro", 0.9);

    // Menampilkan graf
    cout << "Graf saat ini:" << endl;
    tampilkanGraf();

    // Mencari jalur tercepat
    cout << "\nJalur tercepat dari Telkom University ke Indomaret Podomoro:" << endl;
    jalurTercepat("Telkom University", "Indomaret Podomoro");

    // Menemukan persimpangan paling ramai
    cout << "\nPersimpangan paling ramai:" << endl;
    busiestIntersection();

    return 0;
}
