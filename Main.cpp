#include "Simulator.hpp"
#include "UnitBank.hpp"

#include <iostream>
#include <string>
#include <vector>

void printUsage()
{
    std::cout   << "Usage:" << std::endl
                << " rahina.exe path_to_unit_file name_of_unit_a name_of_unit_b"
                << std::endl;
}

int main(int argc, char *argv[])
{
    std::vector<std::string> args(argv + 1, argv + argc);

    if (args.size() != 3)
    {
        printUsage();
        return 1;
    }

    rahina::UnitBank unitBank;
    if (!unitBank.readInfos(args[0]))
        return 1;

    rahina::Simulator simulator(unitBank);
    if (!simulator.setUnits(args[1], args[2]))
        return 1;

    simulator.simulate();

    return 0;
}

