-- mind you, sql is case insensitive



USE sql_store;



-- select last_name, first_name, address




-- give discount (you can use () for precedence of operators)
select
	first_name,
	last_name,
	points,
	points + points / 10 as "10% more profit"
from customers
order by points;



-- get unique elements only(DISTINCT)
-- select state
select distinct state
from customers;



