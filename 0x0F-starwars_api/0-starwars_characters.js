#!/usr/bin/node
const process = require('process');
const request = require('request');
const id = process.argv[2];
let characterList = [];

request(`https://swapi-api.hbtn.io/api/films/${id}`, function (err, res, body) {
  if (err == null) {
    const json = JSON.parse(body);
    characterList = json.characters;

    for (const char of characterList) {
      request(char, function (err, res, body) {
        if (err == null) {
          const person = JSON.parse(body);
          console.log(person.name);
        } else {
          console.error(err);
        }
      });
    }
  } else {
    console.error(err);
  }
});
