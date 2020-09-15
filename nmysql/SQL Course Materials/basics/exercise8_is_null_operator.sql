use sql_store;

select * from orders
where shipped_date is null;

select * from orders
where shipper_id is null;

-- above two are correct answers

select * from orders
where comments is null;

select * from orders
where status = 1;
