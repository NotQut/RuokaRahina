#pragma once

#include "PropertyAbs.hpp"

namespace rahina
{

class PropertyString final : public PropertyAbs
{
public:
    PropertyString(PropertyOwner &ownerP, const std::string &nameP);
    virtual ~PropertyString() {}

    PropertyType getType() const override { return PropertyType::String; }

    bool toString(std::string &stringOutP) const override { stringOutP = valueM; return true; }
    bool fromString(const std::string &stringInP) override { setValue(stringInP); return true; }

    const std::string &getValue() const;
    void setValue(const std::string &valueP);

private:
    std::string valueM;
};

} // rahina

