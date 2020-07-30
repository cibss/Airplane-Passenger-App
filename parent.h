#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define nil NULL


struct data_bandara
{
    string kota;
    int id_bandara;
    string maskapai;
    string tanggal;
    float waktu;
};

typedef data_bandara infotype_p;
typedef struct elmlist_p *address_p;


struct elmlist_p
{
    infotype_p info;
    address_p next;
};

struct List_p
{
    address_p first;
};

address_p delete_parent(List_p &L, infotype_p x); //1301164104
address_p findElm_p(List_p L, infotype_p x);//1301164249
address_p alokasi_p(infotype_p x);//1301164104
void data_bandara(infotype_p *x);//1301164249
void dealokasi_p(address_p &P);//1301164104
void createList_p(List_p &L);//1301164249
void insertFirst_p(List_p &L, address_p P);//1301164104
void insertAfter_p(List_p &L, address_p Prec, address_p P);//1301164249
void insertLast_p(List_p &L, address_p P);//1301164104
void deleteFirst_p(List_p &L, address_p &P);//1301164249
void deleteLast_p(List_p &L, address_p &P);//1301164104
void deleteAfter_p(List_p &L, address_p Prec, address_p &P);//1301164249
void sortinsert_p(List_p &L, infotype_p x);//1301164249
void printInfo_p(List_p L);//1301164104
void print_p(List_p L, infotype_p x); //1301164249

#endif // PARENT_H_INCLUDED
