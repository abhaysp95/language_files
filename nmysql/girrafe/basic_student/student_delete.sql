create table student (
	student_id int auto_increment,
	name varchar(32) not null,  -- you must have to get a name
	-- major varchar(32) unique,  -- unique domain entry in attribute
	major varchar(32) default 'undecided',
	primary key(student_id)
);

insert into student values(1, 'Jack', 'Biology');  -- puts according to attribute order of table
insert into student values(2, 'Kate', 'Sociology');
insert into student (student_id, name) values(3, 'Claire');
insert into student values(4, 'Jack', 'Biology');
insert into student values(5, 'Mike', 'Comp. Sci');
insert into student (student_id, name) values(6, 'Mayors');  -- no major will put default major
insert into student (name, major) values('Tim', 'Programming');  -- with auto_increment in use, you don't need to give student_id(prinary key) every time to insert value
insert into student (name) values('Wilson');

select * from student;

update student
set major = 'Bio'
where major = 'Biology';

select * from student;

update student
set major = 'Computer Science'
where major = 'Comp. Sci';

select * from student;

update student
set major = 'Physics'
where student_id = 3;

select * from student;


-- combine Biology and Chemistry major
update student
set major = 'BioChemistry'
where major = 'Bio' or major = 'Chemistry';

select * from student;

-- change multiple things
update student
set name = 'Tom', major = 'Mathematics'
where student_id = 6;

select * from student;


-- deletion

delete from student
where major = 'undecided';  -- can also use and & or

-- delete from student;  -- will delete everything from student table

select * from student;
