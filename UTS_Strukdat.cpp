#include <iostream>
#include <string>
using namespace std;

struct Service {
    string Nama;
    string Layanan;
    Service* next;
};
class ListService {
private:
    Service* head;
public:
    ListService() {
        head = nullptr;
    }
    void TambahService(string Nama, string Layanan) {
        Service* newService = new Service;
        newService->Nama = Nama;
        newService->Layanan = Layanan;
        newService->next = head;
        head = newService;
    }

    void DaftarService() {
        Service* current = head;
        if (current == nullptr) {
            cout << "Tidak ada Service yang tersedia." << endl;
            return;
        }
        cout << "Daftar Service:" << endl;
        while (current != nullptr) {
            cout << "Nama: " << current->Nama << ", Layanan: " << current->Layanan << endl;
            current = current->next;
        }
    }

    void HapusService(string Nama) {
        Service* current = head;
        Service* prev = nullptr;
        while (current != nullptr) {
            if (current->Nama == Nama) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Service atas nama " << Nama << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Service atas nama " << Nama << " tidak ditemukan." << endl;
    }
    
    void EditService(string Nama, string LayananBaru[]) {
        Service* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->Nama == Nama) {
                for (int i = 0; i < 1; i++) { 
                    current->Layanan = LayananBaru[i]; 
                    cout << "Layanan atas nama " << Nama << " telah diubah menjadi " << LayananBaru[i] << "." << endl;
                }
                found = true;
                return;
            }
            current = current->next;
        }
        if (!found)
            cout << "Service atas nama " << Nama << " tidak ditemukan." << endl;
    }
};

int main() {
    ListService listService;
    int choice;
    string Nama;
    string LayananBaru[1];
    do {
            cout << "-------------------------------------------------------------" << endl;
            cout << "|           Selamat datang di menu layanan bengkel          |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| Menu:                                                     |" << endl;
            cout << "| 1. Input Service                                          |" << endl;
            cout << "| 2. Daftar Service                                         |" << endl;
            cout << "| 3. Edit Service                                           |" << endl;
            cout << "| 4. Hapus Service                                          |" << endl;
            cout << "| 5. Exit                                                   |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "Menu yang anda pilih : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan Nama service: ";
                cin.ignore();
                getline(cin, Nama);
                cout << "Masukkan Layanan service: ";
                getline(cin, LayananBaru[0]);
                listService.TambahService(Nama, LayananBaru[0]);
                break;
            case 2:
                listService.DaftarService();
                break;
            case 3:
                cout << "Masukkan Nama service yang ingin diubah: ";
                cin.ignore();
                getline(cin, Nama);
                cout << "Masukkan Layanan service baru: ";
                for (int i = 0; i < 1; i++) {
                    getline(cin, LayananBaru[i]);
                }
                listService.EditService(Nama, LayananBaru);
                break;
            case 4:
                cout << "Masukkan Nama service yang ingin dihapus: ";
                cin.ignore();
                getline(cin, Nama);
                listService.HapusService(Nama);
                break;
            case 5:
                cout << "Program selesai. Terima kasih.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
  