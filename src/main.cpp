#include<iostream>
#include<string>
#include"common/BigInt.h"
#include"common/HashMap.h"
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
    StringMap<int> kmap;
    kmap.set("1",10);
    kmap.set("2",20);
    kmap.set("2",30);
    StringMap<int>::const_iterator it;
    for( it = kmap.begin(); it!=kmap.end(); it++ )
    {
	cout<<(it->first)<<"\t"<<it->second->getValue()<<endl;
    }
    cout<<"Run Time:"<<(end-start)*1.0/CLOCKS_PER_SEC<<endl;
    return 0;
}
