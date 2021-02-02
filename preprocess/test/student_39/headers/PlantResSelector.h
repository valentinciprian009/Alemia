//
// Created by null on 1/10/2020.
//

#ifndef INC_250_PLANTRESSELECTOR_H
#define INC_250_PLANTRESSELECTOR_H


#include "../drawable/Drawable.h"
#include "../plant/Plant.h"
#include <vector>

class PlantResSelector : public Drawable {
private:
    std::vector<Plant*> plants;
    int rowHeight;
    int selectedPlant = -1;
public:
    PlantResSelector(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset, int rowHeight);
    Plant* getSelectedPlant(EventManager * manager, int row, int col, int *availableMoney);
    void selectPlantAt(int row, int col);
    std::string getSelectedPlantString();
    void draw() override;
};


#endif //INC_250_PLANTRESSELECTOR_H
