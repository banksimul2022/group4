const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where id_Tilitapahtuma=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (id_Tilinumero,Kortinnumero,PvmAika,Tapahtuma,Summa) values(?,?,?,?,?)',
      [tilitapahtumat.id_Tilinumero, tilitapahtumat.Kortinnumero, tilitapahtumat.PvmAika, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where id_Tilitapahtuma=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set id_Tilinumero=?,Kortinnumero=?,PvmAika=?,Tapahtuma=?,Summa=?',
      [tilitapahtumat.id_Tilinumero, tilitapahtumat.Kortinnumero, tilitapahtumat.PvmAika, tilitapahtumat.Tapahtuma, tilitapahtumat.Summa],
      callback
    );
  }
};
module.exports = tilitapahtumat;