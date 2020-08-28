
ff: parsing domain file
domain 'EMERGENCY-LOGISTICS' defined
 ... done.
ff: parsing problem file
problem 'TASK' defined
 ... done.



Cueing down from goal distance:    3 into depth [1][2]
                                   2            [1][2]
                                                H search space got empty !
                                                switching to complete search space now.
                                                [1][2][3][4][5]

Enforced Hill-climbing failed !
switching to Best-first Search now.

advancing to distance :    3
                           2
                           1
                           0

ff: found legal plan as follows

step    0: PICK HELICOPTER1 CRATE1 DEPOT1
        1: LOAD_CRATE CAPACITY CAPACITY HELICOPTER1 CRATE1 CARRIER1 DEPOT1
        2: FLYWITHCARRIER HELICOPTER1 CARRIER1 DEPOT1 LOCATION1
        3: UNLOAD_CRATE CAPACITY CAPACITY HELICOPTER1 CARRIER1 CRATE1 LOCATION1
        4: DROP HELICOPTER1 CARRIER1 CRATE1 LOCATION1
        5: FLYWITHCARRIER HELICOPTER1 CARRIER1 LOCATION1 DEPOT1
     

time spent:    0.00 seconds instantiating 12 easy, 0 hard action templates
               0.00 seconds reachability analysis, yielding 13 facts and 12 actions
               0.00 seconds creating final representation with 12 relevant facts
               0.00 seconds building connectivity graph
               0.00 seconds searching, evaluating 33 states, to a max depth of 5
               0.00 seconds total time



Can't open output file!



