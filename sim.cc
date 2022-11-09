#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh" // inclusion of detector
#include "physics.hh" //inclusion of physics lists
#include "action.hh" //inclusion of particle generator

int main(int argc, char** argv)
{
	G4RunManager *runManager = new G4RunManager();

        MyDetectorConstruction * mydetector = new MyDetectorConstruction();

	runManager->SetUserInitialization(mydetector);
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());

	runManager->Initialize();

	G4UIExecutive *ui = new G4UIExecutive(argc, argv);

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();

	G4UImanager *UImanager = G4UImanager::GetUIpointer();

	UImanager->ApplyCommand("/vis/open OGL"); //automatically opens visual in sim
	UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1"); //changes the initial position (how it views the detector)
	UImanager->ApplyCommand("/vis/drawVolume"); //draws volumes on open
	UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true"); //updates every time you create an event
	UImanager->ApplyCommand("/vis/scene/add/trajectories smooth"); //draws smooth trajectories, you can replace this with other types of trajectories
	UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate"); //displays all events at once if you run more than one

	ui->SessionStart();
	return 0;
}
