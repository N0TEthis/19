#include <iostream>
using namespace std;

class Traveler {
private:
    double v1, v2, v3;// скорости
    double t1, t2, t3;// время на участках

public:
    Traveler(double v1, double t1, double v2, double t2, double v3, double t3)
        : v1(v1), t1(t1), v2(v2), t2(t2), v3(v3), t3(t3) {}

    // весь путь
    double TotalDistance() const {
        return v1 * t1 + v2 * t2 + v3 * t3;
    }

    // время, за которое пройдена половина пути
    double TimeToHalf() const {
        double s1 = v1 * t1;
        double s2 = v2 * t2;
        double half = TotalDistance() / 2;

        if (half == 0) return 0;// путь нулевой

        if (half <= s1)// половина1
            return half / v1;
        else if (half <= s1 + s2)// половина2
            return t1 + (half - s1) / v2;
        else// половина3
            return t1 + t2 + (half - s1 - s2) / v3;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
cout << "привет!" << endl;
    char again;// продолжать или нет

    do {
        double v1, t1, v2, t2, v3, t3;
        
        cout << "введите v1 t1: "; cin >> v1 >> t1;// например 4 2
        cout << "введите v2 t2: "; cin >> v2 >> t2;
        cout << "введите v3 t3: "; cin >> v3 >> t3;

        Traveler man(v1, t1, v2, t2, v3, t3);
        cout << "половину пути пройдено за " << man.TimeToHalf() << " ч" << endl;

        cout << "\nпосчитать ещё раз? (y - да, n - нет): ";
        cin >> again;
        cout << endl;

    } while (again == 'y' || again == 'Y');

    cout << "до встречи!" << endl;
    return 0;
}