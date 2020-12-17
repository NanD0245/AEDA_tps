#include <algorithm>
#include "WideFlatBox.h"

WideFlatBox::WideFlatBox(double capacity) : Box(capacity) {
}

void WideFlatBox::insert(Object object) {
	if(getContentSize()+object.getSize() <= getCapacity()) {
		objects.push_back(object);
		setContentSize(getContentSize()+object.getSize());
	} else {
		throw ObjectDoesNotFitException();
	}
}

const Object& WideFlatBox::next() const {
	return objects[0];
}

void WideFlatBox::sortObjects() {
	sort(objects.begin(), objects.end());
}


void WideFlatBox::remove(Object object) {
    bool check = false;
    for (size_t i = 0; i < objects.size(); i++) {
        if (objects[i] == object) {
            check = true;
            objects.erase(objects.begin()+i);
            setContentSize(getContentSize()-object.getSize());
        }
    }
    if (!check)
        throw InaccessibleObjectException(object);
}
