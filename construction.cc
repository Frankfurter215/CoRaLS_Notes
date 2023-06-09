#include "construction.hh"
#include <iostream>
//i hate github-> its starting to grow on me

MyDetectorConstruction::MyDetectorConstruction()
{
	isCherenkov = false;
	isScintillator= false;
	isAtmosphere = false;
	isRegolith = true;
	
	detThic = 0.1*m;

	nCols = 1;
	nRows = 1;

	fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");

	fMessenger->DeclareProperty("nCols", nCols, "Number of Columns");
	fMessenger->DeclareProperty("nRows", nRows, "Number of Rows");
	fMessenger->DeclareProperty("Cherenkov", isCherenkov, "Toggle Cherenkov Setup");
	fMessenger->DeclareProperty("Scintillator", isScintillator, "Toggle Scintillator Setup");


	DefineMaterials();

	if(isCherenkov)
	{
	xWorld = 0.5*m;
	yWorld = 0.5*m;
	zWorld = 0.5*m;
	}

	if(isRegolith)
	{
	xWorld = 5.*m;
	yWorld = 5.*m; //defining x and y width of the world volume in variables
	zWorld = 5.*m;
	}
}

MyDetectorConstruction::~MyDetectorConstruction()
{}

void MyDetectorConstruction::DefineMaterials()
{
/*new
	G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2}; //conversion factor divided by wavelength in micrometer for red and blue light respectively
	G4double rindexAerogel[2] = {1.1, 1.1};// refractive index of aerogel constant for this example
	G4double rindexWorld[2] = {1.0, 1.0};
endnew*/
	G4NistManager *nist = G4NistManager::Instance();

	SiO2 = new G4Material("SiO2", 2.201*g/cm3, 2); // name (silicon dioxide), density of material, number of components)
	SiO2->AddElement(nist->FindOrBuildElement("Si"), 1); // adds the parts required to build the above material
	SiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	water = new G4Material("water", 1.000*g/cm3, 2);//water, not sure why the text is red in nano
        water->AddElement(nist->FindOrBuildElement("H"), 2);
        water->AddElement(nist->FindOrBuildElement("O"), 1);

	C = nist->FindOrBuildElement("C"); //Carbon, when making the sim it will give an error message for an unused variable, this can be ignored

	Aerogel = new G4Material("Aerogel", 0.200*g/cm3, 3);
	Aerogel->AddMaterial(SiO2, 62.5*perCent); //instead of density, if you know proportion you can do it that way
	Aerogel->AddMaterial(water, 37.4*perCent);
	Aerogel->AddElement(C, 0.1*perCent);

	//Define regolith
	Al2O3 = new G4Material("Al2O3", 3.95*g/cm3, 2);
	Al2O3->AddElement(nist->FindOrBuildElement("Al"), 2);
	Al2O3->AddElement(nist->FindOrBuildElement("O"), 3);

	CaO = new G4Material("CaO", 3.34*g/cm3, 2);
	CaO->AddElement(nist->FindOrBuildElement("Ca"), 1);
	CaO->AddElement(nist->FindOrBuildElement("O"), 1);

	MgO = new G4Material("MgO", 3.58*g/cm3, 2);
	MgO->AddElement(nist->FindOrBuildElement("Mg"), 1);
	MgO->AddElement(nist->FindOrBuildElement("O"), 1);

	TiO2 = new G4Material("TiO2", 4.23*g/cm3, 2);
	TiO2->AddElement(nist->FindOrBuildElement("Ti"), 1);
	TiO2->AddElement(nist->FindOrBuildElement("O"), 2);

	FeO = new G4Material("FeO", 5.74*g/cm3, 2);
	FeO->AddElement(nist->FindOrBuildElement("Fe"), 1);
	FeO->AddElement(nist->FindOrBuildElement("O"), 1);
	
	Regolith= new G4Material("Regolith", 1.5*g/cm3, 6);
	Regolith->AddMaterial(SiO2, 50.*perCent);
	Regolith->AddMaterial(Al2O3, 15*perCent);
	Regolith->AddMaterial(CaO, 10.*perCent);
	Regolith->AddMaterial(MgO, 10.*perCent);
	Regolith->AddMaterial(TiO2, 5*perCent);
	Regolith->AddMaterial(FeO, 10.*perCent);

	worldMat = nist->FindOrBuildMaterial("Regolith");

	G4double energy[2] = {1.239841939*eV/0.9, 1.239841939*eV/0.2}; //conversion factor divided by wavelength in micrometer for red and blue light respectively
	G4double rindexAerogel[2] = {1.1, 1.1};// refractive index of aerogel constant for this example
	G4double rindexWorld[2] = {1.55, 1.4};
	G4double rindexRegolith[2] = {1.55, 1.4}; //just used the rindex of silica

	G4MaterialPropertiesTable *mptAerogel = new G4MaterialPropertiesTable();
	mptAerogel->AddProperty("RINDEX", energy, rindexAerogel, 2); //adding properties of the aerogel so it radiates

	G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
	mptWorld->AddProperty("RINDEX", energy, rindexWorld, 2); //adding properties of the air so that radiation extends past radiator

	G4MaterialPropertiesTable *mptRegolith = new G4MaterialPropertiesTable();
	mptRegolith->AddProperty("RINDEX", energy, rindexRegolith, 2);

	Aerogel->SetMaterialPropertiesTable(mptAerogel);

	worldMat->SetMaterialPropertiesTable(mptWorld);

	Regolith->SetMaterialPropertiesTable(mptRegolith);

	NaI = new G4Material("NaI", 3.67*g/cm3, 2);
	NaI->AddElement(nist->FindOrBuildElement("Na"), 1);
	NaI->AddElement(nist->FindOrBuildElement("I"), 1);

	I = nist->FindOrBuildElement("I");

	G4double density0 = 1.29*kg/m3;
	G4double aN = 14.01*g/mole;
	G4double aO = 16.00*g/mole;
	
	N = new G4Element("Nitrogen", "N", 7, aN);
	O = new G4Element("Oxygen", "O", 8, aO);
	
	G4double f =3;
	G4double R = 8.31446261815; 
	G4double g0 = 9.81;
	G4double kappa = (f+2)/f;
	G4double T = 293.15;
	G4double M = (0.3*aO + 0.7*aN)/1000.;
	
	for(G4int i = 0; i<10; i++) 

	{ 
		std::stringstream stri; 
		stri << i; //converts i into string 
		G4double h = 40e3/10.*i; //calculates the height at each layer 
		G4double density = density0*pow((1-(kappa)/kappa*M*g0*h/(R*T)), (1/(kappa-1))); 
		Air[i] = new G4Material("G4_AIR_"+stri.str(), density, 2);  
		Air[i]->AddElement(N, 70*perCent); 
		Air[i]->AddElement(O, 30*perCent); 
	} 
}

