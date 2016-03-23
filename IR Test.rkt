#lang racket/base

(require "AsipMain.rkt")

(define led1 11)
(define led2 12)
(define led3 13)

(define setup 
  (lambda ()
    (open-asip)
    (enableBumpers 10)
    (enableIR 10)
  )
  )

(define loop 
   
(lambda ()

     (displayln (getIR 1))
      (sleep 1)
    
    (loop)
    )
  )

(setup)
( loop)