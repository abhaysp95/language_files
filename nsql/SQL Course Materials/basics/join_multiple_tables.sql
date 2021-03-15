-- join more than two tables

use sql_store;

select
	o.order_id,
	o.order_date,
	c.first_name,
	c.last_name,
	os.name as status
from customers c
join orders o
	on o.customer_id = c.customer_id
join order_statuses os
	on os.order_status_id = o.status
order by order_id;
