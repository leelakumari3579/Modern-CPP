#include "Engine.h"

Engine::Engine(std::string engineNumber, EngineType engineType, int engineHorsepower, int engineTorque)
    :_engineNumber(engineNumber), _engineType(engineType), _engineHorsepower(engineHorsepower), _engineTorque(engineTorque)
{
}

std::ostream &operator<<(std::ostream &os, const Engine &rhs)
{
    // TODO: insert return statement here
    os << "_engineNumber: " << rhs._engineNumber
       << "_engineType: " << static_cast<int>(rhs._engineType)
       << "_engineHoursepower: " << rhs._engineHorsepower
       << "_engineTorque: " << rhs._engineTorque;
    return os;
}
