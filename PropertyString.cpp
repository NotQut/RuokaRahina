#include "PropertyString.hpp"

namespace rahina
{

PropertyString::PropertyString(PropertyOwner &ownerP, const std::string &nameP)
    : PropertyAbs(ownerP, nameP)
{
}

const std::string &PropertyString::getValue() const
{
    return valueM;
}

void PropertyString::setValue(const std::string &valueP)
{
    if (valueP == valueM)
        return;
    valueM = valueP;
}

} // rahina
