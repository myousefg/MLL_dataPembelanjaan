#include "DB.h"

int main() {
    // Deklarasi isi variable
    int pilih, IDB, IDP, stok;
    adr_Pembeli P;
    adr_Barang B;
    infotypePembeli pembeliInfo;
    infotypeBarang barangInfo;
    listPembeli listP;
    listBarang listB;
    // Membuat list pembeli dan barang
    createListPembeli(listP);
    createListBarang(listB);
    // Menu dari aplikasi Data Pembelanjaan
    cout << "===============================================================" << endl;
    cout << "Mohammed Yousef Gumilar - 1302220085" << endl;
    cout << "Irvan Dzawin Nuha       - 1302223076" << endl;

    do {
        cout << "===============================================================" << endl;
        cout << "1.  Insert First data Pembeli" << endl;
        cout << "2.  Insert Last data Barang" << endl;
        cout << "3.  Menghubungkan data Pembeli ke data Barang" << endl;
        cout << "4.  Menghapus data Pembeli dan Belanjaan" << endl;
        cout << "5.  Menghapus data Barang" << endl;
        cout << "6.  Menghapus data Child pada Keranjang Pembeli" << endl;
        cout << "7.  Mencari data Pembeli" << endl;
        cout << "8.  Mencari data Barang" << endl;
        cout << "9.  Mencari data Belanjaan pada Keranjang Pembeli" << endl;
        cout << "10. Tampilkan data Pembeli dan Barang" << endl;
        cout << "11. Tampilkan data Pembeli" << endl;
        cout << "12. Tampilkan data Pembeli dan Child" << endl;
        cout << "13. Tampilkan data Pembeli yang mengambil barang tertentu" << endl;
        cout << "14. Tampilkan data Barang yang dibeli oleh seseorang" << endl;
        cout << "15. Tampilkan data Barang Popular dan Unpopular" << endl;
        cout << "16. Menghitung jumlah barang pada Keranjang Pembeli" << endl;
        cout << "0.  Exit" << endl;
        cout << "===============================================================" << endl;
        cout << "Masukkan menu: ";
        cin >> pilih;

        B = NULL;
        P = NULL;

        // Insert data parent dari depan (insert first data Pembeli)
        if (pilih == 1){
            cout << "Masukan ID Pembeli : ";
            cin >> pembeliInfo.IDP;
            cout << "Masukan Nama : ";
            cin >> pembeliInfo.nama;
            cout << "Masukan Saldo : ";
            cin >> pembeliInfo. saldo;
            adr_Pembeli newPembeli = createElmPembeli(pembeliInfo);
            insertFirstPembeli(listP, newPembeli);
            cout << "===============================================================" << endl;
            cout << "Data Pembeli Berhasil Ditambahkan." << endl;

        // Insert data Barang dari belakang (Insert last data Barang)
        } else if (pilih == 2) {
            cout << "Masukan ID Barang : ";
            cin >> barangInfo.IDB;
            cout << "Masukan Nama Barang : ";
            cin >> barangInfo. barang;
            cout << "Masukan Harga Barang : ";
            cin >> barangInfo.harga;
            cout << "Masukan Stok Barang : ";
            cin >> barangInfo.stok;
            adr_Barang newBarang = createElmBarang(barangInfo);
            insertLastBarang(listB, newBarang);
            cout << "===============================================================" << endl;
            cout << "Data Barang Berhasil Ditambahkan." << endl;

        // Menambah Data child + Menghubungkan data parent ke data child
        } else if (pilih == 3) {
            int IDP, IDB, stok;
            cout << "Masukkan ID Pembeli untuk menambah data child: ";
            cin >> IDP;
            P = searchPembeli(listP, IDP);
            if (P != NULL) {
                cout << "Masukkan ID Barang untuk ditambahkan sebagai child: ";
                cin >> IDB;
                B = searchBarang(listB, IDB);
                if (B != NULL) {
                    cout << "Masukkan jumlah barang yang dibeli: ";
                    cin >> stok;
                    if (info(B).stok >= stok && info(P).saldo >= stok * info(B).harga) {
                        connectPembeliToBarang(P, B, stok);
                        cout << "===============================================================" << endl;
                        cout << "Data Child Berhasil Ditambahkan." << endl;
                    } else {
                        cout << "===============================================================" << endl;
                        cout << "Stok barang tidak mencukupi atau saldo tidak mencukupi." << endl;
                    }
                } else {
                    cout << "===============================================================" << endl;
                    cout << "Barang tidak ditemukan." << endl;
                }
            } else {
                cout << "===============================================================" << endl;
                cout << "Pembeli tidak ditemukan." << endl;
            }

        // Menghapus data parent beserta relasinya (Menghapus pembeli dan relasinya)
        } else if (pilih == 4) {
            cout << "Masukan ID pembeli yang ingin dihapus: ";
            cin >> IDP;
            deletePembeli(listP, IDP);
            deleteRelasi(listP, IDP);
            cout << "===============================================================" << endl;
            cout << "Data Pembeli Berhasil Dihapus." << endl;

        // Menghapus data barang tertentu
        } else if (pilih == 5) {
            cout << "Masukkan ID barang yang ingin dihapus: ";
            cin >> IDB;
            deleteBarang(listB, IDB);
            cout << "===============================================================" << endl;
            cout << "Data Barang Berhasil Dihapus." << endl;

        // Menghapus data child pada parent tertentu beserta relasinya
        } else if (pilih == 6) {
            int IDP, IDB;
            cout << "Masukkan ID Pembeli untuk menghapus data child dan relasinya: ";
            cin >> IDP;
            cout << "Masukkan ID Barang yang ingin dihapus dari keranjang pembeli: ";
            cin >> IDB;
            deleteChild(listP, listB, IDP, IDB);
            deleteRelasi(listP, IDP);

        // Mencari data parent
        } else if (pilih == 7) {
            cout << "Masukan ID pembeli yang ingin dicari: ";
            cin >> IDP;
            P = searchPembeli(listP, IDP);
            if (P != NULL) {
                printPembeliData(listP, P);
            } else {
                cout << "===============================================================" << endl;
                cout << "Pembeli tidak ditemukan." << endl;
            };

        // Mencari data child
        } else if (pilih == 8) {
            cout << "Masukan barang yang ingin dicari: ";
            cin >> IDB;
            B = searchBarang(listB, IDB);
            if (B != NULL) {
                printBarangData(listB, B);
            } else {
                cout << "===============================================================" << endl;
                cout << "Barang tidak ditemukan." << endl;
            };

        // Mencari data child pada parent tertentu
        } else if (pilih == 9) {
            cout << "Masukan parent yang ingin dicari: ";
            cin >> IDP;
            P = searchPembeli(listP, IDP);
            if (P != NULL) {
                printBarangDibeli(P);
            } else {
                cout << "===============================================================" << endl;
                cout << "Pembeli tidak ditemukan." << endl;
            };

        // Menampilkan data pembeli dan data barang
        } else if (pilih == 10) {
            printDataPembeli(listP);
            printDataBarang(listB);

        // Show all data parent
        } else if (pilih == 11) {
            printDataPembeli(listP);

        // Menampilkan seluruh data parent beserta childnya
        } else if (pilih == 12) {
            printParentChild(listP);

        // Menampilkan data pembeli yang mengambil barang tertentu
        } else if (pilih == 13) {
            cout << "Masukan ID barang: ";
            cin >> IDB;
            printPembeliBarangT(listP, listB, IDB);

        // Menampilkan data barang yang dibeli oleh seseorang
        } else if (pilih == 14) {
            cout << "Masukkan ID pembeli: ";
            cin >> IDP;
            printDataBarangDibeli(IDP, listP, listB);

        // Menampilkan data barang yang paling banyak dibeli dan juga paling sedikit dibeli
        } else if (pilih == 15) {
            cout << "===============================================================" << endl;
            printPopularBarang(listP);
            cout << "------------------------" << endl;
            printUnpopularBarang(listP);

        // Menghitung jumlah data child dari parent tertentu
        } else if (pilih == 16) {
            cout << "Masukan Pembeli yang ingin dihitung childnya: ";
            cin >> IDP;
            P = searchPembeli(listP, IDP);
            if (P != NULL) {
                int count = countChild(P);
                cout << "Jumlah child: " << count << endl;
            } else {
                cout << "===============================================================" << endl;
                cout << "Pembeli tidak ditemukan." << endl;
            };
        };

    } while (pilih != 0);
    cout << endl;
    cout << "===============================================================" << endl;
    cout << "PROGRAM TERMINATED\n";
    cout << "===============================================================" << endl;
    return 0;
};
