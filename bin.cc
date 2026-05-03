#include<iostream>
#include<string>
using namespace std;

class Mobil {
    public :
        string merk;
        int kecepatan;

        void nyalakanmesin() {
            cout << merk << " Menyalakan mesin." << endl;
        }
};

int main() {
    Mobil mobilsaya;
    mobilsaya.merk = "toyota";
    mobilsaya.kecepatan = 0;
    mobilsaya.nyalakanmesin();
    return 0;
}
// int globalVar = 10;

// void printGlobal() {
//     cout << "Fungsi global :" << globalVar << endl; 
// }

// int main() { 
//     cout << "Global var : (dalam main function)" << globalVar << endl;
//     printGlobal();
//     return 0;
// }
