#pragma once

#include "UnitInfo.hpp"
#include <array>

namespace rahina
{

class UnitBank;

class Simulator final
{
public:
    Simulator(const UnitBank &unitBankP);

    bool setUnits(const std::string &unitAP, const std::string &unitBP);
    void simulate();

    UnitInfo &getUnit(size_t indexP);
    const UnitInfo &getUnit(size_t indexP) const;

    size_t getNumUnits() const { return unitsM.size(); }

private:
    const UnitBank &unitBankM;
    std::array<UnitInfo, 2u> unitsM;
};

} // rahina

