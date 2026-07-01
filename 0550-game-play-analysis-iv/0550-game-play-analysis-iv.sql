# Write your MySQL query statement below

Select round(count(distinct A1.player_id) / (select count(distinct player_id) from Activity) ,2) as fraction
from Activity A1 inner join (Select player_id , min(event_date) as event_date from Activity group by player_id) A2 on A1.player_id = A2.player_id and A1.event_date=DATE_ADD(A2.event_date, Interval 1 day)
