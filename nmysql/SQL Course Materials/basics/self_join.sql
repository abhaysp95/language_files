-- sql provides facility to self join columns in the same table, that's why self-join

use sql_hr;

select e.employee_id, e.first_name, m.first_name as manager
from employees e
join employees m
	on e.reports_to = m.employee_id;


-- was thinking to join the m.first_name and m.last_name and then write it as manager
