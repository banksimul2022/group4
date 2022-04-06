const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where tunnus=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (tunnus,nimi,osoite,puhelinnumero) values(?,?,?,?)',
      [asiakas.tunnus, asiakas.nimi, asiakas.osoite, asiakas.puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where tunnus=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set nimi=?,osoite=?, puhelinnumero=? where tunnus=?',
      [asiakas.nimi, asiakas.osoite, asiakas.puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;