#include"ConsoleInput.h"
#include"ConsoleOutput.h"
#include"Soare.h"
#include"Teren.h"
#include"Zombie.h"

string GameLoop()
{

    string logEv = " ";
    UserInterface::ConsoleOutput conOut = UserInterface::ConsoleOutput::getInstance();
    UserInterface::ConsoleInput conIn = UserInterface::ConsoleInput::getInstance();

    Soare SunController;

    bool clickSunflower = 0;
    bool clickPea = 0;
    int k = 0;
    int SunPos;
    int Xpos;
    int Ypos;
    int collectSunPos;
    int xBox = 0;
    int yBox = 0;
    int zombiePosition;

    int spawnZombieCounter = 0;
    bool secondWaveRewind = 0;
    int gameClock = 0;
    int timer = 200;

    int peaNumber;

    int zombieCounter1 = 0;
    int zombieCounter = 0;
    int shootPeaCounter = 0;

    while (Teren::getInstance()->getGameOver() != 1)
    {


        Ypos = -99;
        Xpos = -99;
        peaNumber = Teren::getInstance()->getPeanumber();

        SunController.CheckSun(Teren::getInstance()->getSunFlowerCount());
        if (SunController.getBool() == 1)
        {
            SunPos = SunController.getSunPosition();
            Teren::getInstance()->renewSun(SunPos);




            SunController.resetSun();

        }




        conOut(1, 0) << "  SCORE: " << Teren::getInstance()->getScore() << "      \n";
        conOut(2, 0) << "  RESOURCES: " << Teren::getInstance()->getRes() << "      " << "\n";

        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 55; j++)
            {
                cout << Teren::getInstance()->getMat(i, j);
            }
            cout << endl;
        }

        std::string action = conIn.getUserActions();
        if (action != "")
        {

            conOut(41, 2) << action;
            Xpos = conIn.lastX;
            Ypos = conIn.lastY;

            if ((Ypos == 4 || Ypos == 5))
            {
                clickSunflower = 0;
                collectSunPos = Teren::getInstance()->clickSun(Xpos);
                if (collectSunPos != -999)
                {
                    Teren::getInstance()->collectSun(collectSunPos);
                    logEv = logEv + "Clicked Sun\n";

                }
            }

            else if ((Ypos == 9 || Ypos == 10) && (Xpos == 2 || Xpos == 3 || Xpos == 4))
            {

                clickSunflower = 1;
                clickPea = 0;
                conOut(40, 2) << "ClickSunFlower " << "     ";
                logEv = logEv + "Clicked SunFlower\n";

            }
            else if ((Ypos == 12 || Ypos == 13) && (Xpos == 2 || Xpos == 3 || Xpos == 4))
            {
                clickSunflower = 0;
                clickPea = 1;
                conOut(40, 2) << "ClickPea " << "     ";
                logEv = logEv + "Clicked Pea\n";
            }
            else if (Ypos == 9 || Ypos == 10 || Ypos == 12 || Ypos == 13 || Ypos == 15 || Ypos == 16 || Ypos == 18 || Ypos == 19 || Ypos == 21 || Ypos == 22)
            {
                if (Xpos == 20 || Xpos == 21 || Xpos == 22 || Xpos == 26 || Xpos == 27 || Xpos == 28 || Xpos == 32 || Xpos == 33 || Xpos == 34 || Xpos == 38 || Xpos == 39 || Xpos == 40 || Xpos == 44 || Xpos == 45 || Xpos == 46 || Xpos == 50 || Xpos == 51 || Xpos == 52 || Xpos == 56 || Xpos == 57 || Xpos == 58 || Xpos == 62 || Xpos == 63 || Xpos == 64 || Xpos == 68 || Xpos == 69 || Xpos == 70)
                {
                    if (clickSunflower == 1)
                    {
                        logEv = logEv + "SunFlower Box Select\n";
                        conOut(40, 2) << "Getting Box SF" << "     ";
                        Teren::getInstance()->getBox(Xpos, Ypos, yBox, xBox); // yBox apoi xBox
                        Teren::getInstance()->plantSunflower(xBox, yBox);  // invers!!!
                        clickSunflower = 0;
                        logEv = logEv + "SunFlower Planted\n";
                    }
                    if (clickPea == 1)
                    {
                        logEv = logEv + "Pea Box Select\n";
                        conOut(40, 2) << "Getting Box P" << "     ";
                        Teren::getInstance()->getBox(Xpos, Ypos, yBox, xBox);
                        Teren::getInstance()->plantPea(xBox, yBox);
                        clickPea = 0;
                        logEv = logEv + "Pea Planted\n";
                    }

                }
            }
            else
            {
                conOut(40, 2) << "EMPTY" << "     ";
                clickSunflower = 0;
                clickPea = 0;


            }


        }


        for (int i = 0; i < peaNumber; i++)
        {
            if (Teren::getInstance()->getPea(i).getShot() == 0)
            {
                Teren::getInstance()->PeaShoot(i);


            }
            else
            {
                if (shootPeaCounter % 3 == 0 && Teren::getInstance()->getPea(i).dead == 0)
                {
                    Teren::getInstance()->moveProjOnePosition(i);

                }
            }

        }
        shootPeaCounter++;



        if (gameClock <= timer + 1000)
        {
            if (zombieCounter1 <= 3)
            {
                if (spawnZombieCounter % 10 == 0)
                {
                    if (Teren::getInstance()->CheckZombieSpawn() == 1)
                    {
                        zombiePosition = Teren::getInstance()->setPositionForZombie();
                        Teren::getInstance()->printZombie(zombiePosition);
                        logEv = logEv + "Zombie Spawned\n";

                    }

                    for (int i = 0; i < Teren::getInstance()->getZombieNumber(); i++)
                    {
                        if (Teren::getInstance()->getZombie(i).getAlive() == 1)
                        {
                            Teren::getInstance()->moveZombie(i);


                        }
                    }
                }
            }

            if (zombieCounter1 > 3 && gameClock >= timer)
            {
                if (spawnZombieCounter % 15 == 0)
                {
                    if (secondWaveRewind == 0)
                    {
                        Teren::getInstance()->rewindZombieCounter();
                        Teren::getInstance()->rewindZFull();
                        secondWaveRewind = 1;
                    }


                    if (Teren::getInstance()->CheckZombieSpawn() == 1)
                    {
                        zombiePosition = Teren::getInstance()->setPositionForZombie();
                        Teren::getInstance()->printZombie(zombiePosition);

                    }

                    for (int i = 0; i < Teren::getInstance()->getZombieNumber(); i++)
                    {
                        if (Teren::getInstance()->getZombie2(i).getAlive() == 1)
                        {
                            Teren::getInstance()->moveZombie(i);

                        }
                    }
                }
            }







        }
        if (gameClock > timer + 500)
        {
            if ((spawnZombieCounter % 10) == 0)
            {
                if (Teren::getInstance()->CheckZombieSpawn() == 1)
                {
                    zombiePosition = Teren::getInstance()->setPositionForZombie();
                    Teren::getInstance()->printZombieG(zombiePosition);
                    logEv = logEv + "Bucket Zombie Spawned\n";

                }

                for (int i = 0; i < Teren::getInstance()->getZombieGNumber(); i++)
                {
                    if (Teren::getInstance()->getZombieG(i).getAlive() == 1)
                    {
                        Teren::getInstance()->moveZombieG(i);

                    }
                }
            }
        }

        spawnZombieCounter++;

        gameClock++;









        return logEv;




    }
}