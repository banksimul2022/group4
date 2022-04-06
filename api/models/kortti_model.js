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
      'insert into kortti (kortinnumero, pin, lukittu, idasiakas) values(?,?,?,?)',
      [kortti.kortinnumero, kortti.pin, kortti.lukittu, kortti.idasiakas],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where kortinnumero=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set pin=?, lukittu=?, idasiakas=? where kortinnumero=?',
      [kortti.pin, kortti.lukittu, kortti.idasiakas, id],
      callback
    );
  }
};
module.exports = kortti;