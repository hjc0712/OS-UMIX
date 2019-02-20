/* Programming Assignment 3: Exercise D
 *
 * Now that you have a working implementation of semaphores, you can
 * implement a more sophisticated synchronization scheme for the car
 * simulation. 
 *
 * Study the program below.  Car 1 begins driving over the road,  entering
 * from the East at 40 mph.  After 900 seconds,  both Car 3 and Car 4 try to
 * enter the road. Car 1 may or may not have exited by this time (it should
 * exit after 900 seconds, but recall that the times in the simulation are
 * approximate). If Car 1 has not exited and Car 4 enters, they will crash
 * (why?).  If Car 1 has exited,  Car 3 and Car 4 will be able to enter the
 * road, but since they enter from opposite directions,  they will eventually
 * crash. Finally,  after 1200 seconds, Car 2 enters the road from the West
 * and traveling twice as fast as Car 4.  If Car 3 was not coming from the
 * opposite direction, Car 2 would eventually reach Car 4 from the back and
 * crash.  You may wish to experiment with reducing the initial delay of
 * Car 2,  or increase the initial delay of Car 3, to cause Car 2 to crash
 * with Car 4 before Car 3 crashes with Car 4. 
 *
 *
 * Exercises
 *
 * 1) Modify the procedure driveRoad such that the following rules are obeyed:
 *
 *   	A) Avoid all collisions. 
 *
 * 	B) Multiple cars should be allowed on the road,  as long as they are
 *  	traveling in the same direction.  
 *
 *  	C) If a car arrives and there are already other cars traveling in the
 * 	SAME DIRECTION,  the arriving car should be allowed enter as soon as it
 * 	can. Two situations might prevent this car from entering immediately:
 *  	(1) there is a car immediately in front of it (going in the same
 *   	direction), and if it enters it will crash (which would break rule A);
 * 	(2) one or more cars have arrived at the other end to travel in the
 *  	opposite direction and are waiting for the current cars on the road
 *  	to exit, which is covered by the next rule.  
 *
 * 	D) If a car arrives and there are already other cars traveling in the
 * 	OPPOSITE DIRECTION,  the arriving car must wait until all these other
 *  	cars complete their course over the road and exit.  It should only wait
 *   	for the cars already on the road to exit; no new cars traveling in the
 * 	same direction as the existing ones should be allowed to enter. 
 *
 *  	E) The previous rule implies that if there are multiple cars at each
 *  	end waiting to enter the road, each side will take turns in allowing
 * 	one car to enter and exit. However,  if there are no cars waiting at
 * 	one end,  then as cars arrive at the other end, they should be allowed
 *  	to enter the road immediately.  
 *	
 *   	F) If the road is free (no cars), then any car attempting to enter
 * 	should not be prevented from doing so. 
 *
 *  	G) All starvation must be avoided.  For example,  any car that is
 *  	waiting must eventually be allowed to proceed.  
 *
 * This must be achieved ONLY by adding synchronization and making use of
 * shared memory (as described in Exercise C). You should NOT modify the
 * delays or speeds to solve the problem. In other words, the delays and
 * speeds are givens,  and your goal is to enforce the above rules by making
 * use of only semaphores and shared memory.  
 *
 * 2) Devise different tests (using different numbers of cars,  speeds
 * directions) to see whether your improved implementation of driveRoad
 * obeys the rules above. 
 *
 * IMPLEMENTATION GUIDELINES
 * 
 * 1) Avoid busy waiting.  In class one of the reasons given for using
 * semaphores was to avoid busy waiting in user code and limit it to
 * minimal use in certain parts of the kernel.  This is because busy
 * waiting uses up CPU time, but a blocked process does not. You have
 * semaphores available to implement the driveRoad function, so you
 * should not use busy waiting anywhere. 
 *
 * 2) Prevent race conditions.  One reason for using semaphores is to
 * enforce mutual exclusion on critical sections to avoid race conditions. 
 * You will be using shared memory in your driveRoad implementation.  
 * Identify the places in your code where there may be race conditions
 * (the result of a computation on shared memory depends on the order
 * that processes execute).  Prevent these race conditions from occurring
 * by using semaphores. 
 *
 * 3) Implement semaphores fully and robustly. It is possible for your
 * driveRoad function to work with an incorrect implementation of
 * semaphores,  because controlling cars does not exercise every use of
 * semaphores.  You will be penalized if your semaphores are not correctly
 * implemented, even if your driveRoad works. 
 *
 * 4) Control cars with semaphores: Semaphores should be the basic
 * mechanism for enforcing the rules on driving cars.  You should not
 * force cars to delay in other ways inside driveRoad such as by calling
 * the Delay function or changing the speed of a car.  (You can leave in
 * the delay that is already there that represents the car's speed,  just
 * don't add any additional delaying). Also,  you should not be making
 * decisions on what cars do using calculations based on car speed (since
 * there are a number of unpredictable factors that can affect the
 * actual cars' progress). 
 *
 * GRADING INFORMATION
 *
 * 1) Semaphores: We will run a number of programs that test your
 * semaphores directly (without using cars at all).  For example:
 * enforcing mututal exclusion, testing robustness of your list of
 * waiting processes, calling signal and wait many times to make sure
 * the semaphore state is consistent,  etc. 
 *
 * 2) Cars: We will run some tests of cars arriving in different ways
 * to make sure that you correctly enforce all the rules for cars given
 * in the assignment.  We will use a correct semaphore implementation for
 * these tests so that even if your semaphores are not correct you could
 * still get full credit on the driving part of the grade (you may assume
 * that in our implementation, semaphore unblocking is FIFO,  i.e.,  for
 * each semaphore, the order in which processes are unblocked is the
 * same order in which those same processes blocked).  Think about
 * how your driveRoad might handle different situations and write your
 * own tests with cars arriving in different ways to make sure you handle
 * all cases correctly. 
 *
 *
 * WHAT TO TURN IN
 *
 * You must turn in two files: mycode3.c and pa3d.c. mycode3.c should
 * contain you implementation of semaphores, and pa3d.c should contain
 * your modified version of InitRoad and driveRoad (Main will be ignored).  
 * Note that you may set up your static shared memory struct and other
 * functions as you wish. They should be accessed via InitRoad and driveRoad
 * as those are the functions that we will call to test your code.  
 *
 * Your programs will be tested with various Main programs that will exercise
 * your semaphore implementation,  AND different numbers of cars, directions
 * and speeds,  to exercise your driveRoad function.  Our Main programs will
 * first call InitRoad before calling driveRoad. Make sure you do as much
 * rigorous testing yourself to be sure your implementations are robust. 
 * Good luck.  
 */

