#include<iostream>
#include<string>
#include"BigInt.h"
#include<ctime>
using namespace std;
int main()
{
    clock_t start,end;
    start=clock();
    BigInt::Rossi ret(1);
    BigInt::Rossi sum(0);
    for( int i=2;i<=1000;i++)
    {
	ret =ret*i;
	sum+=ret;
    }
    cout<<sum<<endl;
    end=clock();
    cout<<"Run Time:"<<(end-start)*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}
