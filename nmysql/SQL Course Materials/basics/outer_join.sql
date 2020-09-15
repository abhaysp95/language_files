-- sql supports two types of join,
-- join(or inner join)
-- outer join

use sql_store;

select
	c.customer_id,
	c.first_name,
	c.last_name,
	o.order_id
from customers c
left join orders o
	on c.customer_id = o.customer_id
order by  customer_id;

-- sql have two types of outer join
-- left outer join
-- right outer join

-- when used left, sql will return all the record from the left table are returned whether condition is satisfied or not


select
	c.customer_id,
	c.first_name,
	c.last_name,
	o.order_id
from customers c
right join orders o
	on c.customer_id = o.customer_id
order by  customer_id;
-- we are not seeing all the customers but all the orders

-- or, to check right join more thoroughly you can do something like this
select
	c.customer_id,
	c.first_name,
	c.last_name,
	o.order_id
from orders o
right join customers c
	on c.customer_id = o.customer_id
order by  customer_id;

-- some people prefer to use 'left outer join' or 'right outer join' but 'outer' is optional here
