-- like operator is old one, this ones new and obviously more powerful

use sql_store;

select * from customers
where last_name regexp '[gml]e' or last_name regexp 'field$';

-- supports most of the syntax of regexp, like in others

select * from customers
where last_name regexp '[a-h]f.*';

select * from customers
where last_name regexp 'field|ley';
