/* 1 */

select maker, speed
from Product, Laptop
where hd >= 30 and Product.model = Laptop.model;

/*
	+-------+-------+
	| maker | speed |
	+-------+-------+
	| A     |     2 |
	| A     |  2.16 |
	| A     |     2 |
	| B     |  1.83 |
	| E     |     2 |
	| E     |  1.73 |
	| E     |   1.8 |
	| F     |   1.6 |
	| F     |   1.6 |
	| G     |     2 |
	+-------+-------+
	10 rows in set (0.00 sec)
*/

/* 2 */

select Product.model, price
from Product, PC
where maker = 'B' and Product.model = PC.model
union
select Product.model, price
from Product, Laptop
where maker = 'B' and Product.model = Laptop.model
union
select Product.model, price
from Product, Printer
where maker = 'B' and Product.model = Printer.model;

/*
	+-------+-------+
	| model | price |
	+-------+-------+
	| 1004  |   649 |
	| 1005  |   630 |
	| 1006  |  1049 |
	| 2007  |  1429 |
	+-------+-------+
	4 rows in set (0.00 sec)
*/

/* 3 */

select hd
from PC
group by hd
having count(hd) > 1;

/*
	+------+
	| hd   |
	+------+
	|   80 |
	|  160 |
	|  250 |
	+------+
	3 rows in set (0.00 sec)
*/

/* 4 */

select PC.model, t.model
from PC, (select model, speed, ram from PC) t
where PC.speed = t.speed and PC.ram = t.ram and PC.model < t.model;

/*
	+-------+-------+
	| model | model |
	+-------+-------+
	| 1004  | 1012  |
	+-------+-------+
	1 row in set (0.00 sec)
*/

/* 5 */

select maker
from Product, PC
where Product.model = PC.model and speed >= 3.0
group by maker
having count(*) > 1
union
select maker
from Product, Laptop
where Product.model = Laptop.model and speed >= 3.0
group by maker
having count(*) > 1;

/*
	+-------+
	| maker |
	+-------+
	| B     |
	+-------+
	1 row in set (0.01 sec)
*/

/*
	Tables declarations:

	create table Product(maker char(1), model char(4), type varchar(7));
	create table PC(model char(4), speed double, ram int, hd int, price int);
	create table Laptop(model char(4), speed double, ram int, hd int, screen float, price int);
	create table Printer(model char(4), color bool, type varchar(7), price int);
*/
