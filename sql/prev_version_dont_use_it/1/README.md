0. Create a database named 'exam'
If there is such a database existing delete it first
Use this database for all the instructions from now on

1. Create the following tables
{
  "name": "Article_15",
  "fields": {
    "price": "currency",
    "url": "string",
    "created_on": "date"
  }
}
{
  "name": "Category",
  "fields": {
    "name": "varchar",
    "created_by": "string"
  }
}
{
  "name": "User",
  "fields": {
    "name": "varchar",
    "gender": "varchar(6)",
    "income": "float"
  }
}
{
  "name": "Tag",
  "fields": {
    "hash": "varchar(16)",
    "name": "varchar"
  }
}
As a result SQL queries must be created

2. Connect the tables in the following way
Category has a one to many connection to User
User has a many to one connection to Tag
Tag has a many to many connection to Article_15
As a result SQL queries must be created
Write the queries from point 1 and 2 in a file called creates.sql. It should be possible to execute this file directly in mysql without errors.


3. Insert
Add at least two records in each table
As a result SQL queries must be created
Write the queries from point 3 in a file called inserts.sql. It should be possible to execute this file directly in mysql without errors.

4. Answer the following question
Which are the Tag(s) for a given Category
As a result SQL query must be created
Write the queries from points 4 in a file called selects1.sql. It should be possible to execute this file directly in mysql without errors.

5. Export the Data Base to SQL or CSV

6. Execute the following migration
Separate User on two tables
User_part1 containing income
User_part2 containing all the other fields
As a result SQL queries+code in other programming language must be create.
Write the queries from points 6 in a file called migrates.sql. It should be possible to execute this file directly in mysql without errors.

7. Export the Data Base to SQL or CSV

8. Answer the following question
Which are the Article_15(s) for a given User
As a result SQL query must be created
Write the queries from points 8 in a file called selects2.sql. It should be possible to execute this file directly in mysql without errors.

9. Draw a picture of the database

10. Add all the files in a folder called FirstName_LastName_Class_Number
Create a zip or tar.gz from this folder and name the result FirstName_LastName_Class_Number.zip(tar.gz)
(here FirstName is your first name, LastName is your last name, class is A or B and Number is your number in class)

Good luck!