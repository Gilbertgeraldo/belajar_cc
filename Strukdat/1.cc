#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

class Student {
    public:
        int grade;

    Student(int grade) {
        this->grade = grade;
        cout << "Constructor called : " << grade << endl;
    }

    Student(const Student &student) {
        this->grade = student.grade;
        cout << "Copy constructer called : " << this->grade;
        cout << endl;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> x;
    x.push(4);
    x.push(5);
    x.push(6);


    queue<int> y;
    y.push(5);
    y.push(4);
    y.push(6);

if (x != y) cout << " x != y " << endl;

queue<Student> classroom;
Student joe(90);

classroom.push(joe);
    return 0;
}