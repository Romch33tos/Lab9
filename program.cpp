#include <iostream>
using namespace std;

// Функция для проверки високосного года
bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

// Функция для получения количества дней в месяце
int getDaysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } if (month == 2) {
        return isLeapYear(year) ? 29 : 28; // тернарный оператор
    } else {
        return 31;
    }
}

// Определяем начальный день по формуле Зеллера
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int day = 1; 
    int f = day + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) - (2 * j);
    f = f % 7; 
    return (f + 5) % 7;
}

// Функция для вывода календаря
void printMonth(int month, int year) {
    cout << "\n\t\t" << month << "/" << year << endl;
    cout << "Пн Вт Ср Чт Пт Сб Вс" << endl;

    int daysInMonth = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    // Пробелы
    for (int i = 0; i < startDay; i++) {
        cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; day++) {
        cout << (day < 10 ? " " : "") << day << " "; 
        if ((startDay + day) % 7 == 0) {
            cout << endl; 
        }
    }
}


int main() {
    int year;
    
    cout << "Введите год: ";
    cin >> year;

    for (int month = 1; month <= 12; month++) {
        printMonth(month, year);
    }

    return 0;
}
