use comp_db_girrafe;

-- find all employee ordered by salary
select
	employee.first_name,
	employee.last_name,
	employee.salary
from employee
order by salary;

-- find all employee ordered by sex then name
select
	employee.first_name,
	employee.last_name,
	employee.sex
from employee
order by sex, first_name, last_name;

-- find the first 5 employee in the table
select *
from employee
limit 5;

-- find the first and last name of all employee
select first_name, last_name
from employee;

-- find the forename and surname names of all employee
select
	first_name as forename,
	last_name as surname
from employee;

-- find out all the different genders
select distinct sex
from employee;

-- find out all the branch_id from employee table
select distinct branch_id
from employee;
