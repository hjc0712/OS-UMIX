================================pro1 ready to go'
'curCars:1'
'W1---------E Car 1 enters at 1 at 40 mph
1pro2 wait at east
1pro3 wait at east
2pro4 wait at west
1pro5 wait at east
1pro6 wait at east
2pro7 wait at west
W-1--------E Car 1 moves from 1 to 2
W--1-------E Car 1 moves from 2 to 3
W---1------E Car 1 moves from 3 to 4
W----1-----E Car 1 moves from 4 to 5
W-----1----E Car 1 moves from 5 to 6
W------1---E Car 1 moves from 6 to 7
W-------1--E Car 1 moves from 7 to 8
W--------1-E Car 1 moves from 8 to 9
W---------1E Car 1 moves from 9 to 10
W----------E Car 1 exits road
1signal east
1pro2 go alive
curCars:1'
'W---------2E Car 2 enters at 10 at 60 mph
W--------2-E Car 2 moves from 10 to 9
W-------2--E Car 2 moves from 9 to 8
W------2---E Car 2 moves from 8 to 7
W-----2----E Car 2 moves from 7 to 6
W----2-----E Car 2 moves from 6 to 5
W---2------E Car 2 moves from 5 to 4
W--2-------E Car 2 moves from 4 to 3
W-2--------E Car 2 moves from 3 to 2
W2---------E Car 2 moves from 2 to 1
W----------E Car 2 exits road
1signal west
1pro4 go alive
curCars:1'
'W4---------E Car 4 enters at 1 at 30 mph
W-4--------E Car 4 moves from 1 to 2
W--4-------E Car 4 moves from 2 to 3
W---4------E Car 4 moves from 3 to 4
W----4-----E Car 4 moves from 4 to 5
W-----4----E Car 4 moves from 5 to 6
W------4---E Car 4 moves from 6 to 7
W-------4--E Car 4 moves from 7 to 8
W--------4-E Car 4 moves from 8 to 9
W---------4E Car 4 moves from 9 to 10
W----------E Car 4 exits road
1signal east
1pro3 go alive
curCars:1'
'W---------3E Car 3 enters at 10 at 50 mph
W--------3-E Car 3 moves from 10 to 9
W-------3--E Car 3 moves from 9 to 8
W------3---E Car 3 moves from 8 to 7
W-----3----E Car 3 moves from 7 to 6
W----3-----E Car 3 moves from 6 to 5
W---3------E Car 3 moves from 5 to 4
W--3-------E Car 3 moves from 4 to 3
W-3--------E Car 3 moves from 3 to 2
W3---------E Car 3 moves from 2 to 1
W----------E Car 3 exits road
1signal west
1pro7 go alive
curCars:1'
'W7---------E Car 7 enters at 1 at 30 mph
W-7--------E Car 7 moves from 1 to 2
W--7-------E Car 7 moves from 2 to 3
W---7------E Car 7 moves from 3 to 4
W----7-----E Car 7 moves from 4 to 5
W-----7----E Car 7 moves from 5 to 6
W------7---E Car 7 moves from 6 to 7
W-------7--E Car 7 moves from 7 to 8
W--------7-E Car 7 moves from 8 to 9
W---------7E Car 7 moves from 9 to 10
W----------E Car 7 exits road
1signal east
1pro5 go alive
curCars:1'
'W---------5E Car 5 enters at 10 at 60 mph
2signal west
W--------5-E Car 5 moves from 10 to 9
1pro6 go alive
curCars:2'
'W--------56E Car 6 enters at 10 at 50 mph
W-------5-6E Car 5 moves from 9 to 8
2signal west
W-------56-E Car 6 moves from 10 to 9
W------5-6-E Car 5 moves from 8 to 7
W------56--E Car 6 moves from 9 to 8
W-----5-6--E Car 5 moves from 7 to 6
W-----56---E Car 6 moves from 8 to 7
W----5-6---E Car 5 moves from 6 to 5
W---5--6---E Car 5 moves from 5 to 4
W---5-6----E Car 6 moves from 7 to 6
W--5--6----E Car 5 moves from 4 to 3
W--5-6-----E Car 6 moves from 6 to 5
W-5--6-----E Car 5 moves from 3 to 2
W-5-6------E Car 6 moves from 5 to 4
W5--6------E Car 5 moves from 2 to 1
W5-6-------E Car 6 moves from 4 to 3
W--6-------E Car 5 exits road
W-6--------E Car 6 moves from 3 to 2
W6---------E Car 6 moves from 2 to 1
W----------E Car 6 exits road
Road Trace: >|<|>|<|>|<<||

System exiting (normal)
[cs120wou@ieng9]:pa3:694$ rm pa3d.c 
[cs120wou@ieng9]:pa3:695$ nano pa3d.c
[cs120wou@ieng9]:pa3:696$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:697$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 9734

