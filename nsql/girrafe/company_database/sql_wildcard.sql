use comp_db_giraffe;

-- % = any # characters, _ = one character
-- like(keyword) is used for using wildcard

-- find any client's who are in LLC
select client_name
from client
where client_name like '%LLC';

select client_name
from client
where client_name like '*LLC*';  -- this will not work

-- find any branch supplier who are in the label buisness
select supplier_name
from branch_supplier
where supplier_name like '%Label%';

-- find any employee born in october
-- first
select first_name, last_name, birth_day
from employee
where birth_day like '%-10-%';
-- second
select first_name, last_name, birth_day
from employee
where birth_day like '____-10%';

-- find any client who are in schools
select client_name
from client
where client_name like '%school%';
