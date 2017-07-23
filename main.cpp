#include <iostream>
#include <string>
using namespace std;

int isLeap(int year);
int totalDays(int year, int month);
int start(int year, int month);

int main() {



    return 0;
}

int start(int year, int month){
    
}

int isLeap(int year){
    return ((year&400 == 0) || (year%4 == 0 && year%100 == 0));
}

int totalDays(int year, int month){
    switch (month){
        case 2: return isLeap(year)?29:28;
        case 4: case 6: case 9: case 11: return 30;
        default: return 31;
    }
}