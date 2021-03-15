-- as we know between employee and branch table their circular kind of
-- relationship, where one of the each attribute is working as foreign
-- key referencing other ones attribute

use comp_db_giraffe;

-- data for employee and branch table

-- for Corporate branch

insert into employee values(100, 'David', 'Wallace', '1967-11-17', 'M', 250000, NULL, NULL);
-- cause, branch_id doesn't exist yet, so NULL

insert into branch values(1, 'Corporate', 100, '2006-02-09');

-- now update employee.branch_id
update employee
set branch_id = 1
where emp_id = 100;

insert into employee values(101, 'Jan', 'Lavinson', '1961-05-11', 'F', 110000, 100, 1);


-- for Scarnton branch
insert into employee values(102, 'Micheal', 'Scott', '1964-03-15', 'M', 75000, 100, NULL);
insert into branch values(2, 'Scaranton', 102, '1992-04-6');
update employee
set branch_id = 2
where emp_id = 102;

insert into employee values(103, 'Angela', 'Martin', '1971-06-25', 'F', 63000, 102, 2);
insert into employee values(104, 'Kelly', 'Kappor', '1980-02-05', 'F', 55000, 102, 2);
insert into employee values(105, 'Stanley', 'Hudson', '1958-02-19', 'F', 69000, 102, 2);

-- for stamford branch
insert into employee values(106, 'Josh', 'Porter', '1969-09-05', 'M', 78000, 100, NULL);
insert into branch values(3, 'Stamford', 106, '1998-02-13');
update employee
set branch_id = 3
where emp_id = 106;
insert into employee values(107, 'Andy', 'Bernard', '1973-07-22', 'M', 65000, 106, 3);
insert into employee values(108, 'Jim', 'Halpert', '1978-10-01', 'M', 71000, 106, 3);


-- data into client table
insert into client values(400, 'Dunmore HighSchool', 2);
insert into client values(401, 'Lackawana Country', 2);
insert into client values(402, 'FedEx', 3);
insert into client values(403, 'John Daly Law, LLC', 3);
insert into client values(404, 'Scranton WhitePages', 2);
insert into client values(405, 'Times Newspaper', 3);
insert into client values(406, 'FedEx', 2);

-- data into works_with table
insert into works_with values(105, 400, 55000);
insert into works_with values(102, 401, 267000);
insert into works_with values(108, 401, 22500);
insert into works_with values(107, 403, 5000);
insert into works_with values(108, 403, 12000);
insert into works_with values(105, 404, 33000);
insert into works_with values(107, 405, 26000);
insert into works_with values(102, 406, 15000);
insert into works_with values(105, 406, 130000);

-- data into branch supplier
insert into branch_supplier values(2, 'Hammer Mill', 'Paper');
insert into branch_supplier values(2, 'Uni-ball', 'Writing Utensils');
insert into branch_supplier values(3, 'Patriot Paper', 'Paper');
insert into branch_supplier values(2, 'J.T. Forms & Labels', 'Custom Forms');
insert into branch_supplier values(3, 'Uni-ball', 'Writing Utensils');
insert into branch_supplier values(3, 'Hammer Mill', 'Paper');
insert into branch_supplier values(3, 'Stamford Lables', 'Custom Forms');
