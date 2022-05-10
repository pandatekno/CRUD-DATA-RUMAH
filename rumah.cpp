/*
Program: CRUD DATA RUMAH
Catatan: Program ini dibuat sebagai bahan pembelajaran untuk memahami basic dari CRUD sederhana, yang tentunya open source dan bebas untuk dikembangkan lagi oleh siapa saja
Author: Tegar Sabila (Admin/CEO at Panda Tekno Inc.)
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <string>


using namespace std;
struct rumah
{
    int reg_num;
    char name[100];
    string type[3] = {"Rendah", "Sedang", "Tinggi"};
    double cost;
};
struct rumah_search
{
    char reg_num[100];
    char name[100];
    char cost[100];
    string type[3] = {"Rendah", "Sedang", "Tinggi"};
};

void addrumah()
{
    int i = 0;
        std::vector<rumah> hse(1);
        fstream myfile;
        myfile.open("data.txt",ios::out|ios::app);
        while(i<1)
    {



        cout << "Masukkan Nomor Registrasi: " ;
        cin >> hse[i].reg_num;
        cout << endl << "Masukan Nama: ";
        cin >> hse[i].name;
        cout << "Masukan Harga: ";
        cin >> hse[i].cost;
        cout << "Data telah ditambahkan (✓)" << endl;
        myfile<<hse[i].reg_num <<" "<<hse[i].name <<" "<<hse[i].cost<<"\n";

        i++;
    }


        myfile.close();
        hse.clear();
}

void listrumahs()
{
     int i = 0;
        std::vector<rumah_search> hse(10);
        fstream file1;
        file1.open("data.txt",ios::in);

        while(!file1.eof()){
               // string line;
                file1.getline(hse[i].reg_num,150,' ');
                file1.getline(hse[i].name,150,' ');
                file1.getline(hse[i].cost,150,'\n');




            i++;
        }
        file1.close();


        cout <<"=========================================================="<<endl;
        cout <<"Reg_Num"<<"\t Nama Rmh "<<"\t Harga"<<"\t Tipe"<<endl;
        cout <<"=========================================================="<<endl;

        int j = 0;
        i = i-1;
        while(j<i)
        {

            cout<<hse[j].reg_num<<"\t "<<hse[j].name<<"\t "<<hse[j].cost;
            if(atoi(hse[j].cost) < 15000)
             {
             cout << "\t\t " << hse[j].type[2] <<endl;
             }
             else if(atoi(hse[j].cost) >=15000 && atoi(hse[j].cost) < 25000)
             {
             cout << "\t\t " << hse[j].type[1] <<endl;
             }
             else if(atoi(hse[j].cost) >= 25000)
             {
             cout << "\t\t " << hse[j].type[0] <<endl;
             }

            cout <<"----------------------------------------------------------"<<endl;
            j++;
        }
        hse.clear();

}

void searchrumah()
{
    char ch[100];
	int choise;
    int result = 0;
	int i = 0;
	std::vector<rumah_search> hse(10);

	cout<<"\t       MENU PENCARIAN"<<endl;
	cout<<"\t (1) Mencari berdasarkan Nomor Registrasi "<<endl;
	cout<<"\t (2) Mencari berdasarkan Nama Rumah "<<endl;
	cout<<"\t--------------------------"<<endl;
	cout<<"Masukkan pilihan Anda : ";
	cin>>choise;
	if(choise==1){
		cout<<"Masukan Reg_Num : ";
		cin>>ch;
	} else if(choise==2){
		cout<<"Masukan Nama Rumah : ";
        cin>>ch;
	}


	fstream myfile;
	myfile.open("data.txt",ios::in);
	while(!myfile.eof())
    {
		myfile.getline(hse[i].reg_num,150,' ');
		myfile.getline(hse[i].name,150,' ');
		myfile.getline(hse[i].cost,150,'\n');

		if(choise==1)
		{
			if(strcmp(ch,hse[i].reg_num)==0)
            {
				//cout<<"Found record is "<<endl;
				cout <<"--------------------------------------------"<<endl;
                cout<<hse[i].reg_num<<"\t "<<hse[i].name<<"\t "<<hse[i].cost<<endl;
                cout <<"--------------------------------------------"<<endl;
                result = 1;
			}

		}
        else if(choise==2)
        {
			if(strcmp(ch,hse[i].name)==0 )
            {
                cout <<"--------------------------------------------"<<endl;
                cout<<hse[i].reg_num<<"\t "<<hse[i].name<<"\t "<<hse[i].cost<<endl;
                cout <<"--------------------------------------------"<<endl;
                result = 1;
            }

        }

    }
    if(result == 0)
    {
        cout<<"***tidak ada catatan yang ditemukan!***"<<endl;
    }
    myfile.close();
    hse.clear();
}

void deleterumah()
{
    int way;
    int i = 0;
	char name[20];
    char id[5];
	char ee[1];
	int flag = 0;

    cout<<"\t****************************"<<endl;
	cout<<"\t (1) Hapus Berdasarkan Reg_Num"<<endl;
	cout<<"\t (2) Hapus Berdasarkan Nama"<<endl;
	cout<<"\t****************************"<<endl;
    cout<<"Masukan pilihan Anda : ";
	cin>>way;
	 	if(way==1){
        cout<<"Masukan Reg_Num yang akan di hapus : ";
	 	cin>>id;
		 }
	 	else
		 	if(way==2){
	 		cout<<"Masukan Nama Rumah yang akan di hapus : ";
	 	cin>>name;}

	 	std::vector<rumah_search> hse(10);
        fstream myfile;
	 	fstream search_file;
	 	myfile.open("data.txt",ios::in);//read
	 	search_file.open("fake_storage.txt",ios::out);//write

        while(!myfile.eof()){
		    myfile.getline(hse[i].reg_num,150,' ');
			myfile.getline(hse[i].name,150,' ');
	 		myfile.getline(hse[i].cost,150,'\n');

		 	if(way==1)
            {
                if(strcmp(id,hse[i].reg_num) !=0 && strcmp(ee,hse[i].reg_num) !=0)
                {
                    search_file<<hse[i].reg_num <<" "<<hse[i].name <<" "<<hse[i].cost<<"\n";
                    flag=1;

                }

            }
            else if(way==2)
            {

                if(strcmp(name,hse[i].name) !=0 && strcmp(ee,hse[i].name) !=0)
                {
                    search_file<<hse[i].reg_num <<" "<<hse[i].name <<" "<<hse[i].cost<<"\n";
                    flag=1;

                }

            }


        }
        myfile.close();
		search_file.close();
        remove("data.txt");
        cout << "Rumah telah di hapus (✓)" << endl;
        rename("fake_storage.txt","data.txt");
        hse.clear();
        if(flag == 0)
        {
            cout << "Tidak ada data yang ditemukan"<<endl;
        }
}

int main()
{

int f = 10;
    while(f==10){
        system("clear");
        cout<<"\t(Program C++ CRUD data rumah)"<<endl;
        cout<<"\t*********MENU UTAMA**********"<<endl;
        cout<<"\t (1) Tambahkan rumah baru"<<endl;
        cout<<"\t (2) Lihat daftar rumah"<<endl;
        cout<<"\t (3) Mencari rumah"<<endl;
        cout<<"\t (4) Menghapus rumah"<<endl;
        cout<<"\t (0) KEMBALI"<<endl;
        cout<<"\t*****************************"<<endl;
        cout<<"Masukan pilihan Anda >> ";
        cin>>f;

        while(f==1){
        addrumah();
        cout<<"(1) Untuk tambahkan rumah lain \n (0) Untuk Kembali \n (10) Kembali ke menu utama >> ";
        cin>>f;

        }
            while(f==2){
        listrumahs();
        cout<<endl;
        cout<<"(0) Untuk Kembali \n (10) Kembali ke menu utama >> ";
        cin>>f;
        }
        while(f==4){
        deleterumah(); 

        cout<<"(4) Untuk hapus rumah lainnya \n (0) Untuk Kembali \n (10) Kembali ke menu utama >> ";
        cin>>f;
        }
        while(f==3){
            searchrumah();
            cout<<"(3) Untuk mencari lagi \n (0) Untuk Kembali \n (10) Kembali ke menu utama >>  ";
            cin>>f;
        }
    }
    if(f==0)
    {
       exit(0);

    }
    if(f != 10 || f != 1 || f != 2 || f != 3 || f != 4 || f != 0)
    {
        cout << "Maaf Masukan Anda Tidak Didukung!!!" <<endl;

    }



    return 0;
}
