-- look for sql*plus tips and tricks, like(help set)

-- set lines 256
-- set trimout on
-- set tab off

select to_char(dob, 'yyyy/mm/dd') as dateob from student;  -- you can provide some other delims too

select avg(marks) as avg_marks from student;

select max(marks) as avg_marks from student;

select min(marks) as avg_marks from student;

alter table student add hostler varchar2(10);  -- it's going to be empty

select * from student where marks > 70 and dob > '01-JAN-00';

select * from student where marks > 70 and dob > '01-JAN-70' and dob < '01-JAN-00';

select * from student where marks > 70 and dob between '01-JAN-70' and '01-JAN-00';

alter table student drop column hostler;  -- drop a column

select * from student where marks > 60 and
	std_name like 'A%' or
	std_name like 'E%' or
	std_name like 'I%' or
	std_name like 'O%' or
	std_name like 'U%';

-- like gives here any chars(multiple) then a 'y' then a char in between then 's' and then can be multiple cars
select * from student where std_name in (
	select std_name from student where std_name like '%y_s%');

update student set rollno=35 where std_name='Ramesh';

alter table student modify rollno number(5) primary key;  -- column shouldn't have NULL or duplicate value already

insert all
	into student values('Mohan', 89, '08-FEB-13', 78, 938493423)
	into student (std_name, rollno, marks, contact) values('Sohan', 93, 83, 389238439)
	into employee values(7, 'Mahendra', 'C', date '2011-06-06', 67)
	into employee values(10, 'Surendra', 'A', date '2010-04-06', 73)
	into employee (emp_id, emp_name, department, performance_rating) values(14, 'Rajendra', 'B', 73)
select * from dual;


-- Union and join examples

create table first(name varchar(32), id number(5));
create table second(name varchar(32), id number(5));
create table third(id number(5), email varchar(32));

insert all
	into first values('Ram', 4)
	into first values('Shyam', 10)
	into first values('Rohit', 18)
	into second values('Ramesh', 5)
	into second values('Mahesh', 10)
	into second values('Ram', 15)
	into second values('Shyam', 10)
	into third values(4, 'ram@xyz.com')
	into third values(18, 'rohit@xyz.com')
	into third values(5, 'ramesh@xyz.com')
	into third values(10, 'shyam@xyz.com')
select * from dual;

select * from first union select * from second;
select * from first union all select * from second;

-- in union column data-type(not name) should match position wise
-- the number of columns must match in the query for union
-- union and union all will give the same result if participating queries are mutually exclusive

select f.name, f.id, t.email from first f inner join third t on f.id = t.id;  -- inner join
