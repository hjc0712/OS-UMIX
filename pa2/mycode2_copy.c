/* mycode2.c: your portion of the kernel
 *
 *   	Below are procedures that are called by other parts of the kernel. 
 * 	Your ability to modify the kernel is via these procedures.  You may
 *  	modify the bodies of these procedures any way you wish (however,
 *  	you cannot change the interfaces).  
 */

#include "aux.h"
#include "sys.h"
#include "mycode2.h"

#define TIMERINTERVAL 1	// in ticks (tick = 10 msec)

/* 	A sample process table. You may change this any way you wish. 
 */

static int num=1;
static int cur_run=-1; // the index in proctab, of the current running pro 
static int cur_use=0;  // current usage of the cpu rate
static struct {
	int valid;		// is this entry valid: 1 = yes, 0 = no
	int pid;		// process ID (as provided by kernel)
	int order;      // processes in the order of their come in order (For FIFO & LIFO)
	float reqRate;
	float utiRate;
	float ratio;
	int runTime;
	int stayTime;
} proctab[MAXPROCS];


/* 	InitSched () is called when the kernel starts up.  First, set the
 *  	scheduling policy (see sys.h). Make sure you follow the rules
 *   	below on where and how to set it.  Next, initialize all your data
 * 	structures (such as the process table).  Finally, set the timer
 *  	to interrupt after a specified number of ticks. 
 */

void InitSched ()
{
	int i;

	/* First, set the scheduling policy. You should only set it
	 * from within this conditional statement.  While you are working
	 * on this assignment, GetSchedPolicy () will return NOSCHEDPOLICY. 
	 * Thus, the condition will be true and you may set the scheduling
	 * policy to whatever you choose (i.e., you may replace ARBITRARY).  
	 * After the assignment is over, during the testing phase, we will
	 * have GetSchedPolicy () return the policy we wish to test (and
	 * the policy WILL NOT CHANGE during the entirety of a test).  Thus
	 * the condition will be false and SetSchedPolicy (p) will not be
	 * called, thus leaving the policy to whatever we chose to test
	 * (and so it is important that you NOT put any critical code in
	 * the body of the conditional statement, as it will not execute when
	 * we test your program). 
	 */
	if (GetSchedPolicy () == NOSCHEDPOLICY) {	// leave as is
		SetSchedPolicy (PROPORTIONAL);		// set policy here
	}
		
	/* Initialize all your data structures here */
	for (i = 0; i < MAXPROCS; i++) {
		proctab[i].valid = 0;
		proctab[i].ratio = 0;
		proctab[i].reqRate=0.0;
		proctab[i].utiRate=0.0;
		proctab[i].ratio=0.0;
		proctab[i].runTime=0.0;
		proctab[i].stayTime=0.0;
	}

	/* Set the timer last */
	SetTimer (TIMERINTERVAL);
}


void ReAllocate()
{
	for (int i=0; i<MAXPROCS; i++){
		proctab[i].runTime = 0.0;
		proctab[i].stayTime = 0.0;
		proctab[i].utiRate = 0.0;
	}
}

/*  	StartingProc (p) is called by the kernel when the process
 * 	identified by PID p is starting ( fork() ).  This allows you to record the
 * 	arrival of a new process in the process table, and allocate
 *  	any resources (if necessary).  Returns 1 if successful, 0 otherwise. 
 */

int StartingProc (p)
	int p;				// process that is starting
{
	int i;

	for (i = 0; i < MAXPROCS; i++) {
		if (! proctab[i].valid) {
			proctab[i].valid = 1;
			proctab[i].pid = p;
			proctab[i].order = num; //global var
			num++;
			if (GetSchedPolicy () == LIFO)
				DoSched();
			return (1);
		}
	}

	DPrintf ("Error in StartingProc: no free table entries\n");
	return (0);
}
			

/*   	EndingProc (p) is called by the kernel when the process
 * 	identified by PID p is ending.  This allows you to update the
 *  	process table accordingly, and deallocate any resources (if
 *  	necessary).  Returns 1 if successful, 0 otherwise. 
 */


