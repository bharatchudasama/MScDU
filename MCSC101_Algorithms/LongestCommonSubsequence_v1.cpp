/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
// Naive approach, O(2^n)

#include <iostream>
using namespace std;

int lcsub(string s1, string s2, int ind1, int ind2){
    if( (ind1==-1) || (ind2==-1) ){
        return 0;
    }
    else if(s1[ind1] == s2[ind2]){
        return 1 + lcsub(s1, s2, ind1-1, ind2-1);
    }
    else{
        return max( lcsub(s1, s2, ind1-1, ind2), lcsub(s1, s2, ind1, ind2-1) );
    }
}
int main()
{
    // cout<<"Hello World";
    string s1 = "adebcc";
    string s2 = "dcadbzzc";
    cout << lcsub(s1, s2, s1.size()-1, s2.size()-1);

    return 0;
}