================================
pro1 ready to go'
'curCars:1'
'W1---------E Car 1 enters at 1 at 1 mph
curCars:2'
'1pro3 wait at east
W-1--------E Car 1 moves from 1 to 2
W21--------E Car 2 enters at 1 at 60 mph
W2-1-------E Car 1 moves from 2 to 3
W-21-------E Car 2 moves from 1 to 2
W-2-1------E Car 1 moves from 3 to 4
W--21------E Car 2 moves from 2 to 3
W--2-1-----E Car 1 moves from 4 to 5
W---21-----E Car 2 moves from 3 to 4
W---2-1----E Car 1 moves from 5 to 6
W----21----E Car 2 moves from 4 to 5
W----2-1---E Car 1 moves from 6 to 7
W-----21---E Car 2 moves from 5 to 6
W-----2-1--E Car 1 moves from 7 to 8
W------21--E Car 2 moves from 6 to 7
W------2-1-E Car 1 moves from 8 to 9
W-------21-E Car 2 moves from 7 to 8
W-------2-1E Car 1 moves from 9 to 10
W--------21E Car 2 moves from 8 to 9
W--------2-E Car 1 exits road
W---------2E Car 2 moves from 9 to 10
W----------E Car 2 exits road
1signal east
1pro3 go alive
curCars:1'
'W---------3E Car 3 enters at 10 at 50 mph
W--------3-E Car 3 moves from 10 to 9
W-------3--E Car 3 moves from 9 to 8
W------3---E Car 3 moves from 8 to 7
W-----3----E Car 3 moves from 7 to 6
W----3-----E Car 3 moves from 6 to 5
W---3------E Car 3 moves from 5 to 4
W--3-------E Car 3 moves from 4 to 3
W-3--------E Car 3 moves from 3 to 2
W3---------E Car 3 moves from 2 to 1
W----------E Car 3 exits road
Road Trace: >>||<|

System exiting (normal)
[cs120wou@ieng9]:pa3:698$ nano pa3d.c
[cs120wou@ieng9]:pa3:699$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:700$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 16045

================================
pro1 ready to go'
'curCars:1'
'W1---------E Car 1 enters at 1 at 40 mph
W-1--------E Car 1 moves from 1 to 2
W--1-------E Car 1 moves from 2 to 3
W---1------E Car 1 moves from 3 to 4
W----1-----E Car 1 moves from 4 to 5
W-----1----E Car 1 moves from 5 to 6
W------1---E Car 1 moves from 6 to 7
W-------1--E Car 1 moves from 7 to 8
curCars:2'
'W3------1--E Car 3 enters at 1 at 50 mph
1pro2 wait at east
W3-------1-E Car 1 moves from 8 to 9
W-3------1-E Car 3 moves from 1 to 2
W--3-----1-E Car 3 moves from 2 to 3
W--3------1E Car 1 moves from 9 to 10
1pro4 wait at east
W---3-----1E Car 3 moves from 3 to 4
W---3------E Car 1 exits road
W----3-----E Car 3 moves from 4 to 5
W-----3----E Car 3 moves from 5 to 6
W------3---E Car 3 moves from 6 to 7
W-------3--E Car 3 moves from 7 to 8
W--------3-E Car 3 moves from 8 to 9
W---------3E Car 3 moves from 9 to 10
W----------E Car 3 exits road
1signal east
1pro2 go alive
curCars:1'
'W---------2E Car 2 enters at 10 at 60 mph
2signal west
W--------2-E Car 2 moves from 10 to 9
1pro4 go alive
curCars:2'
'W--------24E Car 4 enters at 10 at 30 mph
W-------2-4E Car 2 moves from 9 to 8
W------2--4E Car 2 moves from 8 to 7
2signal west
W------2-4-E Car 4 moves from 10 to 9
W-----2--4-E Car 2 moves from 7 to 6
W----2---4-E Car 2 moves from 6 to 5
W----2--4--E Car 4 moves from 9 to 8
W---2---4--E Car 2 moves from 5 to 4
W--2----4--E Car 2 moves from 4 to 3
W--2---4---E Car 4 moves from 8 to 7
W-2----4---E Car 2 moves from 3 to 2
W2-----4---E Car 2 moves from 2 to 1
W2----4----E Car 4 moves from 7 to 6
W-----4----E Car 2 exits road
W----4-----E Car 4 moves from 6 to 5
W---4------E Car 4 moves from 5 to 4
W--4-------E Car 4 moves from 4 to 3
W-4--------E Car 4 moves from 3 to 2
W4---------E Car 4 moves from 2 to 1
W----------E Car 4 exits road
Road Trace: >>||<<||

System exiting (normal)
[cs120wou@ieng9]:pa3:701$ nano pa3d.c
[cs120wou@ieng9]:pa3:702$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:703$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 18357

