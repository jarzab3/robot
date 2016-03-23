#lang racket
(require "AsipMain.rkt")

(define count 0)
(define turn 0) ;0 is 0, 1 is on the right f the line 2 is on the left

(define start (λ ()
                (open-asip)
                (enableIR 100)
           ;     (enableBumpers 100)
                (linestart)
                )
  )

(define linestart (λ ()
                    (setMotors 200 -180)
                    (cond
                      ((> (getIR 0) 400)(rightturn))
                      (#t (linestart))
                      )
                    )
  )
                                                                     



(define rightturn (λ ()
                    (stopMotors)
                    (setMotor 0 200)
                    (cond
                      ((> (getIR 0) 200)(leftturn))
                      (#t (rightturn))
                      )
                    )
  )

(define leftturn (λ ()
                   (stopMotors)
                    (setMotor 1 -200)
                    (cond
                      ((> (getIR 0) 200)(rightturn))
                      (#t (leftturn))
                      )
                    )
  )
                     


(start)