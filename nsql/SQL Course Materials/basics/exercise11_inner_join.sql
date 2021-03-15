use sql_store;

select order_id, p.product_id, name, quantity, o.unit_price
from order_items o
inner join products p
	on o.product_id = p.product_id;
-- once you give the alias to a table you can't use table-name elsewhere
