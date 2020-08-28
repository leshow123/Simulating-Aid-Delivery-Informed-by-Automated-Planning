(define (problem task)
(:domain emergency-logistics)
(:objects
    helicopter1 - helicopter
    carrier1 - carriers
    crate1 - crate
    depot1 location1 - locations
    victim1 - victim
    filled n1 n2 n3 capacity - num
)
(:init
    (at crate1 depot1)
    (at helicopter1 depot1)
    (at victim1 location1)
    (at carrier1 depot1)


    (loc depot1 depot1)
    (loc location1 location1)

    (harness_is_free helicopter1)

    (seq filled n1)
    (seq n1 n2)
    (seq n2 n3)
    (seq n3 capacity)


)
(:goal (and
    (at helicopter1 depot1)
    (at crate1 location1)
))
)
