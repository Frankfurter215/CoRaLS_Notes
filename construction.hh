#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh" // includes more  units for meters since G4 runs in mm - change units with <#>*<unit>
#include "G4GenericMessenger.hh"
#include "detector.hh"
/*
Author: Frank
*/

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
	MyDetectorConstruction();
	~MyDetectorConstruction();

//	G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; } //I think this is about det efficiency but trying it for debugging

	virtual G4VPhysicalVolume *Construct();
	void ConstructCherenkov();
	void ConstructScintillator();
	void ConstructAtmosphere();
  void ConstructRegolith();

private:
	G4LogicalVolume *logicDetector;
	virtual void ConstructSDandField();

	G4int nCols, nRows;

  G4Box *solidWorld, *solidRadiator, *solidDetector, *solidScintillator, *solidAtmosphere, *solidRegolith;
  G4LogicalVolume *logicWorld, *logicRadiator, *logicScintillator, *logicAtmosphere[10], *logicRegolith;
  G4VPhysicalVolume *physWorld, *physRadiator, *physDetector, *physScintillator, *physAtmosphere[10], *physRegolith;

	G4GenericMessenger *fMessenger;

  G4Material *SiO2, *water, *Aerogel, *worldMat, *NaI, *Air[10], *Al2O3, *CaO, *MgO, *TiO2, *FeO, *Regolith;
  G4Element *C, *Na, *I, *N, *O;

	void DefineMaterials();

	G4double xWorld, yWorld, zWorld, detThic;
  G4bool isCherenkov, isScintillator, isAtmosphere, isRegolith;
};

#endif
