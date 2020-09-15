-- sql has two types of join

use sql_store;

select *
from orders
inner join customers
	on orders.customer_id = customers.customer_id;
-- inner is optional in inner join

-- we can select any columns from joint tables
select order_id, customers.customer_id, first_name, last_name
from orders
join customers
	on orders.customer_id = customers.customer_id;
-- for column like customer_id which is ambiguous, you can't just select it with name, you have to prefix it with the table name to qualify them
-- here it doesn't matter if you select customers.customer_id or orders.customer_id

-- we can just as welll as give alias to the table names
select order_id, o.customer_id, first_name, last_name
from orders o
join customers c
	on o.customer_id = c.customer_id;
-- to give alias just write the alias name after the table name
-- o -> orders
-- c -> customers
