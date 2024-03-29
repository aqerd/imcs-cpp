const readline = require('readline');

function code(str){
    let count = 1;
    let coded_str = "";
    let i = 0;
    while (str.charAt(i)) {
        if (str.charAt(i) == str.charAt(i + 1)) {
            count++;
        } else if (count > 3 || str.charCodeAt(i) == '#'.charCodeAt(0)) {
            while (count > 255) {
                coded_str += '#' + String.fromCharCode(255) + str.charAt(i);
                count -= 255;
            }
            coded_str += '#' + String.fromCharCode(count) + str.charAt(i);
            count = 1;
        } else {
            while (count !== 0) {
                coded_str += str.charAt(i);
                count--;
            }
            count++;
        }
        i++;
    }
    //console.log("Escape code:", coded_str);
    return coded_str;
}

function decode(str){
    let decoded_str = "";
    i = 0;
    while (str.charAt(i)) {
        if (str.charAt(i) == '#') {
            for (let q = 0; q < str.charCodeAt(i + 1); q++) {
                decoded_str += str.charAt(i + 2);
            }
            i = i + 3;
        } else {
            decoded_str += str.charAt(i);
            i++;
        }
    }
    //console.log("Escape decode:", decoded_str);
    return decoded_str;
}

let str = "EJHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHWWrrWWWWWWWW0";
console.log(decode(decode(code(code(str)))));
console.log(str);