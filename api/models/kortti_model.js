const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getTilinumero: function(id, callback) {
    return db.query('select tilinumero, lukittu from kortti where kortinnumero=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
      bcrypt.hash(kortti.pin, saltRounds,function(err, hash) {
        return db.query(
        'insert into kortti (kortinnumero, pin, lukittu, idasiakas,tilinumero) values(?,?,?,?,?)',
        [kortti.kortinnumero, hash, kortti.lukittu, kortti.idasiakas, kortti.tilinumero],
        callback);
      });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where kortinnumero=?', [id], callback);
  },
  update: function(id, kortti, callback) {
  bcrypt.hash(kortti.pin, saltRounds,function(err, hash) {
    return db.query(
    'update kortti set lukittu=? where kortinnumero=?',
    [kortti.lukittu, id],
    callback);
  });
 }
};
module.exports = kortti;