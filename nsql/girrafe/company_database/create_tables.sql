use comp_db_giraffe;

-- create employee table
create table employee (
	emp_id int primary key,
	first_name varchar(32),
	last_name varchar(32),
	birth_day date,
	sex varchar(1),
	salary int,
	super_id int,  -- is going to be foreign key
	branch_id int  -- is going to be foreign key
	-- foreign keys can't be created cause, employee and branch table
	-- doesn't exist yet
);

-- create branch table
create table branch (
	-- emp_id int primary key,
	-- intentionally put wrong attribute name above, to change it, you can use,
	-- alter table branch change emp_id branch_id int;
	branch_id int primary key,  -- this is the correct one
	branch_name varchar(32),
	mgr_id int,
	mgr_start_date date,
	foreign key(mgr_id) references employee(emp_id)
	on delete set null
);


-- make super_id, branch_id in employee table as foreign key
alter table employee
add foreign key(branch_id)
references branch(branch_id)
on delete set null;

alter table employee
add foreign key(super_id)
references employee(emp_id)
on delete set null;

-- create client table
create table client (
	client_id int primary key,
	client_name varchar(64),
	branch_id int,
	foreign key(branch_id) references branch(branch_id)
	on delete set null
);

-- create works_with table
create table works_with (
	emp_id int,
	client_id int,
	total_sales int,
	primary key(emp_id, client_id),
	foreign key(emp_id) references employee(emp_id)
	on delete cascade,
	foreign key(client_id) references client(client_id)
	on delete cascade
);


-- create branch supplier table
create table branch_supplier (
	branch_id int,
	supplier_name varchar(32),
	supply_type varchar(32),
	primary key(branch_id, supplier_name),
	foreign key(branch_id) references branch(branch_id)
	on delete cascade
);


-- when dropping tables, if two tables have foreign keys linked with
-- each other, like from above employee.branch_id is linked with
-- branch.branch_id and branch.mgr_id is linked with employee.emp_id
-- you can remove the foreign key attribute with alter and then delete
-- the table
-- run following query:
-- alter table table_name drop foreign key constraint_name;

-- you can find constraint_name with following query:
-- show create table table_name;
