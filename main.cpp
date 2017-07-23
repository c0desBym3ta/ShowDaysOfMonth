#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int isLeap(int year);
int totalDays(int year, int month);
int start(int year, int month);
int showCalendar(int year, int month);

int main() {
    int year, month;
    cout << "\nEnter year: "; cin >> year;
    cout << "Enter month: "; cin >> month;
    showCalendar(year,month);
    cout << endl;

    system("pause");
    return 0;
}

int start(int year, int month){
    int table[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    int y =year-(month<3);
    return (year + year/4 -year/100 + year/400 + table[month-1] + 1)%7;
}

int showCalendar(int year, int month){
    string monthName [] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int day, days, dow;

    days=totalDays(year,month);
    dow=start(year,month);
    cout << endl;
    cout << "\t" << monthName[month-1] << " " << year << endl;
    cout << " SUN MON TUE WED THU FRI SUT" << endl;
    cout << " --- --- --- --- --- --- ---" << endl;
    for(auto i = 0; i<dow; i++ ){
        cout << "    ";
    }
    for(day = 1; day < days; day++){
        cout << setw(4) << right << day;
        if(++dow>6){ dow = 0; cout << endl;}
    }
    cout << endl;

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