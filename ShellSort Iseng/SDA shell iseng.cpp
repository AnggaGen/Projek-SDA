#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Fungsi untuk melakukan Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();

    // Mulai dengan jarak maksimum
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Lakukan insertion sort untuk setiap gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Pindahkan elemen di sebelah kiri yang lebih besar dari temp ke posisi di depannya
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // Masukkan temp ke posisi yang tepat
            arr[j] = temp;
        }
    }
}

// Fungsi untuk menampilkan elemen array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Masukkan Data Yang Ingin Diurutkan: ";
    getline(cin, input);

    vector<int> arr;
    stringstream ss(input);
    int temp;
    while (ss >> temp) {
        arr.push_back(temp);
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr);

    shellSort(arr);

    cout << "Array setelah diurutkan: ";
    printArray(arr);

    return 0;
}