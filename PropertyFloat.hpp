#pragma once

#include "PropertyAbs.hpp"

namespace rahina
{

class PropertyFloat final : public PropertyAbs
{
public:
    PropertyFloat(PropertyOwner &ownerP, const std::string &nameP);
    virtual ~PropertyFloat() {}

    PropertyType getType() const override { return PropertyType::Float; }

    bool toString(std::string &stringOutP) const override;
    bool fromString(const std::string &stringInP) override;

    float getValue() const;
    void setValue(float valueP);

private:
    float valueM{0.0f};
};

} // rahina

