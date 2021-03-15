-- a composite primary key contains more than one column

use sql_store;

select *
from order_items oi
join order_item_notes oin
	-- both the column names be same
	on oi.product_id = oin.product_id
	-- now compound statement
	and oi.order_id = oin.order_id;
