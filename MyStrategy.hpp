#ifndef _MY_STRATEGY_HPP_
#define _MY_STRATEGY_HPP_

#include "model/Game.hpp"
#include "model/Action.hpp"

#include "Observer.h"
#include "FlyingController.h"
#include "WarController.h"
#include "Cycle.h"
#include "Planet.h"
#include "Terms.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

enum {
	WORKER = 0,
	LOGIST = 1,
	COMBAT = 2,
};

class MyStrategy {
public:
	MyStrategy();
	model::Action getAction(const model::Game& game);

	int population;
	set<int> teamPlayers; //ids of teammates
	int homePlanet;
	vector<int> teamHomePlanets;
	vector<int> enemyHomePlanets;
	vector<Planet> planetInf;
	vector<vector<int>> planetDists;
	vector<vector<int>> logDists; //distances between planets for logists
	void init(const model::Game& game);
	void separatePlanets(const model::Game& game);

	int resetTimer;
	Cycle prodCycle;

	int role;

	FlyingController fc;
	Observer observer;
	WarController warController;
};

#endif
