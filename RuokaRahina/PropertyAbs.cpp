#include "PropertyAbs.hpp"

#include "PropertyOwner.hpp"
#include <cassert>

namespace rahina
{

PropertyAbs::PropertyAbs(PropertyOwner &ownerP, const std::string &nameP)
{
    ownerP.registerProperty(*this, nameP);
}

PropertyAbs &PropertyAbs::operator=(const PropertyAbs &other)
{
    assert(getType() == other.getType());
    std::string tmp;
    other.toString(tmp);
    fromString(tmp);

    return *this;
}

} // rahina
