#include "construction.hh"
#include <iostream>


MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
	G4NistManager *nist = G4NistManager::Instance();

	G4Material *SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2); // name (silicon dioxide), density of material, number of components)
	SiO2->AddElement(nist->FindOrBuildElement("Si"), 1); // adds the parts required to build the above material
	SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	G4Material *water = new G4Material("water", 1.000*g/cm3, 2);//water, not sure why the text is red in nano
        water->AddElement(nist->FindOrBuildElement("H"), 2);
        water->AddElement(nist->FindOrBuildElement("O"), 1);

	G4Element *C = nist->FindOrBuildElement("C"); //Carbon, when making the sim it will give an error message for an unused variable, this can be ignored

	G4Material *Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
	Aerogel->AddMaterial(SiO2, 62.5*perCent); //instead of density, if you know proportion you can do it that way
	Aerogel->AddMaterial(water, 37.4*perCent);
	Aerogel->AddElement(C, 0.1*perCent);

	G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2}; //conversion factor divided by wavelength in micrometer for red and blue light respectively
	G4double rindexAerogel[2] = {1.1, 1.1};// refractive index of aerogel constant for this example
	G4double rindexWorld[2] = {1.0, 1.0};

	G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
	mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2); //adding properties of the aerogel so it radiates

	Aerogel->SetMaterialPropertiesTable(mptAerogel);

	G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2); //adding properties of the air so that radiation extends past radiator

	worldMat->SetMaterialPropertiesTable(mptWorld);

	G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m); // width, length, height (taken in half measurements so here we get a full meter)

	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

	G4Box *solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m); //name, length, width, thickness (each should be smaller than the world volume, and thickness should be much smaller

	G4LogicalVolume *logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicalRadiator");

	G4VPhysicalVolume *physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);
//creating photon detectors
	G4Box *solidDetector = new G4Box("solidDetector", 0.005*m, 0.005*m, 0.01*m); // (half width, half length, half thickness)

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");//for this example it consists of world material

	for(G4int i = 0; i < 100; i++)
	{
		for(G4int j = 0; j < 100; j++)
			{
				G4VPhysicalVolume *physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/100, -0.5*m+(j+0.5)*m/100, 0.49*m), logicDetector, "physDetector", logicWorld, false, j+i*10, true);//j+i*10 means when i=0, j = 0-9 then you get 10-19 when i=1 and so on to get unique numbers for each detector
			}
	}
/*
Syntax of G4PVPlavement(rotation, placement(half width of world volume (so it starts on the side)+(shift to the right so it builds it centered instead of half outside), repeat, placement for thickness)
*/

	return physWorld;
}

void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

	logicDetector->SetSensitiveDetector(sensDet);

}
