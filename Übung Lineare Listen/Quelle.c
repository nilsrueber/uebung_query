#include <stdio.h>
#include "jobqueue.h"

int main() {
	JobQueue_t jobQueue_1 = { 0 };
	//JobQueue_t jobQueue_2 = { 0 };
	Job_t Job_1 = { 50, "Urlaubplanung" },
		Job_2 = { 60, "Nichts" },
	Job_3 = { 13, "Hände waschen" },
	Job_4 = { 3, "Schlafen" },
	Job_5 = { 0 };

	//pushJQ(&jobQueue_1, &Job_1);
	pushJQ(&jobQueue_1, &Job_2);
	pushJQ(&jobQueue_1, &Job_3);



	//printJQ(&jobQueue_1);
	
	pushJQ(&jobQueue_1, &Job_4);

	//Job_5 = popJQ(&jobQueue_1);

	printJQ(&jobQueue_1);
	//printJQ(&jobQueue_2);

	//printf("%d", jobQueue_1.count);



	return 0;
}