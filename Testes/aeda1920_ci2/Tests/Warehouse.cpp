#include "Warehouse.h"
#include <algorithm>

Warehouse::Warehouse()  {
}

queue<ThinTallBox> Warehouse::getBoxes() {
	return boxes;
}

queue<Object> Warehouse::getObjects() {
    return objects;
}

void Warehouse::setBoxes(queue<ThinTallBox> q) {
    while (!q.empty()) {
        boxes.push(q.front());
        q.pop();
    }
}

void Warehouse::addObject(Object o1) {
    objects.push(o1);
}


int Warehouse::InsertObjectsInQueue(vector <Object> obj){
    int counter = 0;
    while (!obj.empty()) {
        int index_max = 0;
        for (size_t i = 0; i < obj.size(); i++) {
            if (obj[i].getSize() > obj[index_max].getSize())
                index_max = i;
        }
        objects.push(obj[index_max]);
        counter++;
        obj.erase(obj.begin()+index_max);
    }
    return counter;
}

Object Warehouse::RemoveObjectQueue(int maxSize){
    vector<Object> v1;
    Object obj;
    bool check = false;
    int size = objects.size();
    for (int i = 0; i < size; i++) {
        v1.push_back(objects.front());
        objects.pop();
    }
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i].getSize()<=maxSize) {
            obj=v1[i];
            v1.erase(v1.begin()+ i);
            check = true;
            break;
        }
    }
    for (size_t i = 0; i < v1.size(); i++) {
        objects.push(v1[i]);
    }
    if (!check)
        obj = Object("dummy",maxSize);
    return obj;
}

int Warehouse::addPackOfBoxes(vector <ThinTallBox> boV) {
    for (size_t i = 0; i < boV.size();i++) {
        boxes.push(boV[i]);
    }
    return boxes.size();
}

void Warehouse::processBox(ThinTallBox& box){
    queue<Object> newQueue;
    Object current;
    size_t sizeOfQueue = objects.size();
    while (!objects.empty()){
        current = objects.front();
        objects.pop();
        if(current.getSize() <= box.getCapacity()-box.getContentSize()) {
            break;
        }
        newQueue.push(current);
    }
    while (!objects.empty()){
        newQueue.push(objects.front());
        objects.pop();
    }
    objects = newQueue;
    if(newQueue.size() == sizeOfQueue)
        box.insert(Object("dummy", 0));
    else box.insert(current);
}


vector<ThinTallBox> Warehouse::DailyProcessBoxes(){
    vector<ThinTallBox> res;
    queue<ThinTallBox> newQueue;
    while(!boxes.empty()){
        if(boxes.front().getCapacity() == boxes.front().getContentSize() ){
            res.push_back(boxes.front());
            boxes.pop();
        }else if(boxes.front().getDays() == 0){
            processBox(boxes.front());
            res.push_back(boxes.front());
            boxes.pop();
        }else{
            processBox(boxes.front());
            boxes.front().setDaysToSend(boxes.front().getDays()-1);
            newQueue.push(boxes.front());
            boxes.pop();
        }
    }
    return res;
}

