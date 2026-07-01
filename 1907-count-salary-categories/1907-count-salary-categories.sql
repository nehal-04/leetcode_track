# Write your MySQL query statement below
select 'Low Salary' as category , count(case when income < 20000 then 1 end) as accounts_count
from Accounts

UNION ALL

select 'Average Salary' as category , count(case when income >=20000 and income <=50000 then 1 end) as accounts_count
from Accounts

union all

select 'High Salary' as category , count(case when income >50000 then 1 end ) as accounts_count
from Accounts