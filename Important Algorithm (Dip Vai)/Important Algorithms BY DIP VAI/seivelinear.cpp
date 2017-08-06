#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
//factorization in almost O(1)
#define s 1000010
int lp [s +10]; //lowest prime
vector <int> pr; //store primes

int seive(int N)//0 indexed
{
        for (int i = 2; i <= N; + + i) {
            if (lp [i] == 0) {
                lp [i] = i;
                pr.push_back (i);
        }
        for (int j = 0; j <(int) pr.size () && pr [j] <= lp [i] && i * pr [j] <= N; + + j)
            lp [i * pr [j]] = pr [j];
        }
}


int main()
{
    long long n;
    return 0;
}






