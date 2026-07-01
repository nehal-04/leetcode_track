Select round(sum(order_date = customer_pref_delivery_date) *100 / count(*) , 2) as immediate_percentage
from Delivery D1 
inner join 
(Select customer_id , min(order_date) as first_order_date
from Delivery
group by customer_id
) D2 
on D1.customer_id = D2.customer_id and D1.order_date = D2.first_order_date
