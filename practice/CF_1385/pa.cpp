#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int t=0;t<cases;t++){
        int x,y,z,a,b,c;
        cin>>x>>y>>z;

        a=x;
        if(y!=a){
            c=y;
        }else
            c=1;
        if(z<=a&&z>=c){
            b=z;
        }else
            b=1;

        if(x==max(a,b)&&y==max(a,c)&&z==max(b,c)){
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
            continue;
        }
        //cout<<a<<" "<<b<<" "<<c<<"\n";
        a=0,b=0,c=0;
        b=x;
        if(z!=b)
            c=b;
        else
            c=1;
        if(y<=b&&y>=c)
            a=y;
        if(x==max(a,b)&&y==max(a,c)&&z==max(b,c)){
            cout<<"YES\n";
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }else
            cout<<"NO\n";
        //cout<<a<<" "<<b<<" "<<c<<"\n";
    }
}
