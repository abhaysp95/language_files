use sql_store;

select * from customers
where last_name like '%b%y';
-- any character at start and include b but end with y

select * from customers
where last_name like 'b____y';
-- start with b and end with y and names exactly 6 char long

-- % for any number of char at the given posittion
-- _ for a single char at given posittion