#include <stdio.h>
#include "aux.h"
#include "sys.h"
#include "umix.h"

static struct{
	int direction;
	int westWait;
	int eastWait;
	int posi[NUMPOS];
	int westSe;
	int eastSe;
	int westGate;
	int eastGate;
	int mutex;
	int curCars;
	int waitCars;
}roadState;

void InitRoad (void);
void driveRoad (int from, int mph);
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();

void Main ()
{
	InitRoad ();

	/* The following code is specific to this simulation,  e.g., number
	 * of cars, directions and speeds. You should experiment with
	 * different numbers of cars,  directions and speeds to test your
	 * modification of driveRoad.  When your solution is tested, we
	 * will use different Main procedures,  which will first call
	 * InitRoad before any calls to driveRoad.  So,  you should do
	 * any initializations in InitRoad. 
	 */
	// D
	// DPrintf("================================");
 	// test1();
 // 	DPrintf("================================");
 	// test2();
	// test3();
	// // DPrintf("================================");
	// test4();
	// test5();
	// test6();
	// test7();
	// test8();
	// test9();
	// test10();
	// test11();

	if (Fork () == 0) {
		Delay (1200);			// car 2
		driveRoad (WEST, 60);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (900);			// car 3
		driveRoad (EAST, 50);
		Exit ();
	}

	if (Fork () == 0) {
		Delay (900);			// car 4
		driveRoad (WEST, 30);
		Exit ();
	}

	driveRoad (EAST, 40);			// car 1

	Exit ();
}

