#include <iostream>
#include "19.h"

//конструктор
Traveler::Traveler(double v1, double t1, double v2, double t2, double v3, double t3)
    : v1(v1), t1(t1), v2(v2), t2(t2), v3(v3), t3(t3) {}

//время, за которое пройдена половина пути
double Traveler::TimeToHalf() const {
    double s1 = v1 * t1;//длина1
    double s2 = v2 * t2;//длина2
    double s3 = v3 * t3;//длина3
    double H = (s1 + s2 + s3) / 2;//половина пути

    if (H <= s1)//половина1
        return H / v1;
    if (H <= s1 + s2)// =половина2
        return t1 + (H - s1) / v2;
    return t1 + t2 + (H - s1 - s2) / v3;//половина3
}