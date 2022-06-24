#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

const int MAX_QUEUE = 5;

struct Order{
	string nama;
	string pesanan;
	string waktupes;
	string meja;
	int tanggal;

};

struct Queue{
	int depan;
	int belakang;
	struct Order Order[MAX_QUEUE];
}queue;

void home(string user);
void login();
void admin();
void cust();
void inisialisasi();
void enqueue(int tanggal,string nama,string pesanan,string waktupes,string meja);
void dequeue();
void clear();
bool isEmpty();
bool isFull();
void print();
void sort();
void Menu();
void search();


int main (){
	inisialisasi();
	
	//dummy data
	enqueue(20,"ogi","ayam goreng","12.00","12");
	enqueue(20,"reza","tempe goreng","12.00","12");
	system("cls");
	
	login();

	return 0;
}

void Menu(){
	cout << "LIST MENU " << endl;
	cout << "1. Ayam Goreng" << endl;
	cout << "2. Ayam Bakar" << endl;
	cout << "3. Lele Goreng" << endl;
	cout << "4. Lele Bakar" << endl;
	cout << "5. Telor Goreng" << endl;
	cout << "6. Telor Bakar " << endl;
	cout << "7. Es Jeruk" << endl;
	cout << "8. ES GoodDay" << endl;
	cout << "9. Soda Gembira" << endl;
	
}

void home(string user)
{
	system("cls");
	cout << "Login berhasil !" << endl;
	cout << "Anda login sebagai [" << user << "]\n\n";

}
void login()
{
	char pil;
	string username, password;
	do
	{
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "\t\tLoginPage" << endl;
		cout << "\t" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Isi username dan password untuk login !" << endl;
		cout << "Username    : "; cin >> username;
		cout << "Password    : "; cin >> password;
		if (username == "admin" && password == "admin")
		{
			admin();
			break;
		}
		else if (username == "customer" && password == "customer")
		{
			cust();
			break;
		}
		else
		{
			cout << "Maaf, username/password salah ! Login ulang ? [Y/N] : "; cin >> pil;
			if (pil == 'Y' || pil == 'y')
				continue;
			else
			{
				cout << "Terimakasih" << endl;
				break;
			}
		}
	} while (pil == 'y' || pil == 'Y');
}

void admin()
{
	home("admin");
	int PilihanMenu,tanggal;
	string nama, pesanan, waktupes, meja;
	
	do
	{
		cout << ">>> Menu Utama<<<" << endl;
		cout << "1. Input Order" << endl;
		cout << "2. Selesaikan Order" << endl;
		cout << "3. Tampilan Order" << endl;
		cout << "4. Mengosongkan Order" << endl;
		cout << "5. Mengurutkan item " << endl;
		cout << "6. Logout" << endl;
		cout << "7. Selesai" << endl
		<< endl;
		cout << "Masukkan Pilihan Anda : ";
		cin >> PilihanMenu;
		cout << endl;
		switch (PilihanMenu)
		{
		case 1:
			cin.ignore();
				cout << " data order !" << endl;
				cout << "-----------------------------------------------\n";
				cout << "tanggal				: ";	cin >> tanggal;
				cin.ignore();
				cout << "Nama cust              : "; 	getline (cin, nama);
				cout << "Pesanan                : "; 	getline (cin, pesanan);
				cout << "Waktu Pesan            : "; 	getline (cin, waktupes);
				cout << "Nomor Meja             : "; 	getline (cin, meja);
				
			enqueue(tanggal, nama,pesanan,waktupes,meja);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			print();
			break;
		case 4:
			clear();
			break;
		case 5:
			sort();
			break;
		case 6:
			login();
			break;
			
		default:
			cout << "Menu yang anda pilih tidak terdaftar" << endl << endl ;
		}
	} while (PilihanMenu != 7);
}

void cust()
{
	home("Customer");
	int pil;
	do
	{
		cout << "\n1. Menu Makanan\n2. Search Bookig\n3. Lihat Data Pemesanan\n";
		cout << "4. Batalkan Pemesanan\n5. Logout\n6. Keluar\n\nMasukkan pilihan : ";
		cin >> pil;

		switch (pil)
		{
			case 1:
				Menu();
				break;
			case 2:
				search();
				break;
			case 3:
			
				break;
			case 4:
				
				break;
			case 5:
				login();
				break;
			case 6:
				cout << "Terimakasih \n";
				exit(0);
			default:
				cout << "Maaf, angka yang anda inputkan tidak valid !" << endl;
		}
	} while (pil != 6);
}


void inisialisasi(){
	queue.depan = queue.belakang = -1;
}

void enqueue(int tanggal, string nama,string pesanan,string waktupes,string meja){
	if (isFull()){
		cout << "Queue Sudah Penuh" << endl << endl;
	}
	else {

		queue.depan = 0;
		queue.belakang++;
		queue.Order[queue.belakang].tanggal = tanggal;
		queue.Order[queue.belakang].nama = nama;
		queue.Order[queue.belakang].pesanan = pesanan;
		queue.Order[queue.belakang].waktupes = waktupes;
		queue.Order[queue.belakang].meja = meja;
		
		
		cout << "Data berhasil ditambahkan"<<endl<<endl;	
	}

}

void dequeue(){
	if (isEmpty()){
		cout << "Queue Masih Kosong " << endl << endl;	
	}
	else {
		cout << "Orderan atas nama " << queue.Order[queue.depan].nama << " Sudah Selesai" <<endl<<endl;
		for (int i = queue.depan; i <= queue.belakang; i++){
		queue.Order[i].nama = queue.Order[i+1].nama;
		}
		queue.belakang--;	
	}

}

