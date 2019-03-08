/*   	Umix thread package
 *
 */

#include <setjmp.h>

#include "aux.h"
#include "umix.h"
#include "mycode4.h"

static int MyInitThreadsCalled = 0;	// 1 if MyInitThreads called, else 0

static struct thread {			// thread table
	int valid;			// 1 if entry is valid, else 0
	jmp_buf env;			// current context
	jmp_buf init;
	int fPara;
	void (*tFunc)();
} thread[MAXTHREADS];

int curThread = 0;

static struct linklist {
	linklist *last;
	linklist *next;
	int threadId;
	void linklist(int a){
		threadId = a;
	}
};
linklist *prehead = new linklist(-1);
linklist *tail = new linklist(-1)


#define STACKSIZE	65536		// maximum size of thread stack

/* 	MyInitThreads () initializes the thread package. Must be the first
 *  	function called by any user program that uses the thread package.  
 */

void MyInitThreads ()
{
	int i;

	if (MyInitThreadsCalled) {		// run only once
		Printf ("MyInitThreads: should be called only once\n");
		Exit ();
	}

	for (i = 0; i < MAXTHREADS; i++) {	// initialize thread table
		thread[i].valid = 0;
	}

	thread[0].valid = 1;			// initialize thread 0

	MyInitThreadsCalled = 1;

	// Printf("aaaa");
	for(int j = 0; j < MAXTHREADS; j++) {
		char s[(STACKSIZE)*j];
		if (((int) &s[STACKSIZE-1]) - ((int) &s[0]) + 1 != STACKSIZE) {
			Printf ("Stack space reservation failed\n");
			Exit ();
		}
		if(setjmp(thread[j].init)!=0) {	// if the env started at anything but 0
			// Printf("thread%dexecuting",j);
			(*(thread[curThread].tFunc)) (thread[curThread].fPara);
			MyExitThread();
		}
	}

	// initialize the linklist with prehead->head->tail
	linklist *head = new linklist(0);
	linklist *prehead->next = head;
	head->next = tail;
	tail->last = head;
}

/*  	MyCreateThread (f, p) creates a new thread to execute
 * 	f (p), where f is a function with no return value and
 * 	p is an integer parameter.  The new thread does not begin
 *  	executing until another thread yields to it. 
 */

int MyCreateThread (f, p)
	void (*f)();			// function to be executed
	int p;				// integer parameter
{
	if (! MyInitThreadsCalled) {
		Printf ("MyCreateThread: Must call MyInitThreads first\n");
		Exit ();
	}

	// Printf("bbbb");
	// if (setjmp (thread[0].env) == 0) {	// save context of thread 0

	// 	/* The new thread will need stack space. Here we use the
	// 	 * following trick: the new thread simply uses the current
	// 	 * stack.  So, there is no need to allocate space. However,
	// 	 * to ensure that thread 0's stack may grow and (hopefully)
	// 	 * not bump into thread 1's stack, the top of the stack is
	// 	 * effectively extended automatically by declaring a local
	// 	 * variable (a large "dummy" array).  This array is never
	// 	 * actually used.  To prevent an optimizing compiler from
	// 	 * removing it, it should be referenced. 
	// 	 */

	// 	char stack[STACKSIZE];	// reserve space for thread 0's stack
		void (*func)() = f;	// func saves f on top of stack
		int param = p;		// param saves p on top of stack

	// 	if (((int) &stack[STACKSIZE-1]) - ((int) &stack[0]) + 1 != STACKSIZE) {
	// 		Printf ("Stack space reservation failed\n");
	// 		Exit ();
	// 	}

	// 	if (setjmp (thread[1].env) == 0) {	// save context of 1  //thread[1].env 停留在这里，下一次longjmp(thread[1].env)的时候从这里继续，可以直接跳到line 86
	// 		longjmp (thread[0].env, 1);	// back to thread 0  // to the place where thread[0].env prviously saved ( the if .. on line 60), and that will go out of the if all the way to line 93, because the second time setjmp returns t rather than 0
	// 	}

	// 	/* here when thread 1 is scheduled for the first time */

	// 	(*func) (param);		// execute func (param)

	// 	MyExitThread ();		// thread 1 is done - exit
	// }

	int cur=0;
	int found=0;
	for(int i=curThread+1;i<MAXTHREADS;i++){
		if(!thread[i % MAXTHREADS].valid){   //start from the current thread, find the next avialable thread 
			found=1;
			cur=i % MAXTHREADS;
			thread[cur].valid=1;
			thread[cur].tFunc = *func;
			thread[cur].fPara = param;
			memcpy(thread[cur].env, thread[cur].init, sizeof(jmp_buf));
			Printf("%d",cur);
			break;
		}
	}
	if(!found){
		return -1;
	}
	
	// add new node to the end of the linklist
	linklist *curNode = new linklist(cur);
	curNode->last = tail;
	tail->next = curNode;
	tail = curNode;
	// Printf("cccc");
	// thread[1].valid = 1;	// mark the entry for the new thread valid

	return (cur);		// done, return new thread ID
}

/*   	MyYieldThread (t) causes the running thread, call it T, to yield to
 * 	thread t. Returns the ID of the thread that yielded to the calling
 *  	thread T, or -1 if t is an invalid ID.  Example: given two threads
 *  	with IDs 1 and 2, if thread 1 calls MyYieldThread (2), then thread 2
 * 	will resume, and if thread 2 then calls MyYieldThread (1), thread 1
 * 	will resume by returning from its call to MyYieldThread (2), which
 *  	will return the value 2.
 */

int MyYieldThread (t)
	int t;				// thread being yielded to
{
	// Printf("dddddd");
	if (! MyInitThreadsCalled) {
		Printf ("MyYieldThread: Must call MyInitThreads first\n");
		Exit ();
	}

	if (t < 0 || t >= MAXTHREADS) {
		Printf ("MyYieldThread: %d is not a valid thread ID\n", t);
		return (-1);
	}
	// Printf("eeeeee");
	if (! thread[t].valid) {
		Printf ("MyYieldThread: Thread %d does not exist\n", t);
		return (-1);
	}

	// modify the linklist
	// first add cur node to the end
    linklist *curNode = new linklist(curThread);
    curNode->last=tail;
    tail->next=curNode;
    tail=curNode;

    linklist *tmp = prehead->next;
    while(tmp->value!=t){
    	tmp = tmp -> next;
    }
    tmp->last->next = tmp -> next;

    if (setjmp (thread[curThread].env) == 0) { //save current thread's env, so the next time a thread yield to current thread, it will begin at this point
            Printf("\nffffff %d",t);
            curThread = t;                     //after saving, change the global viarable curThread so that 
            longjmp (thread[t].env, t);
    }



}

/*   	MyGetThread () returns ID of currently running thread. 
 */

int MyGetThread ()
{
	if (! MyInitThreadsCalled) {
		Printf ("MyGetThread: Must call MyInitThreads first\n");
		Exit ();
	}
	return curThread;
}

/* 	MySchedThread () causes the running thread to simply give up the
 *  	CPU and allow another thread to be scheduled.  Selecting which
 *  	thread to run is determined here.  Note that the same thread may
 * 	be chosen (as will be the case if there are no other threads). 
 */

void MySchedThread ()
{
	if (! MyInitThreadsCalled) {
		Printf ("MySchedThread: Must call MyInitThreads first\n");
		Exit ();
	}
}

/* 	MyExitThread () causes the currently running thread to exit. 
 */

void MyExitThread ()
{
	if (! MyInitThreadsCalled) {
		Printf ("MyExitThread: Must call MyInitThreads first\n");
		Exit ();
	}
}
