
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Array {
private:
    int* arr;
    int arrSize;
public:
    Array(int sz) {
        this->arrSize = sz;
        this->arr = new int[arrSize];
        for (int i = 0; i < arrSize; i++) {
            cin >> arr[i];
        }

    }

    void shift(int num) {
        for (int i = 0; i < num; i++) {
            int firstNum = arr[0];
            for (int j = 0; j < arrSize; j++) {
                arr[j - 1] = arr[j];
            }
   
            arr[arrSize - 1] = firstNum;
        }
    }


    void Switch(int i, int j) {
        int a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
    }

    void print() {
        for (int i = 0; i < arrSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int T, N = 0, i, s = 0;
    string str;
    cin >> T >> N;
    Array ar(N);


    while (T--) {
        cin >> str;
        if (str == "shift") {
            cin >> i;
            ar.shift(i);
        }
        else if (str == "switch") {
            cin >> i >> s;
            ar.Switch(i, s);
        }

        else if (str == "print") {
            ar.print();
        }
    }
    return 0;
}
