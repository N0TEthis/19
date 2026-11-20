#pragma once   //защита от повторного подключения файла
class Traveler {
private:
    double v1, t1, v2, t2, v3, t3;
public:
    Traveler(double v1, double t1, double v2, double t2, double v3, double t3);
    double TimeToHalf() const;
};