#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.h"
class TBlock : public Block {
public:
    TBlock();
    Color getColor()override;
    void setRotationHeight(int height)override;
    void setRotationWidth(int width)override;
    ~TBlock();
};
#endif //TBLOCK_H
