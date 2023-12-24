#ifndef DB_H_INCLUDED
#define DB_H_INCLUDED

#include <iostream>
using namespace std;

// define (opsional)
#define first(L) (L).first
#define next(P) (P)->next
#define nextP(P) (P)->nextP
#define nextB(P) (P)->nextB
#define info(P) (P)->info
#define child(P) (P)->child
#define keBarang(P) (P)->keBarang
#define NIL NULL

// isi dalam listnya
typedef struct pembeli {
  int IDP, saldo;
  string toko, nama;
};
struct barang {
  int IDB, harga, stok;
  string barang;
};
// bukan adt
typedef pembeli infotypePembeli;
typedef barang infotypeBarang;
typedef struct elmPembeli *adr_Pembeli;
typedef struct elmBarang *adr_Barang;
typedef struct elmRelasi *adr_Relasi;
// list
struct elmRelasi {
  adr_Relasi next;
  adr_Barang keBarang;
};
struct elmPembeli {
  infotypePembeli info;
  adr_Pembeli nextP;
  adr_Relasi child;
};
struct elmBarang {
  infotypeBarang info;
  adr_Barang nextB;
};
// listnya
struct listPembeli {
  adr_Pembeli first;
};
struct listBarang {
  adr_Barang first;
};
// function & procedure
void createListPembeli(listPembeli &P);
void createListBarang(listBarang &B);
adr_Pembeli createElmPembeli(infotypePembeli x);
adr_Barang createElmBarang(infotypeBarang x);
void insertFirstPembeli(listPembeli &L, adr_Pembeli P);
void insertFirstBarang(listBarang &L, adr_Barang B);
void connectPembeliToBarang(adr_Pembeli P, adr_Barang B);
void deletePembeli(listPembeli &L, int IDP);
void deleteBarang(listBarang &L, int IDB);
void deleteRelasi(listPembeli &L, int IDP);
void printAllData(listPembeli L);
void printPembeliData(adr_Pembeli P);
void printPurchasedBarang(adr_Pembeli P);
void printDataBarangDikitBanyak(listPembeli L);
int menu();

#endif // DB_H_INCLUDED
