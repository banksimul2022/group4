const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.kortinnumero && request.body.pin){
      const kortinnumero = request.body.kortinnumero;
      const pin = request.body.pin;
        login.checkpin(kortinnumero, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("onnistui");
                  const token = generateAccessToken({ username: kortinnumero });
                  response.send(token);
                }
                else {
                    console.log("vaara pin");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("tilia ei ole");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("kortinnumero tai pin on vaarin");
      response.send(false);
    }
  }
);

function generateAccessToken(kortinnumero) {
  dotenv.config();
  return jwt.sign(kortinnumero, process.env.MY_TOKEN, { expiresIn: '1800s' });
}

module.exports=router;