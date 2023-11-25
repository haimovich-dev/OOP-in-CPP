#ifndef Cake_H
#define Cake_H
#include <iostream>
#include "Date.h"

using namespace std;

class Cake{

    private:
        Date expiryDate;
        const int diameter;
        double height,price;
        int storage;
        bool gluttenFree;
    public:
        Cake(Date ed, const int d, double h, double p, int s, bool g):diameter(d),expiryDate(ed),
        height(h),price(p),storage(s),gluttenFree(g){
            cout<<"Cake Created : "<<endl;
        }
        bool operator==(const Cake& c) const {
            if(diameter!=c.diameter){
                return false;
            }
            if(height!=c.height){
                return false;
            }
            if(price!=c.price){
                return false;
            }
            if(storage!=c.storage){
                return false;
            }
            if(gluttenFree!=c.gluttenFree){
                return false;
            }else
            if(expiryDate==c.expiryDate){
                return true;
            }else{
                return false;
            }
        }
        void operator+=(double p){
            price+=p;
        }
        friend std::ostream& operator<<(std::ostream& os,Cake& cake){
            os<<cake.expiryDate;
            os<<"\nDiameter: "<<
            cake.diameter<<
            "\nHeight: "<<cake.height<<
            "\nPrice: "<<cake.price<<
            "\nStorage: "<<cake.storage<<
            "\nIs Glutten exists: "<<cake.gluttenFree;
            return os;
        }
        
};

#endif