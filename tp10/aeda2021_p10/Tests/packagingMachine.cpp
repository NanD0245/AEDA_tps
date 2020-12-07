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


unsigned PackagingMachine::loadObjects(vector<Object> &objs) {
    unsigned count = 0;
    vector<std::size_t> erase;
	for (size_t i = 0; i < objs.size(); i++) {
        if (objs[i].getWeight() <= boxCapacity) {
            objects.push(objs[i]);
            erase.push_back(i);
            count++;
        }
    }
	sort(erase.begin(),erase.end(),[](std::size_t i1, std::size_t i2) { return i1 > i2; });
	for (size_t i : erase)
	    objs.erase(objs.begin()+i);
	return count;
}

Box PackagingMachine::searchBox(Object& obj) {
	Box b;
	vector<Box> storeBoxes;
	while (!boxes.empty() && boxes.top().getFree() < obj.getWeight()) {
	    storeBoxes.push_back(boxes.top());
	    boxes.pop();
	}
	if (!boxes.empty()) {
	    b = boxes.top();
	    boxes.pop();
	}
	for (const Box& box : storeBoxes) {
	    boxes.push(box);
	}
	return b;
}

unsigned PackagingMachine::packObjects() {
    vector<unsigned> ids;

    while (!objects.empty()) {
        Object obj = objects.top();
        objects.pop();
        Box bx = searchBox(obj);
        bx.addObject(obj);
        boxes.push(bx);
    }

    return boxes.size();
}

string PackagingMachine::printObjectsNotPacked() const {
    ostringstream oss;
    if (objects.empty()) oss << "No objects!" << endl;

	HeapObj objs = objects;
	while (!objs.empty()) {
	    oss << objs.top() << endl;
	    objs.pop();
	}
	return oss.str();
}

Box PackagingMachine::boxWithMoreObjects() const {
    if (boxes.empty()) throw MachineWithoutBoxes();
    HeapBox bxs = boxes;
    Box b = bxs.top();
    bxs.pop();
    while (!bxs.empty()) {
        if (b.getSize() < bxs.top().getSize())
            b = bxs.top();
        bxs.pop();
    }
    return b;
}