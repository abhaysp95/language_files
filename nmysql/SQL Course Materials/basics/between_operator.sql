use sql_store;

select * from customers
where points >= 1000 and points <= 3000;

-- now, above query written with 'between' could be

select * from customers
where points between 1000 and 3000;
-- range is inclusive here
