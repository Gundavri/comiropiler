const fs = require('fs');
const childProcess = require('child_process');
const compiler = require('./main/compiler');

fs.readFile('./index.gun', 'utf8', (err, data) => {
    fs.writeFile('./index.c', compiler(data), 'utf8', (err) => {
        if(err) console.log(err);
        else {
            childProcess.exec('gcc -o index index.c', (err) => {
                console.log(err);
                if(err) console.log('Gun code error ::: \'could not compile to C\'');
                else {
                    console.log('Gun code success ::: Succesfully compiled');
                }
            });
        }
    });
});