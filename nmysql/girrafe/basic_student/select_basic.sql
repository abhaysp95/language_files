-- select name, major from student

select student.name, student.major
from student
order by name desc;  -- asc for ascending

select student.student_id, student.major
from student
order by major, student_id desc;

select student.student_id, student.major
from student
order by major, student_id desc
limit 2;


select student.name
from student
where major = 'BioChemistry' and student_id = '4';

select *
from student
where major <> 'BioChemistry' and student_id != '4';

-- <, >, <=, =>, =, <>, != and, or


select *
from student
where name in ('Claire', 'Kate', 'Mike')
and major in ('Physics', 'Mathematics');
