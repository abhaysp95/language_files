use sql_store;

select * from customers
where address like '%avenue%' or
	address like '%trail%' or
	phone not like '%9';


-- things to match with like are case insensitive
