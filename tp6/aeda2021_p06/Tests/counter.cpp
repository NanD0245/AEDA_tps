#include <queue>
#include <cstdlib>
#include "counter.h"
#include "exceptions.h"
using namespace std;

//TODO
Client::Client() {
    this->numGifts = rand() % 5 + 1;
}

//TODO
unsigned Client::getNumGifts() const {
    return numGifts;
}


//TODO
Counter::Counter(unsigned wt): wrappingTime(wt) {
    actualTime = 0;
    nextEnter = rand() % 20 + 1;
    nextLeave = 0;
    numAttendedClients = 0;
}

//TODO
unsigned Counter::getActualTime() const {
    return actualTime;
}

//TODO
unsigned Counter::getNextEnter() const {
    return nextEnter;
}

//TODO
unsigned Counter::getNumAttendedClients() const {
    return numAttendedClients;
}

//TODO
unsigned Counter::getWrappingTime() const {
    return wrappingTime;
}

//TODO
unsigned Counter::getNextLeave() const {
    return nextLeave;
}

//TODO
Client & Counter::getNextClient() {
    if (clients.empty()) {
        throw EmptyQueue();
    }
    Client *cl = new Client();
    *cl = clients.front();
    return *cl;
}

//TODO
void Counter::enter()
{
    auto *client = new Client();
    nextEnter = rand() % 20 + 1;
    if (clients.empty()) {
        nextLeave = actualTime + client->getNumGifts()*wrappingTime;
    }
    clients.push(*client);
    cout << "[" << actualTime << ", " << client->getNumGifts() << "]" << endl;
}

//TODO
void Counter::leave()
{
    Client client = getNextClient();
    clients.pop();
    nextLeave = actualTime + clients.front().getNumGifts()*wrappingTime;
    cout << "[" << actualTime << ", " << client.getNumGifts() << "]" << endl;
}

//TODO
void Counter:: nextEvent()
{
    if (nextEnter < nextLeave || nextLeave == 0) {
        actualTime = nextEnter;
        enter();
    }
    else if (nextLeave < nextEnter && !clients.empty()) {
        actualTime = nextLeave;
        leave();
    }
    else {
        actualTime = nextEnter;
        enter();
        leave();
    }
}


//TODO
ostream & operator << (ostream & out, const Counter & c2)
{
     return out;
}


