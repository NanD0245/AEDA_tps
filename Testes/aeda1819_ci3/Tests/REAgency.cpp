#include "REAgency.h"

REAgency::REAgency(): catalogItems(PropertyTypeItem("", "","", 0)) {
	//do nothing!
}

REAgency::REAgency(vector<Property*> properties): catalogItems(PropertyTypeItem("", "","", 0)) {
	this->properties = properties;
}

void REAgency::addProperty(Property* property) {
	this->properties.push_back(property);
}

void REAgency::addProperties(vector<Property*> properties) {
	this->properties = properties;
}

vector<Property*> REAgency::getProperties() const{
	return this->properties;
}

PropertyTypeItem REAgency::getTypeItem(string address, string postalCode, string typology) {
	PropertyTypeItem itemNotFound("", "", "", 0);
	BSTItrIn<PropertyTypeItem> it(catalogItems);
	while (!it.isAtEnd())
	{
		if( it.retrieve().getAddress() == address && it.retrieve().getPostalCode() == postalCode && it.retrieve().getTypology() == typology) {
			PropertyTypeItem pti(it.retrieve().getAddress(), it.retrieve().getPostalCode(), it.retrieve().getTypology(), 0);
			pti.setItems(it.retrieve().getItems());
			return pti;
		}
		it.advance();
	}
	return itemNotFound;
}

void REAgency::addTypeItem(Property* property) {
	PropertyTypeItem itemNotFound("", "","", 0);
	PropertyTypeItem pti(property->getAddress(), property->getPostalCode(), property->getTypology(), property->	getPrice());
	PropertyTypeItem ptiX = catalogItems.find(pti);
	if(ptiX == itemNotFound) {
		pti.addItems(property);
		this->catalogItems.insert(pti);
	}
	else {
		this->catalogItems.remove(ptiX);
		ptiX.addItems(property);
		this->catalogItems.insert(ptiX);
	}
	properties.push_back(property);
}

BST<PropertyTypeItem> REAgency::getTypeItems() const {
	return this->catalogItems;
}

vector<ClientRecord> REAgency::getClientRecords() const {
	vector<ClientRecord> records;
	HashTabClientRecord::const_iterator it1 = this->listingRecords.begin();
	HashTabClientRecord::const_iterator it2 = this->listingRecords.end();
	for(; it1 != it2; it1++) {
			records.push_back(*it1);
	}
	return records;
}

void REAgency::setClientRecords(vector<ClientRecord>& crs) {
	for(unsigned int i = 0; i < crs.size(); i++) {
		listingRecords.insert(crs[i]);
	}

}

priority_queue<Client> REAgency::getClientProfiles() const {
	return clientProfiles;
}
void REAgency::setClientProfiles(priority_queue<Client>& profiles) {
	clientProfiles = profiles;
}

//
// TODO: Part I   - BST
//
void REAgency::generateCatalog() {
	for (Property* property: properties) {
        auto it = BSTItrIn<PropertyTypeItem>(catalogItems);
        PropertyTypeItem pp(property->getAddress(),property->getPostalCode(),property->getTypology(),property->getPrice());
        while (!it.isAtEnd() && !(it.retrieve() == pp))
            it.advance();
        if (it.isAtEnd()) {
            pp.addItems(property);
            catalogItems.insert(pp);
        }
        else {
            it.retrieve().addItems(property);
        }
	}
}

vector<Property*> REAgency::getAvailableProperties(Property* property) const {
	vector<Property*> temp;
	for (Property* prop : properties) {
	    if (prop->getAddress()==property->getAddress() && prop->getPostalCode() == property->getPostalCode() && prop->getTypology() == property->getTypology() && prop->getReservation() == tuple<Client*,int>())
	        temp.push_back(prop);
	}
	return temp;
}

bool REAgency::reservePropertyFromCatalog(Property* property, Client* client, int percentage) {
	for (auto it = BSTItrIn<PropertyTypeItem>(catalogItems); !it.isAtEnd(); it.advance()) {
	    for (Property* prop : it.retrieve().getItems()) {
	        if (prop->getAddress() == property->getAddress() && prop->getTypology() == property->getTypology() &&
	                            prop->getPostalCode() == property->getPostalCode() && prop->getReservation() == tuple<Client*,int>()) {
                client->addVisiting(prop->getAddress(),prop->getPostalCode(), prop->getTypology(),to_string(prop->getPrice()));
	            prop->setReservation(tuple<Client*,int>(client, prop->getPrice()*(1-percentage /100.0)));
	            return true;
	        }
	    }
	}

	return false;
}

//
// TODO: Part II  - Hash Table
//
void REAgency::addClientRecord(Client* client) {
	listingRecords.insert(ClientRecord(client));
}

void REAgency::deleteClients() {
	/*auto it = listingRecords.begin();
    auto it2 = listingRecords.end();
	while (it != listingRecords.end()) {
	    cout << &it << endl;
	    if (it != listingRecords.end() && it->getClientPointer()->getVisitedProperties().empty()) {
	        listingRecords.erase(it);
	    }
	    else it++;
	}*/
	bool check = true;
	while (check) {
	    check = false;
	    for (auto it = listingRecords.begin(); it != listingRecords.end(); it++) {
            if (it != listingRecords.end() && it->getClientPointer()->getVisitedProperties().empty()) {
                listingRecords.erase(it);
                check = true;
                break;
            }
	    }
	}
}

//
// TODO: Part III - Priority Queue
//
void REAgency::addBestClientProfiles(const vector<Client>candidates, int min) {
	for (Client candidate: candidates) {
	    float ratio = 0;
	    for (Property* prop : properties) {
	        if (get<0>(prop->getReservation())->getEMail() == candidate.getEMail())
	            ratio++;
	    }
	    ratio /= candidate.getVisitedProperties().size();
	    if (ratio > min)
	        clientProfiles.push(candidate);
	}
}

vector<Property*> REAgency::suggestProperties() {
	//TODO: G
	vector<Property*> tempProperties;
    priority_queue<Client> pq = clientProfiles;
    Property* p1 = properties[0];
    float diff = 99999999;
    while (!pq.empty()) {
        if (pq.top().getVisiting()== tuple<string,string,string,string>()) {
            pq.pop();
            continue;
        }
        for (Property* prop: properties) {
            if (prop->getReservation() == tuple<Client*,int>()) {
                float diff1 = abs(stoi(prop->getPostalCode()) - stoi(get<1>(pq.top().getVisiting())));
                if (diff1 != 0 && diff1 < diff) {
                    p1 = prop;
                    diff = diff1;
                }
            }
        }
        tempProperties.push_back(p1);
        pq.pop();
    }
	return tempProperties;
}
