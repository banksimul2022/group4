const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where Tilinumero=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (Tilinumero,Saldo) values(?,?)',
      [tili.Tilinumero, tili.Saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where Tilinumero=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set Tilinumero=?,Saldo=?',
      [tili.Tilinumero, tili.Saldo, id],
      callback
    );
  }
};
module.exports = tili;