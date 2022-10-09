#include "UnitBank.hpp"

#include "UnitInfo.hpp"
#include "external/tinyxml2/tinyxml2.h"
#include <iostream>

namespace rahina
{
 
bool UnitBank::readInfos(const std::string &fileP)
{
    infosM.clear();

    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(fileP.c_str()) != tinyxml2::XML_SUCCESS)
    {
        std::cout << "Failed to read file from: " << fileP.c_str() << std::endl;
        return false;
    }

    tinyxml2::XMLElement *root = doc.RootElement();

    bool success = true;
    static const std::string unitStr("unit");
    for (tinyxml2::XMLElement *element = root->FirstChildElement(unitStr.c_str()); 
        element != nullptr; element = element->NextSiblingElement(unitStr.c_str()))
    {
        auto nfo = std::make_unique<UnitInfo>();
        if (nfo->read(element))
            infosM.insert({nfo->getName(), std::move(nfo)});
        else
            success = false;
    }
    return success;
}

bool UnitBank::findInfo(const std::string &nameP, UnitInfo &unitOutP) const
{
    auto itr = infosM.find(nameP);
    if (itr == infosM.end())
    {
        std::cout << "Couldn't locate unit named: " << nameP << std::endl;
        return false;
    }
    unitOutP = *itr->second.get();
    return true;
}

} // rahina

