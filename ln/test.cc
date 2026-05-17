#include <bits/stdc++.h>
using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int,int> pii;


// class RekeningBank {
//     private :
//         string namaPemilik;
//         string nomorRekening;
//         double saldo;


//     public:
//         RekeningBank(string nama,string noRek,double saldoAwal) {
//             namaPemilik = nama;
//             nomorRekening = noRek;
//             saldo = saldoAwal;
//             cout << "[SISTEM] Rekening atas nama " << namaPemilik << " berhasil dibuat.\n";
//         }


//         ~RekeningBank() {
//             cout << "[SISTEM] Rekening atas nama : " << namaPemilik << " berhasil dibuat " << "\n";
//         }

//         void setorUang(double jumlah) {
//             if (jumlah > 0) {
//                 saldo += jumlah;
//                 cout << namaPemilik << " Menyetor Rp " << jumlah << ". Saldo rekening : Rp " << saldo << "\n";
//             } else {
//                 cout << "setoran anda gagal,jumlah tidak valid.\n";
//             }
//         }

//         void tarikUang(double jumlah) {
//             if (jumlah > 0 && jumlah <= saldo) {
//                 saldo -= jumlah;
//                 cout << namaPemilik << " Menarik Rp " << jumlah << ". Saldo rekening sekarang : Rp " << saldo << "\n";
//             }else {
//                 cout << " Penarikan gagal! saldo " << namaPemilik << " tidak cukup.\n";
//             }
//         }


        
// };

class Musuh {
    public:

        virtual void serang() {
            cout << "MUSUH MENYERANG!!" << endl;
        }
};

class Boss : public Musuh {
    public : 

        void serang() override {
            cout << "BOS MENYERANG DENGAN MEGACUM!!!" << endl;
        }
};


int main() {
  Musuh* m = new Boss();
  m->serang();
  delete m;
}