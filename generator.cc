#include "generator.hh"
#include "G4ParticleGun.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1); //1 particle per event

	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4ParticleDefinition *particle = particleTable->FindParticle("chargedgeantino");

	// generator for regolith
	G4ThreeVector pos(0., -15*m, -10.*m);
	G4ThreeVector mom(0., 3., 1.73);

/*
	//generator for cherenkov
	G4ThreeVector pos(0., 0., 0.); //created in center of mother volume
	G4ThreeVector mom(0., 0., 1); //sets momentum direction in positive set direction
*/
	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom); //again, just sets the direction of momentum doesn't create momentum
	fParticleGun->SetParticleMomentum(1000.*GeV); //set particle at very high momentum (original units meV)
	fParticleGun->SetParticleDefinition(particle);

}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleDefinition *particle = fParticleGun->GetParticleDefinition();

	if(particle == G4ChargedGeantino::ChargedGeantino())
	{
		G4int Z = 1;
		G4int A = 1;

		G4double charge = 1. *eplus;
		G4double energy = 0. *keV;

		G4ParticleDefinition *ion = G4IonTable::GetIonTable() -> GetIon(Z, A, energy);
		fParticleGun->SetParticleDefinition(ion);
		fParticleGun->SetParticleCharge(charge);
	}

	fParticleGun->GeneratePrimaryVertex(anEvent);
}
