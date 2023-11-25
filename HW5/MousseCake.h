#ifndef MousseCake_H
#define MousseCake_H
#include <iostream>
#include "Cake.h"
#include "Date.h"

class MousseCake:public Cake{

    private:
        Date expiryDate;
        const int diameter;
        double height,price;
        int storage;
        bool gluttenFree;
        char taste[100];
    public:
        MousseCake(Date ed, const int d, double h, double p, int s, bool g,char * t)
        :Cake(ed,d,h,p,s,g),diameter(d),expiryDate(ed),
        height(h),price(p),storage(s),gluttenFree(g)
        {
            strncpy(taste, t, sizeof(taste) - 1);
            taste[sizeof(taste) - 1] = '\0';
            std::cout << "MousseCake Created : " << std::endl;
        }
        bool operator==(const MousseCake& mc){
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
            }else if(taste[0]!=mc.taste[0]){
                return false;
            }else if(expiryDate==mc.expiryDate){
                return true;
            }else{
                return false;
            }
        }
        void operator+=(double p){
            price+=p;
        }
        friend std::ostream& operator<<(std::ostream& os,MousseCake& moussecake){
            os<<moussecake.expiryDate;
            os<<"\nDiameter: "<<
            moussecake.diameter<<
            "\nHeight: "<<moussecake.height<<
            "\nPrice: "<<moussecake.price<<
            "\nStorage: "<<moussecake.storage<<
            "\nIs Glutten exists: "<<moussecake.gluttenFree<<
            "\nTaste: "<<moussecake.taste<<endl;
            return os;
        }
};

#endif