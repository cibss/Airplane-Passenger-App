#include "parent.h"

void createList_p(List_p &L)
{
    first(L) = NULL;
}
void dealokasi_p(address_p &P)
{
    delete P;
}

void data_bandara(infotype_p *x)
{
    cout<<endl;
    cout<<"===== INPUT DATA BANDARA ====="<<endl;
    cout<<endl;

    cout<<"ID Bandara                       : ";
    cin>>x->id_bandara;
    cout<<"Kota Tujuan                      : ";
    cin>>x->kota;
    cout<<"Maskapai Penerbangan             : ";
    cin>>x->maskapai;
    cout<<"Tanggal Keberangkatan (DD/MM/YY) : ";
    cin>>x->tanggal;
    cout<<"Waktu Keberangkatan              : ";
    cin>>x->waktu;
}

address_p alokasi_p(infotype_p x)
{
    address_p P;

    P = new elmlist_p;
    info(P) = x;
    next(P) = NULL;

    info(P).id_bandara = x.id_bandara;
    info(P).kota =  x.kota;
    info(P).maskapai = x.maskapai;
    info(P).tanggal = x.tanggal;
    info(P).waktu = x.waktu;

    return P;
}

void insertFirst_p(List_p &L, address_p P)
{
    address_p Q;
    if(first(L) == NULL)
    {
        first(L) = P;
        next(P) = P;
    }
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
        {
            Q = next(Q);
        }
        next(P) = first(L);
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast_p(List_p &L, address_p P)
{
    address_p Q;
    if (first(L) == NULL)
        insertFirst_p(L,P);
    else
    {
        Q = first(L);
        while(next(Q) != first(L))
            Q = next(Q);
        next(Q) = P;
        next(P) = first(L);
    }

}

void insertAfter_p(List_p &L, address_p Prec, address_p P)
{
    if(Prec != NULL)
    {
        if(next(Prec) == first(L))
        {
            insertLast_p(L,P);
        }
        else
        {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }

}

void deleteFirst_p(List_p &L, address_p &P)
{
    address_p Q;
    if (first(L) == NULL)
        cout<<"No data"<<endl;
    else if(first(L)->next == first(L))
    {
        P = first(L);
        first(L) = NULL;
    }
    else
    {
        Q = first(L);
        P = first(L);
        while(Q->next != first(L))
            Q = Q->next;
        Q->next = next(P);
        first(L) = next(P);
        next(P) = NULL;

    }
}

void deleteLast_p(List_p &L, address_p &P)
{
    address_p Q;
    if (first(L) == NULL)
        cout<<"No data"<<endl;
    else if(first(L)->next == first(L))
    {
        P = first(L);
        first(L) = NULL;
    }
    else
    {
        Q = first(L);
        P = first(L);
        while(P->next != first(L))
            P = P->next;
        while(Q->next != P)
            Q = Q->next;
        Q->next = first(L);
        P->next = NULL;
    }
}

void deleteAfter_p(List_p &L, address_p Prec, address_p &P)
{
    if(first(L) != NULL)
    {
        if(Prec != NULL)
        {
            if(next(Prec) == first(L))
            {
                deleteFirst_p(L, P);
            }
            else
            {
                P = next(Prec);
                next(Prec) = next(P);
                next(P) = NULL;
            }
        }

    }

}


address_p findElm_p(List_p L, infotype_p x)
{
    address_p P;

    if(first(L) != NULL)
    {
        P = first(L);
        while((info(P).id_bandara != x.id_bandara) && (next(P) != first(L)))
        {
            P = next(P);
        }
    }

    if(info(P).id_bandara == x.id_bandara)
    {
        return P;
    }
    else
    {
        return NULL;
    }
}

void printInfo_p(List_p L)
{
    address_p P;
    if (first(L) == NULL)
    {
        cout<<endl;
        cout<<"===== DATA BANDARA KOSONG ====="<<endl;
    }
    else
    {
        P = first(L);
        cout<<endl;
        cout<<"===== DATA BANDARA ====="<<endl;
        do
        {
            cout<<endl;
            cout<<"ID Bandara                       : "<<info(P).id_bandara<<endl;
            cout<<"Kota Tujuan                      : "<<info(P).kota<<endl;
            cout<<"Maskapai Penerbangan             : "<<info(P).maskapai<<endl;
            cout<<"Tanggal Keberangkatan (DD/MM/YY) : "<<info(P).tanggal<<endl;
            cout<<"Waktu Keberangkatan              : "<<info(P).waktu<<endl;
            cout<<endl;

            P = next(P);
        }
        while (P != first(L));
    }
    cout<<endl;
}

void sortinsert_p(List_p &L, infotype_p x)
{
    address_p P,P1,P2;

    P1 = findElm_p(L,x);

    if(P1 == NULL)
    {
        P2 = alokasi_p(x);
        if(first(L) == NULL)
        {
            insertFirst_p(L,P2);

            cout<<endl;
            cout<<"=== DATA TELAH DI INPUT ===";
        }
        else
        {
            P = first(L);
            if((x.id_bandara > info(P).id_bandara) && (x.id_bandara < info(next(P)).id_bandara))
            {
                insertAfter_p(L,P,P2);

                cout<<endl;
                cout<<"=== DATA TELAH DI INPUT ===";
            }
            else if(x.id_bandara < info(P).id_bandara)
            {
                insertFirst_p(L,P2);

                cout<<endl;
                cout<<"=== DATA TELAH DI INPUT ===";
            }
            else
            {
                while ((next(P) != first(L)) && (info(next(P)).id_bandara < x.id_bandara))
                {
                    P = next(P);
                }
                if(next(P) == first(L))
                {
                    insertLast_p(L,P2);

                    cout<<endl;
                    cout<<"=== DATA TELAH DI INPUT ===";
                }
                else
                {
                    insertAfter_p(L,P,P2);

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
void print_p(List_p L, infotype_p x)
{
    address_p P;

    if (first(L) != NULL)
    {
        P = findElm_p(L,x);

        if(P != NULL)
        {
            cout<<endl;
            cout<<"===== ID DITEMUKAN ====="<<endl;
            cout<<endl;

            cout<<"ID Bandara                       : "<<info(P).id_bandara<<endl;
            cout<<"Kota Tujuan                      : "<<info(P).kota<<endl;
            cout<<"Maskapai Penerbangan             : "<<info(P).maskapai<<endl;
            cout<<"Tanggal Keberangkatan (DD/MM/YY) : "<<info(P).tanggal<<endl;
            cout<<"Waktu Keberangkatan              : "<<info(P).waktu<<endl;
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
        cout<<"===== DATA BANDARA KOSONG ====="<<endl;
    }
}

address_p delete_parent(List_p &L, infotype_p x)
{
    address_p P,P2;

    P = findElm_p(L,x);

    if(P != NULL)
    {
        if(P == first(L))
        {
            deleteFirst_p(L,P);
            return P;

        }
        else if(next(P) == first(L))
        {
            deleteLast_p(L,P);
            return P;
        }
        else
        {
            address_p Q = first(L);
            while (next(Q) != P)
            {
                Q = next(Q);
            }
            deleteAfter_p(L,Q,P);
            return P;
        }
    }
    else
    {

        return NULL;
    }

}
