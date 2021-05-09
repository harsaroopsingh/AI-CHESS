#ifndef COMPUTER_H
#define COMPUTER_H

#include "player.h"

class Computer: public Player {
    public:
        Computer(int level);
        ~Computer();
        void undo() override;
};

#endif

