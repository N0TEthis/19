#include <iostream>
using namespace std;

//участок пути скорость и время 
class Leg {
private:
    double v, t;

public:
    Leg(double v, double t) : v(v), t(t) {}
    double Speed() const { return v; }
    double Time() const { return t; }
    double Distance() const { return v * t; }//длина участка
};
// путник состоит из трёх участков
class Traveler {
private:
    Leg a, b, c;
public:
    Traveler(Leg a, Leg b, Leg c) : a(a), b(b), c(c) {}

    double TotalDistance() const {
        return a.Distance() + b.Distance() + c.Distance();}

    double TimeToHalf() const {
        double half = TotalDistance() / 2;

        if (half == 0) return 0;

        if (half <= a.Distance())//половина1
            return half / a.Speed();
        else if (half <= a.Distance() + b.Distance())//половина2
            return a.Time() + (half - a.Distance()) / b.Speed();
        else//половина3
            return a.Time() + b.Time()
                 + (half - a.Distance() - b.Distance()) / c.Speed();}
};
int main() {
    setlocale(LC_ALL, "RU");
    cout << "привет!" << endl;
    char again;
    do {
        double v1, t1, v2, t2, v3, t3;

        cout << "введите v1 t1: "; cin >> v1 >> t1;//например 4 2
        cout << "введите v2 t2: "; cin >> v2 >> t2;
        cout << "введите v3 t3: "; cin >> v3 >> t3;

        Traveler man(Leg(v1, t1), Leg(v2, t2), Leg(v3, t3));
        cout << "половину пути пройдено за " << man.TimeToHalf() << " ч" << endl;

        cout << "\nпосчитать ещё раз? (y - да, n - нет): ";
        cin >> again;
        cout << endl;
    } while (again == 'y' || again == 'Y');
    cout << "до встречи!" << endl;
    return 0;
}