================================
pro1 ready to go'
'curCars:1'
'W---------1E Car 1 enters at 10 at 10 mph
curCars:2'
'1pro3 wait at west
W--------1-E Car 1 moves from 10 to 9
W--------12E Car 2 enters at 10 at 60 mph
W-------1-2E Car 1 moves from 9 to 8
W-------12-E Car 2 moves from 10 to 9
W------1-2-E Car 1 moves from 8 to 7
W------12--E Car 2 moves from 9 to 8
W-----1-2--E Car 1 moves from 7 to 6
W-----12---E Car 2 moves from 8 to 7
W----1-2---E Car 1 moves from 6 to 5
W----12----E Car 2 moves from 7 to 6
W---1-2----E Car 1 moves from 5 to 4
W---12-----E Car 2 moves from 6 to 5
W--1-2-----E Car 1 moves from 4 to 3
W--12------E Car 2 moves from 5 to 4
W-1-2------E Car 1 moves from 3 to 2
W-12-------E Car 2 moves from 4 to 3
W1-2-------E Car 1 moves from 2 to 1
W12--------E Car 2 moves from 3 to 2
W-2--------E Car 1 exits road
W2---------E Car 2 moves from 2 to 1
W----------E Car 2 exits road
1signal west
curCars:1'
'W3---------E Car 3 enters at 1 at 50 mph
W-3--------E Car 3 moves from 1 to 2
W--3-------E Car 3 moves from 2 to 3
W---3------E Car 3 moves from 3 to 4
W----3-----E Car 3 moves from 4 to 5
W-----3----E Car 3 moves from 5 to 6
W------3---E Car 3 moves from 6 to 7
W-------3--E Car 3 moves from 7 to 8
W--------3-E Car 3 moves from 8 to 9
W---------3E Car 3 moves from 9 to 10
W----------E Car 3 exits road
Road Trace: <<||>|

System exiting (normal)
[cs120wou@ieng9]:pa3:704$ nano pa3d.c
[cs120wou@ieng9]:pa3:705$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:706$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 20400

================================
pro1 ready to go'
'curCars:1'
'W---------1E Car 1 enters at 10 at 10 mph
curCars:2'
'1pro4 wait at west
1pro3 wait at west
W--------1-E Car 1 moves from 10 to 9
W--------12E Car 2 enters at 10 at 60 mph
W-------1-2E Car 1 moves from 9 to 8
W-------12-E Car 2 moves from 10 to 9
W------1-2-E Car 1 moves from 8 to 7
W------12--E Car 2 moves from 9 to 8
W-----1-2--E Car 1 moves from 7 to 6
W-----12---E Car 2 moves from 8 to 7
W----1-2---E Car 1 moves from 6 to 5
W----12----E Car 2 moves from 7 to 6
W---1-2----E Car 1 moves from 5 to 4
W---12-----E Car 2 moves from 6 to 5
W--1-2-----E Car 1 moves from 4 to 3
W--12------E Car 2 moves from 5 to 4
W-1-2------E Car 1 moves from 3 to 2
W-12-------E Car 2 moves from 4 to 3
W1-2-------E Car 1 moves from 2 to 1
W12--------E Car 2 moves from 3 to 2
W-2--------E Car 1 exits road
W2---------E Car 2 moves from 2 to 1
W----------E Car 2 exits road
1signal west
curCars:1'
'W4---------E Car 4 enters at 1 at 50 mph
2signal east
W-4--------E Car 4 moves from 1 to 2
curCars:2'
'W34--------E Car 3 enters at 1 at 50 mph
W3-4-------E Car 4 moves from 2 to 3
2signal east
W-34-------E Car 3 moves from 1 to 2
W-3-4------E Car 4 moves from 3 to 4
W--34------E Car 3 moves from 2 to 3
W--3-4-----E Car 4 moves from 4 to 5
W---34-----E Car 3 moves from 3 to 4
W---3-4----E Car 4 moves from 5 to 6
W----34----E Car 3 moves from 4 to 5
W----3-4---E Car 4 moves from 6 to 7
W-----34---E Car 3 moves from 5 to 6
W-----3-4--E Car 4 moves from 7 to 8
W------34--E Car 3 moves from 6 to 7
W------3-4-E Car 4 moves from 8 to 9
W-------34-E Car 3 moves from 7 to 8
W-------3-4E Car 4 moves from 9 to 10
W--------34E Car 3 moves from 8 to 9
CRASH! Car 3 and 4 collide at 10!
Road Trace: <<||>>C



[cs120wou@ieng9]:pa3:709$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 26222

