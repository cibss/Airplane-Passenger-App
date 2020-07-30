#include "relasi.h"
#include "parent.h"
#include "child.h"
#include "aplikasi.h"

#include <iostream>
#include <conio.h>

address_c CC = NULL;
//address_c Pcari;
infotype_c XC;
infotype_c x;
List_c LC;

address_p PP = NULL;
//address_p cariP;
infotype_p XP;
infotype_p z;
List_p LP;

address_r RR = NULL;
List_r LR;

address_c search_c;
address_p search_p;

void menu()
{
    int pilihan;
    createList_c(LC);
    createList_r(LR);
    createList_p(LP);

    do
    {
        cout<<"======  APLIKASI ======";
        cout<<endl;
        cout<<"== PENUMPANG PESAWAT =="<<endl;
        cout<<endl<<
            " 1. Input Data Bandara"<<endl<<
            " 2. Input Data Penumpang"<<endl<<
            " 3. Lihat Data Bandara"<<endl<<
            " 4. Lihat Data Penumpang"<<endl<<
            " 5. Cari Data Bandara"<<endl<<
            " 6. Cari Data Penumpang"<<endl<<
            " 7. Relasikan"<<endl<<
            " 8. Lihat Data Relasi"<<endl<<
            " 9. Cari Data Relasi"<<endl<<
            "10. Putus Relasi"<<endl<<
            "11. Hapus Data Bandara"<<endl<<
            "12. Hapus Data Penumpang"<<endl<<
            "13. Urutkan Relasi"<<endl<<
            " 0. Exit"<<endl<<

            "Input Menu : ";
        cin>>pilihan;
        switch(pilihan)
        {
        case 1:
            input_bandara();
            break;
        case 2:
            input_penumpang();
            break;
        case 3:
            lihat_bandara();
            break;
        case 4:
            lihat_penumpang();
            break;
        case 5:
            cari_bandara();
            break;
        case 6:
            cari_penumpang();
            break;
        case 7:
            relasikan();
            break;
        case 8:
            lihat_relasi();
            break;
        case 9:
            cari_relasi();
            break;
        case 10:
            putus_relasi();
            break;
        case 11:
            hapus_bandara();
            break;
        case 12:
            hapus_penumpang();
            break;
        case 13:
            urut_relasi();
            break;
        case 0:
            thank_you();
            break;
        default:
            cout<<"Wrong Input"<<endl;
            break;
        }

        cout<<"\nPress Enter";
        getch();
        cout<<endl;
        system ("cls");
    }
    while (pilihan != 0);
}

void input_bandara()
{
    data_bandara(&XP);
    sortinsert_p(LP,XP);
}

void input_penumpang()
{
    data_penumpang(&XC);
    sortinsert_c(LC,XC);
}

void lihat_bandara()
{
    printInfo_p(LP);
}

void lihat_penumpang()
{
    printInfo_c(LC);
}

void cari_bandara()
{
    cout<<endl;
    cout<<"Masukkan ID Bandara      : ";
    cin>>z.id_bandara;

    print_p(LP,z);
}

void cari_penumpang()
{
    cout<<endl;
    cout<<"Masukkan ID Penumpang    : ";
    cin>>x.id_penumpang;

    print_c(LC,x);
}

void relasikan()
{
    cout<<endl;
    cout<<"===== RELASI BANDARA DENGAN PENUMPANG ====="<<endl;
    cout<<endl;

    cout<<"Masukkan ID Bandara  : ";
    cin>>z.id_bandara;

    cout<<"Masukkan ID Penumpang: ";
    cin>>x.id_penumpang;

    search_p = findElm_p(LP,z);
    search_c = findElm_c(LC,x);

    if((search_p != NULL) && (search_c != NULL))
    {
        RR = alokasi_r(search_p,search_c);
        insertLast_r(LR,RR);

        cout<<endl;
        cout<<"===== BANDARA DENGAN PENUMPANG BERHASIL BERELASI ====="<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"===== ID BANDARA DAN PENUMPANG TIDAK DITEMUKAN ====="<<endl;
    }
}

