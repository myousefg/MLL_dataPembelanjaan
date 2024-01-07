#include "DB.h"

// Procedure untuk create single linked list pembeli
void createListPembeli(listPembeli &LP) {
    first(LP) = NULL;
};

// Procedure untuk create double linked list barang
void createListBarang(listBarang &LB) {
    first(LB) = NULL;
};

// Function untuk create element pembeli
adr_Pembeli createElmPembeli(infotypePembeli x) {
    adr_Pembeli AP = new elmPembeli;
    info(AP) = x;
    nextP(AP) = NULL;
    child(AP) = NULL;
    return AP;
};

// Function untuk create element barang
adr_Barang createElmBarang(infotypeBarang x) {
    adr_Barang AB = new elmBarang;
    info(AB) = x;
    nextB(AB) = NULL;
    return AB;
};

// Procedure untuk insert first list pembeli
void insertFirstPembeli(listPembeli &LP, adr_Pembeli AP) {
    if(first(LP) == NULL){
        first(LP) = AP;
    } else {
        nextP(AP)= first(LP);
        first(LP) = AP;
    };
};

// Procedure untuk insert last list barang
void insertLastBarang(listBarang &LB, adr_Barang AB) {
    if (first(LB) == NULL) {
        first(LB) = AB;
        last(LB) = AB;
        nextB(AB) = AB;
        prevB(AB) = AB;
    } else {
        adr_Barang Q = last(LB);
        nextB(Q) = AB;
        prevB(AB) = Q;
        nextB(AB) = first(LB);
        last(LB) = AB;
    };
};

// Procedure untuk menggabungkan pembeli ke barang
void connectPembeliToBarang(adr_Pembeli AP, adr_Barang AB, int stok) {
    adr_Relasi AR = new elmRelasi;
    keBarang(AR) = AB;
    next(AR) = child(AP);
    child(AP) = AR;
    info(AB).stokOri = stok;
    info(AB).stok -= stok;
    info(AP).saldo -= stok * info(AB).harga;
};

// Procedure untuk menghapus data pembeli
void deletePembeli(listPembeli &LP, int IDP) {
    adr_Pembeli AP = first(LP);
    adr_Pembeli Prec = NULL;
    while (AP != NULL && info(AP).IDP != IDP) {
        Prec = AP;
        AP = nextP(AP);
    };
    if (AP != NULL) {
        deleteRelasi(LP, IDP);
        if (Prec == NULL) {
            first(LP) = nextP(AP);
        } else {
            nextP(Prec) = nextP(AP);
        };
        delete AP;
    };
};

// Procedure untuk menghapus data barang
void deleteBarang(listBarang &LB, int IDB) {
    adr_Barang AB = first(LB);
    adr_Barang Prec = NULL;
    while (AB != NULL && info(AB).IDB != IDB) {
        Prec = AB;
        AB = nextB(AB);
    };
    if (AB != NULL) {
        if (Prec == NULL) {
            first(LB) = nextB(AB);
        } else {
            nextB(Prec) = nextB(AB);
        };
        delete AB;
    };
};

// Procedure untuk menghapus data child
void deleteChild(listPembeli &LP, listBarang &LB, int IDP, int IDB) {
    adr_Pembeli AP = searchPembeli(LP, IDP);

    if (AP == NULL) {
        cout << "===============================================================" << endl;
        cout << "Pembeli tidak ditemukan!" << endl;
    } else {
        adr_Relasi AR = child(AP);
        adr_Relasi PrecR = NULL;

        while (AR != NULL && info(keBarang(AR)).IDB != IDB) {
            PrecR = AR;
            AR = next(AR);
        }

        if (AR != NULL) {
            if (PrecR == NULL) {
                child(AP) = next(AR);
            } else {
                next(PrecR) = next(AR);
            }

            int stokOri = info(keBarang(AR)).stokOri;
            int harga = info(keBarang(AR)).harga;
            info(keBarang(AR)).stok += stokOri;
            info(AP).saldo += stokOri * harga;

            delete AR;

            cout << "===============================================================" << endl;
            cout << "Data child berhasil dihapus!" << endl;
        } else {
            cout << "===============================================================" << endl;
            cout << "Barang tidak ditemukan!" << endl;
        }
    }
}

// Procedure untuk menghapus relasi
void deleteRelasi(listPembeli &L, int IDP) {
    adr_Pembeli P = first(L);
    while (P != NULL) {
        adr_Relasi R = child(P);
        adr_Relasi PrecR = NULL;
        while (R != NULL && info(keBarang(R)).IDB != IDP) {
            PrecR = R;
            R = next(R);
        };
        if (R != NULL) {
            if (PrecR == NULL) {
                child(P) = next(R);
            } else {
                next(PrecR) = next(R);
            };
            delete R;
        };
        P = nextP(P);
    };
};

