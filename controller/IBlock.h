#ifndef IBLOCK_H_H
#define IBLOCK_H_H

#include "Block.h"
class IBlock : public Block {
public:
    IBlock();
    virtual void move();
    virtual void rotate();
};
#endif //IBLOCK_H
