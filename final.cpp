#include <iostream>
#include <conio.h>
#include <string>
#include <stack>
#define max 10

using namespace std;

stack <int> s;
stack <float> indeks;

struct datanilai
{
	string kodeMK, namaMK;
	float ipk, ipp, ippp = 0;
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

void mainmenu();
void header();
void showDataMhs();
void deleteDataMhs();
void searchDataMhs();
int HitungIPK (char x, int y);


int main(int argc, char const *argv[])
{
	mainmenu();
	getch();
	return 0;
}

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
	cout<<"5. Exit"<<endl<<endl;

	cout<<"Pilihan : ";
	cin>>pilih;
	cout<<endl;

	switch (pilih)
	{
		case 1:
		cout<<"Masukkan jumlah data yang ingin dimasukkan : ";
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
				mhs[a].nilai.ipp = HitungIPK(mhs[a].nilai.predikat, mhs[a].nilai.sks);
				mhs[a].nilai.ippp += mhs[i].nilai.ipp;
				mhs[a].nilai.jumlahsks = s.top() + mhs[a].nilai.jumlahsks;
				s.pop();
				indeks.pop();
			}
			mhs[a].nilai.ipk = mhs[a].nilai.ippp/mhs[a].nilai.jumlahsks;
			a++;

		}
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
		system("exit");
		break;
	}
}


void header()
{
	cout<<"==========================================="<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"|         MENGHITUNG IPK MAHASISWA        |"<<endl;
	cout<<"|                                         |"<<endl;
	cout<<"==========================================="<<endl;
	cout<<"|         >    Selamat Datang    <        |"<<endl;
	cout<<"==========================================="<<endl;
}

void showDataMhs()
{
	int j=0;
	cout<<"Data IPK Mahasiswa"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\tNo."<<"\tNama"<<"\t\tNIM	"<<"\tProdi	"<<"\t\tJumlah SKS"<<"\tJumlah SKS x nilai"<<"\tIPK"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < a; ++i)
	{
		j=j+1;
		cout<<"\t"<<j<<"\t";
		cout<<mhs[i].nama<<"\t\t";
		cout<<mhs[i].nim<<"\t";
		cout<<mhs[i].prodi<<"\t\t";
		cout<<mhs[i].nilai.jumlahsks<<"\t\t";
		cout<<mhs[i].nilai.ippp<<"\t\t\t";
		cout<<mhs[i].nilai.ipk<<"\n";
	}
	cout<<"-----------------------------------------------------------------------------------------------------------------------"<<endl;
}

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
	cout << "=========================================" << endl;
	cout << "Nama                  : " << mhs[y].nama << endl;
	cout << "NIM                   : " << mhs[y].nim << endl;
	cout << "Prodi                 : " << mhs[y].prodi << endl;
	cout << "Jumlah Sks 	         : " << mhs[y].nilai.jumlahsks << endl;
	cout << "Jumlah Sks x Nilai 	 : " << mhs[y].nilai.ippp << endl;
	cout << "IPK         	         : " << mhs[y].nilai.ipk << endl;
	cout << "=========================================" << endl;
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

void searchDataMhs()
{
	string cari;
	int c, pilih;

	cout<<"\nSilahkan pilih ingin mencari berdasarkan apa : "<<endl;
	cout<<"1. Nama"<<endl;
	cout<<"2. NIM"<<endl;
	cout<<"Pilih : ";
	cin>>pilih;

	switch(pilih)
	{
		case 1 : 
		cout<<"Masukkan nama yang ingin dicari : ";
		cin>>cari;

		for (int i = 0; i < a; ++i)
		{
			if (cari == mhs[i].nama)
			{
				cout << "=========================================" << endl;
				cout << "Nama                   : " << mhs[i].nama << endl;
				cout << "NIM                    : " << mhs[i].nim << endl;
				cout << "Prodi                  : " << mhs[i].prodi << endl;
				cout << "Jumlah Sks             : " << mhs[i].nilai.jumlahsks << endl;
				cout << "Jumlah Sks x Nilai     : " << mhs[i].nilai.ippp << endl;
				cout << "IPK                   	: " << mhs[i].nilai.ipk << endl;
				cout << "=========================================" << endl;	
			}
		}

		case 2 : 
		cout<<"Masukkan nama yang ingin dicari : ";
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
				cout << "Jumlah Sks x Nilai     : " << mhs[i].nilai.ippp << endl;
				cout << "IPK                   	: " << mhs[i].nilai.ipk << endl;
				cout << "=========================================" << endl;	
			}
		}
	}
	system("pause");
	mainmenu();
}

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



