#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // Zuerst werden Systendatein dann Userdatein inkludiert!
#include <stdlib.h>
#include "JobQueue.h"

// Pusht ein Job in die Queue mit der richtigen Priorität!
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
		if (pVorherigesElement == NULL) pJQ->first = pNewElement;
		else pVorherigesElement->next = pNewElement;
		//Zeiger auf neues Last?
		if (pNewElement->next == NULL) {
			pJQ->last = pNewElement;
		}
	}
	pJQ->count++;
	return 0;
}


// Löscht den Job mit der obersten Priorität aus der Liste heraus und kopiert diesen!
Job_t popJQ(JobQueue_t* pJQ) {

	if (pJQ->first == NULL)
	{
		Job_t EmptyJob = { 0, "" };
		return EmptyJob;
	}

	//Das zu löschende Element kopieren
	QueueEl_t* pDeletedElement = pJQ->first;
	Job_t TempJob = pDeletedElement->Job;


	//Ausgabe des zu löschenden Elements
	//printf("Deleted Element: %s\n", pDeletedElement->Job.desc, pDeletedElement->Job.prio);

	//Löschen des Elements und das nächstegelende Element zum neuen "first" machen
	pJQ->first = pDeletedElement->next;
	free(pDeletedElement);

	pJQ->count--;
	return TempJob;
}


// Zeigt alle Aufgaben in der angegebenen Liste aus!
void printJQ(JobQueue_t* pJQ) {
	if (pJQ->first == NULL) {				// WEnn die erste Aufgabe leer ist gebe folgendes aus!
		printf("Leere Queue \n");				
	}
	else {
		QueueEl_t* pEL = pJQ->first;			// Pointer pEL auf erstes Element aller Elemente in der Queue
		for (; pEL != NULL; pEL = pEL->next) {				// Element für Element wird abgegangen, bis kein Element mehr das ist!
			printf("%i\t%s\n", pEL->Job.prio, pEL->Job.desc);
		}
	}
}

// Gibt alle aufgaben in der angegeben Liste in eine Datei aus
void safeJQ(JobQueue_t* pJQ) {
	FILE* fp;
	if (pJQ->first == NULL) {				// WEnn die erste Aufgabe leer ist gebe folgendes aus!
		fp = fopen("C:/Users/nilsr/Source/Repos/nilsrueber/uebung_query/Übung Lineare Listen/file.txt", "w+");
		fprintf(fp, "Leere Queue\n");
		fclose(fp);
	}
	else {
		QueueEl_t* pEL = pJQ->first;			// Pointer pEL auf erstes Element aller Elemente in der Queue
		fp = fopen("C:/Users/nilsr/Source/Repos/nilsrueber/uebung_query/Übung Lineare Listen/file.txt", "w");
		for (; pEL != NULL; pEL = pEL->next) {				// Element für Element wird abgegangen, bis kein Element mehr das ist!
			fprintf(fp, "%i\t%s\n", pEL->Job.prio, pEL->Job.desc);
		}
		fclose(fp);
	}
}