Select E2.name
from Employee E1 inner join Employee E2
on E1.managerId = E2.id
group by E2.id
having count(*)>=5