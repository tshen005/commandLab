#ifndef command_h
#define command_h

#include "composite.h"

class Command {
	protected:
		Base* root;
	
	public:
		Command() {};
		double execute() {
            return this->root->evaluate();
		}
    
		Base* get_root() {
			return this->root;
		}
};

class OpCommand : public Command {
	//OpCommand Code Here
public:
    OpCommand() : Command() {};
    
    OpCommand(int val) {
        this->root = new Op(val);
    }
    
    double execute() {
        return this->root->evaluate();
    }
};

class AddCommand : public Command {
	//AddCommand Code Here
public:
    AddCommand() : Command() {};
    
    AddCommand(Command* cmd, int val) {
        Base* tmp = new Op(val);
        this->root = new Add(cmd->get_root(),tmp);
    }
};

class SubCommand : public Command {
	//SubCommand Code Here
public:
    SubCommand() : Command() {}
    
    SubCommand(Command* cmd, int val) {
        Base* tmp = new Op(val);
        this->root = new Sub(cmd->get_root(),tmp);
    }
};

class MultCommand : public Command {
	//MultCommand Code Here
public:
    MultCommand() : Command() {}
    
    MultCommand(Command* cmd,int val) {
        Base* tmp = new Op(val);
        this->root = new Mult(cmd->get_root(),tmp);
    }
    
};

class SqrCommand : public Command {
	//SqrCommand Code Here
public:
    SqrCommand() : Command() {}
    
    SqrCommand(Command* cmd) {
        this->root = new Sqr(cmd->get_root());
    }
    
};

#endif //__COMMAND_CLASS__