6================================
W2---------E Car 2 enters at 1 at 40 mph
W-2--------E Car 2 moves from 1 to 2
W32--------E Car 3 enters at 1 at 40 mph
W3-2-------E Car 2 moves from 2 to 3
W-32-------E Car 3 moves from 1 to 2
W432-------E Car 4 enters at 1 at 40 mph
W43-2------E Car 2 moves from 3 to 4
W4-32------E Car 3 moves from 2 to 3
W-432------E Car 4 moves from 1 to 2
W-43-2-----E Car 2 moves from 4 to 5
W-4-32-----E Car 3 moves from 3 to 4
W--432-----E Car 4 moves from 2 to 3
W--43-2----E Car 2 moves from 5 to 6
W--4-32----E Car 3 moves from 4 to 5
W---432----E Car 4 moves from 3 to 4
W---43-2---E Car 2 moves from 6 to 7
W---4-32---E Car 3 moves from 5 to 6
W----432---E Car 4 moves from 4 to 5
W----43-2--E Car 2 moves from 7 to 8
W----4-32--E Car 3 moves from 6 to 7
W-----432--E Car 4 moves from 5 to 6
W-----43-2-E Car 2 moves from 8 to 9
W-----4-32-E Car 3 moves from 7 to 8
W------432-E Car 4 moves from 6 to 7
W------43-2E Car 2 moves from 9 to 10
W------4-32E Car 3 moves from 8 to 9
W-------432E Car 4 moves from 7 to 8
W-------43-E Car 2 exits road
W-------4-3E Car 3 moves from 9 to 10
W--------43E Car 4 moves from 8 to 9
W--------4-E Car 3 exits road
W---------4E Car 4 moves from 9 to 10
W----------E Car 4 exits road
W---------5E Car 5 enters at 10 at 40 mph
W--------5-E Car 5 moves from 10 to 9
W-------5--E Car 5 moves from 9 to 8
W------5---E Car 5 moves from 8 to 7
W------5--6E Car 6 enters at 10 at 40 mph
W-----5---6E Car 5 moves from 7 to 6
W-----5--6-E Car 6 moves from 10 to 9
W-----5-6--E Car 6 moves from 9 to 8
W----5--6--E Car 5 moves from 6 to 5
W----5-6---E Car 6 moves from 8 to 7
W---5--6---E Car 5 moves from 5 to 4
W---5-6----E Car 6 moves from 7 to 6
W--5--6----E Car 5 moves from 4 to 3
W--5-6-----E Car 6 moves from 6 to 5
W-5--6-----E Car 5 moves from 3 to 2
W-5-6------E Car 6 moves from 5 to 4
W5--6------E Car 5 moves from 2 to 1
W5-6-------E Car 6 moves from 4 to 3
W--6-------E Car 5 exits road
W-6--------E Car 6 moves from 3 to 2
W6---------E Car 6 moves from 2 to 1
W----------E Car 6 exits road
W7---------E Car 7 enters at 1 at 40 mph
W-7--------E Car 7 moves from 1 to 2
W--7-------E Car 7 moves from 2 to 3
W---7------E Car 7 moves from 3 to 4
W----7-----E Car 7 moves from 4 to 5
W-----7----E Car 7 moves from 5 to 6
W------7---E Car 7 moves from 6 to 7
W-------7--E Car 7 moves from 7 to 8
W--------7-E Car 7 moves from 8 to 9
W---------7E Car 7 moves from 9 to 10
W----------E Car 7 exits road
W---------8E Car 8 enters at 10 at 40 mph
W--------8-E Car 8 moves from 10 to 9
W-------8--E Car 8 moves from 9 to 8
W------8---E Car 8 moves from 8 to 7
W-----8----E Car 8 moves from 7 to 6
W----8-----E Car 8 moves from 6 to 5
W---8------E Car 8 moves from 5 to 4
W--8-------E Car 8 moves from 4 to 3
W-8--------E Car 8 moves from 3 to 2
W8---------E Car 8 moves from 2 to 1
W----------E Car 8 exits road
W9---------E Car 9 enters at 1 at 40 mph
W-9--------E Car 9 moves from 1 to 2
W--9-------E Car 9 moves from 2 to 3
W---9------E Car 9 moves from 3 to 4
W----9-----E Car 9 moves from 4 to 5
W-----9----E Car 9 moves from 5 to 6
W------9---E Car 9 moves from 6 to 7
W-------9--E Car 9 moves from 7 to 8
W--------9-E Car 9 moves from 8 to 9
W---------9E Car 9 moves from 9 to 10
W----------E Car 9 exits road
W---------10E Car 10 enters at 10 at 40 mph
W--------10-E Car 10 moves from 10 to 9
W-------10--E Car 10 moves from 9 to 8
W------10---E Car 10 moves from 8 to 7
W-----10----E Car 10 moves from 7 to 6
W----10-----E Car 10 moves from 6 to 5
W---10------E Car 10 moves from 5 to 4
W--10-------E Car 10 moves from 4 to 3
W-10--------E Car 10 moves from 3 to 2
W10---------E Car 10 moves from 2 to 1

