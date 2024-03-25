//надо подойти в след раз и напомнить что я сделал rle сегодня, чтобы получить доп баллы
// https://studfile.net/preview/1863892/

function encode(input) {
    let encoded = '';
    let count = 1;

    for (let i = 1; i <= input.length; i++) {
        if (input[i] === input[i - 1]) {
            count++;
        } else {
            if (count == 1 || count == 2) { //if n >= 3
                for (count; count > 0; count--){
                    encoded += input[i - 1];
                }
            } else if (count < 255) {
                encoded += '#' + count + input[i - 1];
            } else {
                let j = count;
                for (let k = 0; k <= count; k++){
                    if (k % 255 == 0 && k != 0) {
                        encoded += '#' + k + input[i - 1];
                        j -= 255;
                    }
                } 
                encoded += '#' + j + input[i - 1];
            }
            count = 1;
        }
    }
    return encoded;
}


const str = 'KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKLL';
console.log(encode(str));