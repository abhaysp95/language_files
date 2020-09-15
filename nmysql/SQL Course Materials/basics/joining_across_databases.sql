use sql_store;

select *
from order_items o
join sql_inventory.products p
	on o.product_id = p.product_id;


-- or we can write like this

use sql_inventory;

select *
from sql_store.order_items o
inner join products p
	on o.product_id = p.product_id;

-- you only have to prefix the table that are not part of the current database
-- inner join is working here
