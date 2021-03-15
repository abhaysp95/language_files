# SQl Queries



## DDL:

Data Definition Language, following are the queries for DDL:

* create
* alter
* rename
* drop
* truncate


### Table creation:

```sql
Create table <table-name>(<col> <datatype>(<size>), <col2> <datatype><size>);

create table emp(empno int primary key, ename varchar(25));
```

**output**:

```
MariaDB [csb]> describe emp;
+-------+-------------+------+-----+---------+-------+
| Field | Type        | Null | Key | Default | Extra |
+-------+-------------+------+-----+---------+-------+
| empno | int(11)     | NO   | PRI | NULL    |       |
| ename | varchar(25) | YES  |     | NULL    |       |
+-------+-------------+------+-----+---------+-------+
2 rows in set (0.002 sec)
```


### Modify structure of table:

```sql
Alter table <tablename> add(<new col><datatype(size)>, <newcol><datatype(size)>);

alter table emp add column salary int;

alter table student drop column salary;

alter table emp modify ename varchar(32);
```

**output**:
```
MariaDB [csb]> describe emp;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| empno  | int(11)     | NO   | PRI | NULL    |       |
| ename  | varchar(25) | YES  |     | NULL    |       |
| salary | int(11)     | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)
```


### Rename the table:

```sql
alter table <oldtable> rename to <newtable>;

rename table <oldtable> to <newtable>;


alter table emp rename to empl;

rename table empl to emp;
```

**output**:

```
MariaDB [csb]> show tables;
+---------------+
| Tables_in_csb |
+---------------+
| empl          |
| login         |
| student       |
+---------------+
3 rows in set (0.001 sec)
```


### Truncate table:

delete all the attribute/values:

```sql
truncate table <table-name>;


truncate table emp;
```

**output**:

```
MariaDB [csb]> select * from emp;
+-------+-------+--------+
| empno | ename | salary |
+-------+-------+--------+
|     1 | Name  |  10000 |
+-------+-------+--------+
1 row in set (0.001 sec)

MariaDB [csb]> truncate table emp;
Query OK, 0 rows affected (0.211 sec)

MariaDB [csb]> select * from emp;
Empty set (0.001 sec)
```


### Drop table:

```sql
drop table <table-name>

drop table empl;
```

**output**:

```
MariaDB [csb]> drop table empl;
Query OK, 0 rows affected (0.083 sec)

MariaDB [csb]> show tables;
+---------------+
| Tables_in_csb |
+---------------+
| login         |
| student       |
+---------------+
2 rows in set (0.001 sec)
```


## DML Queries:

Following are the examples to use DML queries:


Initial table:

```sql
MariaDB [csb]> select * from tempweb;
Empty set (0.023 sec)
```


### Insert into existing table:

```sql
insert into <table-name> values(val1, val2);

insert into tempweb(1, "jollygood", "comedy");
```

**output**:

```sql
MariaDB [csb]> select * from tempweb;
+----+-----------+--------+
| id | username  | work   |
+----+-----------+--------+
|  1 | jollygood | comedy |
+----+-----------+--------+
1 row in set (0.001 sec)
```


You can also insert only in selected col, here's the example:

```sql
MariaDB [csb]> insert into tempweb(id, work) values(2, "sweeper");
Query OK, 1 row affected (0.009 sec)

MariaDB [csb]> select * from tempweb;
+----+-----------+---------+
| id | username  | work    |
+----+-----------+---------+
|  1 | jollygood | comedy  |
|  2 | NULL      | sweeper |
+----+-----------+---------+
2 rows in set (0.001 sec)
```

With the above example, you can also change the sequence of inserting data:

```sql
MariaDB [csb]> insert into tempweb(work, id) values("cleaner", 3);
Query OK, 1 row affected (0.015 sec)

MariaDB [csb]> select * from tempweb;
+----+-----------+---------+
| id | username  | work    |
+----+-----------+---------+
|  1 | jollygood | comedy  |
|  2 | NULL      | sweeper |
|  3 | NULL      | cleaner |
+----+-----------+---------+
3 rows in set (0.001 sec)
```

Also, if you want to leave blank a attribute in sequence, you have no need to give attribute name to insert, if you have set the attribute while table creation to fill the domain with **NULL**


There's also `&(ampersand substitution)` which is not supported in `mysql` but in `oracle db`.


### Select from existing table:

```sql
select * from <table-name>
```
```sql
MariaDB [csb]> select * from tempweb;
+----+-----------+---------+
| id | username  | work    |
+----+-----------+---------+
|  1 | jollygood | comedy  |
|  2 | NULL      | sweeper |
|  3 | NULL      | cleaner |
+----+-----------+---------+
3 rows in set (0.038 sec)
```

In the previous example you see, that _select_ clause is using __*__, which is a _wildcard_ and will select every attibute of provided table. You can just as well use attribute name instead of *, like this example:

```sql
MariaDB [csb]> select id, work from tempweb;
+----+---------+
| id | work    |
+----+---------+
|  1 | comedy  |
|  2 | sweeper |
|  3 | cleaner |
+----+---------+
3 rows in set (0.001 sec)
```

So, this is _column selection_ if we want to say, next we see how we can select row and perform action on selected row's attribute. We'll use _where_ clause for it.


### Using 'where' clause:

As said in previous heading, we can use _where_ clause to perform action on given particular rows.

```sql
MariaDB [csb]> select id, work from tempweb where id = 3;
+----+---------+
| id | work    |
+----+---------+
|  3 | cleaner |
+----+---------+
1 row in set (0.001 sec)
```


**UPDATE**:

```sql
update <table-name> set <attr-name>=value where <attr-name>=value;
```

