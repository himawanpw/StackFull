#include <iostream>
#include <stdlib.h>
using namespace std;

typedef  struct {
    string judul[10];
    string pengarang [10];
    int atas = 0;
    int bawah = 1;
}stack_buku;

stack_buku buku;

bool empty_stack (stack_buku &x) {if(x.atas==0) {return true;}else {return false;}}
bool full_stack (stack_buku &x) {if(x.atas==10) {return true;}else {return false;}}

void push_stack(stack_buku &x)
{
    x.atas++;
    cout<<"Masukan Data Buku Yang Akan Disimpan Di Tumpukan : "<<endl;
    cout<<"Masukan Judul : ";cin>>x.judul[x.atas];
    cout<<"Masukan Pengarang : ";cin>>x.pengarang[x.atas];
    cout<<"Buku Berhasil Disimpan "<<endl;
}

void print_stack(stack_buku &x)
{
    cout<<"Berikut Adalah Daftar Buku Di Tmpuka Saat Ini "<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Posisi        Judul        Pengarang"<<endl;
    cout<<"----------------------------------------------"<<endl;
    for(int i=x.atas;i>=1;i--)
        cout<<"  "<<i<<"  "<<x.judul[i]<<"  "<<x.pengarang[i]<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Buku Di Tumpukan = "<<x.atas<<" buah "<<endl;
}

void pop_stack(stack_buku &x)
{
    cout<<"Data Yang Terambl adalah data teratas "<<endl;
    cout<<"Data Yan Diambil adalah : "<<endl;
    cout<<"Judul : "<<x.judul[x.atas]<<endl;
    cout<<"Pengarang : "<<x.pengarang[x.atas]<<endl;
    x.atas--;
}
void find_book(stack_buku &x)
{
    string cari; bool ada=false;
    cout<<"Masukan Judul Buku Yang Di Cari = ";cin>>cari;
    for(int i=1;i<=x.atas;i++)
    {
        if(x.judul[i]==cari)
        {ada=true;cout<<"Buku Dengan Judul = "<<cari<<"Ditemukan"<<endl;
            cout<<"Posisi di Tumpukan ke- "<<i<<endl;
        }
    }
    if(not ada) { cout<<"Buku Dengan Judul "<<cari<<"Tidak Ditemukan "<<endl;
    }
}
void insert_toStack (stack_buku &x)
{
    int sisip;
    print_stack(x);
    ulang:
    cout<<"Buku Akan Disisipkan Pada Posisi Berapa ? , Disisipkan Pada posisi = ";cin>>sisip;
    if((sisip<1) || (sisip>x.atas+1)){
        cout<<"Posisi Tidak Valid , Ulangi "<<endl;goto ulang;}
    if(sisip==x.atas+1){
        push_stack(x);
    }
    else
    {
        for(int i=x.atas+1;i>=sisip;i--)
        {
            x.judul[i]=x.judul[i-1];x.pengarang[i]=x.pengarang[i-1];
        }
        x.atas++;

        cout<<"Sekarang Masukan Buku Yang Akan Disisipkan : "<<endl;
        cout<<"Masukan Jduul : ";cin>>x.judul[sisip];
        cout<<"Masukan Pengarang : ";cin>>x.pengarang[sisip];
        cout<<"Penyisipa Berhasil"<<endl;
    }
}
void take_fromStack(stack_buku &x)
{
    string ambil;
    bool ada=false;
    int pos=0;
    print_stack(x);
    cout<<"Masukan Judul Buku Yag Akan Diambi = ";cin>>ambil;
    for(int i=x.bawah;i<=x.atas;i++)
    {
        if(x.judul[i]==ambil){
            ada=true;
            pos=i;
        }
    }
    if(ada==true)
    {
        cout<<"Buku Dengan Judul "<<ambil<<" Ada dan Akan Diambil "<<endl;
        cout<<"Posisi Buku di "<<pos<<endl;

        for(int i=pos;i<=x.atas;i++)
        {
            x.judul[i]=x.judul[i+1];x.pengarang[i]=x.pengarang[i+1];
        }
        x.atas--;
        cout<<"Pengambilan Berhasil "<<endl;
    }
    else {
        cout<<"Buku Dengan Judul "<<ambil<<" Tidak Ada Di Tumpukan ";
    }
}

int main() {
    int pilih=0;
    while (true){
      //  system("cls");
        cout<<"Pilih Menu "<<endl;
        cout<<"1. Tambah Tumpukan "<<endl;
        cout<<"2. Cetak Tumpukan "<<endl;
        cout<<"3. Cari Buku Di Tumpukan "<<endl;
        cout<<"4. Ambil Buku Di Tumpukan "<<endl;
        cout<<"5. Menyisipkan Buku Di Tumpukan "<<endl;
        cout<<"6. Ambil Buku Secara Acak "<<endl;
        cout<<"7. Keluar "<<endl;
        cout<<"Pilih Menu = ";cin>>pilih;
        switch(pilih)
        {
            case 1 : {
                if(full_stack(buku)) {
                    cout<<"Tumpukan Penuh ";}
                else{
                    push_stack(buku);}
                break;
            }
            case 2 : {if(empty_stack(buku)) {
                    cout<<"Tumpuka Kosong ";}
                else {
                    print_stack(buku);}
                break;}
            case 3 : {if(empty_stack(buku)) {
                    cout<<"Tumpuka Kosong ";}
                else {
                    find_book(buku);}
                break;}
            case 4 : {if(empty_stack(buku)) {
                    cout<<"Tumpuka Kosong ";}
                else {
                    pop_stack(buku);}
                break;}
            case 5 : {if(empty_stack(buku)) {
                    cout<<"Tumpuka Kosong, Tidak Bisa Di Sisip ";}
                else {
                    insert_toStack(buku);}
                break;}
            case 6 : {if(empty_stack(buku)) {
                    cout<<"Tumpuka Kosong, Tidak Bisa Di Ambil ";}
                else {
                    take_fromStack(buku);}
                break;}
            case 7 : {
                return(0);}
            default :
                cout<<"Salah Pilih Menu "<<endl;
                system ("pause");
        }
    }
}

