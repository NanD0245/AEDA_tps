#include "packagingMachine.h"
#include <sstream>

PackagingMachine::PackagingMachine(int boxCap): boxCapacity(boxCap)
{}

unsigned PackagingMachine::numberOfBoxes() {
    return boxes.size();
}

unsigned PackagingMachine::addBox(Box& b1) {
    boxes.push(b1);
    return boxes.size();
}

HeapObj PackagingMachine::getObjects() const {
    return this->objects;
}

HeapBox PackagingMachine::getBoxes() const {
    return this->boxes;
}


#include <set>
unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    set<int,greater<int>> index;
    for (size_t i = 0; i < objs.size(); i++) {
        if (objs[i].getWeight() <= boxCapacity) {
            index.insert(i);
            objects.push(objs[i]);
        }
    }
    for (int num: index)
        objs.erase(objs.begin()+num);
	return objects.size();
}

Box PackagingMachine::searchBox(Object& obj) {
	Box b;
	HeapBox boxes_store;
	while (!boxes.empty() && boxes.top().getFree() < obj.getWeight()) {
        boxes_store.push(boxes.top());
        boxes.pop();
	}
	if (!boxes.empty()) {
        b = boxes.top();
        boxes.pop();
    }
	while (!boxes_store.empty()) {
	    boxes.push(boxes_store.top());
	    boxes_store.pop();
	}
	return b;
}

unsigned PackagingMachine::packObjects() {
    while(!objects.empty()) {
        Object obj = objects.top();
        Box b = searchBox(obj);
        b.addObject(obj);
        boxes.push(b);
        objects.pop();
    }
	return boxes.size();
}

string PackagingMachine::printObjectsNotPacked() const {
    if (objects.empty()) return "No objects!\n";
    ostringstream ss;
    HeapObj objs = objects;
    while (!objs.empty()) {
        ss << objs.top() << endl;
        objs.pop();
    }
	return ss.str();
}

Box PackagingMachine::boxWithMoreObjects() const {
    if (boxes.empty()) throw MachineWithoutBoxes();
    HeapBox boxes_store = boxes;
	Box b;
	while (!boxes_store.empty()) {
	    if (boxes_store.top().getSize() > b.getSize())
	        b = boxes_store.top();
	    boxes_store.pop();
	}
	return b;
}