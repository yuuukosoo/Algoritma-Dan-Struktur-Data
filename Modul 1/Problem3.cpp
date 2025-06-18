#include<iostream>
#include<string>
using namespace std;

struct keyword{
    string huruf;
    string kata;
    int angka;
};

int main(){
    keyword kode;

    cout << "Masukkan sebuah huruf = " ;
    cin >> kode.huruf;

    cout << "Masukkan sebuah kata = " ;
    cin >> kode.kata;

    cout << "Masukkan Angka = " ;
    cin >> kode.angka;

    cout << "Huruf yang Anda masukkan adalah " << kode.huruf << endl;
    cout << "Kata yang Anda masukkan adalah " << kode.kata << endl;
    cout << "Angka yang anda masukkan adalah " << kode.angka << endl;

    return 0;
}