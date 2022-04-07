const db = require('../database');

const login={
  checkpin: function(kortinnumero, callback) {
      return db.query('SELECT pin FROM kortti WHERE kortinnumero = ?',[kortinnumero], callback); 
    }
};
          
module.exports = login;