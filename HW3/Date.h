#ifndef Date_H
#define Date_H
#include <iostream>

class Date{
    private:
        int day,month,year;
    
    public:
        int getDay(){return this->day;}
        int getMonth(){return this->month;}
        int getYear(){return this->year;}

        void setDay(int d){
            if((d>0)&&(d<31)){
                this->day = d;
            }else{
                this->day = 0;
            }
        }
        void setMonth(int m){
            if((m>0)&&(m<13)){
                this->month = m;
            }else{
                this->month = 0;
            }
        }
        void setYear(int y){
            this->year = y;
        }

        Date(int d, int m, int y){
            setDay(d);
            setMonth(m);
            setYear(y);
        }
        Date(){
            this->day = 1;
            this->month = 1;
            this->year = 1;
        }

        void PrintDate(){
            std::cout<<this->day<<"."<<this->month<<"."<<this->year<<std::endl;
        }
};

#endif