#include <iostream>

using namespace std;

double WeightedAverage(double weights[4], double values[4]){
    /*
    This function gets 2 arrays, one is weights and the second one is values
    this function multiply weights by values acording to their arrays indexer
    and divids the result by the result of summaraized values
    */
    double top = 0.0;
    double bottom = 0.0;
    for(int i=0;i<4;i++){
        top+=weights[i]*values[i];
        bottom+=values[i];
    }
    return top/bottom;
}

int main(){
    double weights[] = {0.2, 0.3, 0.4, 0.5};
    double values[] = {2, 3, 4, 5};
    cout << "Result: " << WeightedAverage(weights,values) << endl;
    delete weights, values; // free memory
    return 0;
}