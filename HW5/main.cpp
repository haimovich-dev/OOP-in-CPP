#include <iostream>
#include "Date.h"
#include "Cake.h"
#include "MousseCake.h"
#include "BirthdayCake.h"

using namespace std;

bool test(){
    return true;
}

int main(){

    Date d1 = Date(12,03,2004);
    Date d2 = Date(14,02,2010);
    Cake c1 = Cake(d1,2,3,25.9,701,true);
    cout<<c1<<endl;


    return 0;
}