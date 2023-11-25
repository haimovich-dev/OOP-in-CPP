#ifndef BirthCake_H
#define BirthCake_H
#include <iostream>
#include "Cake.h"
#include "Date.h"

class BirthCake:public Cake{

    private:
        Date expiryDate;
        const int diameter;
        double height,price;
        int storage;
        bool gluttenFree;
        char text[100];
    public:
        BirthCake(Date ed, const int d, double h, double p, int s, bool g,char * t)
        :Cake(ed,d,h,p,s,g),diameter(d),expiryDate(ed),
        height(h),price(p),storage(s),gluttenFree(g)
        {
            strncpy(text, t, sizeof(text) - 1);
            text[sizeof(text) - 1] = '\0';
            std::cout << "BirthCake Created : " << std::endl;
        }
        bool operator==(const BirthCake& mc){
            if(diameter!=mc.diameter){
                return false;
            }else if(height!=mc.height){
                return false;
            }else if(price!=mc.price){
                return false;
            }else if(storage!=mc.storage){
                return false;
            }else if(gluttenFree!= mc.gluttenFree){
                return false;
            }else if(text[0]!=mc.text[0]){
                return false;
            }else if(expiryDate==mc.expiryDate){
                return true;
            }else{
                return false;
            }
};
        void operator+=(double p){
            price+=p;
        }
        friend std::ostream& operator<<(std::ostream& os,BirthCake& birthcake){
            os<<birthcake.expiryDate;
            os<<"\nDiameter: "<<
            birthcake.diameter<<
            "\nHeight: "<<birthcake.height<<
            "\nPrice: "<<birthcake.price<<
            "\nStorage: "<<birthcake.storage<<
            "\nIs Glutten exists: "<<birthcake.gluttenFree<<
            "\nText: "<<birthcake.text<<endl;
            return os;
        }
};
#endif