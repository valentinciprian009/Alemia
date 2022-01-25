//
// Created by null on 1/9/2020.
//

#ifndef INC_250_DRAWABLE_H
#define INC_250_DRAWABLE_H


#include "../ConsoleOutput.h"

class Drawable {
protected:
    int width;
    int height;

    Drawable() = default;
    UserInterface::ConsoleOutput* output;

public:
    int row_offset = 0;
    int column_offset = 0;
    Drawable(UserInterface::ConsoleOutput* output, int rowOffset, int colOffset);
    virtual void draw() = 0;
    virtual ~Drawable() = default;
    virtual void clean();
    void setOffset(int row, int column);

    int getWidth();
    int getHeight();
};


#endif //INC_250_DRAWABLE_H
