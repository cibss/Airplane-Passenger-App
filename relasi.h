#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "parent.h"
#include "child.h"

#include <iostream>
using namespace std;

#define next(P) P -> next
#define first(L) L.first
#define child(P) P->child
#define parent(P) P->parent
#define info(P) P->info

typedef string infotype_r;
typedef struct elmlist_r *address_r;

struct elmlist_r
{
    infotype_r info;
    address_r next;
    address_c child;
    address_p parent;
};

struct List_r
{
    address_r first;
};

address_r search_r(List_r L, address_p Q, address_c Z);//1301164104
address_r search_rp(List_r L, address_p &P);//1301164249
address_r search_rc(List_r L, address_c P);//1301164104
address_r alokasi_r(address_p P, address_c C);//1301164249
void deletebyrelasi(List_r &L, address_r &P);//1301164249
void delete_r(List_r &L, address_r &P);//1301164104
void dealokasi_r(address_r &P);//1301164249
void printInfo_r(List_r L);//1301164104
void createList_r(List_r &L);//1301164104
void insertFirst_r(List_r &L, address_r P);//1301164249
void insertLast_r(List_r &L, address_r P);//1301164104
void insertAfter_r(address_r Prec, address_r P);//1301164249
void deleteFirst_r(List_r &L, address_r &P);//1301164104
void deleteLast_r(List_r &L, address_r&P);//1301164249
void deleteAfter_r(address_r Prec, address_r &P);//1301164249
void sort_r(List_r &L);//1301164104
void print_r(List_r L, address_c C, address_p P);//1301164249

#endif // RELASI_H_INCLUDED
