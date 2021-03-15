-- select * from customers
-- where birth_date > '1990-01-01' or points > 1000 and state = 'VA';

-- order from high to low
-- and
-- or
-- not

-- but we can use () for precendence according to us
select * from customers
where birth_date > '1990-01-01' or
	(points > 1000 and state = 'VA');

-- negation
select * from customers
where not (birth_date > '1990-01-01' or
	(points > 1000 and state = 'VA'));

-- now the above condition can also be written as
select * from customers
where birth_date <= '1990-01-01' and
	(points <= 1000 or state != 'VA')