This will update the provided `attr-name`'s value, _where_ clause is just telling the query to updated if the expression provided after _where_ clause satifies or not. If you not provide the _where_ clause here it'll update every matching `attr-name`'s value.

Let's see an example for our 'tempweb' table:

```sql
MariaDB [csb]> update tempweb set username="Mr. Cleaner" where id=3;
Query OK, 1 row affected (0.062 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

**output**:
```sql
MariaDB [csb]> select * from tempweb;
+----+-------------+---------+
| id | username    | work    |
+----+-------------+---------+
|  1 | jollygood   | comedy  |
|  2 | NULL        | sweeper |
|  3 | Mr. Cleaner | cleaner |
+----+-------------+---------+
3 rows in set (0.001 sec)
```

`Note: You can't update the attribute which is acting as primary key`


### Create copy of table:

To create a psuedo table <new_table> with the same structure as the <prev_table> and insert the table using select clause:

```sql
create table <new_table> as select * from <old_table>;

-- values in old table
MariaDB [csb]> select * from tempweb;
+----+-------------+---------+
| id | username    | work    |
+----+-------------+---------+
|  1 | jollygood   | comedy  |
|  2 | NULL        | sweeper |
|  3 | Mr. Cleaner | cleaner |
+----+-------------+---------+
3 rows in set (0.172 sec)

-- structure of old table
MariaDB [csb]> desc tempweb;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   | PRI | NULL    |       |
| username | varchar(24) | YES  |     | NULL    |       |
| work     | varchar(32) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.104 sec)

-- copy old table to new one
MariaDB [csb]> create table tempweb1 as select * from tempweb;
Query OK, 3 rows affected (0.623 sec)
Records: 3  Duplicates: 0  Warnings: 0

-- structure of new table(see primary key is not set)
-- nor will any other additional settings(like auto_inc etc.)
MariaDB [csb]> desc tempweb1;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   |     | NULL    |       |
| username | varchar(24) | YES  |     | NULL    |       |
| work     | varchar(32) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)

-- values in new copied table
MariaDB [csb]> select * from tempweb1;
+----+-------------+---------+
| id | username    | work    |
+----+-------------+---------+
|  1 | jollygood   | comedy  |
|  2 | NULL        | sweeper |
|  3 | Mr. Cleaner | cleaner |
+----+-------------+---------+
3 rows in set (0.001 sec)

-- setting id as primary key in new copied table
MariaDB [csb]> alter table tempweb1 add primary key(id);
Query OK, 0 rows affected (1.496 sec)
Records: 0  Duplicates: 0  Warnings: 0

-- now see key is set to id attribute
MariaDB [csb]> desc tempweb1;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   | PRI | NULL    |       |
| username | varchar(24) | YES  |     | NULL    |       |
| work     | varchar(32) | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.002 sec)
```

### Delete specific attibute

To delete some specific row you can use following queries:
```sql
MariaDB [csb]> delete from tempweb1 where id = 2;
Query OK, 1 row affected (0.208 sec)

MariaDB [csb]> select * from tempweb1;
+----+-------------+---------+
| id | username    | work    |
+----+-------------+---------+
|  1 | jollygood   | comedy  |
|  3 | Mr. Cleaner | cleaner |
+----+-------------+---------+
2 rows in set (0.001 sec)
```

Making few _changes_ to `tempweb1`:

```sql
MariaDB [csb]> alter table tempweb1 add column salary int;
Query OK, 0 rows affected (0.105 sec)
Records: 0  Duplicates: 0  Warnings: 0

MariaDB [csb]> desc tempweb1;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| id       | int(11)     | NO   | PRI | NULL    |       |
| username | varchar(24) | YES  |     | NULL    |       |
| work     | varchar(32) | YES  |     | NULL    |       |
| salary   | int(11)     | YES  |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
4 rows in set (0.002 sec)

MariaDB [csb]> update tempweb1 set salary=13000 where id=1;
Query OK, 1 row affected (0.034 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [csb]> update tempweb1 set salary=9000 where id=3;
Query OK, 1 row affected (0.019 sec)
Rows matched: 1  Changed: 1  Warnings: 0

MariaDB [csb]> insert into tempweb1 values(4, 'Mr. Racer', 'driver', 15000);
Query OK, 1 row affected (0.062 sec)

MariaDB [csb]> select * from tempweb1;
+----+-------------+---------+--------+
| id | username    | work    | salary |
+----+-------------+---------+--------+
|  1 | jollygood   | comedy  |  13000 |
|  3 | Mr. Cleaner | cleaner |   9000 |
|  4 | Mr. Racer   | driver  |  15000 |
+----+-------------+---------+--------+
3 rows in set (0.001 sec)
```

### Increasing and Decreasing order:

To order in increasing or decreasing order use `ASC` and `DESC`. You don't need to use `ASC`, ordering is default to ascending

```sql
MariaDB [csb]> select * from tempweb1 order by salary desc;
+----+-------------+---------+--------+
| id | username    | work    | salary |
+----+-------------+---------+--------+
|  4 | Mr. Racer   | driver  |  15000 |
|  1 | jollygood   | comedy  |  13000 |
|  3 | Mr. Cleaner | cleaner |   9000 |
+----+-------------+---------+--------+
3 rows in set (0.001 sec)
```

### Select distinct values:

```sql
MariaDB [csb]> select distinct salary from tempweb1;
+--------+
| salary |
+--------+
|  13000 |
|   9000 |
|  15000 |
+--------+
3 rows in set (0.001 sec)

-- to get total pay scale
MariaDB [csb]> select count(distinct salary) as pay_scale from tempweb1;
+-----------+
| pay_scale |
+-----------+
|         3 |
+-----------+
1 row in set (0.008 sec)
```
