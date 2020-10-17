#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int cases;
    cin>>cases;
    for(int t=0;t<cases;t++){
        int man;
        cin>>man;
        int data[man];
        for(int i=0;i<man;i++){
            cin>>data[i];
        }
        sort(data, data+man);
        int ans=1000;
        for(int i=1;i<man;i++){
            if(data[i]-data[i-1]<ans)
                ans = data[i]-data[i-1];
        }
        cout<<ans<<"\n";
    }

}
