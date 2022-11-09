#include "detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name)
{}

MySensitiveDetector::~MySensitiveDetector()
{}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
	G4Track *track = aStep->GetTrack();

	track->SetTrackStatus(fStopAndKill);

	G4StepPoint *preStepPoint = aStep->GetPreStepPoint(); //Gets point where photon initially enters the sensitive volume
	G4StepPoint *postStepPoint = aStep->GetPostStepPoint(); //info from where photon leaves detector

	G4ThreeVector posPhoton = preStepPoint->GetPosition();

	//G4cout << "Photon position:" << posPhoton << G4endl; //gives exact position of photon in coordinate system

	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4int copyNo = touchable->GetCopyNumber(); //gets the number of the detector defined by i+j*10

	//G4cout << "Copy Number:" << copyNo << G4endl; 

	G4VPhysicalVolume *physVol = touchable->GetVolume();
	G4ThreeVector posDetector =  physVol->GetTranslation();

	G4cout << "Detector Position:" << posDetector << G4endl; //gives the position of the detector that detected a hit

	G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

	G4AnalysisManager *man = G4AnalysisManager::Instance();
	man->FillNtupleIColumn(0, evt);
	man->FillNtupleDColumn(1, posDetector[0]);
	man->FillNtupleDColumn(2, posDetector[1]);
	man->FillNtupleDColumn(3, posDetector[2]);
	man->AddNtupleRow(0);

	return true;
}
