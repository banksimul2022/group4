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
      'insert into asiakas (Tunnus,Nimi,Osoite,Puhelinnumero) values(?,?,?,?)',
      [asiakas.Tunnus, asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where tunnus=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set Nimi=?,Osoite=?, Puhelinnumero=? where tunnus=?',
      [asiakas.Nimi, asiakas.Osoite, asiakas.Puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;