#include<bits/stdc++.h>
using namespace std;

class SistemRestoran{
private:
    stack<string> tumpukanPiring;
    queue<string> antreanReguler;
    deque<string> antreanVIP;

public:
void cuciPiring(string idPiring){
    tumpukanPiring.push(idPiring);
}

string ambilPiring(){
   if(tumpukanPiring.empty()){
    return "kosong";
   }
   string piring = tumpukanPiring.top();
   tumpukanPiring.pop();
   return piring;
}

//QUEUE
void tambahAntreanReguler(string nama){
    antreanReguler.push(nama);
}

string layaniReguler(){
    while(!antreanReguler.empty()){
        string nama = antreanReguler.front();
        antreanReguler.pop();
        return nama;
    }
    return "kosong";
}

//deque
void tambahVIPNormal(string nama){
    antreanVIP.push_back(nama);
}

void tambahVIPPrioritas(string nama){
    antreanVIP.push_front(nama);
}

string layaniVIP(){
    //TODO : Layanin VIP yang berada paling depan di antrean
    while(!antreanVIP.empty()){
        string nama = antreanVIP.front();
        antreanVIP.pop_front();
        return nama;
    }
    return "kosong";
}

string VIPBatalAntre(){
    if(antreanVIP.empty()){
        return "Kosong";
    }
    string namaBatal = antreanVIP.back();
    antreanVIP.pop_back();
    return namaBatal;
}

};
int main(){
    SistemRestoran restoran;
    cout << "--- STACK ---" << endl;
     restoran.cuciPiring("P-01");
    restoran.cuciPiring("P-02");
    cout << "Ambil piring: " << restoran.ambilPiring() << " (Ekspektasi: P-02)" << endl;

    cout << "\n--- TES QUEUE ---" << endl;
    restoran.tambahAntreanReguler("Andi");
    restoran.tambahAntreanReguler("Budi");
    cout << "Layani Reguler: " << restoran.layaniReguler() << " (Ekspektasi: Andi)" << endl;

    cout << "\n--- TES DEQUE ---" << endl;
    restoran.tambahVIPNormal("Pak RT");
    restoran.tambahVIPNormal("Bu Lurah");
    restoran.tambahVIPPrioritas("Sultan Andara"); // Nyerobot ke depan!
    
    cout << "Layani VIP: " << restoran.layaniVIP() << " (Ekspektasi: Sultan Andara)" << endl;
    cout << "VIP Batal: " << restoran.VIPBatalAntre() << " (Ekspektasi: Bu Lurah)" << endl;
    cout << "Layani VIP sisa: " << restoran.layaniVIP() << " (Ekspektasi: Pak RT)" << endl;

    return 0;

    // for(int i = 1;i < N;++i){
    //     a.push(i);
    // }cout << "Done pushing the element onto the queue " << endl;

    // cout  << "Size : " << a.size() << endl;
    // cout << "Front : " << a.front() << endl;
    // cout <<"Back :" << a.back() << endl;
    // if (!a.empty()){
    //     cout << "Queue's Size is not null!!" << endl;
    // }

//    deque<int> b;
//    int f;
//    int bk;
//    cin >> f >> bk;
//     for(int i = 1;i < f;++i){
//         b.push_front(i);
//     }
//     cout << "Enter bk : ";
//     for(int j = 1;j < bk;++j){
//         b.push_back(j);
//     }
//     cout << "the deque's size : " << b.size() << endl;
//     b.pop_back();
//     b.pop_front();
//     cout << "the size after pop from front and back : " << b.size() << endl;
//     cout << "index 1 : "<< b[1] << endl;
//     cout << "index 1 using at function : " << b.at(1) << endl;
//     if(!b.empty()){
//         cout << "does not empty!" << endl;
//     }

}