int EndingProc (p)
	int p;				// process that is ending
{
	int i;

	for (i = 0; i < MAXPROCS; i++) {
		if (proctab[i].valid && proctab[i].pid == p) {
			proctab[i].valid = 0;
			cur_use -= proctab[i].reqRate * 100;
			return (1);
		}
	}
	

	DPrintf ("Error in EndingProc: can't find process %d\n", p);
	return (0);
}


/* 	SchedProc () is called by kernel when it needs a decision for
 * 	which process to run next. It calls the kernel function
 *  	GetSchedPolicy () which will return the current scheduling policy
 *   	which was previously set via SetSchedPolicy (policy).  SchedProc ()
 * 	should return a process PID, or 0 if there are no processes to run. 
 */

int SchedProc ()
{
	int i;
	int tmp = MAXPROCS+1;
	int head = 0;
	int tail = 0;
	int index = -1;
	int isEmpty=1;

	float MINRATIO = 1.0;
	float MINRATIO_3 = 3.0;
	int index_3 = -1;
	int proToRunIfUnreq = -1;
	int proNonReq = -1;
	float minNonReqProRunTime = -1;
	float minReqRate= -1;

	switch (GetSchedPolicy ()) {

	case ARBITRARY:

		for (i = 0; i < MAXPROCS; i++) {
			if (proctab[i].valid) {
				return (proctab[i].pid);
			}
		}
		break;

	case FIFO:
		/* your code here */
		for (i = 0; i < MAXPROCS; i++) {
			if (proctab[i].valid && (proctab[i].order<tmp) ) {
				tmp=proctab[i].order;
				head=proctab[i].pid;
				index=i;
				isEmpty=0;
			}
		}
		if(!isEmpty)
			cur_run=index; //the index
			return head;
		break;


	case LIFO:
		/* your code here */
		tmp=0;
		for (i = 0; i < MAXPROCS; i++) {
			if (proctab[i].valid && (proctab[i].order>tmp) ) {
				tmp=proctab[i].order;
				tail=proctab[i].pid;
				index=i;
				isEmpty=0;
			}
		}
		if(!isEmpty)
			cur_run=index;
			return tail;
		break;


	case ROUNDROBIN:
		/* your code here */
		
		for(i=1 ; i<MAXPROCS+1; i++){
			if(proctab[(cur_run+i)%MAXPROCS].valid){ //find the next valid pro
				cur_run=(cur_run+i)%MAXPROCS; //the next pro to run
				return proctab[cur_run].pid;
			}
		}
		
		break;

	case PROPORTIONAL:

		/* your code here */
		for(i=0 ; i<MAXPROCS; i++){
			if(proctab[i].valid){ //find the next valid pro
				isEmpty=0;
				if (proctab[i].reqRate > minReqRate){ //find one with the most reqRate
					proToRunIfUnreq = i;
					minReqRate = proctab[i].reqRate;
				}
				

				// if(proctab[i].reqRate==-1){ // if not get a chance to run the first time
				// 	proctab[i].runTime++;
				// 	proctab[i].reqRate=0;
				// 	return proctab[i].pid;
				// }

				if(proctab[i].reqRate>0){  
					if(proctab[i].ratio < MINRATIO){
						MINRATIO = proctab[i].ratio;
						index=i;
					}
					else if(proctab[i].ratio < MINRATIO_3){
						MINRATIO_3 = proctab[i].ratio;
						index_3=i;
					}
					// Printf("pro:%d ratio%f \n",proctab[i].pid,proctab[i].ratio);
				}
				
				else if((minNonReqProRunTime == -1)  || (proctab[i].runTime < minNonReqProRunTime) ) {
					minNonReqProRunTime = proctab[i].runTime;
					proNonReq = i;
				} // for those pros that don't require, select the nonreq pro with the min runTime -- !!for the rest pros to share the rest cpu time
					
			}
		}

		if(!isEmpty){
			// printf("pro%d \t %f \n", proctab[proToRunIfUnreq].pid, minReqRate);
			if(index!=-1){ //find an insufficient-allocated pro
				proctab[index].runTime++;
				return proctab[index].pid;
			} 
			else if(proNonReq!=-1){  // if all satisfied run the one which doesn't require
				proctab[proNonReq].runTime++;
				return proctab[proNonReq].pid;
			}  	
			else if (index_3!=-1){  // if all required, run the one with smallest ratio
				proctab[index_3].runTime++;
				return proctab[index_3].pid;
			}
			else{
				proctab[proToRunIfUnreq].runTime++;
				return proctab[proToRunIfUnreq].pid;
			}
		}
		break;

	}
	
	return (0);
}


