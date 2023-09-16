#include <iostream>

using namespace std;

bool IsArithmeticProgression(int *p, int size=3){
    int d = p[1]-p[0];
    for(int i=1;i<size-1;i++){
        if(p[i+1]-p[i]!=d){
            return false;
        }
    }
    return true;
}

bool IsArithmeticProgression(char *p, int size=3){
    int d = (int)p[1]-(int)p[0];
    for(int i=1;i<size-1;i++){
        if((int)p[i+1]-(int)p[i]!=d){
            return false;
        }
    }
    return true;
}

int main(){

    int len = 0;
    cout << "Enter length of array: ";
    cin >> len;
    if(len < 3){
        int *arr = new int[3];
        for(int i=0;i<3;i++){
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }
        cout << "Result: " << IsArithmeticProgression(arr) << endl;
        delete [] arr;
    }else{
        int *arr = new int[len];
        for(int i=0;i<len;i++){
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }
        cout << "Result: " << IsArithmeticProgression(arr,len) << endl;
        delete [] arr;
    }

    int len = 0;
    cout << "Enter length of array: ";
    cin >> len;
    if(len < 3){
        char *arr = new char[3];
        for(int i=0;i<3;i++){
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }
        cout << IsArithmeticProgression(arr) << endl;
        delete [] arr;
    }else{
        char *arr = new char[len];
        for(int i=0;i<len;i++){
            cout << "[" << i << "]: ";
            cin >> arr[i];
        }
        cout << IsArithmeticProgression(arr,len) << endl;
        delete [] arr;
    }
    return 0;
}