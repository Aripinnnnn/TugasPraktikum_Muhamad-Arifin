#include <iostream>
#include <string>
using namespace std;

//Variabel Global
const string USERNAME = "staff";
const string PASSWORD = "123";

//Struct Global
struct Book
{string title, author; int stock;};

bool login()
{
    string username, password;
    //Perulangan Do while
    do
    {
        cout<<"Masukkan Username: ";
        cin>>username;
        cout<<"Masukkan Password: ";
        cin>>password;
    } while (username != USERNAME || password != PASSWORD);
    return true;
}
//Fungsi Tidak Mengembalikan Nilai
//Array
void inputbuku(Book books[], int &jumlahbuku)
{
    cout<<"======== MENU INPUT BUKU ========\n";
    cout<<"Masukkan Judul Buku   : ";
    cin.ignore();
    getline(cin, books[jumlahbuku].title);
    cout<<"Masukkan Nama Penulis : ";
    getline(cin, books[jumlahbuku].author);
    cout<<"Masukkan Jumlah Stok  : ";
    cin >> books[jumlahbuku].stock;jumlahbuku++;
    cout<<"DATA BUKU BERHASIL DI INPUT.\n";
}
//Fungsi Tidak Mengembalikan Nilai
void listbuku(Book books[], int jumlahbuku)
{
    cout<<"===== Daftar Buku Yang Tersedia ====="<<endl;
    //Perulangan For
    for (int i = 0; i < jumlahbuku; i++)//Variabel lokal
    {
        cout<< i + 1 << ". " << books[i].title << " - " << books[i].author << " - " << books[i].stock << " Stok"<<endl;
    }
}
//Fungsi Tidak Mengembalikan Nilai
void peminjamanbuku(Book books[], int jumlahbuku)
{
    //Struct lokal
    struct Mahasiswa
    {string nama; string NPM;};
    int nomorbuku;
    Mahasiswa peminjam;

    cout<<"======== MENU PEMINJAMAN BUKU ========\n";
    cout<<"Masukkan Nama Mahasiswa: ";
    cin.ignore();
    getline(cin, peminjam.nama);

    cout<<"Masukkan NPM Mahasiswa: ";
    cin>>peminjam.NPM;

    cout<<"Masukkan Nomor Buku Yang Ingin Dipinjam: ";
    cin>>nomorbuku;
    //Kondisional Bertingkat
    if (nomorbuku < 1 || nomorbuku > jumlahbuku){
        cout<<"Nomor Buku Yang Anda Masukkan Salah. Silakan Coba Lagi."<<endl;
    } else if (books[nomorbuku - 1].stock == 0){
        cout<<"Maaf, Stok Buku Tersebut Saat Ini Kosong. Silakan Coba Lagi Nanti."<<endl;
    } else{
        books[nomorbuku - 1].stock--;
        cout<<"Nama Mahasiswa: "<<peminjam.nama <<endl;
        cout<<"NPM Mahasiswa : "<<peminjam.NPM <<endl;
        cout<<"Buku berhasil dipinjam."<<endl;
        cout<<"Jumlah stok saat ini: " <<books[nomorbuku - 1].stock << "." <<endl;
    }
}
//Fungsi Tidak Mengembalikan Nilai
void pengembalianbuku(Book books[], int jumlahbuku)
{
    //Struct lokal
    struct Mahasiswa
    {string nama; string NPM;};
    int nomorbuku;
    Mahasiswa pengembali;


    cout<<"======== MENU PENGEMBALIAN BUKU ========\n";
    cout<<"Masukkan Nama Mahasiswa: ";
    cin.ignore();
    getline(cin, pengembali.nama);

    cout<<"Masukkan NPM Mahasiswa: ";
    cin>>pengembali.NPM;

    cout<<"Masukkan Nomor Buku Yang Ingin Dikembalikan: ";
    cin>>nomorbuku;
    if (nomorbuku < 1 || nomorbuku > jumlahbuku){
        cout<<"Nomor buku yang Anda masukkan salah. Silakan coba lagi."<<endl;
    } else{
        (books[nomorbuku - 1].stock++);
        cout<<"Nama Mahasiswa: "<< pengembali.nama <<endl;
        cout<<"NPM Mahasiswa : "<< pengembali.NPM <<endl;
        cout<<"Buku Berhasil Dikembalikan."<<endl;
        cout<<"Jumlah Stok Saat Ini: " << books[nomorbuku - 1].stock << "." <<endl;
    }
}
// Fungsi Mengembalikan nilai
int totalStock(Book books[], int jumlahbuku)
{
    int totalStock = 0;
    for (int i = 0; i < jumlahbuku; i++)
    {
        totalStock += books[i].stock;
    }
    return totalStock;
}

int main()
{
    //Kondisional
    if (login())
    {
        int menu, jumlahbuku = 0;
        bool ulang = true;
        //Array
        Book books[100];
        //Perulangan While
        while (ulang)
        {
            cout<<endl;
            cout<<"-------------------------------------------------------------" <<endl;
            cout<<"|       SELAMAT DATANG DI PERPUSTAKAAN RIANG GEMBIRA        |" <<endl;
            cout<<"-------------------------------------------------------------" <<endl;
            cout<<"| PILIHAN MENU:                                             |" <<endl;
            cout<<"| 1. Input Buku                                             |" <<endl;
            cout<<"| 2. Daftar Buku                                            |" <<endl;
            cout<<"| 3. Peminjaman                                             |" <<endl;
            cout<<"| 4. Pengembalian                                           |" <<endl;
            cout<<"| 5. Laporan                                                |" <<endl;
            cout<<"| 6. Exit                                                   |" <<endl;
            cout<<"-------------------------------------------------------------" <<endl;
            cout<<"SILAHKAN PILIH MENU YANG ANDA INGINKAN (1-6): ";
            cin>>menu;
            cout<<endl;

            //Switch case
            switch (menu)
            {
                case 1:
                    inputbuku(books, jumlahbuku);
                    break;
                case 2:
                    listbuku(books, jumlahbuku);
                    break;
                case 3:
                    peminjamanbuku(books, jumlahbuku);
                    break;
                case 4:
                    pengembalianbuku(books, jumlahbuku);
                    break;
                case 5:
                    cout<<"======== LAPORAN PERPUSTAKAAN ========\n";
                    cout << "Total Stok Buku Saat Ini: " << totalStock(books, jumlahbuku) << " Buku" << endl;
                    break;
                case 6:
                    cout<<"TERIMAKASIH SUDAH BERKUNJUNG KE PERPUSTAKAAN\n";
                    cout<<"SAMPAI JUMPA LAGI\n";
                    cout<<"SEMOGA HARIMU MENYENANGKAN ^-^\n";
                    ulang = false;
                    break;
            }
        }
    }
    return 0;
}
