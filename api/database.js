const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'pepe',
  password: 'pepe',
  database: 'banksimul'
});
module.exports = connection;