/* mycode3.c: your portion of the kernel
 *
 *   	Below are procedures that are called by other parts of the kernel. 
 * 	Your ability to modify the kernel is via these procedures.  You may
 *  	modify the bodies of these procedures any way you desire (however,
 *  	you cannot change the interfaces).  
 */

#include "aux.h"
#include "sys.h"
#include "mycode3.h"

#define FALSE 0
#define TRUE 1

/* 	A sample semaphore table. You may change this any way you wish. 
 */

static struct {
	int valid;	// Is this a valid entry (was sem allocated)?
	int value;	// value of semaphore
	int blockList[MAXSEMS];
	int curBlock;
	int curUnblock;
} semtab[MAXSEMS];


/* 	InitSem () is called when kernel starts up.  Initialize data
 *  	structures (such as semaphore table) and call any initialization
 *   	procedures here. 
 */

void InitSem ()
{
	int s;

	/* modify or add code any way you wish */

	for (s = 0; s < MAXSEMS; s++) {		// mark all sems free
		semtab[s].valid = FALSE;
		semtab[s].curBlock = 0;
		semtab[s].curUnblock = 0;
	}
}

/* 	MySeminit (p, v) is called by the kernel whenever the system
 *  	call Seminit (v) is called.  The kernel passes the initial
 *  	value v, along with the process ID p of the process that called
 * 	Seminit.  MySeminit should allocate a semaphore (find free entry
 * 	in semtab and allocate), initialize that semaphore's value to v,
 *  	and then return the ID (i.e., index of allocated entry). 
 */

int MySeminit (int p, int v)
{
	int s;

	/* modify or add code any way you wish */

	for (s = 0; s < MAXSEMS; s++) {
		if (semtab[s].valid == FALSE) {
			break;
		}
	}
	if (s == MAXSEMS) {
		DPrintf ("No free semaphores.\n");
		return (-1);
	}

	semtab[s].valid = TRUE;
	semtab[s].value = v;

	return (s);
}

/*   	MyWait (p, s) is called by the kernel whenever the system call
 * 	Wait (s) is called. 
 */

void MyWait (p, s)
	int p;				// process
	int s;				// semaphore
{
	/* modify or add code any way you wish */
	semtab[s].value--;
	if(semtab[s].value<0){
		semtab[s].blockList[semtab[s].curBlock]=p;
		// DPrintf("sem%d block pro%d in index%d'\n'", s, p, semtab[s].curBlock);
		semtab[s].curBlock++;
		Block(p);
	}
	// else
	// 	semtab[s].value--;
	// DPrintf("%d123",semtab[s].blockList[semtab[s].curBlock]);

}

/*  	MySignal (p, s) is called by the kernel whenever the system call
 *  	Signal (s) is called.  
 */

void MySignal (p, s)
	int p;				// process
	int s;				// semaphore
{
	/* modify or add code any way you wish */
	semtab[s].value++;
	// DPrintf("%d,%d",semtab[s].blockList[semtab[s].curUnblock],semtab[s].curUnblock);
	// if(semtab[s].value==0){
	if(semtab[s].blockList[semtab[s].curUnblock]!=0){
		int q = semtab[s].blockList[semtab[s].curUnblock];
		Unblock(q);
		// DPrintf("sem%d unblock pro%d in index%d", s, q, semtab[s].curUnblock);
		semtab[s].blockList[semtab[s].curUnblock] = 0;
		semtab[s].curUnblock++;
	}
		// else
		// 	semtab[s].value++;
	// }
	// else
	// 	semtab[s].value++;
}

