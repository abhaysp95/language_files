-- create table
create table student (
	student_id int primary key,
	name varchar(32),
	major varchar(32)
	-- primary key(student_id)  -- another way to make primary key
);

-- show table
describe student;

-- make changes to table
alter table student add gpa decimal(3, 2);  -- 3 total with 2 digits after decimal points

describe student;

-- make changes to/for specific attribute(it's acutally a change in table too)
alter table student drop column gpa;

describe student;

drop table student;
