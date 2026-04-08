#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int count[5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        count[arr[i]]++;
    }
    int taxis=0;
    taxis+= count[4];
    taxis+= count[3];
    count[1]=max(0,count[1]-count[3]);
    taxis+= count[2]/2;
    if(count[2]%2==1){
        count[1]=max(0,count[1]-2);
    }
    taxis+=count[1]/4 +1;
    cout<<taxis;
    return taxis;
}