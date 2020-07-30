#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

#define nil NULL


struct data_penumpang
{
    int id_penumpang;
    string nama;
    string status;
    string asal;
    string tujuan;

};
typedef data_penumpang infotype_c;
typedef struct elmlist_c *address_c;

struct elmlist_c
{
    infotype_c info;
    address_c next;
    address_c prev;
};

struct List_c
{
    address_c first;
    address_c last;
};


address_c delete_child(List_c &L, infotype_c x); //1301164249
address_c findElm_c(List_c L, infotype_c x);//1301164104
address_c alokasi_c(infotype_c x);//1301164249
void data_penumpang(infotype_c *x);//1301164104
void dealokasi_c(address_c &P);//130164249
void printInfo_c(List_c L);//1301164104
void createList_c(List_c &L);//1301164249
void insertFirst_c(List_c &L, address_c P);//1301164104
void insertLast_c(List_c &L, address_c P);//1301164104
void insertAfter_c(address_c Prec, address_c P);//1301164249
void deleteFirst_c(List_c &L, address_c &P);//1301164104
void deleteLast_c(List_c &L, address_c &P);//1301164249
void deleteAfter_c(address_c Prec, address_c &P);//1301164104
void sortinsert_c(List_c &L, infotype_c x);//1301164249
void print_c(List_c L, infotype_c x);//1301164104

#endif // CHILD_H_INCLUDED
