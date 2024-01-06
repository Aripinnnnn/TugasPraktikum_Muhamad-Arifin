#include <iostream>
using namespace std;
int main ()
{
    // Deklarasi variabel
    int GajiPokok,GajiBersih;
    float Pajak,Tunjangan;
    string nama;
    do {
    // input nama dan gaji pokok
       cout << "-------------------------------------\n";
    cout << "| Masukkan Nama karyawan  : ";
    cin >> nama;
    cout << "| Masukkan Jumlah Gaji Pokok (RP): ";
    cin >> GajiPokok;
    cout << "-------------------------------------\n";
    }
    //Ulangi input jika user memasukkan gaji dibawah 100000
    while(GajiPokok <= 100000);
    //Jika gaji pokok lebih dari 5 juta maka akan diberi kondisi ini
    if (GajiPokok > 500000){
        Tunjangan = 0.2 * GajiPokok;
        Pajak = 0.15 * (GajiPokok + Tunjangan);
    }  
    //Jika gaji pokok lebih kecil dari 5 juta akan diberikan kondisi ini    
    else {
        Tunjangan = 0.1 * GajiPokok;
        Pajak = 0.05 * (GajiPokok + Tunjangan);
    }
    //Rumus gaji bersih
    GajiBersih = GajiPokok + Tunjangan - Pajak;
    //Output yang keluar
    cout <<"Nama :"<<nama<<endl;
    cout << "Gaji bersih :"<<GajiBersih;
    return 0;
}