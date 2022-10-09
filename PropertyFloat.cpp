#include "PropertyFloat.hpp"

namespace rahina
{

PropertyFloat::PropertyFloat(PropertyOwner &ownerP, const std::string &nameP)
    : PropertyAbs(ownerP, nameP)
{
}

float PropertyFloat::getValue() const
{
    return valueM;
}

void PropertyFloat::setValue(float valueP)
{
    if (valueP == valueM)
        return;
    valueM = valueP;
}

bool PropertyFloat::toString(std::string &stringOutP) const
{
    stringOutP = std::to_string(valueM);
    return true;
}

bool PropertyFloat::fromString(const std::string &stringInP)
{
    if (sscanf_s(stringInP.c_str(), "%f", &valueM) == 1)
        return true;
    return false;
}

} // rahina