// Tampilkan pembeli yang membeli barang tertentu
void printPembeliBarangT(listPembeli LP, listBarang LB, int IDB) {
    adr_Pembeli AP = first(LP);
    adr_Relasi R;
    while (AP != NULL) {
        R = child(AP);
        while (R != NULL) {
            if (info(keBarang(R)).IDB == IDB) {
                cout << info(AP).nama << ", ";
            };
            R = next(R);
        };
        AP = nextP(AP);
    };
    cout << endl;
};

// Procedure untuk menampilkan keseluruhan pembeli beserta data Barang.
void printDataPembeli(listPembeli LP) {
    adr_Pembeli P = first(LP);
    if(P != NULL){
        while (P != NULL) {
            printPembeliData(LP, P);
            cout << "------------------------" << endl;
            P = nextP(P);
        };
    } else {
        cout << "===============================================================" << endl;
        cout << "Data Pembeli tidak ada." << endl;
    };
};

void printDataBarang(listBarang LB) {
    adr_Barang B = first(LB);
        printBarangData(LB, B);
        while (B != last(LB)) {
            B = nextB(B);
            printBarangData(LB, B);
            cout << "------------------------" << endl;
        };
};


// Menampilkan seluruh data parent beserta childnya
void printParentChild(listPembeli LP) {
    adr_Pembeli P = first(LP);
    if(P != NULL){
        while (P != NULL) {
            printPembeliData(LP, P);
            printBarangDibeli(P);
            cout << "------------------------" << endl;
            P = nextP(P);
        };
    } else {
        cout << "===============================================================" << endl;
        cout << "Data Pembeli tidak ada." << endl;
    };
};

// Procedure untuk menampilkan data pembeli
void printPembeliData(listPembeli LP, adr_Pembeli P) {
    cout << "ID Pembeli: " << info(P).IDP << endl;
    cout << "Nama: " << info(P).nama << endl;
    cout << "Saldo: " << info(P).saldo << endl;
};

// Procedure untuk menampilkan data Barang
void printBarangData(listBarang LB, adr_Barang B){
    cout << "ID Barang: " << info(B).IDB << endl;
    cout << "Nama: " << info(B).barang << endl;
    cout << "Harga: " << info(B).harga << endl;
    cout << "Stok: " << info(B).stok << endl;
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

// Procedure untuk menampilkan barang yang dibeli oleh seseorang
void printDataBarangDibeli(int IDP, listPembeli LP, listBarang LB) {
    adr_Pembeli P = searchPembeli(LP, IDP);

    if (P != NULL) {
        adr_Relasi R = child(P);

        if (R != NULL) {
            cout << "Barang dibeli oleh " << info(P).nama << ":" << endl;

            while (R != NULL) {
                cout << "- " << info(keBarang(R)).barang << endl;
                R = next(R);
            }
        } else {
            cout << "===============================================================" << endl;
            cout << "Belum ada barang yang dibeli oleh " << info(P).nama << "." << endl;
        }
    } else {
        cout << "===============================================================" << endl;
        cout << "Pembeli tidak ditemukan." << endl;
    }
}

// Procedure untuk menampilkan barang populer
void printPopularBarang(listPembeli L) {
    adr_Barang maxBarang = NULL;
    int maxCount = INT_MIN;
    adr_Pembeli P = first(L);

    while (P != NULL) {
        adr_Relasi R = child(P);
        int count = 0;

        while (R != NULL) {
            count++;
            R = next(R);
        }

        if (count > maxCount) {
            maxCount = count;
            maxBarang = keBarang(child(P));
        }

        P = nextP(P);
    }

    if (maxBarang != NULL) {
        cout << "Barang yang paling banyak dibeli:" << endl;
        cout << "ID: " << info(maxBarang).IDB << ", Nama: " << info(maxBarang).barang << endl;
    } else {
        cout << "Tidak ada barang yang tercatat." << endl;
    }
}

// Procedure untuk menampilkan barang Unpopuler
void printUnpopularBarang(listPembeli L) {
    adr_Barang minBarang = NULL;
    int minCount = INT_MAX;
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

        P = nextP(P);
    }

    if (minBarang != NULL) {
        cout << "Barang yang paling sedikit dibeli:" << endl;
        cout << "ID: " << info(minBarang).IDB << ", Nama: " << info(minBarang).barang << endl;
    } else {
        cout << "Tidak ada barang yang tercatat." << endl;
    }
}

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
    while (B != last(L) && info(B).IDB != IDB) {
        B = nextB(B);
    };
    return B;
};

// Function untuk menghitung berapa child dari suat parent
int countChild(adr_Pembeli P) {
    int count = 0;
    adr_Relasi R = child(P);
    while (R != NULL) {
        count++;
        R = next(R);
    };
    return count;
};
