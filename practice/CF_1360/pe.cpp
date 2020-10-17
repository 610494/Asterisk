#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases,invalid=0;
    cin>>cases;
    for(int t=0;t<cases;t++){
        int arrsize;
        cin>>arrsize;
        char data[arrsize][arrsize],arr[arrsize][arrsize];
        memset(arr,'0',sizeof(arr));
        for(int i=0;i<arrsize;i++) cin >> data[i];
        for(int i=arrsize-1;i>=0;i--){
            arr[i][arrsize-1] = data[i][arrsize-1];
            arr[arrsize-1][i] = data[arrsize-1][i];
        }
        /*for(int i=0;i<arrsize;i++){
            for(int j=0;j<arrsize;j++){
                cout<<data[i][j];
            }
            cout<<endl;
        }*/
        for(int i=arrsize-2;i>=0 && invalid==0;i--){
            for(int j=i;j>=0;j--){
                if(data[i][j]=='1'){
                    if(arr[i+1][j]=='1' || arr[i][j+1]=='1'){
                        arr[i][j] = '1';
                    }else{
                        invalid = 1;
                        break;
                    }
                }
                if(data[j][i]=='1'){
                    if(arr[j+1][i]=='1' || arr[j][i+1]=='1'){
                        arr[j][i] = '1';
                    }else{
                        invalid = 1;
                        break;
                    }
                }
            }
        }

        if(invalid == 1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        invalid = 0;
    }
    return 0;

}
