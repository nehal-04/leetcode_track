Select S1.user_id , round(ifnull(sum(C1.action = 'confirmed'),0)/count(*),2) as confirmation_rate
from Signups S1 left join Confirmations C1
on S1.user_id = C1.user_id
group by S1.user_id
