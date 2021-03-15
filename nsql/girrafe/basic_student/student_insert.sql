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
