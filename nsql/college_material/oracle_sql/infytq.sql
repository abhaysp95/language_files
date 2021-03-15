select to_char(dob, 'yyyy/mm/dd') as dateob from student;

select avg(marks) as avg_marks from student;

select max(marks) as avg_marks from student;

select min(marks) as avg_marks from student;

alter table student add hostler varchar2(10);  -- it's going to be empty

select * from student where marks > 70 and dob > '01-JAN-00';

select * from student where marks > 70 and dob > '01-JAN-70' and dob < '01-JAN-00';

select * from student where marks > 70 and dob between '01-JAN-70' and '01-JAN-00';

alter table student drop column hostler;

select * from student where marks > 60 and
	std_name like 'A%' or
	std_name like 'E%' or
	std_name like 'I%' or
	std_name like 'O%' or
	std_name like 'U%';

select * from student where std_name in (select std_name from student where std_name like '%y_s%');  -- like gives here any chars(multiple) then a 'y' then a char in between then 's' and then can be multiple cars



alter table student modify rollno number(5) primary key;

insert all
	into stud


