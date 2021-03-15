use sql_store;

-- explicit join syntax
select *
from customers c
join orders o
	on c.customer_id = o.customer_id;

-- implict join syntax
select *
from customers c, orders o
where c.customer_id = o.customer_id;
-- not recommended
-- if you accidentaly forgot to type out where clause, you'll get cross joint
-- so, every record in the order table is now joint to the every record in the customers table
