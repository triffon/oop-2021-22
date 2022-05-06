#pragma once

#include "computer.h"

class ConsultantUtils
{
public:
    static bool isGoodForGaming(const Computer& computer);
    static bool isGoodForTravel(const Computer& computer);
};