7================================
pro1 ready to go'
'curCars:1'
'W---------1E Car 1 enters at 10 at 3599 mph
W--------1-E Car 1 moves from 10 to 9
W-------1--E Car 1 moves from 9 to 8
W------1---E Car 1 moves from 8 to 7
W-----1----E Car 1 moves from 7 to 6
W----1-----E Car 1 moves from 6 to 5
W---1------E Car 1 moves from 5 to 4
W--1-------E Car 1 moves from 4 to 3
W-1--------E Car 1 moves from 3 to 2
W1---------E Car 1 moves from 2 to 1
W----------E Car 1 exits road
pro3 ready to go'
'curCars:1'
'W3---------E Car 3 enters at 1 at 3599 mph
W-3--------E Car 3 moves from 1 to 2
W--3-------E Car 3 moves from 2 to 3
W---3------E Car 3 moves from 3 to 4
W----3-----E Car 3 moves from 4 to 5
W-----3----E Car 3 moves from 5 to 6
W------3---E Car 3 moves from 6 to 7
W-------3--E Car 3 moves from 7 to 8
W--------3-E Car 3 moves from 8 to 9
W---------3E Car 3 moves from 9 to 10
W----------E Car 3 exits road
pro2 ready to go'
'curCars:1'
'W---------2E Car 2 enters at 10 at 3599 mph
W--------2-E Car 2 moves from 10 to 9
W-------2--E Car 2 moves from 9 to 8
W------2---E Car 2 moves from 8 to 7
W-----2----E Car 2 moves from 7 to 6
W----2-----E Car 2 moves from 6 to 5
W---2------E Car 2 moves from 5 to 4
W--2-------E Car 2 moves from 4 to 3
W-2--------E Car 2 moves from 3 to 2
1pro4 wait at west
W2---------E Car 2 moves from 2 to 1
W----------E Car 2 exits road
1signal west
curCars:1'
'W4---------E Car 4 enters at 1 at 3599 mph
W-4--------E Car 4 moves from 1 to 2
W--4-------E Car 4 moves from 2 to 3
W---4------E Car 4 moves from 3 to 4
W----4-----E Car 4 moves from 4 to 5
W-----4----E Car 4 moves from 5 to 6
W------4---E Car 4 moves from 6 to 7
W-------4--E Car 4 moves from 7 to 8
W--------4-E Car 4 moves from 8 to 9
W---------4E Car 4 moves from 9 to 10
W----------E Car 4 exits road
Road Trace: <|>|<|>|

System exiting (normal)
[cs120wou@ieng9]:pa3:713$ nano pa3d.c
[cs120wou@ieng9]:pa3:714$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:715$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 4349

8================================
pro1 ready to go'
'curCars:1'
'W---------1E Car 1 enters at 10 at 3599 mph
W--------1-E Car 1 moves from 10 to 9
curCars:2'
'W--------12E Car 2 enters at 10 at 3599 mph
1pro3 wait at west
W-------1-2E Car 1 moves from 9 to 8
W------1--2E Car 1 moves from 8 to 7
W-----1---2E Car 1 moves from 7 to 6
W----1----2E Car 1 moves from 6 to 5
W---1-----2E Car 1 moves from 5 to 4
W--1------2E Car 1 moves from 4 to 3
W-1-------2E Car 1 moves from 3 to 2
W-1------2-E Car 2 moves from 10 to 9
W-1-----2--E Car 2 moves from 9 to 8
W-1----2---E Car 2 moves from 8 to 7
W-1---2----E Car 2 moves from 7 to 6
W-1--2-----E Car 2 moves from 6 to 5
W-1-2------E Car 2 moves from 5 to 4
W-12-------E Car 2 moves from 4 to 3
1pro4 wait at west
W1-2-------E Car 1 moves from 2 to 1
W--2-------E Car 1 exits road
W-2--------E Car 2 moves from 3 to 2
W2---------E Car 2 moves from 2 to 1
W----------E Car 2 exits road
1signal west
curCars:1'
'W3---------E Car 3 enters at 1 at 3599 mph
2signal east
W-3--------E Car 3 moves from 1 to 2
W--3-------E Car 3 moves from 2 to 3
W---3------E Car 3 moves from 3 to 4
W----3-----E Car 3 moves from 4 to 5
W-----3----E Car 3 moves from 5 to 6
W------3---E Car 3 moves from 6 to 7
curCars:2'
'W4-----3---E Car 4 enters at 1 at 3599 mph
2signal east
W-4----3---E Car 4 moves from 1 to 2
W--4---3---E Car 4 moves from 2 to 3
W---4--3---E Car 4 moves from 3 to 4
W----4-3---E Car 4 moves from 4 to 5
W-----43---E Car 4 moves from 5 to 6
W-----4-3--E Car 3 moves from 7 to 8
W-----4--3-E Car 3 moves from 8 to 9
W-----4---3E Car 3 moves from 9 to 10
W-----4----E Car 3 exits road
W------4---E Car 4 moves from 6 to 7
W-------4--E Car 4 moves from 7 to 8
W--------4-E Car 4 moves from 8 to 9
W---------4E Car 4 moves from 9 to 10
W----------E Car 4 exits road
Road Trace: <<||>>||

