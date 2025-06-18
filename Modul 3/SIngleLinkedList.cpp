#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct TNode {
    string data;
    TNode *next;
};

TNode *head, *tail;

void init(){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(head==NULL){
        return 1;
    }
    else return 0;}

void tambahDepan(){
    string databaru;
    cout <<"Masukkan Data : ";
    cin>>databaru;

    TNode *baru = new TNode;
    baru->data = databaru;
    

    if(isEmpty()==1){
        head = baru;
        tail = baru;
        tail->next = head;
    }

    else{
        baru->next = head;
        head = baru;
        tail ->next = head;
    }
    cout << "Data \"" << databaru <<
    "\" berhasil dimasukkan di bagian depan." << endl;
    
}

void tambahBelakang(){
    string databaru;
    cout<<"Masukkan data :";
    cin >> databaru;
    
    TNode*baru = new TNode;
    baru->data = databaru;
    baru->next = NULL;

    if(isEmpty()==1){
        head=baru;
        tail=baru;
        tail->next = head;
    }
    else{
        tail->next = baru;
        tail = baru;
        baru->next=head;
    }
    cout << "Data \"" << databaru << 
    "\"  berhasil dimasukkan di bagian belakang." << endl;
}

void hapusdepan(){
    if(isEmpty()==0){
        TNode *hapus = head;
        string data = hapus->data;

        if(head == tail ){
            init();
        }
        else{
            head=head->next;
            tail->next = head;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di depan telah berhasil dihapus." << endl;
    }
    else cout<<"Tidak terdapat data pada Linked List." << endl; 
}

void hapusbelakang(){
    if(isEmpty()==0){
        TNode*hapus=tail;
        string data = hapus->data;

        if(head==tail){
            init();
        }
        
        else{
        TNode *bantu = head;
        while(bantu->next != tail){
            bantu=bantu->next;
        }
        tail = bantu;
        tail->next = head;
        }
        delete hapus;
        cout << "Data \"" << data << "\" yang berada di belakang telah berhasil dihapus." << endl;
    }
    else cout<<"Tidak terdapat data pada Linked List." << endl;
}

void tampilkan(){
    if(isEmpty() == 0){

        TNode*bantu=head;
        do{
            cout <<bantu->data << " ";
            bantu = bantu->next;
        } while (bantu != head);
        cout << endl;
    }
    else cout <<"Tidak terdapat data pada Linked List." << endl;
}

void reset(){
    if(isEmpty() == 0){
        TNode *bantu=head;

        do{
            TNode *hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        } while(bantu!=head);

    init();    
    cout << "Semua data telah dihapus.\n";
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void cariData(){
    if(isEmpty()==0){
    string cari;
    cout <<"Masukkan data yang ingin dicari : ";
    cin >> cari;

    bool pencarian = false;
        TNode *bantu = head;
        cout << "Linked List: ";
        do {
            if (bantu->data == cari) {
                cout << "[" << bantu->data << "] ";
                pencarian = true;
            } else {
                cout << bantu->data << " ";
            }
            bantu = bantu->next;
        } while (bantu != head);

        cout << endl;

        if (!pencarian)
            cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    } else cout << "Tidak terdapat data pada Linked List." << endl;
}

void hapusdata(){
    if (!isEmpty()) {
        string cari;
        cout << "Masukkan data yang ingin dihapus: "; cin >> cari;

        bool Pencarian = false;
        TNode *bantu = head;
        TNode *sebelum = tail;

        do {
            if (bantu->data == cari) {
                Pencarian = true;
                if (bantu == head) {
                    hapusdepan();
                    bantu = head;
                    sebelum = tail;
                } else if (bantu == tail) {
                    hapusbelakang();
                    bantu = head;
                    sebelum = tail;
                } else {
                    sebelum->next = bantu->next;
                    delete bantu;
                    bantu = sebelum->next;
                }
            } else {
                sebelum = bantu;
                bantu = bantu->next;
            }
        } while (bantu != head);

        if (Pencarian) cout << "Setiap data \"" << cari << "\" telah dihapus dari Linked List." << endl;
        else cout << "Data \"" << cari << "\" tidak ditemukan pada Linked List." << endl;
    }   else cout << "Tidak terdapat data pada Linked List." << endl;
}

void sisipkanSebelum(){
    if(isEmpty()==0){
        string  nextdata, databaru;
        cout << "Sisipkan data baru sebelum data: ";
        cin >> nextdata;

        TNode *bantu = head;
        TNode *sebelum = tail;
        bool pencarian = false;

        do{
            if(bantu->data == nextdata){
                pencarian = true;
                break;
            }
            sebelum = bantu;
            bantu = bantu->next;
        } while(bantu != head);

        if(pencarian){
            cout << "Masukkan data yang ingin ditambahkan :";
            cin >> databaru;

            TNode *baru= new TNode;
            baru->data= databaru;
            baru->next = bantu;
            sebelum->next= baru;

            if (bantu == head){
                head = baru;
            }
                cout << "Data \"" << databaru << "\" berhasil disisipkan sebelum \"" << nextdata << "\"." << endl;
        
            } else{
                cout<<"Tidak terdapat data \"" <<nextdata<<"\" pada Linked List."<<endl;
            }
        } else {
            cout << "Tidak terdapat data pada Linked List." << endl;
         } 
        }
    
void sisipkanSetelah(){
if (isEmpty()==0) {
    string prevData, dataBaru;
    cout << "Sisipkan data baru setelah data: ";
    cin >> prevData;

    TNode *bantu = head;
    bool pencarian = false;

    do {
        if (bantu->data == prevData) {
            pencarian = true;
            break;
        }
        bantu = bantu->next;
    } while (bantu != head);

    if (pencarian) {
        cout << "Masukkan data yang ingin ditambahkan: "; cin >> dataBaru;

        TNode *baru = new TNode;
        baru->data = dataBaru;
        baru->next = bantu->next;
        bantu->next = baru;

        if (bantu == tail) {
            tail = baru;
        }

        cout << "Data \"" << dataBaru << "\" berhasil disisipkan setelah \"" << prevData << "\"." << endl;
    } else cout << "Data \"" << prevData << "\" tidak ditemukan dalam Linked List." << endl;
} else cout << "Tidak terdapat data pada Linked List." << endl;
}
int main(){
    init();
    int pilihan;

    do{
        cout <<"Single Linked List Circular (SLLC)" << endl;
        cout <<"==============================" << endl;
        cout <<"1. Tambah Depan" << endl;
        cout <<"2. Tambah Belakang" << endl;
        cout <<"3. Hapus Depan" << endl;
        cout <<"4. Hapus Belakang" << endl;
        cout <<"5. Tampilkan Data" << endl;
        cout <<"6. Hapus Semua Elemen" << endl;
        cout <<"7. Cari Data" << endl;
        cout <<"8. Hapus Setiap Data Tertntu" << endl;
        cout <<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu" << endl;
        cout <<"10. Sisipkan Node/Data Baru Setelah Data Tertentu" << endl;
        cout <<"11. Quit" << endl;
        cout <<"Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
        tambahDepan(); 
        break;

        case 2:
        tambahBelakang();
        break;

        case 3:
        hapusdepan();
        break;

        case 4:
        hapusbelakang();
        break;
        
        case 5:
        tampilkan();
        break;

        case 6:
        reset();
        break;

        case 7:
        cariData();
        break;

        case 8:
        hapusdata();
        break;

        case 9:
        sisipkanSebelum();
        break;

        case 10:
        sisipkanSetelah();
        break;

        
        default:
            cout <<"\nTERIMA KASIH" << endl;
            cout <<"Program was made by Muhammad Naufal Khalish (2410817110004)" << endl;
        }

        cout <<"\nPress any key to continue!" <<endl;
        getch();
        system("cls");

    } while(pilihan != 11);

    return 0;
}