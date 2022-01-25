Programul a fost realizat in Visual 2017.
Am plecat de la cele doua clase primite drept model:ConsoleInput,ConsoleOutput
Plantele sunt reprezentate cu litere:P,PS,WN,CB etc,zombie: Z, iar soarele cu: SUN.

AM implementate urmatoarele clase:
"Strategy.h" -> aceasta este clasa de baza pentru toate tipurile de sombie,in functie de abilitatile fiecaruia exista mai multe tipuri de strategii
"StrategyBucketHead.h"
"StrategyRegular.h"
"Zombie.h"- clasa de baza pentru toate tipurile de zombie
"SurfaceContainer.h"-> aceasta reprezinta field-urile. Level 1 are un 'Surface',Level 2 un vetor de 2 surface-uri iar Level 3 contine un vector de 3 'Surface'-uri
"Surface.h"
"Logger.h"-> aceasta clasa credeeaza un fisier de test pentru toate actiunile pe care vreau sa le testez sa vad daca merg( daca nu pot plasa o planta a anumite coordonate => mesajul va aparea in fisierul temporar de test)
"PlantCherryBomb.h"
"Plant.h"->clasa de baza pentru toate tipurile de plante
"PlantPeashooter.h"
"PlantSunflower.h"
"PlantWallnut.h"