/* Our tests will call your versions of InitRoad and driveRoad, so your
 * solution to the car simulation should be limited to modifying the code
 * below. This is in addition to your semaphore implementation contained
 * in mycode3.c.  
 */

void InitRoad ()
{
	/* do any initializations here */
	Regshm((char *) &roadState, sizeof(roadState));
	roadState.direction=-1;
	roadState.westWait=0;
	roadState.eastWait=0;
	
	roadState.westSe=Seminit(0);
	roadState.eastSe=Seminit(0);
	roadState.westGate=Seminit(0);
	roadState.eastGate=Seminit(0);
	roadState.mutex=Seminit(1);
	roadState.curCars=0;
	roadState.waitCars=0;
	for (int i=0;i<NUMPOS;i++){
		roadState.posi[i]=Seminit(1);
	}
	

}

#define IPOS(FROM)	(((FROM) == WEST) ? 1 : NUMPOS)

void driveRoad (from, mph)
	int from;			// which direction coming from
	int mph;			// speed of car
{
	int c;				// car ID c = process ID
	int p, np, i;			// positions

	c = Getpid ();			// get this car's ID


	//wait to enter the road=========================================
	// DPrintf("pro%d starts\n", c);
	Wait(roadState.mutex);
	if(roadState.curCars==0 && roadState.direction==-1){ //need to judge direction(when somethings just be signaled but not yet onto the road, the direction won't be -1 in that case)
		roadState.direction = from;
		// DPrintf("pro%d ready to go'\n'", c);
		Signal(roadState.mutex);
	}
	else if(roadState.direction!=from){ //roadState.curCars > 0 &&
		if(from == WEST){
			roadState.westWait +=1;
			roadState.waitCars +=1;
			Signal(roadState.mutex);
			// DPrintf("1pro%d wait at west\n", c);
			Wait(roadState.westSe);
			// Wait(roadState.westGate);
			// DPrintf("1pro%d go alive\n", c);
		}
		else{
			roadState.eastWait +=1;
			roadState.waitCars +=1;
			Signal(roadState.mutex);
			// DPrintf("1pro%d wait at east\n", c);
			Wait(roadState.eastSe);
			// Wait(roadState.eastGate);
			// DPrintf("1pro%d go alive\n", c);
		}
	}
	else if(roadState.direction == from){
		if(from == WEST){
			Signal(roadState.mutex);
			roadState.westWait += 1;
            roadState.waitCars += 1;
            // DPrintf("%d wait at westgate",c)
			Wait(roadState.westGate);
			// DPrintf("%d go out westgate",c)

			Wait(roadState.mutex);
			if(roadState.eastWait>0){  // if there are already car wait on the other end
                Signal(roadState.mutex);
                // DPrintf("2pro%d wait at west\n", c);
                Wait(roadState.westSe);
                
                // DPrintf("1pro%d go alive\n", c);
			}
			else
				Signal(roadState.mutex);
			
		}
		else{
			Signal(roadState.mutex);
			roadState.eastWait += 1;
            roadState.waitCars += 1;
            // DPrintf("%d wait at eastgate",c);
			Wait(roadState.eastGate);
			// DPrintf("%d go out eastgate",c);

			Wait(roadState.mutex);
			if(roadState.westWait>0){  // if there are already car wait on the other end
                Signal(roadState.mutex);
                // DPrintf("2pro%d wait at east\n", c);
                Wait(roadState.eastSe);
                
			}
			else
				Signal(roadState.mutex);
			
		}
	}
	
	
	//enter===================================================
	Wait(roadState.mutex);
    // roadState.curCars += 1;
    // roadState.direction = from;
    // DPrintf("curCars:%d'\n'",roadState.curCars);
        //if (roadState.numCars == 1) {
    if (from == WEST) {
        Signal(roadState.mutex);
        // Wait(roadState.westGate);
        Wait(roadState.posi[0]);
        // if(roadState.eastWait>0 && roadState.direction==WEST){
        // 	Wait(roadState.westSe);
        // }
    }
    else if (from == EAST) {
        Signal(roadState.mutex);
        // Wait(roadState.eastGate);
        Wait(roadState.posi[NUMPOS - 1]);
        // if(roadState.westWait>0 && roadState.direction==EAST){
        // 	Wait(roadState.eastSe);
        // }
        // DPrintf("%d take %d\n",c,NUMPOS);
    }        
    else Signal(roadState.mutex);	

 
    roadState.curCars += 1;
    roadState.direction = from;
	
	EnterRoad (from);
	PrintRoad ();
	Printf ("Car %d enters at %d at %d mph\n", c, IPOS(from), mph);





	//move forward=============================================
	for (i = 1; i < NUMPOS; i++) {
		if (from == WEST) {
			p = i;
			np = i + 1;
		} else {
			p = NUMPOS + 1 - i;
			np = p - 1;
		}

		Delay (3600/mph);

		//wait to move forward=====================================================
		// DPrintf("car%d start moving'\n'",c);
		Wait(roadState.posi[np - 1]);
		ProceedRoad ();
		Signal(roadState.posi[p - 1]);

		if (i == 1){
         //   DPrintf("in\n");

            Wait(roadState.mutex);
            //if (i == 1){
                //Signal(roadState.mutex);
                               //} 
            if (from == WEST){
            	// roadState.westWait -= 1;
             //    roadState.waitCars -= 1;
                Signal(roadState.mutex);
                // if(roadState.westWait>0)
                	Signal(roadState.westGate);
                
            	// Signal(roadState.posi[0]);   /////--------------------------extra free!!!!!
            	if(roadState.eastWait==0 && roadState.westWait>0){ // if the opposite direction has no waiting cars & same direction has waiting car
            		roadState.westWait-=1;
            		roadState.waitCars-=1;
            		Signal(roadState.westSe);
                	DPrintf("2signal west\n");
            	}
            } 
            else if (from == EAST){
            	// roadState.eastWait -= 1;
             //    roadState.notRoadCars -= 1;
                Signal(roadState.mutex);
                // if(roadState.eastWait>0)
                	Signal(roadState.eastGate);
            	// Signal(roadState.posi[NUMPOS-1]);
            	if(roadState.westWait==0 && roadState.eastWait>0){
            		roadState.eastWait-=1;
            		roadState.waitCars-=1;
            		Signal(roadState.eastSe);
                	// DPrintf("2signal east\n");
            	}
            } 

            else {
                Signal(roadState.mutex); 
            }
        }

		PrintRoad ();
		Printf ("Car %d moves from %d to %d\n", c, p, np);
	}

	// DPrintf("car%d ready to exit\n");
	Delay (3600/mph);
	ProceedRoad ();

	if (from == WEST) {
	    Signal(roadState.posi[NUMPOS - 1]);
	    // DPrintf("car%d free the exit");
    }
    else {
        Signal(roadState.posi[0]);
    }

	PrintRoad ();
	Printf ("Car %d exits road\n", c);

	roadState.curCars -= 1;
	if (from == WEST){
            //DPrintf("we\n");
            if (roadState.curCars == 0 && roadState.eastWait > 0){
                roadState.eastWait -= 1;
                roadState.waitCars -= 1;
                roadState.direction = from;
          //      DPrintf("eastcars:%d\n",roadState.eastWait);
            //    DPrintf("westcars:%d\n",roadState.westWait);
                
                Signal(roadState.mutex);
                Signal(roadState.eastSe);
                // DPrintf("1signal east\n");

                // if(roadState.westWait==0){
                // 	while(roadState.eastWait>0){
                // 		roadState.eastWait -= 1;
                // 		roadState.waitCars -= 1;
                // 		Signal(roadState.eastSe);
                // 		DPrintf("2signal east\n");
                // 	}
                // }
            }
            else if(roadState.curCars == 0 && roadState.eastWait == 0){
            	Signal(roadState.mutex);
            	roadState.direction = -1;
            } 
            else Signal(roadState.mutex);
        }
    else if (from == EAST) {
    	// DPrintf("fixfixfix\n");
        if (roadState.curCars == 0 && roadState.westWait > 0){
            roadState.westWait -= 1;
            roadState.waitCars -= 1;
            roadState.direction = from;
          //  DPrintf("westcars:%d\n",roadState.westWait);

            Signal(roadState.mutex);
            Signal(roadState.westSe);
            // DPrintf("1signal west\n");
            // if(roadState.eastWait==0){
            // 	while(roadState.westWait>0){
            // 		roadState.westWait -= 1;
            // 		roadState.waitCars -= 1;
            // 		Signal(roadState.westSe);
            // 		DPrintf("2signal west\n");
            // 	}
            // }
        }
        else if(roadState.curCars == 0 && roadState.eastWait == 0){
        	Signal(roadState.mutex);
        	roadState.direction = -1;
        } 
        else Signal(roadState.mutex);
    }

    else {
       // DPrintf("si\n");
        Signal(roadState.mutex);
    }

}


