#include "bmi.h"

const int BMI_CONVERSION_FACTOR = 703;

Bmi::Bmi(int feet, int inch, float weight)
    : mHeight_Feet(feet), mHeight_Inch(inch), mWeight(weight)
{

}

float Bmi::Calculate(QString &category)
{
    float value = 0.0;

    int total_inches = mHeight_Feet*12 + mHeight_Inch;

    value = mWeight / (total_inches *total_inches);
    value = value * BMI_CONVERSION_FACTOR;

    category = GetBmiCategory(value);

    return value;
}

void Bmi::SetHeightFeet(const int feet)
{
    mHeight_Feet = feet;
}

void Bmi::SetHeightInch(const int inch)
{
    mHeight_Inch = inch;
}

void Bmi::SetWeight(float weight)
{
    mWeight = weight;
}

QString Bmi::GetBmiCategory(const float bmiValue)
{
    QString     category = "None";

    if (WithinRange(static_cast<float>(1000.0),
                    static_cast<float>(30.1),
                    bmiValue))
    {
        category = "Obese";
    }

    else if (WithinRange(static_cast<float>(30.0),
                         static_cast<float>(25.1),
                         bmiValue))
    {
            category = "Overweight";
    }


    else if (WithinRange(static_cast<float>(25.0),
                         static_cast<float>(18.5),
                         bmiValue))
    {
        category = "Healthy";
    }

    else if (WithinRange(static_cast<float>(18.49),
                         static_cast<float>(0.1),
                         bmiValue))
    {
        category = "Underweight";
    }

    else
    {
        category = "invalid bmi value: " + QString::number(static_cast<double>(bmiValue));
    }

    return category;
}



bool Bmi::WithinRange(float top, float bottom, float value)
{
    bool success = false;

    // Trivial case all equal
    if (qFuzzyCompare(top, bottom) &&
       (qFuzzyCompare(top, value) || qFuzzyCompare(bottom, value)))
    {
        success = true;
    }

    if (!success)
    {
        success = (((value < top)    && !qFuzzyCompare(value, top)) &&
                   ((value > bottom) && !qFuzzyCompare(value, bottom)));
    }


    return success;
}
