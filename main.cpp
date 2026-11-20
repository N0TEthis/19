#include <iostream>
#include "19.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    char again;
    do {
        double v1, t1, v2, t2, v3, t3;
        cout << "введите v1 t1: "; cin >> v1 >> t1;//например 4 2
        cout << "введите v2 t2: "; cin >> v2 >> t2;
        cout << "введите v3 t3: "; cin >> v3 >> t3;
        Traveler man(v1, t1, v2, t2, v3, t3);
        cout << "половину пути пройдено за " << man.TimeToHalf() << " ч" << endl;
        cout << "посчитать ещё раз? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');
    return 0;
}