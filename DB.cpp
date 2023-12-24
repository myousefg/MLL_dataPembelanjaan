#include "DB.h"
adr_Relasi *child;

// Procedure untuk create single linked list pembeli
void createListPembeli(listPembeli &P) {
  first(P) = NULL;
};

// Procedure untuk create circular single linked list barang
void createListBarang(listBarang &B) {
  first(B) = NULL;
  nextB(first(B)) = NULL;
};

// Function untuk create element pembeli
adr_Pembeli createElmPembeli(infotypePembeli x) {
  adr_Pembeli P = new elmPembeli;
  info(P) = x;
  nextP(P) = NULL;
  child(P) = NULL;
  return P;
};

// Function untuk create element barang
adr_Barang createElmBarang(infotypeBarang x) {
  adr_Barang B = new elmBarang;
  info(B) = x;
  nextB(B) = NULL;
  return B;
};

// Procedure untuk insert first list pembeli
void insertFirstPembeli(listPembeli &L, adr_Pembeli P) {
  nextP(P) = first(L);
  first(L) = P;
};

// Procedure untuk insert first list barang
void insertFirstBarang(listBarang &L, adr_Barang B) {
  if (first(L) == NULL) {
    first(L) = B;
    nextB(B) = first(L);
  } else {
    nextB(B) = first(L);
    first(L) = B;
  };
};

// Procedure untuk menggabungkan pembeli ke barang
void connectPembeliToBarang(adr_Pembeli P, adr_Barang B) {
  adr_Relasi R = new elmRelasi;
  keBarang(R) = B;
  next(R) = child(P);
  child(P) = R;
};

// Procedure untuk menghapus data pembeli
void deletePembeli(listPembeli &L, int IDP) {
  adr_Pembeli P = first(L);
  adr_Pembeli Prec = NULL;
  while (P != NULL && info(P).IDP != IDP) {
    Prec = P;
    P = nextP(P);
  };
  if (P != NULL) {
    deleteRelasi(L, IDP);
    if (Prec == NULL) {
      first(L) = nextP(P);
    } else {
      nextP(Prec) = nextP(P);
    };
    delete P;
  };
};

// Procedure untuk menghapus data barang
void deleteBarang(listBarang &L, int IDB) {
  adr_Barang B = first(L);
  adr_Barang Prec = NULL;
  while (B != NULL && info(B).IDB != IDB) {
    Prec = B;
    B = nextB(B);
  };
  if (B != NULL) {
    if (Prec == NULL) {
      first(L) = nextB(B);
    } else {
      nextB(Prec) = nextB(B);
    };
    delete B;
  };
};

// Procedure untuk menghapus relasi
void deleteRelasi(listPembeli &L, int IDP) {
  adr_Pembeli P = first(L);
  while (P != NULL) {
    adr_Relasi R = child(P);
    adr_Relasi PrecR = NULL;
    while (R != NULL && info(keBarang(R)).IDB != IDP) {
      PrecR = R;
      R = next(R);
    }
    if (R != NULL) {
      if (PrecR == NULL) {
        child(P) = next(R);
      } else {
        next(PrecR) = next(R);
      }
      delete R;
    };
    P = nextP(P);
  };
};

// Procedure untuk menampilkan semua data
void printAllData(listPembeli L) {
  adr_Pembeli P = first(L);
  while (P != NULL) {
    printPembeliData(P);
    printBarangDibeli(P);
    cout << "------------------------" << endl;
    P = nextP(P);
  };
};

// Procedure untuk menampilkan date pembeli
void printPembeliData(adr_Pembeli P) {
  cout << "Pembeli ID: " << info(P).IDP << endl;
  cout << "Saldo: " << info(P).saldo << endl;
  cout << "Toko: " << info(P).toko << endl;
  cout << "Nama: " << info(P).nama << endl;
};

// Procedure untuk menampilkan barang yang di beli
void printBarangDibeli(adr_Pembeli P) {
  adr_Relasi R = child(P);
  cout << "Barang yang dibeli: " << endl;
  while (R != NULL) {
    cout << "- " << info(keBarang(R)).barang << endl;
    R = next(R);
  };
};

// Procedure untuk menampilkan barang populer atau tidak
void printDataBarangDikitBanyak(listPembeli L) {
  adr_Barang minBarang = NULL, maxBarang = NULL;
  int minCount = INT_MAX, maxCount = INT_MIN;

  adr_Pembeli P = first(L);
  while (P != NULL) {
    adr_Relasi R = child(P);
    int count = 0;
    while (R != NULL) {
      count++;
      R = next(R);
    }
    if (count < minCount) {
      minCount = count;
      minBarang = keBarang(child(P));
    }
    if (count > maxCount) {
      maxCount = count;
      maxBarang = keBarang(child(P));
    };
    P = nextP(P);
  };

  if (minBarang != NULL) {
    cout << "Barang yang paling sedikit dibeli:" << endl;
    cout << "ID: " << info(minBarang).IDB
         << ", Nama: " << info(minBarang).barang << endl;
  };

  if (maxBarang != NULL) {
    cout << "Barang yang paling banyak dibeli:" << endl;
    cout << "ID: " << info(maxBarang).IDB
         << ", Nama: " << info(maxBarang).barang << endl;
  };
};

// Function untuk mencari data parent sesuai ID
adr_Pembeli searchPembeli(listPembeli L, int IDP) {
  adr_Pembeli P = first(L);
  while (P != NULL && info(P).IDP != IDP) {
    P = nextP(P);
  };
  return P;
};

// Function untuk mencari data child sesuai ID
adr_Barang searchBarang(listBarang L, int IDB) {
  adr_Barang B = first(L);
  while (B != NULL && info(B).IDB != IDB) {
    B = nextB(B);
  };
  return B;
};

// Function untuk menghitung berapa childe dari suat parent
int countChild(adr_Pembeli P) {
  int count = 0;
  adr_Relasi R = child(P);
  while (R != NULL) {
    count++;
    R = next(R);
  };
  return count;
};

// Function untuk menampilan menu
int menu(){
    cout << "===============================================================" <<endl;
    cout << "Mohammed Yousef Gumilar - 1302220085" << endl;
    cout << "Irvan Dzawin Nuha       - 1302223076" << endl;
    cout << "===============================================================" <<endl;
    cout << "1.  Insert data parent dari depan/belakang" <<endl;
    cout << "2.  Show all data parent" <<endl;
    cout << "3.  Menghapus data parent beserta relasinya" <<endl;
    cout << "4.  Mencari data parent" <<endl;
    cout << "5.  Mencari data child" <<endl;
    cout << "6.  Menambahkan data child" <<endl;
    cout << "7.  Menghubungkan data parent ke data child" <<endl;
    cout << "8.  Menampilkan seluruh data parent beserta childnya" <<endl;
    cout << "9.  Mencari data child pada parent tertentu" <<endl;
    cout << "10. Menghapus data child pada parent tertentu beserta relasinya" <<endl;
    cout << "11. Menghitung jumlah data child dari parent tertentu" <<endl;
    cout << "0.  Exit"<<endl;
    cout << "===============================================================" <<endl;
    cout << "Masukkan menu: ";

    int x = 0;
    cin >> x;

    return x;
};
