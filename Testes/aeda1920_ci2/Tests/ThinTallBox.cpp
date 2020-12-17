#include "ThinTallBox.h"
#include "WideFlatBox.h"

ThinTallBox::ThinTallBox(double capacity) : Box(capacity) {
}

ThinTallBox::ThinTallBox(double capacity, stack<Object> objects, double content_size) : Box(capacity) {
	this->objects = objects;
	this->setContentSize(content_size);
}

stack<Object> ThinTallBox::getObjects() const {
    return objects;
}

void ThinTallBox::remove(Object object) {
	Object next_object = next();
	if(!(next_object == object)) {
		throw InaccessibleObjectException(object);
	} else {
		setContentSize(getContentSize()-next_object.getSize());
		objects.pop();
	}
}

const Object& ThinTallBox::next() const {
	return objects.top();
}


void ThinTallBox::insert(Object object) {
    if (getCapacity() >= object.getSize()+getContentSize()) {
        objects.push(object);
        setContentSize(getContentSize()+object.getSize());
    }
    else throw ObjectDoesNotFitException();
}

void ThinTallBox::sortObjects() {
	vector<Object> v1;
	while (!objects.empty()) {
	    v1.push_back(objects.top());
	    objects.pop();
	}
	while (!v1.empty()) {
	    int index_max = 0;
	    for (size_t i = 0; i < v1.size(); i++) {
            if (v1[i].getSize()>v1[index_max].getSize())
                index_max = i;
	    }
	    objects.push(v1[index_max]);
	    v1.erase(v1.begin()+index_max);
	}
}
