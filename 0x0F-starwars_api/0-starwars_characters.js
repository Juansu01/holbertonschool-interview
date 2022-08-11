#!/usr/bin/node
const process = require('process');
const request = require('request');
const id = process.argv[2];
let characterList = [];

request(`https://swapi-api.hbtn.io/api/films/${id}`, function (err, res, body) {
  if (err == null) {
    const json = JSON.parse(body);
    characterList = json.characters;

    getCharacterName(0, characterList[0], characterList, characterList.length);
  } else {
    console.error(err);
  }
});

function getCharacterName (idx, url, characters, limit) {
  if (idx === limit) {
    return;
  }
  request(url, function (err, response, body) {
    if (!err) {
      const rbody = JSON.parse(body);
      console.log(rbody.name);
      idx++;
      getCharacterName(idx, characters[idx], characters, limit);
    } else {
      console.error(err);
    }
  });
}
