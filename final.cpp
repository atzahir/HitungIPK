#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#define max 10

using namespace std;

//Deklarasi Stack
stack <int> s;
stack <float> indeks;

//Struct
struct datanilai
{
	string kodeMK, namaMK;
	float ipk, ipmatkul, totalip = 0;
	int jumlahMK, sks, jumlahsks = 0;
	char predikat;
};

struct mahasiswa
{
	string nama, nim, prodi;
	struct datanilai nilai;
};


mahasiswa mhs[100];
int a, b, c, jml,temp;

// Deklarasi Fungsi 
void header();
void mainmenu();
void createDataMhs();
void showDataMhs();
void deleteDataMhs();
void searchDataMhs();
void about();
int HitungIPK (char x, int y);

// Main Program
int main(int argc, char const *argv[])
{
	mainmenu();
	return 0;
}

// Header Program
void header()
{
	cout<<"==========================================="<<endl;
	cout<<"|Kelompok 5                               |"<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"|              DATA MAHASISWA             |"<<endl;
	cout<<"|           DAN PERHITUNGAN IPK           |"<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"==========================================="<<endl;
	cout<<"|         >    Selamat Datang    <        |"<<endl;
	cout<<"==========================================="<<endl;
}

// Menu Utama
void mainmenu()
{
	int jml, pilih, jumlahMK, sks;
	string nim, nama, prodi, kodeMK,namaMK;
	menu:
	system("cls");
	header();

	cout<<endl;
	cout<<"1. Tambah Data"<<endl;
	cout<<"2. Hapus Data "<<endl;
	cout<<"3. Tampilkan Data"<<endl;
	cout<<"4. Cari Data"<<endl;
	cout<<"5. About"<<endl;
	cout<<"6. Exit"<<endl<<endl;

	cout<<"Pilihan : ";
	cin>>pilih;
	cout<<endl;

	switch (pilih)
	{
		case 1:
		createDataMhs();
		goto menu;
		break;

		case 2 : 
		deleteDataMhs();
		system("pause");
		break;

		case 3 :
		showDataMhs();
		system("pause");
		mainmenu();
		break;

		case 4 :
		searchDataMhs();
		system("pause");
		mainmenu();
		break;

		case 5:
		system("cls");
		header();
		about();
		system("pause");
		mainmenu();
		break;

		case 6:
		system("exit");
		break;


		default:
		cout<<"\nInput yang anda masukan salah"<<endl;
		system("pause");
		mainmenu();
		break;
	}
}


//Menambahkan Data Mahasiswa
void createDataMhs()
{
	cout<<"Masukkan jumlah data Mahasiswa yang ingin dimasukkan : ";
	cin>>jml;
	for (int i = 0; i < jml; ++i)
	{
		cout<<"\nData ke-"<<i+1<<endl;
		cout<<"Masukkan Nama  : ";
		getline(cin>>ws, mhs[a].nama);
		cout<<"Masukkan NIM   : ";
		cin>>mhs[a].nim;
		cout<<"Masukkan Prodi : ";
		getline(cin>>ws, mhs[a].prodi);
		cout<<"Masukkan Jumlah Mata Kuliah   : ";
		cin>>mhs[a].nilai.jumlahMK;
		for (int j = 0; j < mhs[a].nilai.jumlahMK; ++j)
		{
			cout<<"\nMata Kuliah ke-"<<j+1<<endl;
			cout<<"Masukkan Kode Mata Kuliah      : ";
			getline(cin>>ws, mhs[a].nilai.kodeMK);
			cout<<"Masukkan Nama Mata Kuliah      : ";
			getline(cin>>ws, mhs[a].nilai.namaMK);
			cout<<"Masukkan Sks                   : ";
			cin>>mhs[a].nilai.sks;
			s.push(mhs[a].nilai.sks);
			cout<<"Masukkan Predikat (A/B/C/D/E)  : ";
			cin>>mhs[a].nilai.predikat;
			indeks.push(mhs[a].nilai.predikat);
			mhs[a].nilai.ipmatkul = HitungIPK(mhs[a].nilai.predikat, mhs[a].nilai.sks);
			mhs[a].nilai.totalip += mhs[i].nilai.ipmatkul;
			mhs[a].nilai.jumlahsks = s.top() + mhs[a].nilai.jumlahsks;
			s.pop();
			indeks.pop();
		}
		mhs[a].nilai.ipk = mhs[a].nilai.totalip/mhs[a].nilai.jumlahsks;
		a++;

	}
}

// Menampilkan Data Mahasiswa yang telah diinputkan
void showDataMhs()
{
	int j=0;
	cout<<"Data IPK Mahasiswa"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"No."<<"\tNama"<<"\t\t\t\tNIM	"<<"\tProdi	"<<"\t\t\tJumlah SKS"<<"\tJumlah SKS x nilai"<<"\tIPK"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < a; ++i)
	{
		j=j+1;
		cout<<j<<"\t";
		cout<<mhs[i].nama<<"\t\t";
		cout<<mhs[i].nim<<"\t";
		cout<<mhs[i].prodi<<"\t\t";
		cout<<mhs[i].nilai.jumlahsks<<"\t\t\t";
		cout<<mhs[i].nilai.totalip<<"\t\t\t";
		cout<<mhs[i].nilai.ipk<<"\n";
	}
	cout<<"------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
}

