#include <omnetpp.h>

using namespace omnetpp;

class My_Node : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(My_Node); // Register the class with OMNeT++

void My_Node::initialize() {
    const char *myName = getName();

    if (strcmp(myName, "computer1") == 0) {
        // Computer 1 initiates the message passing
        cMessage *msg = new cMessage("Hey, what is your index number?");
        send(msg, "output_gate");
    }
}

void My_Node::handleMessage(cMessage *msg) {
    const char *myName = getName();

    if (strcmp(myName, "computer2") == 0) {
        // Computer 2 sends a specific reply
        std::string replyMsg = "Hello, 205009E.";
        cMessage *reply = new cMessage(replyMsg.c_str());
        send(reply, "output_gate");
    } else if (strcmp(myName, "computer3") == 0) {
        // Computer 3 sends another specific reply
        std::string replyMsg = "Hello, what's your name?";
        cMessage *reply = new cMessage(replyMsg.c_str());
        send(reply, "output_gate");
    } else if (strcmp(myName, "computer4") == 0) {
        // Computer 4 sends its own message
        std::string replyMsg = "Hi, I'm chaami.";
        cMessage *reply = new cMessage(replyMsg.c_str());
        send(reply, "output_gate");
    } else if (strcmp(myName, "computer5") == 0) {
        // Computer 5 (the last one) sends a closing message
        std::string replyMsg = "Hi all!";
        cMessage *reply = new cMessage(replyMsg.c_str());
        send(reply, "output_gate");
    }

    // Delete the received message
    delete msg;
}
