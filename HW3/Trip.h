#ifndef Trip_H
#define Trip_H
#include "Date.h"
#include <iostream>

class Trip{
    private:
        int * id;
        char * destination[100];
        Date * date;
    
    public:
        int getID(){return *this->id;}
        char * getDestination(){return this->destination[0];}
        Date * getDate(){return this->date;}

        void setID(int * id){
            if(*id>0){
                this->id = id;
            }else{
                this->id = new int;
            }
        }
        void setDestination(char * n){
            this->destination[0] = n;
        }
        void setDate(Date * d){
            this->date = d;
        }

        Trip(int * id, char * n, Date * d){
            setID(id);
            setDestination(n);
            setDate(d);
        }
        Trip(const Trip * t){
            *this = t;
        }
        Trip(){
            this->id = new int;
            //this->destination[0];
            for(int i=0;i<100;i++){
                this->destination[i]=new char;
            }
            this->date = new Date();
        }

        ~Trip(){// Destructor
            delete id;
            for(int i=0;i<100;i++){
                delete[] this->destination[i];
            }
            delete date;
        }

        void PrintTrip(){
            std::cout<<"ID: "<<this->getID()<<"\nName: "<<this->getDestination()<<"\nDate: ";
            this->getDate()->PrintDate();
        }

        Trip * change(const Trip * t){
            *this = t;
            return this;
        }
};

#endif