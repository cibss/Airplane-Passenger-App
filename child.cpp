#include "child.h"

void createList_c(List_c &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

void dealokasi_c(address_c &P)
{
    delete P;
}

void data_penumpang(infotype_c *x)
{
    cout<<endl;
    cout<<"===== INPUT DATA PENUMPANG ====="<<endl;
    cout<<endl;

    cout<<"ID Penumpang             : ";
    cin>>x->id_penumpang;
    cout<<"Nama Penumpang           : ";
    cin>>x->nama;
    cout<<"Status Kewarganegaraan   : ";
    cin>>x->status;
    cout<<"Asal Kota                : ";
    cin>>x->asal;
    cout<<"Kota Tujuan              : ";
    cin>>x->tujuan;
}

address_c alokasi_c(infotype_c x)
{
    address_c P;

    P = new elmlist_c;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;

    info(P).id_penumpang = x.id_penumpang;
    info(P).nama = x.nama;
    info(P).status = x.status;
    info(P).asal = x.asal;
    info(P).tujuan = x.tujuan;

    return P;
}


void insertFirst_c(List_c &L, address_c P)
{
    if(first(L) == NULL)
    {
        last(L) = P;
        first(L) = P;
        next(P) = NULL;
        prev(P) = NULL;
    }
    else
    {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void printInfo_c(List_c L)
{
   address_c P = first(L);

    if (first(L) == NULL)
    {
        cout<<endl;
        cout<<"===== DATA PENUMPANG KOSONG ====="<<endl;
    }
    else
    {
        P = first(L);
        cout<<endl;
        cout<<"===== DATA PENUMPANG ====="<<endl;
        do
        {
            cout<<endl;
            cout<<"ID Penumpang             : "<<info(P).id_penumpang<<endl;
            cout<<"Nama Penumpang           : "<<info(P).nama<<endl;
            cout<<"Status Kewarganegaraan   : "<<info(P).status<<endl;
            cout<<"Asal Kota                : "<<info(P).asal<<endl;
            cout<<"Kota Tujuan              : "<<info(P).tujuan<<endl;
            cout<<endl;

            P = next(P);
        }
        while (P != NULL);
    }
}

address_c findElm_c(List_c L, infotype_c x)
{
    address_c P = first(L);

    while ((P != NULL) && (info(P).id_penumpang != x.id_penumpang))
    {
        P = next(P);
    }
    if (P != NULL)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

void insertLast_c(List_c &L, address_c P)
{
    if (first(L) == NULL)
    {
        insertFirst_c(L,P);
    }
    else
    {
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertAfter_c(address_c Prec, address_c P)
{
    List_c L;

    if(first(L) == NULL)
    {
        insertFirst_c(L,P);
    }
    else if(next(Prec) == NULL)
    {
        insertLast_c(L,P);
    }
    else
    {
        next(P) = next(Prec);
        prev(P) = Prec;
        prev(next(Prec)) = P;
        next(Prec) = P;
    }
}


void deleteFirst_c(List_c &L, address_c &P)
{
    if (first(L) != NULL)
    {
        P = first(L);
        if(next(P) == NULL)
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            first(L) = next(P);
            next(P) = NULL;
            prev(first(L))= NULL;
        }
    }
    else
    {
        cout<<"===== LIST KOSONG ====="<<endl;
    }

}

void deleteLast_c(List_c &L, address_c &P)
{
    if(first(L) != NULL)
    {
        if(first(L) == last(L))
        {
            first(L) = NULL;
            last(L) = NULL;
        }
        else
        {
            P = last(L);
            last(L) = prev(P);
            next(prev(P)) = NULL;
            prev(P) = NULL;
        }
    }
}

void deleteAfter_c(address_c Prec, address_c &P)
{
    List_c L;

    if(first(L)!= NULL)
    {
        if(next(Prec) != NULL)
        {
            if(next(Prec) == last(L))
            {
                deleteLast_c(L,P);
            }
            else if (Prec == first(L))
            {
                deleteFirst_c(L,next(Prec));
            }
            else
            {
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                next(P) = NULL;
                prev(P) = NULL;
            }

        }
    }
    else
    {
        cout<<"===== LIST KOSONG ====="<<endl;

    }
}

address_c delete_child(List_c &L, infotype_c x)
{
    address_c P,P2;

    P = findElm_c(L,x);

    if(P != NULL)
    {
        if(P == first(L))
        {
            deleteFirst_c(L,P);
            return P;
        }
        else if(P == last(L))
        {
            deleteLast_c(L,P);
            return P;
        }
        else
        {
            P2 = prev(P);
            deleteAfter_c(P2,P);
            return P;
        }
    }
    else
    {
        return NULL;
    }

}

void sortinsert_c(List_c &L, infotype_c x)
{
    address_c P,P2,P3;

    P3 = findElm_c(L,x);

    if(P3 == NULL)
    {
        P2 = alokasi_c(x);
        if(first(L) != NULL)
        {
            P = first(L);
        }
        if(first(L) == NULL)
        {
            insertFirst_c(L,P2);
            cout<<endl;
            cout<<"=== DATA TELAH DI INPUT ===";
        }
        else if(info(P2).id_penumpang < info(P).id_penumpang)
        {
            insertFirst_c(L,P2);
            cout<<endl;
            cout<<"=== DATA TELAH DI INPUT ===";
        }
        else
        {
            {
                P = first(L);

                while((info(P2).id_penumpang > info(P).id_penumpang) && (next(P) != NULL))
                {
                    P = next(P);
                }
                if(info(P2).id_penumpang > info(P).id_penumpang)
                {
                    if(next(P) == NULL)
                    {
                        insertLast_c(L,P2);
                        cout<<endl;
                        cout<<"=== DATA TELAH DI INPUT ===";
                    }
                    else
                    {
                        insertAfter_c(P,P2);
                        cout<<endl;
                        cout<<"=== DATA TELAH DI INPUT ===";
                    }
                }
                else
                {
                    insertAfter_c(prev(P),P2);
                    cout<<endl;
                    cout<<"=== DATA TELAH DI INPUT ===";
                }
            }

        }
    }
    else
    {
        cout<<endl;
        cout<<"===== MAAF ID SUDAH DIGUNAKAN ====="<<endl;
    }
}

void print_c(List_c L, infotype_c x)
{
    address_c P;

    if(first(L) != NULL)
    {
        P = findElm_c(L,x);

        if(P != NULL)
        {
            cout<<endl;
            cout<<"===== ID DITEMUKAN ====="<<endl;
            cout<<endl;

            cout<<"ID Penumpang             : "<<info(P).id_penumpang<<endl;
            cout<<"Nama Penumpang           : "<<info(P).nama<<endl;
            cout<<"Status Kewarganegaraan   : "<<info(P).status<<endl;
            cout<<"Asal Kota                : "<<info(P).asal<<endl;
            cout<<"Kota Tujuan              : "<<info(P).tujuan<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"===== ID TIDAK DITEMUKAN ====="<<endl;
        }
    }
    else
    {
        cout<<endl;
        cout<<"===== DATA PENUMPANG KOSONG ====="<<endl;
    }
}
