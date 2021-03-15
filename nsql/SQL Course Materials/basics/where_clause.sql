-- WHERE clause is used to filter data

select * from customers
where points > 1000
order by points;
-- query sql engine is going to iterate all over customer and customer table

select * from customers
where state <> 'VA';  -- for alphanumerical data use '' or ""
-- != is same to <>

select first_name, last_name
from customers
where birth_date > '1990-01-01';
-- above is given the standard syntax of sql date
