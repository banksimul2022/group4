const db = require('../database');

const asiakas_has_tili = {
  getById: function(id, callback) {
    return db.query('select * from asiakas_has_tili where asiakas_idasiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas_has_tili', callback);
  },
  add: function(asiakas_has_tili, callback) {
    return db.query(
      'insert into asiakas_has_tili (asiakas_idasiakas, tili_tilinumero) values(?,?)',
      [asiakas_has_tili.asiakas_idasiakas, asiakas_has_tili.tili_tilinumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas_has_tili where asiakas_idasiakas=?', [id], callback);
  }
};
module.exports = asiakas_has_tili;