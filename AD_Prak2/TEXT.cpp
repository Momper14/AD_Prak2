#include "TEXT.h"


// initialisiert die Variablen
TEXT::TEXT(){
	anz = 0;
	start = nullptr;
}


// h�ngt ein neues Element hinten an die Liste an
void TEXT::anhaengen(const char *in){
	if(this->start == nullptr){
		this->start = new EVKD(in);
		this->anz++;
	} else{
		EVKD *tmp = this->start;
		while(tmp->getNext() != nullptr){
			tmp = tmp->getNext();
		}
		tmp->setNext(new EVKD(in));
		this->anz++;
	}
}

void TEXT::einfuegenSortiert(EVKD *in, int max){
	// start-Element vorhanden ?
	if(this->start == nullptr){
		//start-Element ersetzen
		this->start = in;
		this->anz++;

	}else if(max >= 1){
		// 1. Element gr��er ?
		if(*this->start > *in){
			//start-Element ersetzen
			in->setNext(this->start);
			this->start = in;
			this->anz++;

		} else{
			int drin = 0;
			EVKD *vorg = this->start, *vergl = vorg->getNext();

			// suchen nach Position und einf�gen
			for(int i = 2; drin == 0 && i < max; i++){
				if(*vergl > *in){
					in->setNext(vergl);
					vorg->setNext(in);
					this->anz++;
					drin = 1;
				}
				vorg = vergl;
				vergl = vorg->getNext();
			}

			// hinten anh�ngen, falls gr��er als gr��tes Element der Liste
			if(!drin){
				vorg->setNext(in);
				this->anz++;
			}
		}
	}
}


// l�scht alle Elemente der Liste
TEXT::~TEXT(){
	if(start != nullptr){
		EVKD *tmp, *tmpvor;

		while(this->start->getNext() != nullptr){
			tmpvor = this->start;
			tmp = tmpvor->getNext();

			while(tmp->getNext() != nullptr){
				tmpvor = tmp;
				tmp = tmpvor->getNext();
			}

			tmpvor->setNext(nullptr);
			delete tmp;
		}

		delete this->start;
	}
}
