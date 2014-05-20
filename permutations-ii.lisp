(defun walk (nums)
  (if (= (length nums) 1)
      (list nums)
      (let (result (prev (1+ (car nums))))
        (loop for num in nums
           when (/= num prev)
           do (progn
                (setf prev num)
                (setf result
                      (append (cons-ret num (walk (remove num nums :count 1))) result))))
        result)))

(defun cons-ret (num result)
  (mapcar #'(lambda (nums)
              (push num nums))
          result))
