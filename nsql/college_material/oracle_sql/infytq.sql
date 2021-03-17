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

-- practice problem(ddl, dml)

-- 1)
create table BookTransaction(
	book_id varchar2(6) primary key check(book_id like 'B%'),
	book_title varchar2(50),
	author_name varchar2(20),
	genre varchar2(10) check(genre = 'Mystery' or genre = 'Thriller'),
	year_of_publication date
);

--2)
create table RetailStore(
	itemcode varchar2(6) primary key,
	itemtype varchar2(30),
	description varchar2(50),
	price number(5,2),
	category char(1)
);
alter table RetailStore add discout number;
alter table RetailStore modify description varchar2(45);
alter table RetailStore modify category varchar2(5);
alter table RetailStore rename column description to itemdescription;
alter table RetailStore drop column itemtype;
alter table RetailStore drop primary key;

--3)
insert into Course values('C208', 'Software Engineering', 3, 1200);
insert into CourseRegistration values('R507', 'S306', 'C204', sysdate);

--4)
select doctorid, qualification from doctor_ddldml where outpatientfee >= 400 and outpatientfee <= 600 and inpatientfee >= 650;
select specialization, outpatientfee from doctor_ddldml where outpatientfee < 500;
select empno, empname, emptype from employee where gender = 'F' and empname like '%i%' or empname like '_a%' and salary <= 90000;
select empname, gender from employee where emailid <> NULL and dateofjoining like '%10%';  -- try date with between


-- practice problem(grouping, joining)
-- data in the file in this folder

-- problem1

-- 1)
-- is summing necessary ?
select category, sum(price) from greetingcard where price > 300 or category = 'Birthday Special' group by category;
select customerid from customer where custname like '_____' or customerid in (select customerid from greetingcard where price > 300);

-- 2)
-- select * from customer c inner join greetingcard g on c.customerid = g.customerid;
select c.customerid, g.cardid, c.custname, g.category from customer c inner join greetingcard g on c.customerid = g.customerid;  -- query not full

-- problem2

select * from patient p inner join consultation c on p.patientid = c.patientid inner join doctor d on d.doctorid = c.doctorid;

-- 1)
select p.pname, p.patientid, c.consultationid, c.doctorid, d.dname from patient p
	inner join consultation c on p.patientid = c.patientid
	inner join doctor d on c.doctorid = d.doctorid  -- joining more than 2 tables
	where p.pname in (select pname from patient where pname like '%e%')
	and c.doctorid in (select doctorid from doctor where dept = 'Cardiology');

-- 2)
select p.pname, d.dname, d.dept from patient p
	inner join consultation c on c.patientid = p.patientid
	inner join doctor d on c.doctorid = d.doctorid
	where p.pname in (select pname from patient where city = 'Boston' or city = 'Chicago');
-- still need to show total patient count for the doctors

-- 3)
select d.dname,
	-- (select d.dname from doctor inner join consultation on d.doctorid = c.doctorid group by d.doctorid),
	count(c.patientid) as count_of_patients from patient p  -- try to print doctorid too
	inner join consultation c on c.patientid = p.patientid
	inner join doctor d on c.doctorid = d.doctorid
	where d.dept in (select dept from doctor where dept = 'Cardiology')
	group by d.dname;
