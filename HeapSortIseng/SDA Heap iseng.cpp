#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk melakukan pertukaran elemen pada posisi i dan j
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk mengubah array menjadi heap maksimum
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Menginisialisasi largest sebagai root
    int left = 2 * i + 1; // Kiri = 2*i + 1
    int right = 2 * i + 2; // Kanan = 2*i + 2

    // Jika anak kiri lebih besar dari root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Jika anak kanan lebih besar dari root
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Jika largest bukan root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Rekursif memanggil heapify pada subtree yang diubah
        heapify(arr, n, largest);
    }
}

// Fungsi untuk melakukan Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Membangun heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Ekstrak elemen satu per satu dari heap
    for (int i = n - 1; i > 0; i--) {
        // Pindahkan root ke akhir
        swap(arr[0], arr[i]);
        // Panggil heapify pada heap yang berkurang
        heapify(arr, i, 0);
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
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array sebelum diurutkan: ";
    printArray(arr);

    heapSort(arr);

    cout << "Array setelah diurutkan: ";
    printArray(arr);

    return 0;
}