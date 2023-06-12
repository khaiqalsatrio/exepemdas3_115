#include <iostream>
using namespace std;

class bidangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar
public:
    bidangDatar() { // constructor
        x = 0;
    }
    virtual void input() {} // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    virtual float Luas(int a) { return 0; } // fungsi untuk menghitung luas
    virtual float Keliling(int a) { return 0; } // fungsi untuk menghitung keliling
    void setX(int a) { // fungsi untuk memberi/mengirim nilai pada x
        this->x = a;
    }
    int getX() { // fungsi untuk membaca/mengambil nilai dalam x
        return x;
    }
};

class Lingkaran : public bidangDatar {
public:
    void input() {
        cout << "Masukkan jejari: ";
        int r;
        cin >> r;
        setX(r);
    }
    float Luas(int r) {
        return 3.14 * r * r;
    }
    float Keliling(int r) {
        return 2 * 3.14 * r;
    }
};

class Bujursangkar : public bidangDatar {
public:
    void input() {
        cout << "Masukkan sisi: ";
        int s;
        cin >> s;
        setX(s);
    }
    float Luas(int s) {
        return s * s;
    }
    float Keliling(int s) {
        return 4 * s;
    }
};

int main() {
    bidangDatar* bd; // pointer untuk objek polymorphic
    Lingkaran lingkaran;
    Bujursangkar bujursangkar;

    // Lingkaran
    cout << "Lingkaran dibuat" << endl;
    lingkaran.input();
    bd = &lingkaran;
    cout << "Luas Lingkaran = " << bd->Luas(bd->getX()) << endl;
    cout << "Keliling Lingkaran = " << bd->Keliling(bd->getX()) << endl;

    // Bujursangkar
    cout << "Bujursangkar dibuat" << endl;
    bujursangkar.input();
    bd = &bujursangkar;
    cout << "Luas Bujursangkar = " << bd->Luas(bd->getX()) << endl;
    cout << "Keliling Bujursangkar = " << bd->Keliling(bd->getX()) << endl;

    return 0;
}
