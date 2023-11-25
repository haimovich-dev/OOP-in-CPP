#ifndef Date_H
#define Date_H
#include <iostream>

using namespace std;

class Date{

    private:
        int day,month,year;
    public:

        int const getDay(){
            return this->day;
        }
        int const getMonth(){
            return this->month;
        }
        int const getYear(){
            return this->year;
        }

        void setDay(int d){
            if((d>0)&&(d<32)){
                this->day = d;
            }else{
                this->day = 31;
                cout<<"Invalid day value (1-31)"<<endl;
            }
        }
        void setMonth(int m){
            if((m>0)&&(m<13)){
                this->month = m;
            }else{
                this->month = 12;
                cout<<"Invalid month value (1-12)"<<endl;
            }
        }
        void setYear(int y){
            if(y>2000){
                this->year = y;
            }else{
                this->year = 2024;
                cout<<"Invalid year value (year > 2000)"<<endl;
            }
        }

        Date(){
            this->day = 0;
            this->month = 0;
            this->year = 2024;
        }
        Date(int d,int m, int y){
            setDay(d);
            setMonth(m);
            setYear(y);
        }

        void printDate(){
            cout<<getDay()<<"."<<getMonth()<<"."<<getYear()<<endl;
        }
        bool operator==(const Date d) const{
            if(day != d.day){
                return false;
            }else
            if(month != d.month){
                return false;
            }else
            if(year != d.year){
                return false;
            }else{
                return true;
            }
        }
        friend std::ostream& operator<<(std::ostream& os, const Date& d){
            os<<"Day: "<<d.day<<"\nMonth: "<<d.month<<"\nYear: "<<d.year;
            return os;
        }
};

#endif