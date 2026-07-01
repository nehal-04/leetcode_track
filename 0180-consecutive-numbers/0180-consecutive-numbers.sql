Select distinct L1.num as ConsecutiveNums
from Logs L1 inner join Logs L2 inner join Logs L3
on L2.id=L1.id+1 and L2.num = L1.num and L3.id = L2.id +1 and L3.num=L2.num 