System exiting (normal)
[cs120wou@ieng9]:pa3:716$ nano pa3d.c
[cs120wou@ieng9]:pa3:717$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:718$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 8867

9================================
pro1 ready to go'
'curCars:1'
'W1---------E Car 1 enters at 1 at 5 mph
curCars:2'
'curCars:3'
'curCars:4'
'curCars:5'
'curCars:6'
'curCars:7'
'curCars:8'
'curCars:9'
'curCars:10'
'W-1--------E Car 1 moves from 1 to 2
W21--------E Car 2 enters at 1 at 10 mph
CRASH! Cars 3 and 2 collide at 1!
W--1-------E Car 1 moves from 2 to 3
W---1------E Car 1 moves from 3 to 4
W----1-----E Car 1 moves from 4 to 5
W-----1----E Car 1 moves from 5 to 6
W------1---E Car 1 moves from 6 to 7
W-------1--E Car 1 moves from 7 to 8
W--------1-E Car 1 moves from 8 to 9
W---------1E Car 1 moves from 9 to 10
W----------E Car 1 exits road

Kernel Panic! Processes 4, 5, 6, 7, 8, 9 and 10 are deadlocked

System exiting (abnormal)
[cs120wou@ieng9]:pa3:719$ nano pa3d.c
[cs120wou@ieng9]:pa3:720$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:721$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 12025

10================================
pro1 ready to go'
'curCars:1'
'W1---------E Car 1 enters at 1 at 3599 mph
W-1--------E Car 1 moves from 1 to 2
W--1-------E Car 1 moves from 2 to 3
W---1------E Car 1 moves from 3 to 4
W----1-----E Car 1 moves from 4 to 5
W-----1----E Car 1 moves from 5 to 6
W------1---E Car 1 moves from 6 to 7
W-------1--E Car 1 moves from 7 to 8
W--------1-E Car 1 moves from 8 to 9
W---------1E Car 1 moves from 9 to 10
W----------E Car 1 exits road
pro2 ready to go'
'curCars:1'
'W2---------E Car 2 enters at 1 at 3599 mph
W-2--------E Car 2 moves from 1 to 2
W--2-------E Car 2 moves from 2 to 3
W---2------E Car 2 moves from 3 to 4
W----2-----E Car 2 moves from 4 to 5
W-----2----E Car 2 moves from 5 to 6
W------2---E Car 2 moves from 6 to 7
W-------2--E Car 2 moves from 7 to 8
curCars:2'
'W3------2--E Car 3 enters at 1 at 3599 mph
W-3-----2--E Car 3 moves from 1 to 2
W--3----2--E Car 3 moves from 2 to 3
W---3---2--E Car 3 moves from 3 to 4
W----3--2--E curCars:3'
'W4---3--2--E Car 4 enters at 1 at 3599 mph
W-4--3--2--E Car 4 moves from 1 to 2
W--4-3--2--E Car 4 moves from 2 to 3
W---43--2--E Car 4 moves from 3 to 4
1pro6 wait at east
1pro8 wait at east
1pro10 wait at east
Car 3 moves from 4 to 5
2pro5 wait at west
1pro7 wait at east
W---43---2-E Car 2 moves from 8 to 9
W---43----2E Car 2 moves from 9 to 10
W---43-----E Car 2 exits road
1pro9 wait at east
W---4-3----E Car 3 moves from 5 to 6
W---4--3---E Car 3 moves from 6 to 7
W---4---3--E W----4--3--E Car 4 moves from 4 to 5
W-----4-3--E Car 4 moves from 5 to 6
W------43--E Car 4 moves from 6 to 7
Car 3 moves from 7 to 8
W------4-3-E Car 3 moves from 8 to 9
W------4--3E Car 3 moves from 9 to 10
W------4---E Car 3 exits road
W-------4--E Car 4 moves from 7 to 8
W--------4-E Car 4 moves from 8 to 9
W---------4E Car 4 moves from 9 to 10
W----------E Car 4 exits road
1signal east
1pro6 go alive
curCars:1'
'W---------6E Car 6 enters at 10 at 3599 mph
W--------6-E Car 6 moves from 10 to 9
W-------6--E Car 6 moves from 9 to 8
W------6---E Car 6 moves from 8 to 7
W-----6----E Car 6 moves from 7 to 6
W----6-----E Car 6 moves from 6 to 5
W---6------E Car 6 moves from 5 to 4
W--6-------E Car 6 moves from 4 to 3
W-6--------E Car 6 moves from 3 to 2
W6---------E Car 6 moves from 2 to 1
W----------E Car 6 exits road
1signal west
1pro5 go alive
curCars:1'
'W5---------E Car 5 enters at 1 at 3599 mph
W-5--------E Car 5 moves from 1 to 2
W--5-------E Car 5 moves from 2 to 3
W---5------E Car 5 moves from 3 to 4
W----5-----E Car 5 moves from 4 to 5
W-----5----E Car 5 moves from 5 to 6
W------5---E Car 5 moves from 6 to 7
W-------5--E Car 5 moves from 7 to 8
W--------5-E Car 5 moves from 8 to 9
W---------5E Car 5 moves from 9 to 10
W----------E Car 5 exits road
1signal east
1pro8 go alive
curCars:1'
'W---------8E Car 8 enters at 10 at 3599 mph
2signal west
W--------8-E Car 8 moves from 10 to 9
1pro10 go alive
curCars:2'
'W--------810E Car 10 enters at 10 at 3599 mph
W-------8-10E Car 8 moves from 9 to 8
W------8--10E Car 8 moves from 8 to 7
W-----8---10E Car 8 moves from 7 to 6
W----8----10E Car 8 moves from 6 to 5
W---8-----10E Car 8 moves from 5 to 4
W--8------10E Car 8 moves from 4 to 3
W-8-------10E Car 8 moves from 3 to 2
W8--------10E Car 8 moves from 2 to 1
W---------10E Car 8 exits road
2signal west
W--------10-E Car 10 moves from 10 to 9
W-------10--E Car 10 moves from 9 to 8
W------10---E Car 10 moves from 8 to 7
W-----10----E Car 10 moves from 7 to 6
W----10-----E Car 10 moves from 6 to 5
W---10------E Car 10 moves from 5 to 4
W--10-------E Car 10 moves from 4 to 3
W-10--------E Car 10 moves from 3 to 2
W10---------E Car 10 moves from 2 to 1
W----------E Car 10 exits road
1pro7 go alive
curCars:1'
'W---------7E Car 7 enters at 10 at 3599 mph
2signal west
W--------7-E Car 7 moves from 10 to 9
W-------7--E Car 7 moves from 9 to 8
W------7---E Car 7 moves from 8 to 7
W-----7----E Car 7 moves from 7 to 6
W----7-----E Car 7 moves from 6 to 5
W---7------E Car 7 moves from 5 to 4
1pro9 go alive
curCars:2'
'W---7-----9E Car 9 enters at 10 at 3599 mph
2signal west
W---7----9-E Car 9 moves from 10 to 9
W---7---9--E Car 9 moves from 9 to 8
W---7--9---E Car 9 moves from 8 to 7
W---7-9----E Car 9 moves from 7 to 6
W---79-----E Car 9 moves from 6 to 5
W--7-9-----E Car 7 moves from 4 to 3
W-7--9-----E Car 7 moves from 3 to 2
W7---9-----E Car 7 moves from 2 to 1
W----9-----E Car 7 exits road
W---9------E Car 9 moves from 5 to 4
W--9-------E Car 9 moves from 4 to 3
W-9--------E Car 9 moves from 3 to 2
W9---------E Car 9 moves from 2 to 1
W----------E Car 9 exits road
Road Trace: >|>>>|||<|>|<<||<<||

