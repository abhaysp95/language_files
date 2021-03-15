select * from customers
where state = 'VA' or state = 'FL' or state = 'GA';

-- this same statement can be written as

select * from customers
where state not in ('VA', 'FL', 'GA');

-- so use 'in' operator when you want to compare a list of values with attributes
