#include "Util.h"
#include "EVKD.h"
#include "string"


// initialisiert die Lokalen variablen
EVKD::EVKD(const char* lpszDaten, EVKD* n){
	this->anz = std::string(lpszDaten).length();
	this->daten = new char[this->anz];
	charcpy(this->daten, lpszDaten, this->anz);
	this->next = n;
}

// runf Initialisierung-Konstruktor mit nullprt auf
EVKD::EVKD(const char *lpszDaten) : EVKD(lpszDaten, nullptr){
}

// Copy-konstruktor
EVKD::EVKD(const EVKD &obj){
	this->anz = obj.anz;
	this->daten = new char[obj.anz];
	charcpy(this->daten, obj.daten, this->anz);
	this->next = obj.next;
}


// gibt daten als String zur�ck
// @return daten + '\0'
char * EVKD::getDaten() const{
	char *ret = new char[anz + 1];

	charcpy(ret, this->daten, this->anz);
	ret[anz] = '\0';

	return ret;
}

// getter f�r anz
int EVKD::getAnz() const{
	return anz;
}

// setter f�r next
void EVKD::setNext(EVKD *obj){
	next = obj;
}

// getter f�r next
EVKD * EVKD::getNext() const{
	return next;
}

// �berladen von Operatoren
int EVKD::operator>(const EVKD &obj){
	return (charcmp(this->daten, this->anz, obj.daten, obj.anz) > 0) ? 1 : 0;
}

int EVKD::operator==(const EVKD &obj){
	if(this->anz != obj.anz){
		return 0;
	} else{
		for(int i = 0; i < this->anz; i++){
			if(this->daten[i] != obj.daten[i]){
				return 0;
			}
		}
		return 1;
	}
}


// l�scht daten und next
EVKD::~EVKD(){
	delete daten;
	if(next != nullptr)
		delete next;
}