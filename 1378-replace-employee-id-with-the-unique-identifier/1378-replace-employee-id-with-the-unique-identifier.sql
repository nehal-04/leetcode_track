# Write your MySQL query statement below
Select E2.unique_id , E1.name
from Employees as E1 Left Join EmployeeUNI as E2
on E1.id = E2.id;

