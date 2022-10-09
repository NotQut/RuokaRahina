#pragma once

#include "PropertyFloat.hpp"
#include "PropertyOwner.hpp"
#include "PropertyString.hpp"

namespace rahina
{

class UnitInfo final : public PropertyOwner
{
    DECL_STRING_PROP(Name);
    DECL_FLOAT_PROP(Energia);
    DECL_FLOAT_PROP(Hiilihydraatti);
    DECL_FLOAT_PROP(Proteiini);
    DECL_FLOAT_PROP(Rasva);

public:
    UnitInfo();

    float getDelay() const { return getProteiini() + getHiilihydraatti() + getRasva(); }
};

} // rahina

