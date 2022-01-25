//
// Created by null on 1/10/2020.
//

#include "PlantResSelector.h"

void PlantResSelector::draw() {
    int textOffset = row_offset;
    for(auto p : plants){
        p->draw();
        textOffset += rowHeight;
        (*output)(textOffset-4, column_offset-1 ) << "cost: " << p->getCost();
    }
}

PlantResSelector::PlantResSelector(UserInterface::ConsoleOutput *output, int rowOffset, int colOffset,  int rowHeight) : Drawable(
        output, rowOffset, colOffset), rowHeight(rowHeight) {
    plants.push_back(new Plant(output, rowOffset, colOffset, NULL, PEA_SHOOTER, false));
    plants.push_back(new Plant(output, rowOffset + rowHeight, colOffset, NULL, CHERRY_BOMB, false));
    plants.push_back(new Plant(output, rowOffset + 2*rowHeight, colOffset, NULL, WALL_NUT, false));
    plants.push_back(new Plant(output, rowOffset + 3*rowHeight, colOffset, NULL, SNOW_PEA, false));
    plants.push_back(new Plant(output, rowOffset + 4*rowHeight, colOffset, NULL, SUNFLOWER, false));

}


Plant* PlantResSelector::getSelectedPlant(EventManager * manager, int row, int col, int* availableMoney){
    PlantType t[] = {
            PEA_SHOOTER,
            CHERRY_BOMB,
            WALL_NUT,
            SNOW_PEA,
            SUNFLOWER
    };
    if(selectedPlant != -1){
       auto p =  new Plant(output, row, col, manager, t[selectedPlant]);
        selectedPlant = -1;
       if(*availableMoney >= p->getCost()) {
           *availableMoney -= p->getCost();
           if(*availableMoney < 0)
               *availableMoney = 0;
           return p;
       }else{
           delete p;
           return  NULL;
       }

    }
    return  NULL;
}

void PlantResSelector::selectPlantAt(int row, int col){
    if(col < 7){
        int i = (row - row_offset)/(rowHeight);
        if(row - row_offset >=0 && i < plants.size()){
            selectedPlant = i;
        }
    }
}

std::string PlantResSelector::getSelectedPlantString(){
    std::string s[] = {
        "Pea shooter",
        "Cherry bomb",
        "Wall nut",
        "Snow pea",
        "Sun flower"
    };
    if(selectedPlant != -1){
        return  s[selectedPlant] + " selected!";
    }
    return "                    ";
}

