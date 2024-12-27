#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
using namespace std;

struct Edge {
    string destindomaret;
    float jarak;
    Edge* next;
};

struct Vertex {
    string namaIndomaret;
    Edge* firstEdge;
    Vertex* next;
};

Vertex* findVertex(string indomaret);
Vertex* createNewVertex(string indomaret);
Edge* createNewEdge(string dest, float jarak);
void insertVertex(string indomaret);
void tambahJalur(string from, string to, float jarak);
void tampilkanGraf();
void cariJalurTercepat(Vertex* current, string to, float jarakSaatIni, float& shortestDistance, string path, string& shortestPath);
void jalurTercepat(string from, string to);

void busiestIntersection();
#endif
