#include <stdio.h> // Zuerst werden Systendatein dann Userdatein inkludiert!
#include <stdlib.h>
#include "JobQueue.h"

// Pusht ein Job in die Queue mit der richtigen Priorit�t!
int pushJQ(JobQueue_t* pJQ, Job_t* pJob) {
	QueueEl_t* pNewElement = (QueueEl_t*)malloc(sizeof(QueueEl_t));
	pNewElement->Job = *pJob;
	QueueEl_t* pVorherigesElement = NULL;
	//Check ob die Queue leer ist!
	
	//Queue ist noch leer!
	if (pJQ->count == 0) {
		//Zeiger auf NExt wird gesetz!
		pNewElement->next = NULL;
		//Der JobQueue werden neue Werte zugewiesen!
		pJQ->first = pNewElement;
		pJQ->last = pNewElement;

	}
	// In der Queue sind schon Elemente drin!
	else {
		pNewElement->next = pJQ->first;
		for (; pNewElement->next != NULL && pNewElement->Job.prio < pNewElement->next->Job.prio; pNewElement->next = pNewElement->next->next) {
			pVorherigesElement = pNewElement->next;
			
		}
		//Zeiger auf neues First?
		if (pVorherigesElement == NULL) {
			pJQ->first = pNewElement;
		}
		else {
			pVorherigesElement->next = pNewElement;
		}
		//Zeiger auf neues Last?
		if (pNewElement->next == NULL) {
			pJQ->last = pNewElement;
		}

		return 0;
	}
	pJQ->count++;
	return 0;
}


// L�scht den Job mit der obersten Priorit�t aus der Liste heraus und kopiert diesen!
Job_t popJQ(JobQueue_t* pJQ) {
	//Das zu l�schende Element kopieren
	QueueEl_t* pDeletedElement = pJQ->first;

	//Ausgabe des zu l�schenden Elements
	printf("Deleted Element: %s\n", pDeletedElement->Job.desc, pDeletedElement->Job.prio);

	//L�schen des Elements und das n�chstegelende Element zum neuen "first" machen
	pJQ->first = pDeletedElement->next;


	//Keine Ahnung wof�r das hier ist?
	Job_t job = { 0 };
	return job;
}


// Zeigt alle Aufgaben in der angegebenen Liste aus!
void printJQ(JobQueue_t* pJQ) {
	if (pJQ->first == NULL) {				// WEnn die erste Aufgabe leer ist gebe folgendes aus!
		printf("Leere Queue \n");				
	}
	else {
		QueueEl_t* pEL = pJQ->first;			// Pointer pEL auf erstes Element aller Elemente in der Queue
		for (; pEL != NULL; pEL = pEL->next) {				// Element f�r Element wird abgegangen, bis kein Element mehr das ist!
			printf("%i\t%s\n", pEL->Job.prio, pEL->Job.desc);
		}
	}
}