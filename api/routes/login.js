const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');

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
                  response.send(true);
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

module.exports=router;