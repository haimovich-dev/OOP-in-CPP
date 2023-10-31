#include <iostream>
#include "Date.h"
#include "Trip.h"
#include <string>
#include <cstring>

using namespace std;

char * getString(){
    string s;
    cin >> s;
    const int length = s.length();
    char * dst = new char[length+1];
    strcpy(dst, s.c_str());
    return dst;
}
bool isEmpty(int size){
    if(size == 0){
        cout<<"No trips setten yet\n";
        return true;
    }else{
        return false;
    }
}
void Print(Trip * arr, int size){
    if(!isEmpty(size)){
        for(int i=0;i<size;i++){
            arr[i].PrintTrip();
        }
    }
}
void EditTrip(Trip * arr, int size){
    int id;
    cout<<"Enter trip's ID you would like to change: ";
    cin>>id;

    bool isFound = false;

    for(int i=0;i<size;i++){
        if(arr[i].getID()==id){
            isFound = true;
            char opt;
            cout<<"Do you want to change destination? [y/n]: ";
            cin>>opt;
            if(opt=='y'){
                char * dst = getString();
                arr[i].setDestination(dst);
            }
            cout<<"Do you want to change date? [y/n]: ";
            cin>>opt;
            if(opt=='y'){
                int d,m,y;

                cout<<"\nEnter trip's day: ";
                cin>>d;
                cout<<"\nEnter trip's month: ";
                cin>>m;
                cout<<"\nEnter trip's year: ";
                cin>>y;

                arr[i].setDate(new Date(d,m,y));
            }
        }
    }
    if(!isFound){
        cout<<"Not found"<<endl;
    }
}
Trip * AddTrip(Trip * arr, int size){

    int newsize = size + 1;
    int * id = new int;
    *id = newsize;

    Trip * tmpArr = new Trip[newsize];
    for(int i=0;i<size;i++){
        tmpArr[i] = arr[i];
    }

    int d,m,y;

    cout<<"\nEnter trip's destination: ";
    char * name = getString();
    cout<<"\nEnter trip's day: ";
    cin>>d;
    cout<<"\nEnter trip's month: ";
    cin>>m;
    cout<<"\nEnter trip's year: ";
    cin>>y;

    Trip * newT = new Trip(id,name,new Date(d,m,y));
    tmpArr[size] = *newT;
    return tmpArr;
}

int main(){
    int option;
    Trip * array = new Trip[0];
    int size = 0;
    do{
        cout<<"\nPlease select an option: \n----------------\n1.Print Trips\n2.Edit Trip\n3.Add Trip\n4.Exit\n----------------"<<endl;
        cin>>option;
        cout<<"\n";
        switch (option){
            case 1:
                Print(array,size);
                break;
            case 2:
                EditTrip(array,size);
                break;
            case 3:
                array = AddTrip(array,size);
                size++;
                break;
            case 4:
                cout<<"Bye Bye!"<<endl;
                break;
            default:
                cout<<"Invalid option"<<endl;
                break;
        }
    }while(option != 4);

    return 0;
}

/*Date * date = new Date(30,12,2004);
    int * id = new int;
    *id = 10;
    Trip * trip1 = new Trip(id,"Danil",date);
    Trip * trip2 = new Trip();

    trip1->PrintTrip();
    trip2->PrintTrip();*/
