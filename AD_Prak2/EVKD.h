#pragma once


class EVKD{
public:

	// initialisiert die Lokalen variablen
	EVKD(const char*, EVKD*);

	// runf Initialisierung-Konstruktor mit nullprt auf
	EVKD(const char*);

	// Copy-konstruktor
	EVKD(const EVKD&);

	// gibt daten als String zur�ck
	// @return daten + '\0'
	char* getDaten() const;

	// getter f�r anz
	int getAnz() const;

	// setter f�r next
	void setNext(EVKD*);

	// getter f�r next
	EVKD* getNext() const;

	// �berladen von Operatoren
	int operator> (const EVKD&);
	int operator== (const EVKD&);

	// l�scht daten und next
	~EVKD();

private:
	// beinhaltet den Text
	char *daten;
	// Anzahl an Elementen in daten
	int anz;
	// n�chstes Element der Liste
	EVKD *next;

};

