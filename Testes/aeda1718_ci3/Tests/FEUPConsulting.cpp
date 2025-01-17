/*
 * FEUPConsulting.cpp
 *
 *  Created on: 10/12/2017
 *      Author: CS
 */

#include "FEUPConsulting.h"

FEUPConsulting::FEUPConsulting(): expertizes(Expertize("", 0)) {
}

FEUPConsulting::FEUPConsulting(vector<Project*> projects): expertizes(Expertize("", 0)) {
	this->projects = projects;
}

void FEUPConsulting::addProjects(vector<Project*> projects) {
	this->projects = projects;
}

vector<Project*> FEUPConsulting::getProjects() const{
	return this->projects;
}


// get the expertize objet with the given name, including all students with the corresponding skills
Expertize FEUPConsulting::getExpertize(string name, unsigned cost) {
	Expertize itemNotFound("", 0);
	Expertize expertize(name, cost);
	Expertize search = expertizes.find(expertize);

	return search;
}


void FEUPConsulting::addProject(Project* project) {
	//TODO
	Expertize itemNotFound("", 0);
	Expertize expertize(project->getExpertize(), project->getCost());
	Expertize search = expertizes.find(expertize);

	if(search == itemNotFound) {
		this->expertizes.insert(expertize);
	}

	projects.push_back(project);
}

BST<Expertize> FEUPConsulting::getExpertizes() const {
	return this->expertizes;
}

void FEUPConsulting::addNewExpertize(const Expertize & expertize1) {
	this->expertizes.insert(expertize1);
}

vector<StudentPtr> FEUPConsulting::getStudents() const {
	vector<StudentPtr> ptrs;
	HashTabStudentPtr::const_iterator it1 = this->students.begin();
	HashTabStudentPtr::const_iterator it2 = this->students.end();
	for(; it1 != it2; it1++) {
			ptrs.push_back(*it1); //We can make it a bit more complex by considering only records with a condition!
	}
	return ptrs;
}

void FEUPConsulting::setStudents(vector<StudentPtr>& newStudents) {
	for(int i = 0; i < newStudents.size(); i++) students.insert(newStudents[i]);
}

priority_queue<Student> FEUPConsulting::getActiveStudents() const {
	return activeStudents;
}
void FEUPConsulting::setActiveStudents(priority_queue<Student>& students) {
	activeStudents = students;
}


//
// TODO: Part I   - BST
//

void FEUPConsulting::addAvailability(Student* student, string expertizeAvailable, unsigned cost) {
	Expertize e(expertizeAvailable,cost);
	e.addConsultant(student);
	bool check = false;
    for (auto it = BSTItrIn<Expertize>(expertizes); !it.isAtEnd(); it.advance())
        if (it.retrieve() == e) {
            it.retrieve().addConsultant(student);
            check = true;
            break;
        }
    if (!check)
        expertizes.insert(e);
}

vector<Student*> FEUPConsulting::getCandidateStudents(Project* project) const {
	vector<Student*> temp;
	//TODO:
    for (auto it = BSTItrIn<Expertize>(expertizes); !it.isAtEnd(); it.advance())
        for (Student* student : it.retrieve().getConsultants())
            if (it.retrieve().getName() == project->getExpertize() && it.retrieve().getCost() == project->getCost() && student->getCurrentProject().empty())
                temp.push_back(student);
	return temp;

}

#include <algorithm>
bool FEUPConsulting::assignProjectToStudent(Project* project, Student* student) {
	//TODO:
	if (project->getConsultant() != nullptr)
	    return false;
	if (!student->getCurrentProject().empty())
	    return false;
	for (auto it = BSTItrIn<Expertize>(expertizes); !it.isAtEnd(); it.advance())
        if (it.retrieve().getName() == project->getExpertize() && it.retrieve().getCost() == project->getCost())
            for (size_t i = 0; i < it.retrieve().getConsultants().size(); i++)
                if (it.retrieve().getConsultants()[i]->getName() == student->getName()) {
                    project->setConsultant(student);
                    student->addProject(project->getTitle());
                    return true;
                }
	return false;
}

//
// TODO: Part II  - Hash Table
//

void FEUPConsulting::addStudent(Student* student) {
	//TODO:
    students.insert(StudentPtr(student));
}

void FEUPConsulting::changeStudentEMail(Student* student, string newEMail) {
	//TODO
    for (auto stu : students)
        if (stu.getEMail() == student->getEMail())
            stu.setEMail(newEMail);
}


//
// TODO: Part III - Priority Queue
//

void FEUPConsulting::addActiveStudents(const vector<Student>& candidates, int min) {
	//TODO:
    for (Student stu : candidates) {
        int count = stu.getPastProjects().size();
        if (!stu.getCurrentProject().empty())
            count++;
        if (count > min)
            activeStudents.push(stu);
    }
}


int FEUPConsulting::mostActiveStudent(Student& studentMaximus) {
	//TODO:
	auto ha = activeStudents;
    if (ha.empty()) return 0;
	Student a = ha.top();
	ha.pop();
	if (ha.empty()) {
	    studentMaximus = a;
	    return 1;
	}
	if (a.getPastProjects().size() == ha.top().getPastProjects().size())
	    return 0;
	studentMaximus = a;
	int count = 1;
	while (!ha.empty()) {
	    ha.pop();
	    count++;
	}
    return count;
}





















