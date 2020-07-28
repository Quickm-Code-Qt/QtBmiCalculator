#ifndef BMI_H
#define BMI_H

#include <QString>



class Bmi
{
public:
    Bmi() = default;
    Bmi(int feet, int inch, float weight);

    float Calculate(QString & category);

    void    SetHeightFeet(const int feet);
    void    SetHeightInch(const int inch);
    void    SetWeight(float weight);

protected:
    void    SetBmiCategory(const float bmiValue);
    int     CompareNumbers(float a, float b);
    bool    WithinRange(float top, float bottom, float value);

private:
    int     mHeight_Feet;
    int     mHeight_Inch;
    float   mWeight;

    float   mBmi;

    QString mBmiCategory;
};

#endif // BMI_H
