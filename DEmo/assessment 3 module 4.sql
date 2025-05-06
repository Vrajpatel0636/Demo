CREATE DATABASE ASSESSMENT_3;
USE ASSESSMENT_3 ;

-- Creating Salesman table
CREATE TABLE Salesman (
    salesman_id INT PRIMARY KEY,
    name VARCHAR(50),
    city VARCHAR(50),
    commission FLOAT
);

-- Creating Customer table
CREATE TABLE Customer (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(50),
    city VARCHAR(50),
    grade INT null,
    salesman_id INT,
    FOREIGN KEY (salesman_id) REFERENCES Salesman(salesman_id)
);


-- Inserting into Salesman table
INSERT INTO Salesman (salesman_id, name, city, commission) VALUES
(5001, 'James Hoog', 'New York', 0.15),
(5002, 'Nail Knite', 'Paris', 0.13),
(5005, 'Pit Alex', 'London', 0.11),
(5006, 'Mc Lyon', 'Paris', 0.14);

-- Inserting into Customer table
INSERT INTO Customer (customer_id, customer_name, city, grade, salesman_id) VALUES
(3002, 'Nick Rimando', 'New York', 100, 5001),
(3007, 'Brad Davis', 'New York', 200, 5001),
(3005, 'Graham Zusi', 'California', 200, 5002),
(3008, 'Julian Green', 'London', 300, 5005),
(3004, 'Fabian Johnson', 'Paris', 300, 5006),
(3009, 'Geoff Cameron', 'Berlin', 100, 5002),
(3003, 'Jozy Altidor', 'Moscow', 200, 5006),
(3001, 'Brad Guzan', 'London', NULL, 5005);

-- Query to find customer name, city, salesman name, and commission
SELECT 
    c.customer_name AS "Customer Name",
    c.city AS "Customer City",
    s.name AS "Salesman Name",
    s.commission AS "Commission"
FROM 
    Customer c
JOIN 
    Salesman s
ON 
    c.salesman_id = s.salesman_id;


drop table Customer;
SELECT * FROM Customer ;