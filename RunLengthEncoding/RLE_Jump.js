const readline = require('readline');

function code(str){
    let q = "";
    let coded_str = "";
    let repeat_count = 0; // повтор
    let nonrepeat_count = 0; // не повтор
    i = 0;
    while (str.charAt(i)) {
        if (str.charAt(i) == str.charAt(i + 1)) {
            repeat_count++;
            if (nonrepeat_count !== 0) {
                coded_str += String.fromCharCode(nonrepeat_count + 128) + q;
                q = "";
                nonrepeat_count = 0;
            }
        } else {
            if (repeat_count !== 0) {
                while (repeat_count > 255) {
                    coded_str += String.fromCharCode(127) + str.charAt(i);
                    repeat_count -= 127;
                }
                coded_str += String.fromCharCode(repeat_count + 1) + str.charAt(i);
                repeat_count = 0;
            } else {
                nonrepeat_count++;
                q += str.charAt(i);
            }
        }
        i++;
    }
    if (nonrepeat_count !== 0) {
        coded_str += String.fromCharCode(nonrepeat_count + 128) + q;
    }
    //console.log("Jump code:", coded_str);
    return coded_str;
}

function decode(str){
    let decoded_str = "";
    let i = 0;
    let w = 0;
    while (str.charAt(i)) {
        if (str.charCodeAt(i) > 128) {
            let q = str.charCodeAt(i) - 128;
            for (w = 0; w < q; w++) {
                decoded_str += str.charAt(i + 1);
                i++;
            }
        } else {
            let q = str.charCodeAt(i);
            for (w = 0; w < q; w++) {
                decoded_str += str.charAt(i + 1);
            }
            i++;
        }
        i++;
    }
    //console.log("Jump decode:", decoded_str);
    return decoded_str;
}

let str = "EJHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHWWrrWWWWWWWW0";
console.log(decode(decode(code(code(str)))));
console.log(str);