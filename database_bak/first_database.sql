create table posts(
	id int(11) not null PRIMARY KEY AUTO_INCREMENT,
   	subject varchar(128) not null,
    content varchar(1024) not null,
    date datetime not null
);

insert into posts (subject, content, date) VALUES ('This is subject', 'This is going to be content of the first subject', '2020-03-23 22:35:59');
insert into posts (subject, content, date) VALUES ('This is sec subject', 'This is going to be content of the second subject', '2020-03-23 22:39:50');

-- selection of element from table
select subject from posts
select * from posts  -- selects everything of posts table
select * from posts where id='2'  -- only select everything for id='2'
select * from posts where id='1' AND subject='This is subject'


-- update
update posts
set subject='This is first subject', content='This is going to be content of first subject'
where id='1'


-- delete
delete from posts
where id='2'
-- now to again properly set the table id, you can use
set @count=0;
update posts set posts.id = @count:= @count + 1;
-- you can give any number in count, this will change number from start
-- you can also only write id in place of posts.id here


insert into posts (subject, content, date) values ('this is second subject', 'This is the content of second subject', '2020-05-31 12:34:43');
insert into posts (subject, content, date) values ('this is third subject', 'This is the content of third subject', '2020-04-25 14:34:43');


-- order by (sort)
select * from posts order by id ASC
-- ASC can also be asc, desc for descending


-- check for group by


-- change column name of table
alter table posts CHANGE subject Subject varchar(128);


-- to delete duplicate rows
select * from posts order by subject;
-- below line returns duplicate
select subject, count(subject) from posts group by subject having count(subject) > 1;
-- delete duplicate rows using DELETE JOIN statement
delete t1 from posts t1
inner join posts t2
where
	t1.id < t2.id and
	t1.subject = t2.subject;
-- can also do this to keep minimum id number
-- t1.id > t2.id
