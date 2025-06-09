# Sisop-5-2025-IT-18

## Kelompok

Nama | NRP
--- | ---
Muhammad Fachry Shalahuddin Rusamsi | 5027241031
Reza Aziz Simatupang | 5027241051
Muhammad Farrel Shaputra | 5027241110

## Daftar Isi

- [Kelompok](#kelompok)
- [Daftar Isi](#daftar-isi)
- [Soal](#soal)
- [Petunjuk Soal](#petunjuk-soal)
  - [Source](#source)
  - [Headers](#headers)
  - [Makefile](#makefile)
  - [Video Demonstrasi](#video-demonstrasi)
- [Laporan](#laporan)

## Soal

Pada suatu hari, anda merasa sangat lelah dari segala macam praktikum yang sudah ada, sehingga anda berencana untuk tidur yang nyenyak di sebuah jam 3:34AM yang cerah. Tetapi, anda terbangun di dalam dunia berbeda yang bernama "Eorzea". Ada sesuatu yang mengganggu pikiran anda sehingga anda diharuskan membuat sebuah operating system bernama "EorzeOS" untuk mendampingi diri anda dalam dunia ini.

1. Sebagai seorang main character dari dunia ini, ternyata anda memiliki kekuatan yang bernama "The Echo", kekuatan ini memungkinkan anda untuk berbicara pada Operating System ini (mungkin sebenarnya bukan ini kekuatannya, tetapi ini cukup kuat juga), dengan tujuan agar semua hal yang anda katakan, bila bukan merupakan sebuah command yang valid, akan mengulang hal yang anda katakan.

   Ilustrasi:
   ```
   user> Hello!
   Hello!
   user> I have the Echo
   I have the Echo
   ```

2. gurt: yo

   Ilustrasi:
   ```
   user> yo
   gurt
   user> gurt
   yo
   ```

3. Seorang main character memerlukan sebuah nama yang semua orang bisa ingat dengan baik. Buatlah sebuah command yang memungkinkan pengguna untuk mengubah nama user pada shell yang digunakan:
   * `user <username>` = mengubah username menjadi `<username>`
   * `user` = mengubah username menjadi default `user`
   
   Ilustrasi:
   ```
   user> user Tia
   Username changed to Tia
   Tia> user
   Username changed to user
   user>
   ```

4. Tiga negara besar dari Eorzean Alliance butuh bantuan anda untuk ikut serta dalam "Grand Company" mereka sehingga anda bisa mengubah warna terminal ajaib anda sesuai warna utama dari company mereka:
   * `grandcompany maelstrom` = clear terminal, ubah semua teks berikutnya jadi merah
   * `grandcompany twinadder` = clear terminal, ubah semua teks berikutnya jadi kuning
   * `grandcompany immortalflames` = clear terminal, ubah semua teks berikutnya jadi biru
   * `grandcompany <selain atau kosong>` = tunjukkan error message
   * `clear` = clear terminal, ubah semua teks berikutnya kembali jadi awal (para Grand Company sedih kamu netral)

   Selain mengubah seluruh warna terminal, nama anda di dalam terminal akan diberikan tambahan nama judul Grand Company:
   * Maelstrom = `user@Storm`
   * Twin Adder = `user@Serpent`
   * Immortal Flames = `user@Flame`
   * `clear` = menghapus nama grand company

   Ilustrasi:
   ```
   gurt> grandcompany maelstrom
   -- terminal clear menjadi warna merah --
   gurt@Storm> clear
   -- terminal clear menjadi warna putih --
   ```

5. Sebagai pahlawan terkenal di antara ketiga negara besar Eorzean Alliance, salah satu supplier senjata terbesar di seluruh Eorzea bernama "Rowena's House of Splendors" tiba-tiba memerlukan bantuan anda untuk membuat sebuah sistem kalkulator sederhana melalui command karena pemimpin mereka tertidur setelah mengurus semua orang di dalam Eorzea:
   * `add <x> <y>` = x + y
   * `sub <x> <y>` = x - y
   * `mul <x> <y>` = x * y
   * `div <x> <y>` = x / y

   Ilustrasi:
   ```
   user> add 4 2
   6
   user> sub 4 2
   2
   user> mul 3 -2
   -6
   user> div -6 -2
   3
   ```

6. me: yogurt
   
   gurt:
   * `yo`
   * `ts unami gng </3`
   * `sygau`

   pilih secara *random*

   Ilustrasi:
   ```
   user> yogurt
   gurt> yo
   user> yogurt
   gurt> ts unami gng </3
   user> yogurt
   gurt> sygau
   ```

8. Perusahaan mesin "Garlond Ironworks" tiba-tiba lelah mengurus permintaan senjata perang untuk orang ke-148649813234 yang berusaha menghadapi final boss yang sama, sehingga mereka perlu bantuan kamu untuk melengkapi `Makefile` yang diberikan dengan command-command yang sesuai untuk compile seluruh operating system ini.

## Petunjuk Soal

### Source

* [kernel.asm](src/kernel.asm)
  * `_putInMemory`: penjelasan terdapat dalam modul
  * `_interrupt`: fungsi untuk interrupt
    * `number`: interrupt vector number
    * `AX`,`BX`,`CX`,`DX`: register untuk diisi
    * `AX` merupakan kombinasi dari `AH` dan `AL`, pola ini juga berlaku untuk `BX`,`CX`, dan `DX`
    * Untuk menggabungkan jenis register `H` dan `L` menjadi `X` bisa menggunakan salah satu metode berikut:
      ```c
      AX = AH << 8 | AL    // first method
      AX = AH * 256 + AL   // second method
      ```
   * `getBiosTick`: fungsi untuk mendapatkan tick dari BIOS
* [kernel.c](src/kernel.c)
  * Diisi penerapan fungsi `printString`, `readString`, dan `clearScreen` dengan bantuan `kernel.asm`
    * untuk `printString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` dengan parameter `AH = 0x0E` untuk _teletype output_. Karakter yang ditampilkan dapat dimasukkan pada register `AL`. Fungsi ini akan menampilkan string karakter ASCII (_null-terminated_) ke layar.
    * untuk `readString`: Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 16h` dengan parameter `AH = 0x00` untuk _keyboard input_. Fungsi ini akan membaca karakter ASCII (_non-control_) yang dimasukkan oleh pengguna dan menyimpannya pada buffer hingga menekan tombol `Enter`. Handle tombol `Backspace` dibebaskan kepada praktikan.
    * untuk `clearScreen`: Ukuran layar adalah `80x25` karakter. Setelah layar dibersihkan, kursor akan kembali ke posisi awal yaitu `(0, 0)` dan buffer video untuk warna karakter diubah ke warna putih. Implementasi dapat menggunakan fungsi `interrupt` dengan service `int 10h` atau menggunakan fungsi `putInMemory` untuk mengisi memori video.
* [shell.c](src/shell.c)
  * Diisi penerapan shell yang menggunakan fungsi kernel untuk parsing keseluruhan command yang diinput

### Headers

* [std_type.h](include/std_type.h)
  * `byte`: unsigned char data type, untuk angka 0-255 (`0x00`-`0xFF`)
  * `bool`: untuk boolean (true/false), karena boolean tidak built-in
* [std_lib.h](include/std_lib.h)
  * `div`: division
  * `mod`: modulo
  * Pembagian dan modulo tidak ada dalam assembly, sehingga harus dilengkapi dengan operator yang tersedia (`+`,`-`,`*`,`<<`,`>>`)
  * `strcmp`: membandingkan dua string
  * `strcpy`: copy string
  * `clear`: fill memory dengan `0`
  * `atoi`: alphanumeric to integer (string menjadi angka)
  * `itoa`: integer to alphanumeric (angka menjadi string)
* [kernel.h](include/kernel.h)
  * Deklarasi header untuk fungsi-fungsi dalam `kernel.c`
* [shell.h](include/shell.h)
  * Deklarasi header untuk fungsi-fungsi dalam `shell.c`

### Makefile

* [makefile](./makefile)
   * `prepare` : membuat disk image baru `floppy.img` pada direktori `bin/` dengan ukuran 1.44 MB.
   * `bootloader` : mengkompilasi `bootloader.asm` menjadi `bootloader.bin` pada direktori `bin/`.
   * `stdlib` : mengkompilasi `std_lib.c` menjadi `std_lib.o` pada direktori `bin/`.
   * `shell`: mengkompilasi `shell.c` menjadi `shell.o` pada direktori `bin/`.
   * `kernel` : mengkompilasi `kernel.c` menjadi `kernel.o` pada direktori `bin/` dan mengkompilasi `kernel.asm` menjadi `kernel_asm.o` pada direktori `bin/`.
   * `link` : menggabungkan `bootloader.bin`, `kernel.o`, `kernel_asm.o`, dan `std_lib.o` menjadi `floppy.img`.
   * `build` : menjalankan perintah `prepare`, `bootloader`, `stdlib`, `kernel`, dan `link`.

### Video Demonstrasi

[Akses Video dalam Assets](./assets/demo.mp4)

https://github.com/user-attachments/assets/1cfa66b1-b2f5-4e3e-a4b2-ec8b012f6fbb


## Laporan

> Isi sesuai pengerjaan.
1. Mengimplementasikan sistem "The Echo" yang memungkinkan shell untuk mengulang input user jika input bukan command yang valid.
<pre>
  if (processCommand(cmd, arg)) {
  continue;
} else {
  printString(buf);
  printString("\n");
}
</pre>
2. Implementasikan swap system antara command "yo" dan "gurt".
<pre>
  if (strcmp(cmd, "yo") == 0) {
  printString("gurt\n");
  return true;
}

if (strcmp(cmd, "gurt") == 0) {
  printString("yo\n");
  return true;
}
</pre>
3. Sistem manajemen username yang memungkinkan user mengubah nama user pada shell prompt.
<pre>
     char currentUsername[32] = "user";
</pre>
<pre>
     if (strcmp(cmd, "user") == 0) {
  if (arg[0][0] == '\0') {
    strcpy(currentUsername, "user");
    printString("Username changed to user\n");
  } else {
    strcpy(currentUsername, arg[0]);
    printString("Username changed to ");
    printString(arg[0]);
    printString("\n");
  }
  return true;
}
</pre>

4. Tiga negara besar Eorzean Alliance membutuhkan bantuan Anda! Pilih salah satu Grand Company untuk mengubah tampilan terminal.
<pre>
  if (strcmp(cmd, "grandcompany") == 0) {
    if (strcmp(arg[0], "maelstrom") == 0) {
      clearScreen();
      setColor(0x04); // red
      strcpy(grandCompanyTitle, "@Storm");
      printString("Grand Company set to Maelstrom\n");
    } else if (strcmp(arg[0], "twinadder") == 0) {
      clearScreen();
      setColor(0x0E); // yellow
      strcpy(grandCompanyTitle, "@Serpent");
      printString("Grand Company set to Twin Adder\n");
    } else if (strcmp(arg[0], "immortalflames") == 0) {
      clearScreen();
      setColor(0x01); // blue
      strcpy(grandCompanyTitle, "@Flame");
      printString("Grand Company set to Immortal Flames\n");
    } else {
      printString("Error: Invalid Grand Company\n");
    }
    return true;
}
</pre>
* Mengubah warna terminal dan judul pengguna berdasarkan faksi yang dipilih
* Tiga opsi yang valid:
* maelstrom: Warna merah, judul "@Storm"
* twinadder: Warna kuning, judul "@Serpent"
* immortalflames: Warna biru, judul "@Flame"
* Menghapus layar sebelum menerapkan perubahan
* Menampilkan kesalahan untuk nama faksi yang tidak valid

<pre>
    if (strcmp(cmd, "clear") == 0) {
    clearScreen();
    setColor(0x07); // default white
    strcpy(grandCompanyTitle, "");
    printString("Grand Company cleared\n");
    return true;
}
</pre>
* Mengatur ulang terminal ke status default:
* Membersihkan layar
* Mengatur kembali warna ke putih (0x07)
* Menghapus judul Grand Company
* Menyediakan pesan konfirmasi

5. Kalkulator sederhana melalui command
<pre>
  if (strcmp(cmd, "add") == 0) {
    int x = atoi(arg[0]);
    int y = atoi(arg[1]);
    int res = x + y;
    char resStr[16];
    itoa(res, resStr);
    printString(resStr);
    printString("\n");
    return true;
}
</pre>
* Semua mengikuti pola yang sama dengan aritmatika yang berbeda:
* sub: Pengurangan
* mul: Perkalian
* div: Pembagian (dengan pemeriksaan pembagian nol)

6. me:yogurt
   
   gurt: random (yo, ts unami gng </3, sygau)
   
   ``c
    if (strcmp(cmd, "yogurt") == 0) {
        int tick = getBiosTick();
        const char* replies[] = {"yo", "ts unami gng </3", "sygau"};
        int index = tick % 3;
        printString("gurt> ");
        printString(replies[index]);
        printString("\n");
        return true;
    }
* Mengecek apakah perintah yang diketik user (cmd) adalah "yogurt"
* Mengambil sisa hasil bagi tick dengan 3, sehingga index-nya akan selalu 0, 1, atau 2 untuk memilih salah satu balasan dari array replies secara random
