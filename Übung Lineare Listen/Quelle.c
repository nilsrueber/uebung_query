#include <stdio.h>
#include "jobqueue.h"

int main() {
	JobQueue_t jobQueue_1 = { 0 };
	JobQueue_t jobQueue_2 = { 0 };
	Job_t
		Job_1 = { 50, "Urlaubplanung" },
		Job_2 = { 60, "Nichts" },
		Job_3 = { 13, "Haende waschen" },
		Job_4 = { 3, "Schlafen" },
		Job_5 = { 0 },
		Job_6 = { 70, "Auto waschen" },
		Job_7 = { 65, "Arbeiten" };

	pushJQ(&jobQueue_1, &Job_2);
	pushJQ(&jobQueue_1, &Job_3);
	pushJQ(&jobQueue_1, &Job_1);
	pushJQ(&jobQueue_1, &Job_4);
	pushJQ(&jobQueue_1, &Job_6);
	pushJQ(&jobQueue_1, &Job_7);

	printf("Job Queue 1: \n");
	printJQ(&jobQueue_1);

	printf("%i\n", jobQueue_1.count);
	Job_5 = popJQ(&jobQueue_1);

	printf("Job Queue 1 nach Pop: \n");
	printJQ(&jobQueue_1);

	printf("%i\n", jobQueue_1.count);

	printf("%i \t%s wurde geloescht\n", Job_5.prio, Job_5.desc);



	return 0;
}