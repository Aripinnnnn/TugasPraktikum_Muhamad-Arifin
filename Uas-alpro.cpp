#include <iostream>
#include <string>
using namespace std;

const string USERNAME = "staff";
const string PASSWORD = "123";

struct Book
{string title, author; int stock;};

bool login() 
{
    string username, password;
    do 
    {
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;
    } while (username != USERNAME || password != PASSWORD);
    return true;
}

void inputbuku(Book books[], int &jumlahbuku) 
{
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, books[jumlahbuku].title);
    cout << "Masukkan nama penulis: ";
    getline(cin, books[jumlahbuku].author);
    cout << "Masukkan jumlah stok: ";
    cin >> books[jumlahbuku].stock;
    jumlahbuku++;
}

void listbuku(Book books[], int jumlahbuku) 
{
    cout << "Daftar buku yang tersedia:" << endl;
    for (int i = 0; i < jumlahbuku; i++) 
    {
        cout << i + 1 << ". " << books[i].title << " - " << books[i].author << " - " << books[i].stock << " stok" << endl;
    }
}

void peminjamanbuku(Book books[], int jumlahbuku)
{
    struct Mahasiswa
    {string nama; string NPM="2310631170";};
    int nomorbuku;
    Mahasiswa peminjam; 

    cout << "Masukkan nama mahasiswa: ";
    cin.ignore();
    getline(cin, peminjam.nama); 

    cout << "Masukkan NPM mahasiswa: ";
    cin >> peminjam.NPM; 

    cout << "Masukkan nomor buku yang ingin dipinjam: ";
    cin >> nomorbuku;
    if (nomorbuku < 1 || nomorbuku > jumlahbuku) 
    {
        cout << "Nomor buku yang Anda masukkan salah. Silakan coba lagi." << endl;
    } else if (books[nomorbuku - 1].stock == 0) 
    {
        cout << "Maaf, stok buku tersebut saat ini kosong. Silakan coba lagi nanti." << endl;
    } else 
    {
        books[nomorbuku - 1].stock--;
        cout <<"Nama: "<< peminjam.nama << endl;
        cout <<"NPM: "<< peminjam.NPM << endl;
        cout << "Buku berhasil dipinjam."<< endl;
        cout <<"Jumlah stok saat ini: " << books[nomorbuku - 1].stock << "." << endl;
    }
}

void pengembalianbuku(Book books[], int jumlahbuku) 
{
    int nomorbuku;
    cout << "Masukkan nomor buku yang ingin dikembalikan: ";
    cin >> nomorbuku;
    if (nomorbuku < 1 || nomorbuku > jumlahbuku)
    {
        cout << "Nomor buku yang Anda masukkan salah. Silakan coba lagi." << endl;
    } else 
    {
        books[nomorbuku - 1].stock++;
        cout << "Buku berhasil dikembalikan. Jumlah stok saat ini: " << books[nomorbuku - 1].stock << "." << endl;
    }
}

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
    if (login()) 
    {
        int menu, jumlahbuku = 0;
        bool ulang = true;
        Book books[100];
        while (ulang)
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "|       Selamat datang di menu manajemen perpustakaan       |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| Menu:                                                     |" << endl;
            cout << "| 1. Input buku                                             |" << endl;
            cout << "| 2. Daftar buku                                            |" << endl;
            cout << "| 3. Peminjaman                                             |" << endl;
            cout << "| 4. Pengembalian                                           |" << endl;
            cout << "| 5. Laporan                                                |" << endl;
            cout << "| 6. Exit                                                   |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "Menu yang anda pilih : ";
            cin >> menu;
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
                    cout << "Total stok buku saat ini: " << totalStock(books, jumlahbuku) << " buku" << endl;
                    break;
                case 6:
                    ulang = false;
                    break;
            }
        }
    }
    return 0;
}
