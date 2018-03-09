#ifndef menu_h
#define menu_h

#include <iostream>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
            this->history_index = -1;
            
		};
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
            if(history_index < 0) {
                cout << 0 << endl;
                return;
            }
            cout << this->history.at(history_index)->execute() << endl;
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruciton
			//This is necessary because that is the base of a calculation
            if(this->history_index >= 0) return true;
            return false;
		};
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
           
            this->history.push_back(cmd);
            this->history_index += 1;
            
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
            return this->history[this->history_index];
            
		};
		void undo() {
			//Moves to the last command in history (if possible)
            
            if(this->history_index > 0) {
                history_index -= 1;
                return;
            }
            
            cout << "Error\n";
		};
		void redo() {
			//Moves to the next command in history (if possible)
            
            if(this->history_index < (int)this->history.size()-1) {
                ++ history_index;
                return;
            }
            cout << "Error\n";
		};
};

#endif //__MENU_CLASS__
