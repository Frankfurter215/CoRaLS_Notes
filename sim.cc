#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "construction.hh" // inclusion of detector
#include "physics.hh" //inclusion of physics lists
#include "action.hh" //inclusion of particle generator

int main(int argc, char** argv)
{
std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << std::endl;
	#ifdef G4MULTITHREADED
		G4MTRunManager *runManager = new G4MTRunManager();
	#else
		G4RunManager *runManager = new G4RunManager();
	#endif
std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << std::endl;

        MyDetectorConstruction * mydetector = new MyDetectorConstruction();
std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << std::endl;

	runManager->SetUserInitialization(mydetector);
	runManager->SetUserInitialization(new MyPhysicsList());
	runManager->SetUserInitialization(new MyActionInitialization());
std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << std::endl;

	G4UIExecutive *ui = 0;

	if(argc == 1)
	{
		ui = new G4UIExecutive(argc, argv);
	}

std::cout << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << std::endl;
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
