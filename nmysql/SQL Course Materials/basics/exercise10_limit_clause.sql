-- get top 3 loyal customers

use sql_store;

select * from customers
order by points desc
limit 3;

-- the limit clause should always come at the end
-- select
-- from
-- where
-- order by
-- limit