System exiting (normal)
[cs120wou@ieng9]:pa3:722$ nano pa3d.c
[cs120wou@ieng9]:pa3:723$ make
cc -g -L/home/solaris/ieng9/cs120w/public/umix/lib -lumix3 -o pa3d pa3d.c mycode3.o
[cs120wou@ieng9]:pa3:724$ pa3d
Umix (User-Mode Unix) CSE120 Instructional OS v. 4.009 12/03/18-00:33 13649

11================================


W---------1E Car 1 enters at 10 at 5 mph
W--------1-E Car 1 moves from 10 to 9
W--------12E Car 2 enters at 10 at 10 mph
W-------1-2E Car 1 moves from 9 to 8
W-------12-E Car 2 moves from 10 to 9
W-------123E Car 3 enters at 10 at 20 mph
W------1-23E Car 1 moves from 8 to 7
W------12-3E Car 2 moves from 9 to 8
W------123-E Car 3 moves from 10 to 9
W------1234E Car 4 enters at 10 at 30 mph
W-----1-234E Car 1 moves from 7 to 6
W-----12-34E Car 2 moves from 8 to 7
W-----123-4E Car 3 moves from 9 to 8
W-----1234-E Car 4 moves from 10 to 9
W-----12345E Car 5 enters at 10 at 40 mph
W----1-2345E Car 1 moves from 6 to 5
W----12-345E Car 2 moves from 7 to 6
W----123-45E Car 3 moves from 8 to 7
W----1234-5E Car 4 moves from 9 to 8
W----12345-E Car 5 moves from 10 to 9
W----123456E Car 6 enters at 10 at 50 mph
W---1-23456E Car 1 moves from 5 to 4
W---12-3456E Car 2 moves from 6 to 5
W---123-456E Car 3 moves from 7 to 6
W---1234-56E Car 4 moves from 8 to 7
W---12345-6E Car 5 moves from 9 to 8
W---123456-E Car 6 moves from 10 to 9
W---1234567E Car 7 enters at 10 at 60 mph
W--1-234567E Car 1 moves from 4 to 3
W--12-34567E Car 2 moves from 5 to 4
W--123-4567E Car 3 moves from 6 to 5
W--1234-567E Car 4 moves from 7 to 6
W--12345-67E Car 5 moves from 8 to 7
W--123456-7E Car 6 moves from 9 to 8
W--1234567-E Car 7 moves from 10 to 9
W--12345678E Car 8 enters at 10 at 70 mph
W-1-2345678E Car 1 moves from 3 to 2
W-12-345678E Car 2 moves from 4 to 3
W-123-45678E Car 3 moves from 5 to 4
W-1234-5678E Car 4 moves from 6 to 5
W-12345-678E Car 5 moves from 7 to 6
W-123456-78E Car 6 moves from 8 to 7
W-1234567-8E Car 7 moves from 9 to 8
W-12345678-E Car 8 moves from 10 to 9
W-123456789E Car 9 enters at 10 at 80 mph
W1-23456789E Car 1 moves from 2 to 1
W12-3456789E Car 2 moves from 3 to 2
W123-456789E Car 3 moves from 4 to 3
W1234-56789E Car 4 moves from 5 to 4
W12345-6789E Car 5 moves from 6 to 5
W123456-789E Car 6 moves from 7 to 6
W1234567-89E Car 7 moves from 8 to 7
W12345678-9E Car 8 moves from 9 to 8
W123456789-E Car 9 moves from 10 to 9
W12345678910E Car 10 enters at 10 at 90 mph
W-2345678910E Car 1 exits road
W2-345678910E Car 2 moves from 2 to 1
W23-45678910E Car 3 moves from 3 to 2
W234-5678910E Car 4 moves from 4 to 3
W2345-678910E Car 5 moves from 5 to 4
W23456-78910E Car 6 moves from 6 to 5
W234567-8910E Car 7 moves from 7 to 6
W2345678-910E Car 8 moves from 8 to 7
W23456789-10E Car 9 moves from 9 to 8
W2345678910-E Car 10 moves from 10 to 9
W-345678910-E Car 2 exits road
W3-45678910-E Car 3 moves from 2 to 1
W34-5678910-E Car 4 moves from 3 to 2
W345-678910-E Car 5 moves from 4 to 3
W3456-78910-E Car 6 moves from 5 to 4
W34567-8910-E Car 7 moves from 6 to 5
W345678-910-E Car 8 moves from 7 to 6
W3456789-10-E Car 9 moves from 8 to 7
W345678910--E Car 10 moves from 9 to 8
W-45678910--E Car 3 exits road
W4-5678910--E Car 4 moves from 2 to 1
W45-678910--E Car 5 moves from 3 to 2
W456-78910--E Car 6 moves from 4 to 3
W4567-8910--E Car 7 moves from 5 to 4
W45678-910--E Car 8 moves from 6 to 5
W456789-10--E Car 9 moves from 7 to 6
W45678910---E Car 10 moves from 8 to 7
W-5678910---E Car 4 exits road
W5-678910---E Car 5 moves from 2 to 1
W56-78910---E Car 6 moves from 3 to 2
W567-8910---E Car 7 moves from 4 to 3
W5678-910---E Car 8 moves from 5 to 4
W56789-10---E Car 9 moves from 6 to 5
W5678910----E Car 10 moves from 7 to 6
W-678910----E Car 5 exits road
W6-78910----E Car 6 moves from 2 to 1
W67-8910----E Car 7 moves from 3 to 2
W678-910----E Car 8 moves from 4 to 3
W6789-10----E Car 9 moves from 5 to 4
W678910-----E Car 10 moves from 6 to 5
W-78910-----E Car 6 exits road
W7-8910-----E Car 7 moves from 2 to 1
W78-910-----E Car 8 moves from 3 to 2
W789-10-----E Car 9 moves from 4 to 3
W78910------E Car 10 moves from 5 to 4
W-8910------E Car 7 exits road
W8-910------E Car 8 moves from 2 to 1
W89-10------E Car 9 moves from 3 to 2
W8910-------E Car 10 moves from 4 to 3
W-910-------E Car 8 exits road
W9-10-------E Car 9 moves from 2 to 1
W910--------E Car 10 moves from 3 to 2
W-10--------E Car 9 exits road
W10---------E Car 10 moves from 2 to 1
W----------E Car 10 exits road
Road Trace: <<<<<<<<<<||||||||||

System exiting (normal)
[cs120wou@ieng9]:pa3:832$ 
