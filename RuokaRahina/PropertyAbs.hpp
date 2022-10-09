#pragma once

#include <string>

namespace rahina
{

class PropertyOwner;

enum class PropertyType
{
    Float,
    String
};

class PropertyAbs
{
public:
    PropertyAbs(PropertyOwner &ownerP, const std::string &nameP);
    virtual ~PropertyAbs() {}

    virtual PropertyType getType() const = 0;

    virtual bool toString(std::string &stringOutP) const = 0;
    virtual bool fromString(const std::string &stringInP) = 0;

    virtual PropertyAbs &operator=(const PropertyAbs &other);

    PropertyAbs(PropertyAbs &other) = delete;
    PropertyAbs(PropertyAbs &&other) = delete;
};


} // rahina

