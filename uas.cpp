#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float hitungX(int SigmaX[], int j) // Hitung SigmaX
{
    float jumlah = 0;
    int i = 0;
    while(i < j){
        jumlah += SigmaX[i];
        i++;
    }
    return jumlah;
}

float hitungY(int SigmaY[], int j) // Hitung sigmaY
{
    float jumlah = 0;
    int i = 0;
    while(i < j){
        jumlah += SigmaY[i];
        i++;
    }
    return jumlah;
}

float hitungXY(int SigmaXY1[], int SigmaXY2[], int j) // Hitung Perkalian SigmaX dan Sigma Y
{
    float jumlah = 0;
    int i = 0;
    while(i < j){
        jumlah += SigmaXY1[i] * SigmaXY2[i];
        i++;
    }
    return jumlah;
}

float hitungX2(int SigmaX2[], int j) // Hitung Sigma X kuadrat
{
    float jumlah = 0, jumlah2 = 0;
    int i = 0;
    while(i < j){
        jumlah += pow(SigmaX2[i],2);
        i++;
    }
    jumlah2 += jumlah;
    return jumlah2;
}

float hitungY2(int SigmaY2[], int j) // Hitung Sigma Y kuadrat
{
    float jumlah = 0;
    int i = 0;
    while(i < j){
        jumlah += pow(SigmaY2[i],2);
        i++;
    }
    return jumlah;
}

float hasill(int hitung1, int hitung2, int hitung3, int hitung4, float hitung5, int j){
    float korelasipearson;
    korelasipearson = (j * hitung3 - hitung1 * hitung2) / sqrt((j * hitung4 - hitung1 * hitung1)* (j * hitung5 - hitung2 * hitung2));
    return korelasipearson;
}

float hasill2(int korelasi){
    float KoefisienDeterminasi;
    KoefisienDeterminasi = (korelasi * korelasi) * (100 / 100);
    return KoefisienDeterminasi;
}
int main(){
    int input1[100],input2[100],n,i;
    float hasilx,hasily,hasilxy,hasilx2,hasily2,hasil1,hasil2;
    system("cls");
    cout << "-------------------------------------------" << endl;
    cout << "     MENGHITUNG RUMUS KORELASI PEARSON" << endl;
	cout << "-------------------------------------------" << endl;
    cout<<"Masukkan Jumlah Data X dan Y: ";
	cin >> n;
	cout << "-------------------------------------------" << endl;
    i = 0;
    while(i < n){
        cout<<"Masukkan data X ke-"<< i+1 << " : ";cin >> input1[i];
        if (input1[i] < 0){
            cout << "Masukkan data x ke-" << i+1 << ": ";
            cin >> input1[i];
        }
        cout<<"Masukkan data y ke-"<< i+1 << " : ";cin >> input2[i];
        if (input2[i] < 0){
            cout << "Masukkan data y ke-" << i+1 << ": ";
            cin >> input2[i];
        }
        i++;
    }

    hasilx = hitungX(input1, n);
    hasily = hitungY(input2, n);
    hasilxy = hitungXY(input1, input2,n);
    hasilx2 = hitungX2(input1,n);
    hasily2 = hitungY2(input2,n);
    hasil1 = hasill(hasilx, hasily,hasilxy,hasilx2,hasily2,n);
    hasil2 = hasill2(hasil1);
	cout << "-------------------------------------------" << endl;
    cout << "Hasil Sigma X  : " << hasilx << endl;
    cout << "Hasil Sigma Y : " << hasily << endl;
    cout << "Hasil Perkalian Sigma X dan Sigma Y : " << hasilxy << endl;
    cout << "Hasil Sigma X kuadrat : " << setprecision(3) << hasilx2 << endl;
    cout << "Hasil Sigma Y kuadrat : " << setprecision(3) << hasily2 << endl;
    cout << "Hasil Korelasi (r) : " << setprecision(2) << hasil1 << endl;
    cout << "-------------------------------------------" << endl;
    if (hasil1 >= 0 && hasil1 <= 0,9) {
        cout << "Hubungan korelasinya diabaikan" << endl;
    }
    else if (hasil1 >= 0,10 && hasil1 <= 0,29) {
        cout << "Hubungan korelasi rendah" << endl;
    }
    else if (hasil1 >= 0,30 && hasil1 <= 0,49) {
        cout << "Hubungan korelasi moderat" << endl;
    }
    else if (hasil1 >= 0,50 && hasil1 <= 0,70) {
        cout << "Hubungan korelasi sedang" << endl;
    }
    else if (hasil1 >= 0,70) {
        cout << "Hubungan korelasi sangat kuat" << endl;
    }

    if (hasil1 > 0){
        cout << "Hubungan antara variable X dan Y adalah positif, dimana jika nilai X bertambah, maka nilai Y pun akan bertambah, dan juga sebaliknya" << endl;
    }
    else if (hasil1 < 0){
        cout << "Hubungan antara variable X dan Y adalah negatif, dimana jika nilai X bertambah, maka nilai Y akan mengecil, dan juga sebaliknya" << endl;
    }
    else if (hasil1 == 0){
        cout << "Tidak ada hubungan antara variable X dan Y" << endl;
    }
    cout << "-------------------------------------------" << endl;
    cout << "Hasil Koefisien Determinasi : " << setprecision(2) << hasill2 << endl;

    return 0;
}