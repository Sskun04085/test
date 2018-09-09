#include <iostream>
#include <cstdlib>
#ifndef sort
#define sort
using namespace std;
const int Infty = 2147483647;
    void Merge(int* A, int p, int q, int r)
    {
        int i, j;
        int len1 = q-p+1;
        int len2 = r-q;
        int *L1 = new int[len1+1];
        int *L2 = new int[len2+1];
        for(i = 0;i < len1;i++) L1[i] = A[p+i];
        for(j = 0;j < len2;j++) L2[j] = A[q+j+1];
        i = 0; j = 0;
        L1[len1] = Infty;
        L2[len2] = Infty;
        for(int k = p;k <= r;k++)
        {
            if(L1[i] <= L2[j])
            {
                A[k] = L1[i];
                i++;
            }
            else
            {
                A[k] = L2[j];
                j++;
            }
        }
        delete [] L1;
        delete [] L2;
        return;
    }

    void Mergesort(int* A, int p, int r)
    {
        int q;
        if(p < r)
        {
            q = (p+r)/2;
            //cerr << "bugM" << endl;
            Mergesort(A, p, q);
            Mergesort(A, q+1, r);
            Merge(A, p, q, r);
        }
        return;
    }
#endif // sort
