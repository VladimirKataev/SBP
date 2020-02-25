; "Ansi common lisp, by Paul Graham"

;Ch1

;(print (+ (- 5 1) (+ 3 7))) ; returns 4 + 10, or 14

;(print (list 1 (+ 2 3))) ; returns (1 5)

;(print (if (listp 1)  (+ 1 2) (+ 3 4)))
				; if '1' is a list, it returns 3. if not, 7
				; PS, it's not, so 7

;(print (list (and (listp 3) t ) (+ 1 2))) ;creates (nil 3)


; 3 cons expressions to return (a b c)
;(print (cons 1 (list 2 3)))
; errrr, wat?



; funtion to car and cdr to return list[3]
(defun myFourth (list) 
	(
		car (
			cdr (
				cdr (
					cdr list
				)
			)
		)
	)
)

;(print (myFourth (list 1 2 3 4 5)))



; function that returns the greater of the two args
(defun greater (a b)
	(if (> a b) 
		a 
		b
	)
)
;(print (greater 69 420))



(defun enigma (x)
	(and	(not (null x))		; returns if list isnt empty and
		(or	(null (car x))	; either first element !nil
			(enigma (cdr x)); or same is true for later
		)
	)
)
; so it checks if there's a nil in the list or not

;(print (enigma (list 1 'a' nil 1.3)))
;(print (enigma (list 1 'a' 1.3)))



(defun mystery (x y)
	(if (null y)					;if y is nil, return nil
		nil
		(if (eql (car y) x)			;else, if first of y is x
			0				; return 0
			(let ((z (mystery x (cdr y))))  ;else z is 
				(and z (+ z 1)))
		)
	)
)
; checks for x in y, gives index from 0

;(print (mystery 3 (list 1 2 3 4)))
;(print (mystery 3 (list 1 2 4)))




;(print
;	(car (car (cdr '(a (b c) d))))
;)
;>B
;x was 'car'



;(print
;	(or 13 (/ 1 0))
;)
;>13
;x was 'or'



;(print
;	(apply #'list 1 nil)
;)
;>(1)
;x was 'apply'



;function that returns true if an item within list is a list
(defun hasNestedList (listIn) ;note, end of list is tested as itself
	(and
		listIn
		(or 
			(listp (car listIn))
			(hasNestedList (cdr listIn))
		)
	)
)

;(print (hasNestedList (list 1 2 3 4)))
;(print (hasNestedList (list 1 (list 2 3) 4)))


(defun nDotsIter (n) 
	(do	(
		(i n (- i 1))
		)
		
		((< i 0))
		(print ".")
	)
)


(defun nDotsRecurs (n)
	(print ".")
	(if (> n 0)
		(nDotsRecurs (- n 1))
	)
)

;(nDotsIter 5)
;(nDotsRecurs 5)


(defun elemCountIter (elem inList)
	(do	(
			(srch inList (cdr srch))
			(n 0 (if (= (car srch) elem) (+ n 1) n))
		)
		((not srch) n)
		
	)

)

(print (elemCountIter 69 (list 69 2 4 69)))


(defun elemCounterRecurs (elem inList)
	(if	inList
		(if (= elem (car inList))
			(+ 1 (elemCounterRecurs elem (cdr inList) ))
			(elemCounterRecurs elem (cdr inList))
		)
		0
	)
)

(print 
	(elemCounterRecurs 69 (list 69 2 4 69))
)



