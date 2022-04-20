const db = require('../database');

const tilitapahtumat = {
  getTapahtumat: function(id, callback) {
    return db.query('select pvmaika, tapahtuma, summa from tilitapahtumat where id_tilinumero=?', [id], callback);
  },
  
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (id_tilinumero,kortinnumero,pvmaika,tapahtuma,summa) values(?,?,?,?,?)',
      [tilitapahtumat.id_tilinumero, tilitapahtumat.kortinnumero, tilitapahtumat.pvmaika, tilitapahtumat.tapahtuma, tilitapahtumat.summa],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where id_tilitapahtuma=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set id_tilinumero=?,kortinnumero=?,pvmaika=?,tapahtuma=?,summa=?',
      [tilitapahtumat.id_tilinumero, tilitapahtumat.kortinnumero, tilitapahtumat.pvmaika, tilitapahtumat.tapahtuma, tilitapahtumat.summa],
      callback
    );
  }
};
module.exports = tilitapahtumat;