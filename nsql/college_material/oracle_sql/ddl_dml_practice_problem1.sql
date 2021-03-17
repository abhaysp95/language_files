/* Practice Problem 3 */

drop table course cascade constraints;
drop table courseregistration cascade constraints;

create table course(courseid varchar2(6) primary key check (courseid like 'C%'), coursename varchar2(40), duration number, coursefee number);
create table courseregistration(registrationid varchar2(6) primary key check (registrationid like 'R%'), studentid varchar2(6), courseid varchar2(6) references course(courseid), registrationdate date DEFAULT SYSDATE);

insert into course values('C201','Advanced SQL',5,1200);
insert into course values('C202','Networking Fundamentals',4,1600);
insert into course values('C203','Cloud Computing',7,3500);
insert into course values('C204','Software Testing',4,2500);

insert into courseregistration values('R501','S301','C201','22-Sep-17');
insert into courseregistration values('R502','S302','C202','20-Nov-17');
insert into courseregistration values('R503','S303','C202','12-Oct-17');
insert into courseregistration values('R504','S302','C201','27-Nov-17');
insert into courseregistration values('R505','S304','C204','10-Nov-17');
insert into courseregistration values('R506','S305','C203','17-Oct-17');

select * from course;
select * from courseregistration;

/* Practice Problem 4 */

DROP TABLE employee CASCADE CONSTRAINTS;
DROP TABLE doctor CASCADE CONSTRAINTS;

CREATE TABLE employee
(
empno NUMBER PRIMARY KEY,
empname VARCHAR2(15) NOT NULL,
emptype VARCHAR2(10),
salary NUMBER,
gender VARCHAR2(1) CHECK(gender in ('M','F')),
emailid VARCHAR2(30) UNIQUE,
dateofjoining DATE);

CREATE TABLE doctor(
doctorid NUMBER PRIMARY KEY REFERENCES employee(empno),
qualification VARCHAR2(15),
specialization VARCHAR2(30),
inpatientfee NUMBER,
outpatientfee NUMBER
);

delete from doctor;
delete from employee;

Insert into employee values(1002,'Alice','Doctor',95000,'F',NULL,'9-Jun-15');
Insert into employee values(2001,'Henry','Admin',25000,'M','2001henry@xyz.com','10-Jun-15');
Insert into employee values(1003,'Gabrielle','Doctor',110000,'F','1004gabrielle@xyz.com','14-Aug-15');
Insert into employee values(9201,'Thomas','Attendant',20000,'M','9201thomas@xyz.com','22-Nov-15');
Insert into employee values(1004,'Tom','Doctor',100000,'M',NULL,'25-Dec-15');
Insert into employee values(1005,'Aldan','Doctor',150000,'M','1002aldan@xyz.com','24-Jan-16');
Insert into employee values(1006,'Nicole','Doctor',90000,'F','1006nicole@xyz.com','12-Oct-16');
Insert into employee values(9204,'Kate','Attendant',20000,'F','9204kate@xyz.com','30-Nov-16');

Insert into doctor values(1002,'MS','Nephrology',600,400);
Insert into doctor values(1003,'MD','Nephrology',700,500);
Insert into doctor values(1004,'MS','Neurology',750,550);
Insert into doctor values(1005,'MS','Cardiology',800,600);
Insert into doctor values(1006,'MS','Gynaecology',550,350);

select * from doctor;
select * from employee;


