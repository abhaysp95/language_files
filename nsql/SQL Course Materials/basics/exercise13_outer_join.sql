use sql_store;

select
	p.product_id,
	p.name,
	o.quantity
from order_items o
right join products p
	on p.product_id = o.product_id;
