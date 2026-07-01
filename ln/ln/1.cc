#include<iostream>
using namespace std;

int main() {
    int angka = 10;
    cout << "R num : " << angka << endl;

    auto byVal = [=]() {
        cout << "In lamba [=] : " << angka << endl;
    };

    auto byRef = [&]() {
        cout << "In lamda [&] : " << angka << endl;
    };

    angka = 50;
    cout << "after : " << angka << endl;

    byVal();
    byRef();
    
    auto sum = [&]() {
        angka += 100;
    };

    sum();
    cout << "after change number with reference : " << angka << endl;

    const auto rebol = [angka](int y) {
        return 10 * 10 + y;
    }(5);

    cout << "rebol value : " << rebol << endl;

    auto kalku = [a = 100](int tambah) mutable constexpr noexcept -> int{
        a += tambah;
        return a * 2;
    };



    return 0;
}