#include "generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator()
{
	fParticleGun = new G4ParticleGun(1); //1 particle per event
}

MyPrimaryGenerator::~MyPrimaryGenerator()
{
	delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
	G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
	G4String particleName="proton"; //for this were trying a proton
	G4ParticleDefinition *particle = particleTable->FindParticle("proton");

	G4ThreeVector pos(0., 0., 0.); //created in center of mother volume
	G4ThreeVector mom(0., 0., 1.); //sets momentum direction in positive set direction

	fParticleGun->SetParticlePosition(pos);
	fParticleGun->SetParticleMomentumDirection(mom); //again, just sets the direction of momentum doesn't create momentum
	fParticleGun->SetParticleMomentum(100.*GeV); //set particle at very high momentum (original units meV)
	fParticleGun->SetParticleDefinition(particle);

	fParticleGun->GeneratePrimaryVertex(anEvent);
}
