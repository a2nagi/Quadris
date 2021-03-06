#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include "Block.h"
#include "../model/Grid.h"
#include "Controller.h"
#include "../view/TextDisplay.h"

using namespace std;

Controller::Controller(Grid *g,TextDisplay *td): g{g},td{td} {

    //The commands in Regular Expression
    left = new regex("lef");
    right = new regex("ri");
    down = new regex("do");
    clockwise = new regex("cl");
    counterclockwise = new regex("co");
    drop = new regex("dr");
    levelup = new regex("levelu");
    leveldown = new regex("leveld");
    norandom = new regex("^nor");
    random = new regex("^ra");
    sequence = new regex("^s");
    block = new regex("^[IJLOSZT]$");
 	restart = new regex("^re");
 	hint = new regex("^h");

    cout << *td;
};

void Controller::parseCommand(istream *inputStream){

    int multiple=1;
    string s;
    while(getline(*inputStream, s)){
        if(isdigit(s[0])) {
            multiple = stoi(s);
        }
        else {
            multiple = 1;
        }

        if(regex_search(s,*norandom)){
            istringstream noRandomFileName{s};
            string fileName;
            noRandomFileName >> fileName >> fileName;
            g->makeCurrentLevelFromFile(fileName);
        }

        else if(regex_search(s, *random)) {
            g->makeCurrentLevelRandom();
        }

        else if(regex_search(s, *sequence)) {
            istringstream sequenceFile{s};
            string fileName;
            sequenceFile >> fileName >> fileName;
            fstream *file = new fstream(fileName);
            parseCommand(file);
            delete file;
        }
        else if(regex_search(s, *block)) {
            g->replaceCurrentBlock(s.at(0));
            cout << *td << endl;
        }
        else if(regex_search(s, *restart)) {
            g->clearGrid();
            cout << *td << endl;
        }
        else if(regex_search(s, *hint)) {
            g->showHint();
            cout << *td << endl;
        }

        else if(regex_search(s,*left)){
            try {
                g->moveCurrentBlockLeftRight(Direction::left, multiple);
                cout<<*td;
            }catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);
            }
        }

        else if(regex_search(s,*right)){
            try {
                g->moveCurrentBlockLeftRight(Direction::right, multiple);
                cout<<*td;
            }catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);
            }
        }

        else if(regex_search(s,*down)){
            try {
                g->moveCurrentBlockDown(multiple);
                cout<<*td;
            }
            catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);
            }

        }

        else if(regex_search(s,*clockwise)){
            multiple = multiple%4;
            try {
                g->rotateBlock( multiple );
                cout<<*td;
            }catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);

            }
        }

        else if(regex_search(s,*counterclockwise)){
            try{
                multiple = 4 - (multiple%4);
                g->rotateBlock(multiple);
                cout<<*td;
            }catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);

            }
        }

        else if(regex_search(s,*drop)){
            try {
                for(int i = 0; i < multiple; i++) {
                    g->dropBlock();
                }
                cout<<*td;
            }catch (gameOver) {
                cout << "Game Over!! Press any key to quit" << endl;
                getline(cin, s);
                exit(0);
            }

        }

        else if(regex_search(s,*levelup)){
            g->nextLevel(multiple);
        }

        else if(regex_search(s,*leveldown)){
            g->levelDown(multiple);
        }

        else {
            cout << "Invalid command! Please try again" << endl;
        }
    }
}

