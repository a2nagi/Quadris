#include "Controller.h"

using namespace std;

Controller::Controller(Grid *g): g{g} {}

void Controller::parseCommand(){

    string s;
    bool match;
    int multiple=1;

    //The commands in Regular Expression
    regex left(".lef.*");//Arjan
    regex right(".ri.*");//Arjan
    regex down(".do.*");//Arjan
    regex clockwise(".cl.*");//Arjan
    regex counterclockwise(".co.*");//Arjan
    regex drop(".dr.*");//Arjan or Harkamal
// 	regex levelup(".levelu.*");//Sarthak
// 	regex leveldown(".leveld.*");//Sarthak
// 	regex norandom(".nor.*");//Sarthak
// 	regex random(".ra.*");//Sarthak
// 	regex sequence(".s.*");//Sarthak
// 	regex blocks(".[IJLOSZT]");//Sarthak
// 	regex restart(".re.*");//Sarthak
// 	regex hint(".h*");//Harkamal

    while(cin>>s){

        istringstream ss{s};
        ss>>multiple;

        if(regex_match(s,left)){

            for(int i=0;i<multiple;i++){
                g->moveCurrentBlockLeftRight(Direction::left);
            }
        }

        else if(regex_match(s,right)){
            for(int i=0;i<multiple;i++){
                g->moveCurrentBlockLeftRight(Direction::right);
            }
        }

        else if(regex_match(s,down)){
            for(int i=0;i<multiple;i++){
                g->moveCurrentBlockDown(Direction::down);
            }
        }

        else if(regex_match(s,clockwise)){
            for(int i=0;i<multiple;i++){
                g->rotateBlock(Rotate::clockWise);
            }
        }

        else if(regex_match(s,counterclockwise)){
            for(int i=0;i<multiple;i++){
                g->rotateBlock(Rotate::counterClockWise);
            }
        }

        else if(regex_match(s,drop)){
            g->dropBlock();
        }

//		else if(regex_match(s,levelup)){
//			for(int i=0;i<multiple;i++){
//				g->
//			}
//			currLevel=newLevel(currLevel); //Do we need to Refresh
//		}
//
//		else if(regex_match(s,leveldown)){
//
//			for(int i=0;i<multiple;i++){
//				currlevel--;
//			}
//			currlevel=newLevel(curLevel);//Do we need to Refresh
//		}
//
//		else if(regex_match(s,norandom)){
//			string filename;
//			ifstream f;
//			f.open(filename);
//			char c;
//			while(f>>c){
//
//			}
//
//		}
//
//		else if(regex_match(s,random)){
//
//		}
//
//		else if(regex_match(s,sequence)){//Applicable to level
//			string filename;
//			ifstream f;
//			f.open(filename);
//			char c;
//			while(f>>c){
//				currLevel->getNextBlock(c);
//			}
//		}
//
//		else if(regex_match(s,blocks)){
//			currLevel->getNextBlock(s);
//		}
//
//		else if(regex_match(s,restart)){
//
//		}
//
//		else if(regex_match(s,hint)){
//
//		}


    }
}
