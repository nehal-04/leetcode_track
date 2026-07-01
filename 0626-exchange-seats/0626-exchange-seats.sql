# Write your MySQL query statement below
Select S1.id , (case 
        when S1.id % 2 !=0 and S1.next_student is null then S1.student
        when S1.id % 2 !=0 then S1.next_student
        else S1.prev_student 
        end  
) as student 
from
(Select 
s.* , lag(student) over(order by id) as prev_student ,lead(student) over(order by id) as next_student
from Seat S) 
S1
