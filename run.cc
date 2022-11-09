#include "run.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->OpenFile("output.root");

	man->CreateNtuple("Hits", "Hits");
	man->CreateNtupleIColumn("fEvent"); //stands for Integer column
	man->CreateNtupleDColumn("fX");
	man->CreateNtupleDColumn("fY");
	man->CreateNtupleDColumn("fZ"); //these show position
	man->FinishNtuple(0); //this first set (ntuple) is labelled as number 0
}

void MyRunAction::EndOfRunAction(const G4Run*)
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();

	man->Write(); //root files are sensitive, if you don't do this it will corrupt the data
	man->CloseFile();
}
