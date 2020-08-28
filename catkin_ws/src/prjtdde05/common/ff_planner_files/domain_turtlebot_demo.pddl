
(define (domain emergency-logistics)

  (:requirements :typing :disjunctive-preconditions)
  (:types

    helicopter carriers crate locations victim num - object

  )

  (:predicates

   (at ?x - object ?somewhere - locations)          ;; ?x (helicopter, crate, or victim) is at location ?ls
   (in ?this - object ?that - object)            ;; crate on chopper ; content in crate
   (loc ?to ?to2 - locations)              ;; true iff ls == ls2
   (harness_is_free ?h - helicopter)       ;; unary predicate true iff UAV is not laden
   (seq ?number1 - num ?number2 - num)

   (visited ?to - locations)

  )


  (:action pick

    :parameters (?h - helicopter ?c - crate ?here - locations)
    :precondition (and
               (harness_is_free ?h)
               (at ?h ?here)
               (at ?c ?here)
               
               )
    :effect (and
            (in ?c ?h)
            (not (harness_is_free ?h))
            )
  )


  (:action load_crate

    :parameters (?m - num ?n - num ?h - helicopter ?c - crate ?cr - carriers ?here - locations)
    :precondition (and
                  (at ?h ?here)
                  (in ?c ?h)
                 ;; (seq ?m ?n)

                  )
    :effect (and
            (in ?c ?cr)
            (not (in ?c ?h))
            (in ?cr ?h)
            (not (at ?c ?here))
            (harness_is_free ?h)
            ;;(not (seq ?m ?n))

            )
     )


  (:action flywithcarrier

    :parameters (?h - helicopter ?cr - carriers ?from - locations ?to - locations)
    :precondition (and
               (harness_is_free ?h)
               (at ?cr ?from)
               (at ?h ?from)
               
               )
    :effect (and
            (not (at ?h ?from))
            (not (at ?cr ?from))
            (not (harness_is_free ?h))
            (at ?h ?to)
            (at ?cr ?to)
            (not (harness_is_free ?h))
            (visited ?to)
            )
  )


  (:action unload_crate

    :parameters (?m - num ?n - num ?h - helicopter ?cr - carriers ?c - crate ?to - locations)  
    :precondition (and
               (at ?h ?to)
               (in ?c ?cr)
               
               )
    :effect (and
            (not (harness_is_free ?h))   ;; now prior concern: CAUTION 1b : complementing annotation to CAUTION 1a
            (not (in ?c ?cr))
            (in ?c ?h)
            (at ?c ?to)
	    ;;(seq ?m ?n)

            )
  )


  (:action drop

    :parameters (?h - helicopter ?cr - carriers ?c - crate ?here - locations)   ;;?victim_loc - locations
    :precondition (and
               (at ?h ?here)
               (in ?c ?h)
               
               )
    :effect (and
            (at ?h ?here)
            (at ?cr ?here)
            (not (in ?c ?cr))
            (harness_is_free ?h)
            (not (in ?c ?h))
            (at ?c ?here)        ;; for some reason, affirming location of c matters to the solver a lot; had been stated in unload_crate's effect 
            )
  )

)
