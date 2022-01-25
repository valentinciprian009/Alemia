#include "Plant.h"
#include "Zombie.h"

namespace Arena
{
	const std::array<PlantInfo, 5> BasicPlant::plants = {
		PlantInfo(0, 3, "Pea Shooter", "peashooter.txt", 5),
		PlantInfo(1, 3, "Sunflower", "sunflower.txt", 4),
		PlantInfo(2, 3, "Wall Nut", "wallnut.txt", 10),
		PlantInfo(3, 1, "Cherry Bomb", "peashooter.txt", 3),
		PlantInfo(4, 5, "Frozen Shooter", "peashooter.txt", 5)
	};

	const std::array<ZombieInfo, 4> BasicZombie::zombies = {
		ZombieInfo("Basic Zombie", "zombie.txt", 6, 800, 50),
		ZombieInfo("Bucket Head Zombie", "bucketzombie.txt", 10, 900, 100),
		ZombieInfo("Pole Vaulting Zombie", "polezombie.txt", 5, 700, 75),
		ZombieInfo("Super Zombie", "zombie.txt", 10, 800, 150)
	};
}