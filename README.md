Topic : Data pembelanjaan (MLL dan DLL pada c++)
Description : implementasikan multi linked-list yang memodelkan data pembeli dan data barang yang dibelinya di suatu toko. 
Seorang pembeli bisa membeli banyak barang tertentu selama total harga barang yang dibeli tidak melebihi saldo yang dimilikinya. 
Sedangkan suatu barang bisa dibeli oleh siapapun, selama persedian barang tersebut masih ada.

Fungsionalitas :
a. Penambahan data pembeli.
b. Penambahan data barang.
c. Penentuan relasi antara pembeli dan barang yang dibelinya (dan sebalikknya).
d. Menghapus data pembeli tertentu.
e. Manghapus data barang tertentu.
f. Menampilkan data keseluruhan pembeli beserta data barang yang dibelinya.
g. Menampilkan data pembeli yang mengambil barang tertentu.
h. Menampilkan data barang yang dibeli oleh seseorang.
i. Menampilkan data barang yang paling banyak dibeli dan juga paling sedikit dibeli.

Penilaian :
5  - Insert data parent dari depan/belakang [1.]
5  - Show all data parent [11.]
15 - Menghapus data parent beserta relasinya [4.]
5  - Mencari data parent [7.]
5  - Mencari data child [8.]
5  - Menambahkan data child [3. (digabung)] 
5  - Menghubungkan data parent ke data child [3. (digabung)] 
15 - Menampilkan seluruh data parent beserta childnya [12.]
10 - Mencari data child pada parent tertentu [9.]
15 - Menghapus data child pada parent tertentu beserta relasinya [6.]
5  - Menghitung jumlah data child dari parent tertentu [16.]
10 - Main program [default]

List Menu :
 1.  Insert First data Pembeli
 2.  Insert Last data Barang
 3.  Menghubungkan data Pembeli ke data Barang
 4.  Menghapus data Pembeli dan Belanjaan
 5.  Menghapus data Barang
 6.  Menghapus data Child pada Keranjang Pembeli
 7.  Mencari data Pembeli
 8.  Mencari data Barang
 9.  Mencari data Belanjaan pada Keranjang Pembeli
 10. Tampilkan data Pembeli dan Barang
 11. Tampilkan data Pembeli
 12. Tampilkan data Pembeli dan Child
 13. Tampilkan data Pembeli yang mengambil barang tertentu
 14. Tampilkan data Barang yang dibeli oleh seseorang
 15. Tampilkan data Barang Popular dan Unpopular
 16. Menghitung jumlah barang pada Keranjang Pembeli
 0.  Exit

Feedback dari asprak :
- List data pembeli dibuat array, biar pas barang dihapus masih ada di list pembeli
- No.15 Error/no if statement untuk data barang