/*  	HandleTimerIntr () is called by the kernel whenever a timer
 *  	interrupt occurs.  Timer interrupts should occur on a fixed
 * 	periodic basis.
 */

void HandleTimerIntr ()
{
	SetTimer (TIMERINTERVAL);

	for(int i=0; i<MAXPROCS; i++){
		if(proctab[i].valid){
			proctab[i].stayTime++;
			proctab[i].utiRate = (1.0 * proctab[i].runTime) / proctab[i].stayTime;
			// Printf("pro:%d ratio:%f \n", proctab[i].pid, proctab[i].ratio);
		}
		if(proctab[i].reqRate != 0){
			proctab[i].ratio = (1.0 * proctab[i].utiRate) / proctab[i].reqRate;
		}
		// else if(proctab[i].runTime != 0) //means it has run but not require any cpu 
		// 	proctab[i].ratio = 3;
	}

	switch (GetSchedPolicy ()) {	// is policy preemptive?

	case ROUNDROBIN:		// ROUNDROBIN is preemptive
		DoSched ();		// make scheduling decision
		break;

	case PROPORTIONAL:		// PROPORTIONAL is preemptive

		DoSched ();		// make scheduling decision
		break;

	default:			// if non-preemptive, do nothing
		break;
	}
}

/* 	MyRequestCPUrate (p, n) is called by the kernel whenever a process
 *  	identified by PID p calls RequestCPUrate (n).  This is a request for
 *   	n% of CPU time, i.e., requesting a CPU whose speed is effectively
 * 	n% of the actual CPU speed. Roughly n out of every 100 quantums
 *  	should be allocated to the calling process. n must be at least
 *  	0 and must be less than or equal to 100.  MyRequestCPUrate (p, n)
 * 	should return 0 if successful, i.e., if such a request can be
 * 	satisfied, otherwise it should return -1, i.e., error (including if
 *  	n < 0 or n > 100). If MyRequestCPUrate (p, n) fails, it should
 *   	have no effect on scheduling of this or any other process, i.e., AS
 * 	IF IT WERE NEVER CALLED.
 */

int MyRequestCPUrate (p, n)
	int p;				// process whose rate to change
	int n;				// percent of CPU time
{
	/* your code here */
	if(n<0)
		return -1;

	for (int i = 0; i < MAXPROCS; i++) {
		if (proctab[i].valid && proctab[i].pid == p) {
			if(proctab[i].reqRate == 0){
                if (cur_use + n >100){
                    return (-1);
                }
                proctab[i].reqRate = (1.0* n)/100;
                cur_use += n;
                ReAllocate();  // reallocate will restart the counting of runtime & staytime & utirate, from the exact time of one pro's requesting cpurate
                //when new pro appear, or some pro re-request, will need to clear the utirate data. Or it will cause problems
                // Printf("pro:%d requested:%f \n",p,proctab[i].reqRate);
                return (0);
            }
            else{
                if( (cur_use - proctab[i].reqRate*100 + n) > 100){
                    // printf("pro%d req fail",p);
                    return(-1);
                }
                cur_use = cur_use - proctab[i].reqRate*100 + n;
                proctab[i].reqRate = (1.0* n)/100;
                ReAllocate();
                // Printf("pro:%d requested:%f \n",p,proctab[i].reqRate);
                return (0);
            }
		}
	}

	return (0);
}



