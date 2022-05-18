#include "consultantUtils.h"

bool ConsultantUtils::isGoodForGaming(const Computer& computer)
{
    std::string processor = computer.getProcessor();
    std::size_t video = computer.getVideo();
    double hardDrive = computer.getHardDrive();

    return (processor == "i5" || processor == "i7") &&
           (video == 3060 || video == 3070 || video == 3080 || video == 3090) &&
           (hardDrive >= 512);
}

bool ConsultantUtils::isGoodForTravel(const Computer& computer)
{
    double weight = computer.getWeight();
    double batteryLife = computer.getBatteryLife();

    return weight <= 2.5 && batteryLife > 6;
}