void lihat_relasi()
{
    cout<<endl;
    cout<<"===== DATA RELASI ====="<<endl;
    cout<<endl;

    printInfo_r(LR);
}

void cari_relasi()
{
    cout<<endl;
    cout<<"===== CARI DATA RELASI ====="<<endl;
    cout<<endl;

    cout<<"Masukkan ID Bandara      : ";
    cin>>z.id_bandara;
    cout<<"Masukkan ID Penumpang    : ";
    cin>>x.id_penumpang;

    search_p = findElm_p(LP,z);
    search_c = findElm_c(LC,x);

    if((search_p != NULL) && (search_c != NULL))
    {
        RR = search_r(LR,search_p,search_c);

        if(RR != NULL)
        {
            cout<<endl;
            cout<<"===== DATA RELASI DITEMUKAN ====="<<endl;
            cout<<endl;
            print_r(LR,search_c,search_p);
        }
    }
    else
    {
        cout<<endl;
        cout<<"===== DATA RELASI TIDAK DITEMUKAN ====="<<endl;
    }

}

void putus_relasi()
{
    cout<<endl;
    cout<<"===== PUTUS RELASI ====="<<endl;
    cout<<endl;

    cout<<"Masukkan ID Bandara: ";
    cin>>z.id_bandara;
    cout<<"Masukkan ID Penumpang: :";
    cin>>x.id_penumpang;

    search_p = findElm_p(LP,z);
    search_c = findElm_c(LC,x);

    if((search_p != NULL) && (search_c != NULL))
    {
        RR = search_r(LR,search_p,search_c);
        if(RR != NULL)
        {
            deletebyrelasi(LR,RR);
            delete_r(LR,RR);

            cout<<endl;
            cout<<"===== RELASI DIPUTUS =====";
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"===== DATA TIDAK BERELASI =====";
            cout<<endl;
        }
    }
    else
    {
            cout<<endl;
            cout<<"===== DATA RELASI TIDAK DITEMUKAN =====";
            cout<<endl;
    }
}

void hapus_bandara()
{
    cout<<endl;
    cout<<"===== HAPUS DATA BANDARA ====="<<endl;
    cout<<endl;

    cout<<"Masukkan ID Bandara: ";
    cin>>z.id_bandara;

    search_p = delete_parent(LP,z);
    if(search_p != NULL)
    {
        cout<<endl;
        cout<<"===== DATA BANDARA DIHAPUS ====="<<endl;
        cout<<endl;

        RR = search_rp(LR, search_p);
        dealokasi_p(search_p);

        if(RR != NULL)
        {
            deletebyrelasi(LR,RR);
            delete_r(LR,RR);
        }
        else
        {
            cout<<"===== DATA TIDAK BERELASI ====="<<endl;
        }
    }
    else
    {
        cout<<"===== DATA TIDAK DITEMUKAN ====="<<endl;
    }
}

void hapus_penumpang()
{
    cout<<endl;
    cout<<"===== HAPUS DATA PENUMPANG ====="<<endl;
    cout<<endl;

    cout<<"Masukkan ID Penumpang : ";
    cin>>x.id_penumpang;

    search_c = delete_child(LC,x);
    if (search_c != NULL)
    {
        cout<<endl;
        cout<<"===== DATA PENUMPANG DIHAPUS ====="<<endl;
        cout<<endl;

        RR = search_rc(LR,search_c);
        dealokasi_c(search_c);
        if(RR != NULL)
        {
            deletebyrelasi(LR,RR);
            delete_r(LR,RR);
        }
        else
        {
            cout<<"===== DATA TIDAK BERELASI ====="<<endl;
        }
    }
    else
    {
        cout<<"===== DATA TIDAK DITEMUKAN ====="<<endl;
    }

}

void urut_relasi()
{

}

void thank_you()
{
    cout<<"             ===== TERIMAKASIH ====="<<endl;
    cout<<endl;
    cout<<"===== APLIKASI PENUMPANG PESAWAT SELESAI====="<<endl;
    cout<<endl;
}

