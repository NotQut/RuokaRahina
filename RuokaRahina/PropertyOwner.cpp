#include "PropertyOwner.hpp"

#include "external/tinyxml2/tinyxml2.h"
#include <cassert>

namespace rahina
{

void PropertyOwner::registerProperty(PropertyAbs &propertyP, const std::string &nameP)
{
    const auto itr = propertiesM.find(nameP);
    if (itr != propertiesM.end())
    {
        assert(0 && "Duplicate property name");
        return;
    }
    propertiesM.insert({nameP, &propertyP});
}

PropertyAbs *PropertyOwner::findProperty(const std::string &nameP)
{
    auto itr = propertiesM.find(nameP);
    if (itr != propertiesM.end())
        return itr->second;
    return nullptr;
}

const PropertyAbs *PropertyOwner::findProperty(const std::string &nameP) const
{
    auto itr = propertiesM.find(nameP);
    if (itr != propertiesM.end())
        return itr->second;
    return nullptr;
}

bool PropertyOwner::read(const tinyxml2::XMLElement *xmlElementP)
{
    bool success = true;
    for (auto itr = propertiesM.begin(), end = propertiesM.end(); itr != end; ++itr)
    {
        const tinyxml2::XMLAttribute *attrb = xmlElementP->FindAttribute(itr->first.c_str());
        if (attrb == nullptr)
            continue;
        if (!itr->second->fromString(attrb->Value()))
            success = false;
    }
    return success;
}

} // rahina

