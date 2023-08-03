#include "run.hh"
#include "generator.hh"
#include <sstream>

MyRunAction::MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
/*
	man->CreateNtuple("Photons", "Photons");
	man->CreateNtupleIColumn("fEvent"); //stands for Integer column
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ"); //these show position
	man->CreateNtupleDColumn("fwlen"); //shows wavelength
	man->FinishNtuple(0); //this first set (ntuple) is labelled as number 0
*/
	man->CreateNtuple("Hits", "Hits");

	man->CreateNtupleSColumn("partNames");
	man->CreateNtupleDColumn("Z");
	man->CreateNtupleDColumn("nrg");
	//man->CreateNtupleDColumn("wavelength");
	man->FinishNtuple(0);

//	man->CreateNtupleSColumn("partNames");
//	man->FinishNtuple(0); //this second set (ntuple) is labelled as number 1
/*
	man->CreateNtuple("Scoring", "Scoring");
	man->CreateNtupleDColumn("fEdep");
	man->FinishNtuple(2); //ntuple for nrg deposition
*/
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	G4int runID = run->GetRunID();

	std::stringstream strRunID;
	strRunID << runID;

/*
	G4Random::showEngineStatus();
	seed = G4Random::getTheSeed();
	std::stringstream strseed;
	strseed << seed;
*/
	man->OpenFile("photonprimarty"+strRunID.str()+".root");
//	man->OpenFile("photonprimary"+strpe.str()+".root");

/*
	man->CreateNtuple("Hits", "Hits");
	man->CreateNtupleSColumn("partNames");
	man->CreateNtupleDColumn("Z");
	man->CreateNtupleDColumn("nrg");
	//man->CreateNtupleDColumn("wavelength");
	man->FinishNtuple(0);
*/
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->Write(); //root files are sensitive, if you don't do this it will corrupt the data
	man->CloseFile();
}
