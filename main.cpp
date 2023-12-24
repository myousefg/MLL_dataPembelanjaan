#include "DB.h"

int main(){

    int pilih, x, n, i, IDD, IDP;
    adr_Pembeli P; adr_Barang B;
    menu:
        system("cls");
        pilih = menu();

    while(pilih != 0){
        system("cls");
        B, P = NULL;
        if(pilih == 1){
            cout << "===============================================================" << endl;
            cout << "1.  Insert data parent dari depan/belakang" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 2){
            cout << "===============================================================" << endl;
            cout << "2.  Show all data parent" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 3){
            cout << "===============================================================" << endl;
            cout << "3.  Menghapus data parent beserta relasinya" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 4){
            cout << "===============================================================" << endl;
            cout << "4.  Mencari data parent" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 5){
            cout << "===============================================================" << endl;
            cout << "5.  Mencari data child" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 6){
            cout << "===============================================================" << endl;
            cout << "6.  Menambahkan data child" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 7){
            cout << "===============================================================" << endl;
            cout << "7.  Menghubungkan data parent ke data child" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 8){
            cout << "===============================================================" << endl;
            cout << "8.  Menampilkan seluruh data parent beserta childnya" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 9){
            cout << "===============================================================" << endl;
            cout << "9.  Mencari data child pada parent tertentu" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 10){
            cout << "===============================================================" << endl;
            cout << "10. Menghapus data child pada parent tertentu beserta relasinya" << endl;
            cout << "===============================================================" << endl;

        } else if(pilih == 11){
            cout << "===============================================================" << endl;
            cout << "11. Menghitung jumlah data child dari parent tertentu" << endl;
            cout << "===============================================================" << endl;
        };
        cout << "\n===============================================================" << endl;
        cout << "PROGRAM TERMINATED\n";
        cout << "===============================================================" << endl;
    };
    return 0;
};
