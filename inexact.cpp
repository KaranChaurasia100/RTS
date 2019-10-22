#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cout<<"Enter number of tasks";
cin>>n;
float exec[20],period[20];
for(int i=0;i<n;i++){
cout<<"Enter period  for task "<<i+1<<" ";
cin>>period[i];
cout<<"Enter execution time for task "<<i+1<<" ";
cin>>exec[i];
}
float ut=0,ua=0;
for(int i=0;i<n;i++){
    ut+=(exec[i]/period[i]);
}
float y=(float)n;
y=(y*(pow(2.0,1/y)))-1;
ua=y;
if(ut<=ua)
cout<<"The system is surely schedulable";
else
 cout<<"Not sure.It may or may not be schedulable";
 return 0;
}
