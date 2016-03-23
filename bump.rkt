#lang racket

(require "AsipMain.rkt")

(define setup (λ ()
                (open-asip )
                (enableBumpers 100)
                (enableIR 10)
                ;  (bumpe)
                ;   (close-asip)
                )
  )
(define bumpe (λ ()
                      
                      (cond ((leftBump?) (printf " Left bump pressed \n"))
                            ((rightBump?) (printf " Right bump pressed \n"))
                            )
                      
                      (sleep 0.05)
                      (bumpe)
                      )
  )

(define ir (λ ()

     (displayln (getIR 1))
      (sleep 1)
    
    (ir)
    )
  )

(setup)
;(bumpe)
(ir)
