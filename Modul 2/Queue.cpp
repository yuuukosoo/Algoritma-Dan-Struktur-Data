#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20
using namespace std;

struct Struct{
    int front,back,size;
    int Q[MAX];
};

Struct queue;

int IsEmpty(){
    if (queue.front == queue.back){
        return 1;
    }
    else {
        return 0;
    } }

int IsFull(){
    if ((queue.back + 1) % queue.size == queue.front){
        return 1;
    }

    else{
        return 0;
    } }

void INSERT(int data){

    cout << " " << endl;
    
    if(IsFull() == 1){
        cout << "Queue Penuh" << endl;
    }

    else  {
        queue.Q[queue.back] = data;
        cout << "Data " << queue.Q[queue.back] << " Masuk Ke Queue" << endl;
        queue.back = ( queue.back + 1 ) % queue.size;
    }
}

void DELETE(){
    if(IsEmpty() == 1){
        cout << "Queue Kosong" << endl;
        
    }
    else {
        cout << "Data yang dihapus : " << queue.Q[queue.front] << endl;
        queue.front = (queue.front + 1) % queue.size;
    }
}


void CETAKLAYAR(){
    if(IsEmpty() == 0){
        int i = queue.front;
        while ( i != queue.back)
        {
            cout << "Queue ke " << i << " : " << queue.Q[i] << endl;
            i = ( i + 1 ) % queue.size;
        }
    }
    else { cout << "Queue Kosong" << endl;

    }
}

void Inisialisasi(){
    queue.front =0;
    queue.back = 0;
    queue.size = MAX;

}

void RESET(){
if(IsEmpty() == 1){
    cout << "Tidak Ada Data Queue Untuk Di Reset" << endl;

}
else {
    queue.back =0;
    queue.front = 0;
    cout << "Queue Telah Di Reset" << endl;
    }
}
int PIL;
char PILIHAN [2];

int main(){
    Inisialisasi();
    do{
        cout << "QUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : ";
        cin >> PILIHAN ;
        cout << " " << endl;
        PIL=atoi(PILIHAN);

        if(PIL <1 || PIL >5){
            cout <<"Input Anda Keliru" << endl;
        }

        else {
        switch (PIL)
        {
        case 1:
            int data;
            cout << "Masukkan Nilai Anda : ";
            cin >> data ;
            INSERT(data);
            break;
        
        case 2:
            DELETE();
            break;

        case 3:
            CETAKLAYAR();
            break;


        case 4:
            RESET();
            break;

        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
    }
        cout << " " << endl;
        cout << "press any key to continue" << endl;
        getch();
        system("cls");
    }
    while(PIL != 5);

    return 0;
}

