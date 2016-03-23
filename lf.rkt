#lang racket

(require "AsipMain.rkt")

(define setup 
  (lambda ()
    (open-asip)
    (enableBumpers 100)
    (enableIR 10)
    (stopMotors)
  )
  )

(define test (lambda ()
		(clearLCD)
		(setLCDMessage "haha I'm driving" 2)
		(sleep 10)
		(setMotors -200 200)
		(sleep 7)
		(setMotors 200 200)
		(sleep 4)
		(setMotors -200 200)
		(sleep 8)
		(stopMotors)
)
)

(define loop 
   
(lambda ()

     (displayln (getIR 1))
      (sleep 1)
    
    (loop)
    )
  )

(define ls (λ ()
                   (cond
                     ((> (getIR 1) 200 ) (setMotors 150 150))
                     ((> (getIR 2) 100 ) (setMotors 0 150))
                     ((> (getIR 0) 100 ) (setMotors 150 0)))
                    (cond ((leftBump?) (printf " Left bump pressed \n"))
                            ((rightBump?) (printf " Right bump pressed \n"))
                            )
                    )
               )



(setup)
(ls)


                     
  
  