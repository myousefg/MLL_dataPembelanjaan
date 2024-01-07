#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED

#include <iostream>
using namespace std;

// define
#define NIL NULL
#define next(P) (P)->next
#define nextP(P) (P)->nextP
#define nextB(P) (P)->nextB
#define prevB(P) (P)->prevB
#define info(P) (P)->info
#define first(L) (L).first
#define last(L) (L).last
#define child(P) (P)->child
#define keBarang(P) (P)->keBarang

// single_linked_list parent = pembeli
// double_linked_list child  = barang

// isi list
struct pembeli {
  int IDP, saldo;
  string nama;
};

struct barang {
  int IDB, harga, stok, stokOri;
  string barang;
};

// pointer untuk element
typedef pembeli infotypePembeli;
typedef barang infotypeBarang;
typedef struct elmPembeli *adr_Pembeli;
typedef struct elmBarang *adr_Barang;
typedef struct elmRelasi *adr_Relasi;

// element untuk list
struct elmPembeli {
  infotypePembeli info;
  adr_Pembeli nextP;
  adr_Relasi child;
};
struct elmBarang {
  infotypeBarang info;
  adr_Barang nextB;
  adr_Barang prevB;
};
struct elmRelasi {
  adr_Relasi next;
  adr_Barang keBarang;
};

// list
struct listPembeli {
  adr_Pembeli first;
};
struct listBarang {
  adr_Barang first;
  adr_Barang last;
};

// function & procedure
void createListPembeli(listPembeli &LP);
void createListBarang(listBarang &LB);
adr_Pembeli createElmPembeli(infotypePembeli x);
adr_Barang createElmBarang(infotypeBarang x);
void insertFirstPembeli(listPembeli &LP, adr_Pembeli AP);
void insertLastBarang(listBarang &LB, adr_Barang AB);
void connectPembeliToBarang(adr_Pembeli AP, adr_Barang AB, int stok);
void deletePembeli(listPembeli &LP, int IDP);
void deleteBarang(listBarang &LB, int IDB);
void deleteChild(listPembeli &LP, listBarang &LB, int IDP, int IDB);
void deleteRelasi(listPembeli &L, int IDP);
void printDataPembeli(listPembeli LP);
void printDataBarang(listBarang LB);
void printParentChild(listPembeli LP);
void printPembeliData(listPembeli LP, adr_Pembeli P);
void printPembeliBarangT(listPembeli P, listBarang B, int inB);
void printBarangData(listBarang LB, adr_Barang B);
void printBarangDibeli(adr_Pembeli P);
void printDataBarangDibeli(int IDP, listPembeli LP, listBarang LB);
void printPopularBarang(listPembeli L);
void printUnpopularBarang(listPembeli L);
adr_Pembeli searchPembeli(listPembeli L, int IDP);
adr_Barang searchBarang(listBarang L, int IDB);
int countChild(adr_Pembeli P);

#endif // DB_H_INCLUDED