void test1() {
  if (Fork () == 0) {
    Delay (1200);     // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (800);      // car 3
    driveRoad (EAST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (900);      // car 4
    driveRoad (WEST, 30);
    Exit ();
  }

  driveRoad (EAST, 30);     // car 1
}


// 5 cars at each gate (entered approximately at the same time)
// Should alternate on the road
void test2() {
  int i;
  for (i = 0; i < 5; i++) {
    if (Fork() == 0) {
      driveRoad(WEST, 40);
      Exit();
    }
    if (Fork() == 0 && i != 4) {
      driveRoad(EAST, 40);
      Exit();
    }
  }

  driveRoad (EAST, 40);     // car 1
}


// Car 1 comes in from the EAST, then car 2 comes in from the WEST. And then
// car 3 comes in from the WEST. And then car 4 comes in from the EAST.
// Once car 1 finishes, car 2 should be allowed to enter. Car 3 now cannot
// enter from the WEST even though it is going in the same direction as car 2
// and that it arrived before car 4 because car 4 has come in and is waiting on
// the EAST side
// Piazza @353
void test3() {
  if (Fork () == 0) {
    Delay (50);     // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (100);      // car 3
    driveRoad (WEST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (150);      // car 4
    driveRoad (EAST, 50);
    Exit ();
  }

  driveRoad (EAST, 80);     // car 1
}

// Rule B)
// 10 cars coming from the same side (WEST), with the one that comes later going
// faster than the ones that came before
// Cars should come in the same order 1 2 ... 10 and they should be allowed
// on the road at the same time as soon as an empty spot is present in front
// of them
void test4() {  
  int i = 0;
  for (i = 1; i <= 10; i++) {
    if (Fork() == 0) {
      Delay(i * 75);
      driveRoad(WEST, 10 + i * 10);
      Exit();
    }
  }
  driveRoad (WEST, 10);     // car 1
}

// Rule B)
// 10 cars coming from the same side (EAST), with the one that comes later going
// faster than the ones that came before
// Cars should come in the same order 1 2 ... 10 and they should be allowed
// on the road at the same time as soon as an empty spot is present in front
// of them
void test5() {  
  int i = 0;
  for (i = 1; i <= 10; i++) {
    if (Fork() == 0) {
      Delay(i * 75);
      driveRoad(EAST, 10 + i * 10);
      Exit();
    }
  }
  driveRoad (EAST, 10);     // car 1
}

// Tests Rule C1, car 2 should not enter when car 1 is in spot 1
// Car 1 and 2 come in from the WEST at the same time (Car 1 will enter first). 
// Car 1 will enter the road. Car 2 will try to enter the road but cannot b/c
// car 1 has the first spot. When car 1 moves to the 2nd spot, car 3 has
// arrived, so car 2 now has to wait for car 3 to come from the other side
// before it could enter the road. Once car 3 finishes, car 2 will enter the
// road followed by car 4
void test6() {
  if (Fork () == 0) {
    // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (200);      // car 3
    driveRoad (EAST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    Delay (400);      // car 4
    driveRoad (WEST, 50);
    Exit ();
  }

  driveRoad (WEST, 10);     // car 1
}

// Tests Rule C2 (also D).
// Car 1 enters from the WEST. Car 3 comes from EAST. Car 2 shows up at WEST
// but has to wait because car 3 is waiting at EAST.
void test7() {
     if (Fork () == 0) {
        Delay (10);              // car 2
        driveRoad (WEST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (20);              // car 3
        driveRoad (WEST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (30);              // car 4
        driveRoad (WEST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (40);              // car 5
        driveRoad (WEST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (50);              // car 6
        driveRoad (EAST, 3599);
        Exit ();
    }
    if (Fork () == 0) {
        Delay (60);              // car 7
        driveRoad (EAST, 3599);
        Exit ();
    } 

    if (Fork () == 0) {
        Delay (70);              // car 8
        driveRoad (EAST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (80);              // car 9
        driveRoad (EAST, 3599);
        Exit ();
    }

    if (Fork () == 0) {
        Delay (90);              // car 10
        driveRoad (EAST, 3599);
        Exit ();
    }
    driveRoad (WEST, 3599);     // car 1

    Exit ();
  // if (Fork () == 0) {
  //   // car 2
  //   Delay(100);
  //   driveRoad (WEST, 60);
  //   Exit ();
  // }

  // if (Fork () == 0) {
  //   // car 3
  //   driveRoad (EAST, 50);
  //   Exit ();
  // }

  // driveRoad (WEST, 40);     // car 1
}

// Cars 1 through 6 come to WEST. Before all 6 cars get to enter road, 
// Car 7 will come to EAST (couple cars might enter before car 7 come and
// stop the rest from entering).
// For example, car 1-3 come. 2 has to wait for 1 to clear the first spot
// before it enters. Then 3 has to wait for 2 to clear the first spot so it
// could enter. Now 7 enters the EAST. 4-6 have to wait even though it came
// first but because it hasn't gotten on the road, it still has to assess
// whether the otherside has any car that came.
void test8() {
  if (Fork () == 0) {
    // car 2
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    // car 3
    driveRoad (WEST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    // car 4
    driveRoad (WEST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    // car 5
    driveRoad (WEST, 60);
    Exit ();
  }

  if (Fork () == 0) {
    // car 6
    driveRoad (WEST, 50);
    Exit ();
  }

  if (Fork () == 0) {
    // car 7
    Delay(10);
    driveRoad (EAST, 50);
    Exit ();
  }

  driveRoad (WEST, 40);     // car 1
}

// Tests Rule F. If road is free, any car should be able to enter
// Car 1 and 3 enter WEST. Car 2 and 4 enter EAST. A while later (after 
// cars 1-4 all exit the road), car 5 enters.
void test9() {
  if (Fork () == 0) {
    // car 2
    driveRoad (EAST, 100);
    Exit ();
  }

  if (Fork () == 0) {
    // car 3
    driveRoad (WEST, 100);
    Exit ();
  }

  if (Fork () == 0) {
    // car 4
    driveRoad (EAST, 100);
    Exit ();
  }

  if (Fork () == 0) {
    // car 5
    Delay(3000);
    driveRoad (WEST, 50);
    Exit ();
  }

  driveRoad (WEST, 100);      // car 1
}

// 2 cars different direction. Car 1 (WEST) first then car 2 (EAST)
void test10() {
  if (Fork() == 0) {
    Delay(100);
    driveRoad(EAST, 50);
    Exit();
  }
  driveRoad(WEST, 50);
}

// 2 cars different direction. Car 1 (EAST) first then car 2 (WEST)
void test11() {
  if (Fork() == 0) {
    Delay(100);
    driveRoad(WEST, 50);
    Exit();
  }
  driveRoad(EAST, 50);
}


