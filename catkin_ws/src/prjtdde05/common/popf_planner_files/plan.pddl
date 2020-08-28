Number of literals: 13
Constructing lookup tables: [10%] [20%] [30%] [40%] [50%] [60%] [70%] [80%] [90%] [100%]
Post filtering unreachable actions:  [10%] [20%] [30%] [40%] [50%] [60%] [70%] [80%] [90%] [100%]
[01;34mNo analytic limits found, not considering limit effects of goal-only operators[00m
51% of the ground temporal actions in this problem are compression-safe
Initial heuristic = 5.000
b (4.000 | 1.000)b (2.000 | 2.001)
Resorting to best-first search
b (4.000 | 1.000)b (2.000 | 2.001)b (1.000 | 24.004);;;; Solution Found
; States evaluated: 849
; Cost: 44.005
; Time 1.22
0.000: (pick helicopter1 crate1 depot1)  [1.000]
1.001: (load_crate capacity capacity helicopter1 crate1 carrier1 depot1)  [1.000]
2.002: (flywithcarrier helicopter1 carrier1 depot1 location1)  [20.000]
22.003: (unload_crate capacity capacity helicopter1 carrier1 crate1 location1)  [1.000]
23.004: (drop helicopter1 carrier1 crate1 location1)  [1.000]
24.005: (flywithcarrier helicopter1 carrier1 location1 depot1)  [20.000]