void MyDetectorConstruction::ConstructCherenkov()
{
	solidRadiator = new G4Box("solidRadiator", 0.4*m, 0.4*m, 0.01*m); //name, length, width, thickness (each should be smaller than the world volume, and thickness should be much smaller

	logicRadiator = new G4LogicalVolume(solidRadiator, Aerogel, "logicalRadiator");

	physRadiator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicRadiator, "physRadiator", logicWorld, false, 0, true);
//creating photon detectors
	solidDetector = new G4Box("solidDetector", xWorld/nRows, yWorld/nCols, 0.01*m); // (half width, half length, half thickness)

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");//for this example it consists of world material


	for(G4int i = 0; i < nRows; i++)
	{
		for(G4int j = 0; j < nCols; j++)
			{
				physDetector = new G4PVPlacement(0, G4ThreeVector(-0.5*m+(i+0.5)*m/nRows, -0.5*m+(j+0.5)*m/nCols, 0.1*m), logicDetector, "physDetector", logicWorld, false, j+i*nCols, true);//j+i*10 means when i=0, j = 0-9 then you get 10-19 when i=1 and so on to get unique numbers for each detector
			}
	}

/*
Syntax of G4PVPlavement(rotation, placement(half width of world volume (so it starts on the side)+(shift to the right so it builds it centered instead of half outside), repeat, placement for thickness)
*/


}

void MyDetectorConstruction::ConstructScintillator()
{
	solidScintillator = new G4Box("solidScintillator", 5*cm, 5*cm, 6*cm);

	logicScintillator = new G4LogicalVolume(solidScintillator, NaI, "logicalScintillator");

	physScintillator = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicScintillator, "physScintillator", logicWorld, false, 0, true);
}

void MyDetectorConstruction::ConstructAtmosphere() 
{ 
  solidAtmosphere = new G4Box("solidAtmosphere", xWorld, yWorld, zWorld/10.); //zworld/10 b/c we want 10 layers 

  for(G4int i = 0; i < 10; i++) 
  { 
     logicAtmosphere[i] = new G4LogicalVolume(solidAtmosphere, Air[i], "logicAtmosphere"); 
     physAtmosphere[i] = new G4PVPlacement(0, G4ThreeVector(0, 0, zWorld/10.*2*i - zWorld +zWorld/10.), logicAtmosphere[i], "physAtmosphere", logicWorld, false, i, true); 
  } 
}
void MyDetectorConstruction::ConstructRegolith()
{
/*
    solidRegolith = new G4Box("solidRegolith", xWorld, yWorld, 9*zWorld/10.);
    logicRegolith = new G4LogicalVolume(solidRegolith, Regolith, "logicRegolith");
    physRegolith = new G4PVPlacement(0, G4ThreeVector(0., 0., -zWorld/10.), logicRegolith, "physRegolith", logicWorld, false, 0, true);
*/
	solidDetector = new G4Box("solidDetector", xWorld/nRows, yWorld/nCols, detThic); // (half width, half length, half thickness)

	logicDetector = new G4LogicalVolume(solidDetector, worldMat, "logicDetector");//for this example it consists of world material

	physDetector = new G4PVPlacement(0, G4ThreeVector(0., 0., zWorld-detThic), logicDetector, "physDetector", logicWorld, false, 0, true);//j+i*10 means when i=0, j = 0-9 then you get 10-19 when i=1 and so on to get unique numbers for each detector

}
 
void MyDetectorConstruction::ConstructSDandField()
{
	MySensitiveDetector *sensDet = new MySensitiveDetector("SensitiveDetector");

    if(logicDetector != NULL)
        logicDetector->SetSensitiveDetector(sensDet);

}


G4VPhysicalVolume *MyDetectorConstruction::Construct()
{

	solidWorld = new G4Box("solidWorld", xWorld, yWorld, zWorld); // width, length, height (taken in half measurements so here we get a full meter)

	logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

	physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

	if(isCherenkov)
		ConstructCherenkov();
	if(isScintillator)
		ConstructScintillator();
	if(isAtmosphere)
		ConstructAtmosphere();
	if(isRegolith)
	  ConstructRegolith();

	return physWorld;
}
