(define (domain emergency-logistics)

  (:requirements :typing :fluents :disjunctive-preconditions :durative-actions)
  (:types helicopter carriers crate locations victim num - object)

  (:predicates

   (at ?x - object ?somewhere - locations)          
   (in ?this - object ?that - object)            
   (loc ?to ?to2 - locations)              
   (harness_is_free ?h - helicopter)
   (seq ?s1 - num ?s2 - num)
   (visited ?to - locations)

  )

  (:durative-action pick

    :parameters (?h - helicopter ?c - crate ?here - locations)
    :duration ( = ?duration 1)
    :condition (and
               (at start (harness_is_free ?h))
               (at start (at ?h ?here))
               (at start (at ?c ?here)))
    :effect (and
            (at end (in ?c ?h))
            (at start (not (harness_is_free ?h)))
            ))

  (:durative-action load_crate

    :parameters (?m - num ?n - num ?h - helicopter ?c - crate ?cr - carriers ?d - locations)
    :duration ( = ?duration 1)
    :condition (and
               (at start (at ?h ?d))
               (at start (in ?c ?h)))
    :effect (and
            (at end (in ?c ?cr))
            (at end (not (in ?c ?h)))
            (at end (in ?cr ?h))
            (at end (not (at ?c ?d)))
            (at end (harness_is_free ?h))
            ))

  (:durative-action flywithcarrier

    :parameters (?h - helicopter ?cr - carriers ?from - locations ?to - locations)
    :duration ( = ?duration 20 )
    :condition (and
               (at start (harness_is_free ?h))
               (at start (at ?cr ?from))
               (at start (at ?h ?from)))
    :effect (and
            (at start (not (at ?h ?from)))
            (at start (not (at ?cr ?from)))
            (at start (not (harness_is_free ?h)))
            (at end (at ?h ?to))
            (at end (at ?cr ?to))
            (at end (not (harness_is_free ?h)))
            (at end (visited ?to))
            ))

  (:durative-action unload_crate

    :parameters (?m - num ?n - num ?h - helicopter ?cr - carriers ?c - crate ?to - locations)
    :duration ( = ?duration 1)
    :condition (and
               (at start (at ?h ?to))
               (at start (in ?c ?cr)))
    :effect (and
            (at start (not (harness_is_free ?h)))
            (at start (not (in ?c ?cr)))
            (at end (in ?c ?h))
            (at end (at ?c ?to))
            ))

  (:durative-action drop

    :parameters (?h - helicopter ?cr - carriers ?c - crate ?here - locations)
    :duration ( = ?duration 1)
    :condition (and
               (at start (at ?h ?here))
               (at start (in ?c ?h)))
    :effect (and
            (at start (at ?h ?here))
            (at start (at ?cr ?here))
            (at start (not (in ?c ?cr)))
            (at end (harness_is_free ?h))
            (at end (not (in ?c ?h)))
            (at end (at ?c ?here))
            ))

  )
