GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost';
CREATE DATABASE wordpress;
update mysql.user set plugin = 'mysql_native_password' where user='root';
FLUSH PRIVILEGES;
