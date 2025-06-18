#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> indices;

    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) indices.push_back(i);
    }
    if (indices.empty()) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else {
        cout << "Angka " << target << " terdapat pada array sebanyak " << indices.size() << " Kali" << endl;
        cout << "Angka " << target << " ditemukan pada indeks: ";
        for (auto i = 0; i < indices.size(); i++){
            cout << indices[i];
            if (i != indices.size() - 1) cout << ", ";
        }
        cout << "." << endl;
    }  }

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (index == -1) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << index << endl; 
}


void clearScreen(){
    system("cls");
}


void explain(){
    cout << "\nPENJELASAN\n\n";

    cout << "1. Sequential Searching:\n";
    cout << "- Pencarian dilakukan dengan memeriksa setiap elemen dari awal hingga akhir.\n";
    cout << "- Tidak perlu data dalam keadaan terurut.\n";
    cout << "- Waktu pencarian cenderung lebih lama pada data yang besar.\n";
    cout << "- Contoh kasus: mencari nama siswa dalam daftar kehadiran yang acak.\n\n";

    cout << "2. Binary Searching:\n";
    cout << "- Pencarian dilakukan dengan membagi data menjadi dua secara berulang.\n";
    cout << "- Data harus dalam keadaan terurut terlebih dahulu.\n";
    cout << "- Lebih efisien karena mengurangi separuh data setiap langkah.\n";
    cout << "- Contoh kasus: mencari nomor halaman dalam daftar isi buku.\n\n";

    cout << "Kesimpulan:\n";
    cout << "- Gunakan Sequential Search jika data tidak terurut atau ukurannya kecil.\n";
    cout << "- Gunakan Binary Search jika data sudah terurut dan ingin efisiensi tinggi.\n";
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = (dist(rng));
                }
                     for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
             }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;
                if (size < 1){
                cout << "Error: Mohon masukkan bilangan di atas 0" << endl;
                break; }

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }
                
                sort(nums.begin(), nums.end());

                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by Muhammad Naufal Khalish (2410817110004)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}