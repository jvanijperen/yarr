#include "UserInteractor.h"

#include "InputException.h"

UserInteractor::UserInteractor() {
}

UserInteractor::~UserInteractor() {
}

void UserInteractor::run() {
	try {
		run_loop();
	} catch (InputException &e) {
	}
}

void UserInteractor::run_loop() {
	// while(true) {
//	dataSourceShower.showChoices(dataSourceCache);
//	auto choice = dataSourceSelector.getChoice(dataSourceCache.size());
//	handleChoice(choice);
//	}


//	auto dataSource = dataSourceCache.get(choice);
//	auto line = dataSource.getLine();
//	dataSourceShower.showLine(line);
}
