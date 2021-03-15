-- this line is comment

-- line breaks, whitespaces, tabs are ignored in sql syntax

USE sql_store;
select * from customers
where customer_id = 1
order by first_name;


USE sql_store;
select * from customers
order by first_name;

USE sql_store;
select 1, 2;
