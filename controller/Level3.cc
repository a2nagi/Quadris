#include "Level3.h"

using namespace std;
Level3::Level3(){
    setLevel(3);
}

Block* Level3::getNextBlock(){
    if(getIsRandom()) {
        return this->getBlockFromFile();
    }
	int x = rand()%9;
	Block *b;

	if(x==1){
		b= new IBlock();
	}
	else if(x==3){
		b= new LBlock();
	}

	else if(x==4){
		b= new OBlock();
	}

	else if(x==5){
		b= new JBlock();
	}

	else if(x==6){
		b= new TBlock();
	}

	else if(x==2 || x==8){
		b= new SBlock();
	}

	else if(x==0 || x==7){
		b= new ZBlock();
	}

	return b;
}