void clear(){
	if (isEmpty()){
		cout << "Queue Masih Kosong " << endl << endl;	
	}
	else {
		queue.depan = queue.belakang = -1;
		cout << "Queue sudah dikosongkan"<<endl<<endl;
	}
	
}

bool isEmpty(){
	return (queue.belakang == -1);
}

bool isFull(){
	return (queue.belakang >= (MAX_QUEUE - 1));
}

void print(){
	if (isEmpty()){
		cout << "Queue Masih Kosong " << endl << endl;	
	}
	else {
		cout << "Isi queue : " << endl; 
		for (int i = queue.depan; i <= queue.belakang; i++){
		cout << "--------------------------------------------" << endl;
		cout << "No. " << (i+1) << endl; 
		cout << "--------------------------------------------" << endl;
		cout << "Tanggal	 : " << queue.Order[i].tanggal << endl;
		cout << "Nama Cust   : " << queue.Order[i].nama << endl;
		cout << "Pesananan   : " << queue.Order[i].pesanan << endl;
		cout << "Waktu Pesan : " << queue.Order[i].waktupes << endl;
		cout << "Nomor Meja  : " << queue.Order[i].meja << endl;
		
		cout << "--------------------------------------------" << endl;
		}
	cout<<endl<<endl;	
	}
	
}

void search()
{
	int tanggal;
	string bulan;
	int j = 0;
	int index[MAX_QUEUE];

	cout << "\nMasukkan tanggal : ";
	cin >> tanggal;
	cout << "\nMasukkan bulan: ";
	cin >> bulan;

	for (int i = 0; i <= queue.belakang; i++)
	{
		if (queue.Order[i].tanggal == tanggal)
		{
			index[j] = i;
			j++;
		}
	}
	
	
	if (j > 0)
	{
		system("cls");
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                          LIST BOOKING BULAN " << bulan << "                                      " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "No.\tTanggal\t Nama \t Jam \t No.Meja " << endl;
		for (int i = 0; i < j; i++)
		{
			cout << (i+1) << " \t" << queue.Order[index[i]].tanggal << "\t\t " << queue.Order[index[i]].nama << " \t " << queue.Order[index[i]].waktupes << " \t ";
			cout << queue.Order[index[i]].meja << " \t " << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	}
	else
	{
		cout << "\nTidak ada yang Booking pada tanggal " << tanggal << " !" << endl;
	}
}

void sort()
{
	Queue tempqueue;

	//Copy data dari struct utama ke temporary struct/struct sementara
	tempqueue.depan = tempqueue.belakang = -1;
	for (int i = 0; i <= queue.belakang; i++)
	{
		tempqueue.belakang++;
		tempqueue.Order[i].tanggal = queue.Order[i].tanggal;
		tempqueue.Order[i].nama = queue.Order[i].nama;
		tempqueue.Order[i].pesanan = queue.Order[i].pesanan;
		tempqueue.Order[i].waktupes = queue.Order[i].waktupes;
		tempqueue.Order[i].meja = queue.Order[i].meja;
		
	}
	int tanggal[MAX_QUEUE];
	string nama[MAX_QUEUE], pesanan[MAX_QUEUE], waktupes[MAX_QUEUE], meja[MAX_QUEUE];
	//Sorting metode bubble sort

		for (int i = 1; i <= queue.belakang; i++)
		{
			for (int j = 0; j <= queue.belakang - i; j++)
			{
				//Sorting berdasarkan keberangkatan terpagi
				//Jadwal paling pagi diletakan paling atas( dari atas kebawah ) == ascending
				if (tempqueue.Order[j].tanggal < tempqueue.Order[j + 1].tanggal)
				{
					//Proses pertukaran data
					tanggal[j] = tempqueue.Order[j].tanggal;
					nama[j] = tempqueue.Order[j].nama;
					pesanan[j] = tempqueue.Order[j].pesanan;
					waktupes[j] = tempqueue.Order[j].waktupes;
					meja[j] = tempqueue.Order[j].meja;

					tempqueue.Order[j].tanggal = tempqueue.Order[j + 1].tanggal;
					tempqueue.Order[j].nama = tempqueue.Order[j + 1].tanggal;
					tempqueue.Order[j].pesanan = tempqueue.Order[j + 1].pesanan;
					tempqueue.Order[j].waktupes = tempqueue.Order[j + 1].waktupes;
					tempqueue.Order[j].meja = tempqueue.Order[j + 1].meja;

					tempqueue.Order[j + 1].tanggal = tanggal[j];
					tempqueue.Order[j + 1].nama = nama[j];
					tempqueue.Order[j + 1].pesanan = pesanan[j];
					tempqueue.Order[j + 1].waktupes = waktupes[j];
					tempqueue.Order[j + 1].meja = meja[j];
					
					
				}
			}
		}
		//Menampilkan hasil sorting
		
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "                                          LIST BOOKING BULAN ""                                      " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "No.\tTanggal\t Nama \t Jam \t No.Meja " << endl;
		for (int i = queue.belakang; i >=0; i--)
		{
			cout << (i) << " \t" << tempqueue.Order[i].tanggal << "\t\t " << tempqueue.Order[i].nama << " \t " << tempqueue.Order[i].waktupes << " \t ";
			cout << tempqueue.Order[i].meja << " \t " << endl;
		}

		}


	



