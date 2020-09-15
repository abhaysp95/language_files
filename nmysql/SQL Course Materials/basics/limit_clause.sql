use sql_store;

select * from customers
limit 3;

-- if limit is greater than the number of records than all records are shown, like

select * from customers
limit 20;  -- but record is only 10, so it'll show all 10

-- offset
select * from customers
limit 6, 3;
-- 6 is offset, which basically means skip first 6 records and then pick 3 records
