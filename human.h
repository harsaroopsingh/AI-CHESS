#ifndef HUMAN_H
#define HUMAN_H

#include "player.h"

class Human: public Player {
    public:
        Human();
        ~Human();
        void undo() override;
};

#endif 

