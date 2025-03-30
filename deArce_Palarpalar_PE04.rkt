;Richelle de Arce && Cherlie Palarpalar
; Tasks
; A,

#lang racket

; Helper function to recursively sum numbers in a list
(define (sum-helper lis)
  (cond
    [(null? lis) 0]  ; Base case: empty list, return 0
    [(number? (car lis)) (+ (car lis) (sum-helper (cdr lis)))]  ; Add numbers
    [(list? (car lis)) (+ (sum-helper (car lis)) (sum-helper (cdr lis)))]  ; Recurse into sublists
    [else (sum-helper (cdr lis))]))  ; Ignore non-number elements

; Interface function
(define (my-sums lis)
  (sum-helper lis))

;Reverse List function
;Put the reverse list into a new list
(define (my-reverse1 lis)
  (define (reverse-helper lst acc)
    (if (null? lst)
        acc
        (reverse-helper (cdr lst) (cons (car lst) acc))))
  (reverse-helper lis '()))

;Reverse List function
;No helper which creates new list every recursion
(define (my-reverse2 lis)
  (if (null? lis)
      '()
      (append (my-reverse2 (cdr lis)) (list (car lis)))))

; Example test cases
(display "I. SUM OF THE LIST ")
(newline)
(display "List: (1 2 (3 4) (5 (6 7)) 8)")
(newline)
(display "Sum: ")
(display (my-sums '(1 2 (3 4) (5 (6 7)) 8)))  ; Output: 36
(newline)

(display "List: ((1 2) (3 (4 (5 6))) 7)")
(newline)
(display "Sum: ")
(display (my-sums '((1 2) (3 (4 (5 6))) 7)))  ; Output: 28
(newline)

(display "List: (10 (20 30) (40 (50 (60))))")
(newline)
(display "Sum: ")
(display (my-sums '(10 (20 30) (40 (50 (60))))))  ; Output: 210
(newline)(newline)

(display "II. REVERSE LIST ")
(display "Original: 1 2 3 4 5")
(newline)
(display "Reverse: ")
(display (my-reverse1 '(1 2 3 4 5)))
(newline)

(display "III. REVERSE LIST TWO ")
(display "Original: 1 2 3 4 5")
(newline)
(display "Reverse: ")
(display (my-reverse2 '(1 2 3 4 5)))