use comp_db_giraffe;

-- find the number of employee
select count(emp_id)
from employee;

-- find the number of super_id
select distinct count(super_id)
from employee

-- find the number of super_id
select count(super_id)  -- (no change from the prev query in result)
from employee;

-- find the number of female employee born after 1970
select count(emp_id)
from employee
where sex = 'F'
and birth_day >= '1970-01-01';

-- find the average of all the employees salary
select avg(salary)
from employee
where sex = 'M';

-- find the sum of all the employees salary
select sum(salary)
from employee;


-- aggregation example

-- find out how many males and females are there
select count(sex), sex
from employee
group by sex;  -- group data by sex

-- find the total sales of each salesman
select sum(total_sales) as total_sale, emp_id
from works_with
group by emp_id
order by total_sale desc;

-- how much each client spend
select sum(total_sales) as total_spent, client_id
from works_with
group by client_id
order by total_spent desc;

-- highest paid employee in every branch
select first_name, last_name, salary, branch_id
from employee
group by branch_id
order by salary desc;
