#pragma once

#include "PropertyFloat.hpp"
#include "PropertyOwner.hpp"
#include "PropertyString.hpp"

namespace rahina
{

class UnitInfo final : public PropertyOwner
{
    DECL_STRING_PROP(Name);
    DECL_FLOAT_PROP(Health);
    DECL_FLOAT_PROP(Attack);
    DECL_FLOAT_PROP(Defence);
    DECL_FLOAT_PROP(Delay);

public:
    UnitInfo();
};

} // rahina

