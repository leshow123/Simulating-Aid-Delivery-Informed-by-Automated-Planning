(define (problem task)
(:domain emergency-logistics)
(:objects
    helicopter1 - helicopter
    carrier1 - carriers
    crate1 crate2 - crate
    depot1 location1 location2 - locations
    victim1 victim2 - victim
    filled n1 n2 n3 capacity - num
)
(:init
    (at crate1 depot1)
    (at crate2 depot1)
    (at helicopter1 depot1)
    (at victim1 location1)
    (at victim2 location2)
    (at carrier1 depot1)


    (loc depot1 depot1)
    (loc location1 location1)
    (loc location2 location2)

    (harness_is_free helicopter1)

    (seq filled n1)
    (seq n1 n2)
    (seq n2 n3)
    (seq n3 capacity)


)
(:goal (and
    (at helicopter1 depot1)
    (at crate1 location1)
    (at crate2 location2)
))
)
