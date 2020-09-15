use sql_store;

select * from customers
order by first_name;

select * from customers
order by first_name desc;

select * from customers
order by state, first_name;
-- sort by state and in state sort by first name(ascending)

select * from customers
order by state desc, first_name;


-- a feature of sql is you can use order by on any column whether it is in select clause or not

select first_name, last_name, address from customers
order by state, first_name desc;

select first_name, last_name, 10 as points
from customers
order by points, first_name;


-- sorting data by column position(should be avoided)
select first_name, last_name, 10 as points
from customers
order by 2, 1;  -- sort last_name then first_name
-- but
select birth_date, first_name, last_name, 10 as points
from customers
order by 2, 1;  -- now it is sorted according first_name then birth_date

-- so always sort by column name
