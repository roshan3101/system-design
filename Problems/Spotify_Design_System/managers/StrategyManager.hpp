#pragma once
#include <iostream>
#include "../strategy/SequentialStrategy.hpp"
#include "../strategy/CustomStrategy.hpp"
#include "../strategy/RandomStrategy.hpp"
#include "../enums/StrategyType.hpp"

class StrategyManager {
private:
    static StrategyManager* instance;
    SequentialStrategy* sequentialStrategy;
    RandomStrategy* randomStrategy;
    CustomStrategy* customStrategy;

    StrategyManager() {
        sequentialStrategy = new SequentialStrategy();
        randomStrategy = new RandomStrategy();
        customStrategy = new CustomStrategy();
    }
public:
    static StrategyManager* getInstance() {
        if (!instance) {
            instance = new StrategyManager();
        }
        return instance;
    }

    PlayStrategy* getStrategy(StrategyType type) {
        switch (type) {
        case StrategyType::SEQUENTIAL:
            return sequentialStrategy;
        case StrategyType::RANDOM:
            return randomStrategy;
        case StrategyType::CUSTOM:
        default:
            return customStrategy;
        }
    }
};

StrategyManager* StrategyManager::instance = nullptr;