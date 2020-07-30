#include "relasi.h"

void createList_r(List_r &L)
{
    first(L) = NULL;
}

address_r alokasi_r(address_p P, address_c C)
{
    address_r Q = new elmlist_r;

    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;

    return Q;
}

void dealokasi_r(address_r &P)
{
    delete P;
}

void insertFirst_r(List_r &L, address_r P)
{
    if (first(L) == NULL)
    {
        first(L) = P;
        next(P) = NULL;
    }
    else
    {

        next(P) = first(L);
        first(L) = P;
    }
}

void insertLast_r(List_r &L, address_r P)
{
    if (first(L) == NULL)
    {
        insertFirst_r(L,P);
    }
    else
    {
        address_r Q = first(L);
        while (next(Q) != NULL)
        {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = NULL;

    }

}

address_r findElm_r(List_r L, address_p P, address_c C)
{
    address_r Q = first(L);

    while(Q != NULL)
    {
        if((parent(Q) == P) && (child(Q) == C))
        {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter_r(List_r L,address_r &Prec, address_r &P)
{
    if(first(L) == NULL)
    {
        insertFirst_r(L,P);
    }
    else
    {
        next(P) = next(Prec);
        next(Prec) = P;
    }
}


void deleteFirst_r(List_r &L, address_r &P)
{
    if(first(L) != NULL)
    {
        if(next(first(L)) == NULL)
        {
            P = first(L);
            first(L) = NULL;
        }
        else
        {
            P = first(L);
            first(L) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteLast_r(List_r &L, address_r &P)
{
    if(first(L) != NULL)
    {
        if(next(first(L)) == NULL)
        {
            deleteFirst_r(L,P);
        }
        else
        {
            address_r Q = first(L);

            while(next(next(Q)) != NULL)
            {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = NULL;
        }
    }

}

void deleteAfter_r(address_r Prec, address_r &P)
{
    List_r L;

    if(first(L)!= NULL)
    {
        if(next(P) == NULL)
        {
            deleteLast_r(L,P);
        }
        else if (P == first(L))
        {
            deleteFirst_r(L,P);
        }
        else
        {
            next(Prec) = next(P);
            next(P) = NULL;
        }

    }
    else
    {
        cout<<"===== LIST KOSONG ====="<<endl;
    }
}

void deletebyrelasi (List_r &L, address_r &P)
{
    address_r Q;

    if(first(L) != NULL)
    {
        if(P == first(L))
        {
            deleteFirst_r(L,P);
        }
        else
        {
            Q = first(L);
            while(next(Q) != P)
                Q = next(Q);
        }
        if((next(Q) == P) && (next(P) == NULL))
        {
            deleteLast_r(L,P);
        }
        else
        {
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
    else
    {
        cout<<"===== LIST KOSONG ====="<<endl;
    }
}


void printInfo_r(List_r L)
{
    address_r P = first(L);

    if(first(L) != NULL)
    {
        while(P != NULL)
        {


            cout<<"ID Bandara           : "<<info(parent(P)).id_bandara<<" <---> "<<"ID Penumpang : "<<info(child(P)).id_penumpang<<endl;
            cout<<"Kota Tujuan          : "<<info(parent(P)).kota<<" <---> "<<"Nama Penumpang     : "<<info(child(P)).nama<<endl;

            cout<<endl;
            P = next(P);
        }
    }
    else
    {
        cout<<endl;
        cout<<"===== DATA RELASI KOSONG ====="<<endl;
    }
}

address_r search_rp(List_r L, address_p &P)
{
    if(first(L) != NULL)
    {
        address_r PR = first(L);

        while((next(PR) != NULL) && (parent(PR) != P))
        {
            PR = next(PR);
        }
        if (parent(PR) == P)
        {
            return PR;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        cout<<"===== LIST KOSONG ====="<<endl;

        return NULL;
    }
}

address_r search_rc(List_r L, address_c P)
{
    if(first(L) != NULL)
    {
        address_r PR = first(L);

        while((next(PR) != NULL) && (child(PR) != P))
        {
            PR = next(PR);
        }
        if (child(PR) == P)
        {
            return PR;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }

}

address_r search_r(List_r L, address_p Q, address_c Z)
{
    if(first(L) != NULL)
    {
        address_r P = first(L);

        while (next(P) != NULL)
        {
            if((parent(P) != Q) && (child(P) != Z))
            {
                P = next(P);
            }
            if((child(P) == Z) && (parent(P) == Q))
            {
                return P;
            }
        }
        return NULL;

    }
    else
    {
        return NULL;

        cout<<"===== LIST KOSONG ====="<<endl;
    }
}

void delete_r(List_r &L, address_r &P)
{
    child(P) = NULL;
    parent(P) = NULL;
    dealokasi_r(P);
}

void sort_r(List_r &L)
{
    address_r R,S;

    if (first(L) != NULL)
    {
        R = first(L);
        while (next(next(R)) != NULL)
        {
            S = next(R);
            while (next(S) != NULL)
            {
                if (info(parent(R)).id_bandara > info(parent(S)).id_bandara)
                {
                    if (next(S) != NULL)
                    {
                        deleteAfter_r(R,S);
                        if (R == first(L))
                        {
                            insertFirst_r(L,S);
                        }
                        else if(next(R) != NULL)
                        {
                            address_r Prec;
                            Prec = first(L);
                            while (next(Prec) != R)
                            {
                                Prec = next(Prec);
                            }
                            insertAfter_r(L,Prec,S);
                        }
                        else
                        {
                            insertLast_r(L,S);
                        }
                    }
                    else
                    {
                        deleteLast_r(L,S);
                        if (R == first(L))
                        {
                            insertFirst_r(L,S);
                        }
                        else if(next(S) != NULL)
                        {
                            address_r Prec;
                            Prec = first(L);
                            while (next(Prec) != R)
                            {
                                Prec = next(Prec);
                            }
                            insertAfter_r(L,Prec,S);
                        }
                        else
                        {
                            insertLast_r(L,S);
                        }
                    }
                }
                S = next(S);
            }
            R = next(R);
        }
    }
}

void print_r(List_r L, address_c C, address_p P)
{
    address_r Q;

    if(first(L) != NULL)
    {

        Q = findElm_r(L,P,C);

        if(Q != NULL)
        {
            cout<<endl;
            cout<<"===== ID DITEMUKAN ====="<<endl;
            cout<<endl;

            cout<<"ID Bandara           : "<<info(parent(Q)).id_bandara<<" <---> "<<"ID Penumpang : "<<info(child(Q)).id_penumpang<<endl;
            cout<<"Kota Tujuan          : "<<info(parent(Q)).kota<<" <---> "<<"Nama Penumpang     : "<<info(child(Q)).nama<<endl;
            cout<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"===== RELASI TIDAK DITEMUKAN ====="<<endl;
        }
    }
    else
    {
        cout<<endl;
        cout<<"===== DATA RELASI KOSONG ====="<<endl;
    }
}
