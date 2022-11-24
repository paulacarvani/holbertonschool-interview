#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function getRequest (charactersUrl) {
    return new Promise((resolve, reject) => {
        request(charactersUrl, (error, response, body) => {
            if (error) reject(error);
            resolve(JSON.parse(body));
        });
    });
}

async function charsName () {
    const response = await getRequest(url);
    for (let i = 0; i < Object.keys(response.characters).length; i++) {
        const char = await getRequest(response.characters[i]);
        console.log(char.name);
    }
}

charsName();
