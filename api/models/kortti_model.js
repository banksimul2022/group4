const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where kortinnumero=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (kortinumero,pin,idAsiakas) values(?,?,?)',
      [kortti.kortinumero, kortti.pin, kortti.idAsiakas],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where kortinnumero=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set pin=?, idAsiakas=? where kortinnumero=?',
      [kortti.pin, kortti.idAsiakas, id],
      callback
    );
  }
};
module.exports = kortti;