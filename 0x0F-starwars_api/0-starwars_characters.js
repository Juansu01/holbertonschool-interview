#!/usr/bin/node

const process = require('process');
const request = require('request');

const id = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${id}`, function(err, res, body) {
    console.log(body);
});
