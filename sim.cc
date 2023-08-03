#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"
//#include "fsa_physics.cc"
#include "construction.hh" // inclusion of detector
#include "physics.hh" //inclusion of physics lists
#include "action.hh" //inclusion of particle generator
#include "Randomize.hh"
#include <random>

int main(int argc, char** argv)
{
	G4UIExecutive *ui = 0;

	std::random_device rd;
	std::mt19937 gen(rd());
	long seed = gen();
	CLHEP::HepRandom::setTheSeed(3);


	#ifdef G4MULTITHREADED
		G4MTRunManager *runManager = new G4MTRunManager();
	#else
		G4RunManager *runManager = new G4RunManager();
	#endif

	runManager->SetUserInitialization(new MyDetectorConstruction);
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());

	G4VModularPhysicsList* physics = new QGSP_BERT(); 
	physics->RegisterPhysics(new G4DecayPhysics());
	runManager->SetUserInitialization(physics);

	if(argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}

	G4VisManager *visManager = new G4VisExecutive();
	visManager->Initialize();

	G4UImanager *UImanager = G4UImanager::GetUIpointer();


	if(ui)
	{
		UImanager->ApplyCommand("/control/execute vis.mac");
		ui->SessionStart();
	}
	else
	{
		G4String command = "/control/execute ";
		G4String fileName = argv[1];
		UImanager->ApplyCommand(command+fileName);
	}

	ui->SessionStart();
	return 0;
}
