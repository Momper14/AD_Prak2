#pragma once

#include "EVKD.h"


class TEXT{
public:
	// Anzahl an Elementen der Liste
	int anz;


	// initialisiert die Variablen
	TEXT();


	// h�ngt ein neues Element hinten an die Liste an
	void anhaengen(const char*);

	// f�gt das Element lexikalisch sortiert in die Liste ein
	void einfuegenSortiert(EVKD*, int);

	// l�scht alle Elemente der Liste
	~TEXT();
private:
	// anfang der Liste
	EVKD* start;
};