// Hapus Data Mahasiswa yang telah diinputkan
void deleteDataMhs() 
{
	int w,x,y;
	char z;
	awal:
	showDataMhs();
	cout << "Hapus Data Mahasiswa No : ";
	cin >> x;

	y = x - 1;
	cout << "Data yang akan dihapus : " << endl;
	cout << "============================================================" << endl;
	cout << "Nama                  : " << mhs[y].nama << endl;
	cout << "NIM                   : " << mhs[y].nim << endl;
	cout << "Prodi                 : " << mhs[y].prodi << endl;
	cout << "Jumlah Sks 	         : " << mhs[y].nilai.jumlahsks << endl;
	cout << "Jumlah Sks x Nilai 	 : " << mhs[y].nilai.totalip << endl;
	cout << "IPK         	         : " << mhs[y].nilai.ipk << endl;
	cout << "============================================================" << endl;
	cout << "Yakin ingin hapus? (Y/N): ";
	cin >> z;

	yakin:
	if(z == 'y' || z == 'Y') {
		a--;
		for(int i = y; i < a; i++) {
			mhs[i] = mhs[i + 1];
		}
		cout << "Data Mahasiswa berhasil dihapus" << endl;
	}else if(z == 'n' || z == 'N') {
		mainmenu();
	}else {
		goto yakin;
	}

}

// Mencari Data Mahasiswa yang telah diinputkan
void searchDataMhs()
{
	string cari;
	int c, pilih;

	cout<<"\nCari Data mahasiswa berdasarkan : "<<endl;
	cout<<"1. Nama"<<endl;
	cout<<"2. NIM"<<endl;
	cout<<"Pilih : ";
	cin>>pilih;

	switch(pilih)
	{
		// Mencari berdasarkan nama
		case 1 : 
		cout<<"Masukkan nama dari Mahasiswa yang ingin dicari : ";
		cin>>cari;

		for (int i = 0; i < a; ++i)
		{
			if (cari == mhs[i].nama)
			{
				cout << "============================================================" << endl;
				cout << "Nama                   : " << mhs[i].nama << endl;
				cout << "NIM                    : " << mhs[i].nim << endl;
				cout << "Prodi                  : " << mhs[i].prodi << endl;
				cout << "Jumlah Sks             : " << mhs[i].nilai.jumlahsks << endl;
				cout << "Jumlah Sks x Nilai     : " << mhs[i].nilai.totalip << endl;
				cout << "IPK                   	: " << mhs[i].nilai.ipk << endl;
				cout << "============================================================" << endl;
			}
		}

		// Mencari berdasarkan NIM
		case 2 : 
		cout<<"Masukkan NIM dari Mahasiswa yang ingin dicari : ";
		cin>>cari;

		for (int i = 0; i < a; ++i)
		{
			if (cari == mhs[i].nim)
			{
				cout << "=========================================" << endl;
				cout << "Nama                   : " << mhs[i].nama << endl;
				cout << "NIM                    : " << mhs[i].nim << endl;
				cout << "Prodi                  : " << mhs[i].prodi << endl;
				cout << "Jumlah Sks             : " << mhs[i].nilai.jumlahsks << endl;
				cout << "Jumlah Sks x Nilai     : " << mhs[i].nilai.totalip << endl;
				cout << "IPK                   	: " << mhs[i].nilai.ipk << endl;
				cout << "=========================================" << endl;	
			}
		}

		default :
		cout<<"\nInput yang anda masukan salah"<<endl;
		system("pause");
		searchDataMhs();
		break;

	}
	system("pause");
	mainmenu();
}

void about()
{
	cout<<"\nProgram ini merupakan program untuk menampung data mahasiswa dan juga terdapat perhitungan ipk didalamnya"<<endl<<endl;

	cout<<"Tim Penyusun : "<<endl<<endl;
	cout<<"1. Akhmad Taajuddin Zahir                   19.11.3209 "<<endl;
	cout<<"2. Anna Caroline Arruan Banga               19.11.3193 "<<endl;
	cout<<"3. Ikhsan Arisyahdani                       19.11.3211 "<<endl;
	cout<<"4. Rangga Ihza Umayah                       19.11.3187 "<<endl;
	cout<<"5. Muhammad Fahmuddin                       19.11.3245 "<<endl;
	cout<<"6. Galih Waskito Utomo                      19.11.3232 "<<endl;
	cout<<"7. Yohan Wahid Subhan                       19.11.3212 "<<endl;
	cout<<"8. Fajar Bima Tri Jatmiko                   19.11.3207 "<<endl<<endl;
}

// Perhitungan nilai IPK
int HitungIPK (char x, int y)
{
	int ip;
	switch(x)
	{
		case 'A':
		ip=4*y;
		break;

		case 'a':
		ip=4*y;
		break;

		case 'B':
		ip=3*y;
		break;

		case 'b':
		ip=3*y;
		break;

		case 'C':
		ip=2*y;
		break;

		case 'c':
		ip=2*y;
		break;

		case 'D':
		ip=1*y;
		break;

		case 'd':
		ip=1*y;
		break;

		case 'E':
		ip=0*y;
		break;

		case 'e':
		ip=0*y;
		break;

		default:
		ip=0;
		break;
	}
	return ip;
}



