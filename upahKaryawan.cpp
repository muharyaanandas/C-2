#include <iostream>
using namespace std;

struct perusahaan{
	string nama;
	int gol, jamkerja, upah, lembur, jamlembur, gajilembur, total;
};
struct minimal{
	string nama;
	int gol, jamkerja, upah, lembur, jamlembur, gajilembur, total;
};
struct maksimal{
	string nama;
	int gol, jamkerja, upah, lembur, jamlembur, gajilembur, total;
};

int jumlah;
perusahaan karyawan[10];

int main(){
	cout<<"+-----+-------------+-----------------+\n";
	cout<<"| GOL | Upah Harian | Upah Lembur/Jam |\n";
	cout<<"+-----+-------------+-----------------+\n";
	cout<<"|  1  |  Rp30000,-  |     Rp3000,-    |\n";
	cout<<"|  2  |  Rp40000,-  |     Rp4000,-    |\n";
	cout<<"|  3  |  Rp50000,-  |     Rp5000,-    |\n";
	cout<<"+-------------------------------------+\n\n";
	
	cout<<"PROGRAM MENGHITUNG TOTAL UPAH HARIAN\n";
	cout<<"Masukan Jumlah Karyawan : ";
	cin>>jumlah;
	cout<<endl;
	
	for(int i=0; i<jumlah; i++){
		cout<<"Karyawan ke-"<<i+1<<endl;
		cout<<"Masukkan Nama Karyawan    : ";
		cin>>karyawan[i].nama;
		cout<<"Masukkan Golongan [1-3]   : ";
		cin>>karyawan[i].gol;
		cout<<"Masukkan Jumlah Jam Kerja : ";
		cin>>karyawan[i].jamkerja;
		cout<<endl;
		
		switch (karyawan[i].gol){
			case 1:
    			karyawan[i].upah = 30000;
    			karyawan[i].lembur = 3000;
    			break;
			case 2:
				karyawan[i].upah = 40000;
				karyawan[i].lembur = 4000;
				break;
			case 3:
				karyawan[i].upah = 50000;
				karyawan[i].lembur = 5000;
				break;
			default :
				karyawan[i].upah = 0;
		}
		
		if(karyawan[i].jamkerja > 8){
			karyawan[i].jamlembur = karyawan[i].jamkerja - 8;
		}
		else{
			karyawan[i].jamlembur = 0;
		}
		
		karyawan[i].gajilembur = karyawan[i].lembur * karyawan[i].jamlembur;
		karyawan[i].total = karyawan[i].upah + karyawan[i].gajilembur;
	}
	
	cout<<"TOTAL UPAH HARIAN KARYAWAN\n\n";
	for(int i=0; i<jumlah; i++){
		cout<<"Karyawan ke-"<<i+1<<endl;
		cout<<"Nama Karyawan : "<<karyawan[i].nama<<endl;
		cout<<"Golongan      : "<<karyawan[i].gol<<endl;
		cout<<"Total Upah    : Rp"<<karyawan[i].total<<",-"<<endl<<endl;
	}
	
	maksimal maks;
	maks.nama = karyawan[0].nama;
	maks.gol = karyawan[0].gol;
	maks.total = karyawan[0].total;
	
	minimal min;
	min.nama = karyawan[0].nama;
	min.gol = karyawan[0].gol;
	min.total = karyawan[0].total;
	
	for(int i=0; i<jumlah; i++){
		if(maks.total < karyawan[i].total){
			maks.nama = karyawan[i].nama;
			maks.gol = karyawan[i].gol;
			maks.total = karyawan[i].total;
		}
		if(min.total > karyawan[i].total){
			min.nama = karyawan[i].nama;
			min.gol = karyawan[i].gol;
			min.total = karyawan[i].total;
		}
	}
	
	cout<<"\nUPAH HARIAN KARYAWAN TERBESAR\n";
	cout<<"Nama Karyawan : "<<maks.nama<<endl;
	cout<<"Golongan      : "<<maks.gol<<endl;
	cout<<"Total Upah    : Rp"<<maks.total<<",-"<<endl;
	
	cout<<"\nUPAH HARIAN KARYAWAN TERKECIL\n";
	cout<<"Nama Karyawan : "<<min.nama<<endl;
	cout<<"Golongan      : "<<min.gol<<endl;
	cout<<"Total Upah    : Rp"<<min.total<<",-"<<endl;
}