#ifndef JOBQUEUE_H


#define JOBQUEUE_H
#define MAX_LENGTH 100

typedef struct Job {
	int prio;
	char desc[MAX_LENGTH];
} Job_t;

typedef struct QueueEl {
	Job_t Job;
	struct QueueEl* next;
} QueueEl_t;

typedef struct JobQueue {
	int count;
	QueueEl_t* first, * last;
} JobQueue_t;



int pushJQ(JobQueue_t* pJQ, const Job_t* pJob);
Job_t popJQ(JobQueue_t* pJQ);
void printJQ(JobQueue_t* pJQ);



#endif

