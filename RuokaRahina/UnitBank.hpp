#pragma once

#include <memory>
#include <string>
#include <unordered_map>

namespace rahina
{

class UnitInfo;

using InfoMap = std::unordered_map<std::string, std::unique_ptr<UnitInfo>>;

class UnitBank final
{
public:
    bool readInfos(const std::string &fileP);
    bool findInfo(const std::string &nameP, UnitInfo &unitOutP) const;

    const InfoMap &getInfos() const { return infosM; }

private:
    InfoMap infosM;
};

} // rahina

