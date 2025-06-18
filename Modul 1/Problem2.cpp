#include<iostream>
#include<string>
using namespace std;

struct kendaraan{
    string plat;
    string jenis;
    string pemilik;
    string alamat;
    string kota;
};

int main(){
kendaraan profil={
    "DA1234MK",
    "RUSH",
    "Andika Hartanto",
    "Jl.Kayu Tangi",
    "Kota Banjarmasin"
};
cout << "Plat Nomor Kendaraan : "<< profil.plat << endl;
cout << "Jenis Kendaraan : "<< profil.jenis << endl;
cout << "Nama Pemilik : "<< profil.pemilik << endl;
cout << "Alamat : " << profil.alamat << endl;
cout << "Kota : " << profil.kota << endl;

    return 0;
}