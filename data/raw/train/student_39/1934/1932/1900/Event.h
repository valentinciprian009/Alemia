//
// Created by null on 1/10/2020.
//

#ifndef INC_250_EVENT_H
#define INC_250_EVENT_H

enum Event{
    SPAWN_NEW_PROJECTILE,
    EXPLOSION,
    MOUSE_CLICK,
};
class EventManager {

public:
    virtual void onEvent(Event event, int row, int col, void* data) = 0;
};

extern EventManager* GAME_EVENT_MANAGER;
#endif //INC_250_EVENT_H
