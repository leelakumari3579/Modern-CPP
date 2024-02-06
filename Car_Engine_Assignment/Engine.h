#ifndef ENGINE_H
#define ENGINE_H
#include <string>
#include <ostream>
#include "EngineType.h"


class Engine
{
private:
    const std::string _engineNumber{""};
    const EngineType _engineType{EngineType::HYBRID};
    int _engineHorsepower{0};
    int _engineTorque{0};

public:
    Engine() = default;
    Engine(const Engine&) = default;
    Engine& operator=(const Engine&) = delete;
    Engine(Engine&&) = default;
    Engine& operator=(Engine&&) = delete;
    ~Engine() = default;

    // Engine defEngine()
    // {
    //     return Engine();
    // }

    Engine(std::string engineNumber, EngineType engineType, int engineHorsepower, int engineTorque);

    std::string engineNumber() const { return _engineNumber; }

    EngineType engineType() const { return _engineType; }

    int engineHorsepower() const { return _engineHorsepower; }
    void setEngineHorsepower(int engineHorsepower) { _engineHorsepower = engineHorsepower; }

    int engineTorque() const { return _engineTorque; }
    void setEngineTorque(int engineTorque) { _engineTorque = engineTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Engine &rhs);

};

#endif // ENGINE_H