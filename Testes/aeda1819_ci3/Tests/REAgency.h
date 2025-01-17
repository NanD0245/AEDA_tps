#ifndef SRC_REAGENCY_H_
#define SRC_REAGENCY_H_

#include "BST.h"
#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include "ClientRecord.h"
#include "PropertyTypeItem.h"

using namespace std;

struct clientRecordHash
{
	int operator() (const ClientRecord& cr) const
	{
		//TODO:
		int v = 0;
        for (char i : cr.getEMail()) {
            v = 37 * v + i;
        }
		return v;
	}

	bool operator() (const ClientRecord& cr1, const ClientRecord& cr2) const
	{
		//TODO:
		return cr1.getEMail() == cr2.getEMail();
	}
};

typedef unordered_set<ClientRecord, clientRecordHash, clientRecordHash> HashTabClientRecord;

class REAgency {
	vector<Property*> properties;
	BST<PropertyTypeItem> catalogItems;
	HashTabClientRecord listingRecords;
	priority_queue<Client> clientProfiles;
public:
	REAgency();
	REAgency(vector<Property*> properties);
	void addProperty(Property* property);
	void addProperties(vector<Property*> properties);
	vector<Property*> getProperties() const;

	// Part I   - BST
	PropertyTypeItem getTypeItem(string address, string postalCode, string typology);
	void addTypeItem(Property* property);
	BST<PropertyTypeItem> getTypeItems() const;
	// Part II  - Hash Table
	vector<ClientRecord> getClientRecords() const;
	void setClientRecords(vector<ClientRecord>& crs);
	// Part III - Priority Queue
	priority_queue<Client> getClientProfiles() const;
	void setClientProfiles(priority_queue<Client>& profiles);

	// TODO: Implement methods below...
	// Part I   - BST
	/* A */ void generateCatalog();
	/* B */ vector<Property*> getAvailableProperties(Property* property) const;
	/* C */ bool reservePropertyFromCatalog(Property* property, Client* client, int percentage);

	// Part II  - Hash Table
	/* D */ void addClientRecord(Client* client);
	/* E */ void deleteClients();

	// Part III - Priority Queue
	/* F */ void addBestClientProfiles(const vector<Client> candidates, int min);
	/* G */ vector<Property*> suggestProperties();
};



#endif /* SRC_REAGENCY_H_ */
