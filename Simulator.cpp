#include "Simulator.hpp"

#include "UnitBank.hpp"
#include <cassert>
#include <iostream>

namespace rahina
{

Simulator::Simulator(const UnitBank &unitBankP)
    : unitBankM{unitBankP}
{
}

UnitInfo &Simulator::getUnit(size_t indexP)
{
    assert(indexP < unitsM.size());
    return unitsM[indexP];
}

const UnitInfo &Simulator::getUnit(size_t indexP) const
{
    assert(indexP < unitsM.size());
    return unitsM[indexP];
}

bool Simulator::setUnits(const std::string &unitAP, const std::string &unitBP)
{
    if (!unitAP.empty())
    {
        if (!unitBankM.findInfo(unitAP, unitsM[0u]))
            return false;
    }
    if (!unitBP.empty())
    {
        if (!unitBankM.findInfo(unitBP, unitsM[1u]))
            return false;
    }
    return true;
}

void Simulator::simulate()
{
    struct SimUnit
    {
        float healthRemainingM{0.0f};
        float nextActionTimeM{0.0f};
    };

    std::array<SimUnit, 2u> simUnits{
        SimUnit{unitsM[0].getEnergia(), unitsM[0].getDelay()}, SimUnit{unitsM[1].getEnergia(), unitsM[1].getDelay()}};

    size_t winner = ~0u;

    std::cout << "Simuation begins" << std::endl;

    for (;;)
    {
        float simTime = std::min(simUnits[0u].nextActionTimeM, simUnits[1u].nextActionTimeM);
        for (size_t i = 0; i < unitsM.size(); ++i)
        {
            if (simTime == simUnits[i].nextActionTimeM)
            {
                size_t otherIndex = i == 0u ? 1u : 0u;
                UnitInfo &thisUnit = unitsM[i];
                UnitInfo &otherUnit = unitsM[otherIndex];

                float dmg = thisUnit.getHiilihydraatti() * (1.0f - otherUnit.getProteiini() * 0.01f);
                simUnits[otherIndex].healthRemainingM -= dmg;

                std::cout << simTime << ": " << thisUnit.getName() << " attacked " << otherUnit.getName() << " for " << dmg << " damage - "
                    << otherUnit.getName() << " has " << simUnits[otherIndex].healthRemainingM << " health remaining" << std::endl;

                if (simUnits[otherIndex].healthRemainingM <= 0.0f)
                {
                    winner = i;
                    break;
                }
                simUnits[i].nextActionTimeM += thisUnit.getDelay();
            }
        }
        if (winner != ~0u)
        {
            std::cout << "*** " << unitsM[winner].getName() << " wins the match! ***" << std::endl;
            break;
        }
    }
}

} // rahina
