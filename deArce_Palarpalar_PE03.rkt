#lang racket

;; This is a program that contains procedures in Racket language.
;; Programmer: Richelle S. de Arce & Cherlie Joy Palarpalar
;; Date: Feb 27, 2025 - Mar 1, 2025

;; A. Factorial Function
(define (factorial n)
  (if (and (integer? n) (>= n 0))
      (if (= n 0)  ;; Base case: factorial of 0 is 1
          1
          (* n (factorial (- n 1))))  ;; Recursive case: n * factorial of (n-1)
      (begin
        (display "Error: Input must be a non-negative integer.")
        #f)))  ;; Return #f to indicate an error

;; B. T-Ice Function
(define (t-ice-helper n current)
  (if (> current n)  ;; Base case: stop recursion when current exceeds n
      (void)  ;; Do nothing and return void
      (begin
        (cond
          ((and (= (modulo current 2) 0) (= (modulo current 3) 0)) (display "T-ICE "))  ;; Divisible by both 2 and 3
          ((= (modulo current 2) 0) (display "T "))  ;; Divisible by 2
          ((= (modulo current 3) 0) (display "ICE "))  ;; Divisible by 3
          (else (display current) (display " ")))  ;; Not divisible by 2 or 3
        (t-ice-helper n (+ current 1)))))  ;; Recursive call with incremented current

(define (t-ice n)
  (if (and (integer? n) (> n 0))
      (t-ice-helper n 1)  ;; Start helper function with current = 1
      (begin
        (display "Error: Input must be a positive integer.")
        #f)))  ;; Return #f to indicate an error

;; C. Sum of Primes Function
(define (is-prime? num divisor)
  (cond
    ((< num 2) #f)  ;; Numbers less than 2 are not prime
    ((> divisor (sqrt num)) #t)  ;; No divisors found up to sqrt(num), so num is prime
    ((= (modulo num divisor) 0) #f)  ;; num is divisible by divisor, so not prime
    (else (is-prime? num (+ divisor 1)))))  ;; Recursive call with incremented divisor

(define (sumprimes-helper n current sum)
  (if (> current n)  ;; Base case: stop recursion when current exceeds n
      sum
      (sumprimes-helper n (+ current 1)
                        (if (is-prime? current 2) (+ sum current) sum))))  ;; Add current to sum if prime

(define (sumprimes n)
  (if (and (integer? n) (> n 0))
      (sumprimes-helper n 1 0)  ;; Start helper function with current = 1 and sum = 0
      (begin
        (display "Error: Input must be a positive integer.")
        #f)))  ;; Return #f to indicate an error

;; D. Perform-op Function
(define (perform-op m n opt)
  (if (and (number? m) (number? n) (member opt '(+ - * / mod)))
      (cond
        ((eq? opt '+) (+ m n))  ;; Addition
        ((eq? opt '-) (- m n))  ;; Subtraction
        ((eq? opt '*) (* m n))  ;; Multiplication
        ((eq? opt '/) (if (zero? n) (begin (display "Error: Division by zero.") #f) (/ m n)))  ;; Division
        ((eq? opt 'mod) (if (zero? n) (begin (display "Error: Division by zero.") #f) (modulo m n)))  ;; Modulo
        (else "Invalid operator"))  ;; Invalid operator case
      (begin
        (display "Error: Invalid input.")
        (newline)
        #f)))  ;; Return #f to indicate an error

;; E. Calculate Distance Function
(define (calc-distance x1 y1 x2 y2)
  (if (and (number? x1) (number? y1) (number? x2) (number? y2))
      (sqrt (+ (expt (- x2 x1) 2) (expt (- y2 y1) 2)))  ;; Calculate Euclidean distance
      (begin
        (display "Error: All inputs must be numbers.")
        #f)))  ;; Return #f to indicate an error

;; F. Count Factors Function
(define (count-factors m n)
  (if (and (integer? m) (integer? n) (> m 0) (> n 0))
      (let loop ((n n) (count 0))
        (if (= (modulo n m) 0)
            (if (= n 1)
                count  ;; Base case: Stop recursion when n reaches 1
                (loop (/ n m) (+ count 1)))  ;; Count factor
            (if (= count 0)
                (begin
                  (display "None")
                  (newline)
                  0)
                count)))  ;; Return count if m is not a factor of n
      (begin
        (display "Error: Inputs must be positive integers.")
        #f)))  ;; Return #f to indicate an error

;; Main function to run all tests
(define (main)
  (display "Factorial of n: ")
  (display (factorial 0))  ;; Expected output: 120
  (newline)
  
  (display "T-Ice for n: ")
  (t-ice 0)  ;; Expected output: 1 T ICE T 5 T-ICE 7 T
  (newline)
  
  (display "Sum of primes up to n: ")
  (display (sumprimes 0))  ;; Expected output: 17 (2+3+5+7)
  (newline)
  
  (display "Perform operation: ")
  (display (perform-op 10 0 '/))  ;; Expected output: 20
  (newline)
  
  (display "Calculate distance between points (x1, y1) and (x2, y2): ")
  (display (calc-distance 1 2 4 6))  ;; Expected output: ~5
  (newline)
  
  (display "Count factors of m in n: ")
  (display (count-factors 4 48))  ;; Expected output: 2
  (newline))

;; Run the main function
(main)