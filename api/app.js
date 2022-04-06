var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');

const asiakasRouter = require('./routes/asiakas');
const asiakas_has_tiliRouter = require('./routes/asiakas_has_tili');
const korttiRouter = require('./routes/kortti');
const tiliRouter = require('./routes/tili');
const tilitapahtumatRouter = require('./routes/tilitapahtumat');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(helmet());
app.use(cors());

app.use('/asiakas', asiakasRouter);
app.use('/asiakas_has_tili', asiakas_has_tiliRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);

module.exports = app;