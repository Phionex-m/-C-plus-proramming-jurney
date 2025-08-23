#include <iostream>


using namespace std;

int main(){

    int size;
    cout<<"Enter the size of te array"<<endl;
    cin>>size;
    cout<<"Enter the elemnts of the array"<<endl;
    int arr[size];
    
    for (int i=0;i<size;i++){

        cin>>arr[i];

    }

    int max =arr[0];
    int min = arr[0];

    for(int x=1;x<size;x++){
        if( arr[x]>max)
        max = arr[x];
       

        if( arr[x]<min)
        min = arr[x];
        
    }
       
    cout<<"The Largest number is "<<max<<endl;
    cout<<"The Smallest number is "<<min<<endl;
   
system("pause");
    
    return 0;
}