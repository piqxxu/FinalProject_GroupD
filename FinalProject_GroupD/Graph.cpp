#include "Graph.h"

Vertex* head = nullptr;

// Mencari vertex berdasarkan nama
Vertex* findVertex(string indomaret) {
    Vertex* current = head;
    while (current != nullptr) {
        if (current->namaIndomaret == indomaret) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Membuat vertex baru
Vertex* createNewVertex(string indomaret) {
    Vertex* newVertex = new Vertex;
    newVertex->namaIndomaret = indomaret;
    newVertex->firstEdge = nullptr;
    newVertex->next = nullptr;
    return newVertex;
}

// Membuat edge baru
Edge* createNewEdge(string dest, float jarak) {
    Edge* newEdge = new Edge;
    newEdge->destindomaret = dest;
    newEdge->jarak = jarak;
    newEdge->next = nullptr;
    return newEdge;
}

// Tambah vertex ke dalam graf
void insertVertex(string indomaret) {
    if (findVertex(indomaret) != nullptr) {
        cout << "Vertex " << indomaret << " sudah ada." << endl;
        return;
    }
    Vertex* newVertex = createNewVertex(indomaret);
    if (head == nullptr) {
        head = newVertex; // Kalau linked list kosong
    } else {
        Vertex* temp = head;
        while (temp->next != nullptr) { // Loop sampai node terakhir
            temp = temp->next;
        }
        temp->next = newVertex; // Tambah di akhir linked list
    }
}

// Menambahkan jalur ke dalam graf
void tambahJalur(string from, string to, float jarak) {
    Vertex* fromVertex = findVertex(from);
    Vertex* toVertex = findVertex(to);
    if (fromVertex == nullptr || toVertex == nullptr) {
        cout << "Vertex tidak ditemukan." << endl;
        return;
    }

    Edge* newEdge = createNewEdge(to, jarak);
    newEdge->next = fromVertex->firstEdge;
    fromVertex->firstEdge = newEdge;
}

// Tampilkan semua vertex dan edge
void tampilkanGraf() {
    Vertex* current = head;
    while (current != nullptr) {
        cout << "Vertex " << current->namaIndomaret << " -> ";
        Edge* edge = current->firstEdge;
        while (edge != nullptr) {
            cout << edge->destindomaret << "(" << edge->jarak << " km) ";
            edge = edge->next;
        }
        cout << endl;
        current = current->next;
    }
}

void cariJalurTercepat(Vertex* current, string to, float jarakSaatIni, float& shortestDistance, string path, string& shortestPath) {
    // Kalau sampai di tujuan, cek apakah jarak ini lebih pendek
    if (current->namaIndomaret == to) {
        if (jarakSaatIni < shortestDistance) {
            shortestDistance = jarakSaatIni;
            shortestPath = path;
        }
        return;
    }

    // Eksplorasi semua edge dari vertex sekarang
    Edge* edge = current->firstEdge;
    while (edge != nullptr) {
        // Tambahkan jarak edge ke total jarak dan rekursi ke vertex tujuan edge
        cariJalurTercepat(findVertex(edge->destindomaret), to, jarakSaatIni + edge->jarak, shortestDistance, path + " -> " + edge->destindomaret, shortestPath);
        edge = edge->next;
    }
}

void jalurTercepat(string from, string to) {
    Vertex* start = findVertex(from);
    if (start == nullptr) {
        cout << "Vertex " << from << " tidak ditemukan." << endl;
        return;
    }

    Vertex* end = findVertex(to);
    if (end == nullptr) {
        cout << "Vertex " << to << " tidak ditemukan." << endl;
        return;
    }

    float shortestDistance = 9999; // Angka besar sebagai pengganti float_MAX
    string shortestPath = "";
    string path = from;

    cariJalurTercepat(start, to, 0, shortestDistance, path, shortestPath);

    if (shortestDistance == 9999) {
        cout << "Jalur dari " << from << " ke " << to << " tidak ditemukan." << endl;
    } else {
        cout << "Jarak terpendek: " << shortestDistance << " km" << endl;
        cout << "Jalur: " << shortestPath << endl;
    }
}


// Mencari persimpangan paling ramai
void busiestIntersection() {
    Vertex* current = head;
    float maxCount = 0;
    string busiest;

    while (current != nullptr) {
        float count = 0;
        Edge* edge = current->firstEdge;
        while (edge != nullptr) {
            count++;
            edge = edge->next;
        }

        if (count > maxCount) {
            maxCount = count;
            busiest = current->namaIndomaret;
        }
        current = current->next;
    }

    cout << "Persimpangan paling ramai: " << busiest << " dengan " << maxCount << " jalur." << endl;
}
