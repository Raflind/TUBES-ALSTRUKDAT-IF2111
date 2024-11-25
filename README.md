# TUBES-ALSTRUKDAT-IF2111

Dibuat oleh:
Kelompok 09 - Kelas 02

1. Karunia Mega Lestari - 18221126
2. Mahesa Satria Prayata - 18223082
3. Rafli Dwi Nugraha - 18223038
4. M Khalfani Shaquille Indrajaya - 18223104
5. Alghan Pridanusuta - 18223058
6. Michael Ballard Isaiah Silaen - 18223080

Tugas Alstrukdat ini merupakan sistem yang dijalankan melalui CLI. Program disini menjalankan PURRMART.

# PANDUAN OPERASI

Compile:
gcc main.c help.c listbarang.c load.c login.c logout.c mesinkarakter.c mesinkata.c queue.c quit.c register.c save.c start.c store.c tebakangka.c user.c wordl3.c works.c -o main

Execution:
./main

1. Compile dengan perintah gcc yang sesuai, kemudian execute .exe hasil kompilasi
2. Pada awal, hanya terdapat 3 command legal, yaitu START/LOAD/QUIT. START akan memakai file default untuk konfigurasi data item dan user, sementara LOAD akan memakai file .txt berdasarkan input yang diberikan setelah command LOAD diberikan.
3. Kemudian, terdapat user verification. Terdapat tiga command legal, yaitu REGISTER/LOGIN/QUIT. REGISTER untuk membuat akun user baru, LOGIN untuk masuk ke akun user yang sudah exist. Keduanya memerlukan username dan password.
4. Setelah melewati user verification, terdapat opsi command antara: WORK/WORK CHALLENGE/STORE LIST/STORE SUPPLY/STORE REQUEST/STORE REMOVE/LOGOUT/SAVE/QUIT.
5. LOGOUT untuk keluar dari akun yang sekarang, dan SAVE untuk menyimpan semua data yang ada ke suatu savefile.
6. QUIT untuk keluar dari program secara keseluruhan.
