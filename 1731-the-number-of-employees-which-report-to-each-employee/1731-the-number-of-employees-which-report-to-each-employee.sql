select E1.employee_id ,E1.name, count(*) as reports_count , round(avg(E2.age) , 0) as average_age
from Employees E1 inner join Employees E2
on E1.employee_id = E2.reports_to
#E1 side is all managers and E2 is mapping to all wmployees under
group by E1.employee_id , E1.name
order by E1.employee_id